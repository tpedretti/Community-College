<?php
/** 
* Some useful functions to validate data and
* convert data to insert into our database
* In some cases a function wil create a 
* database object and use it
*/

/** 
* Takes a string as input and creates a
* human-friendly URL string.
*    
* @param string $str The string
* @return string $permalink
*/
function strToPermalink($str)
{
	$permalink = iconv('UTF-8', 'ASCII//TRANSLIT', $str);
	$permalink = preg_replace("/[^a-zA-Z0-9\/_|+ -]/", '', $permalink);
	$permalink = strtolower(trim($permalink, '-'));
	$permalink = preg_replace("/[\/_|+ -]+/", '_', $permalink);

	return $permalink;    
}

/**
 * Clean a string so we can use it in queries 
 * @param mixed $value
 */
function clean($value)
{
	// Stripslashes
	if (get_magic_quotes_gpc()) {
		$value = stripslashes( $value );
	}
	
	// Quote if not a number or a numeric string
	if (!is_numeric($value) && !empty($value)) {
		$value = mysql_real_escape_string($value);
	}
	return $value;
}

/**
 * Takes an array as input, checks if everything is correct
 * and inserts the post into the database.
 * If something is wrong an errorCode is analyzed and 
 *  an error message is returned in an array.
 * 
 * The errorCode can be:
 * 	-1 -> A field is empty 
 *	-2 -> Title is duplicated
 * 	-3 -> Something is wrong with the INSERT query
 *
 * @param string $permalink The permalink we have to process 
 * @param bool $newThread 
 * 
 * @return array $returnArray Return an array with some useful values to know what happened
 * 
 */
function processPost($permalink = null, $newThread = true)
{
	$input = $_POST;
	
	//The array we'll return
	$returnArray = array('errorHTML' => NULL,
						 'okMessage' => NULL,
						 'recaptchaError' => NULL,
						 'showBox' => NULL);
	
	if (array_sum($input) > 0 && !empty($input["recaptcha_response_field"])) {
		//We have something in the $input and the Recaptcha response
		$resp = recaptcha_check_answer (RE_PRIVATE_KEY,
										$_SERVER["REMOTE_ADDR"],
										$input["recaptcha_challenge_field"],
										$input["recaptcha_response_field"]);
		if ($resp->is_valid) {
			require_once 'classes/Database.php';
			$db = new Database();
			
			if (is_null($permalink)){
				$permalink = strToPermalink(strip_tags($input['title']));  
			} 
			
			$saveResult = $db->savePost($input, 
										clean(strip_tags($permalink)), 
										$newThread);
										
			switch ($saveResult) {
				case -1:  //A field is empty 
					$returnArray['errorHTML'] = 'All fields are required';
					break;
					
				case -2: //The title is already in use
					$returnArray['errorHTML'] = 'Duplicated title, please, choose another one.';
					break;				
				case -3: //There has been an error with the query
					$returnArray['errorHTML'] = 'There has been an error with the Database, '.
											'please, try again later.';
					break;				
					
				default: //Everything is OK
					$returnArray['okMessage'] = '<p>The post has been published. You can see it '
						.'<a href="view_thread.php?permalink=' . $permalink . '">here</a></p>';
			}
		} else { //The recaptcha response is not valid. 
			$returnArray['recaptchaError'] = $resp->error;	
		}
	} elseif (array_sum($input) > 0) {
		//We have something in the $input array but the recaptcha response is not
		$returnArray['errorHTML'] = 'All fields are required';
	}
	
	/* Anyway we compose a boolean value to know if we have to show 
	   the box to write a message or not */
	if ($newThread) {
		$returnArray['showBox'] = !empty($returnArray['errorHTML']) 
								  || !empty($returnArray['recaptchaError']) 
								  || empty($input);		
	}

	return $returnArray;
}

?>