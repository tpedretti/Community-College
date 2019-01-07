<?php

//Config file
require_once 'config.inc.php';

/** 
 * Database class to save and retrieve data
 * 
 * @author Jose from TutToaster.com
 */
class Database 
{
	/**
	* The MySQL link identifier
	* 
	* @var resource
	* @access private
	*/
	private $db;
	
	/** 
	* Sets the config and db vars using the config.ini file
	* @access public
	*/
	function __construct()
	{
		// We set our own error_handler
		set_error_handler(array($this,'errorHandler'));
		
		//Connect to Database
		$this->db = mysql_connect(DB_HOSTNAME, DB_USERNAME, DB_PASSWORD);	
		mysql_set_charset('utf8', $this->db);				
	 	mysql_select_db(DB_NAME, $this->db);
	}

	/** 
	* Error_handler function just in case we get a warning
	* trying to connect to the database
	* The rest of errors will be managed as usually
	*
	* @param int 	 $errno  An error_handler function must have it
	* @param string $errstr An error_handler function must have it
	* @return bool
	* @access public
	*/
	function errorHandler($errno, $errstr)
	{
		switch ($errno){
		    case E_WARNING:
				echo '<b>There has been an error with the MySQL database connection. '.
				  	 'Please, make sure the config file is OK.</b>';
				die(); 
		    default:
		        return false;
		}
	}
	
	/**
	* Executes a select query for getting 
	* all the initial posts
	*
	* @return resource
	* @access public
	*/
	function getThreads()
	{
		$query = "SELECT p.title, date_format(p.date,'%m/%d/%Y %T') as date, p.permalink, p.author ". 
				 "FROM posts p ".
				 "WHERE permalink_parent IS NULL";   
		return mysql_query($query); 
	}
	
	/**
	* Executes a select query for getting all the 
	* posts (the first one and the responses)
	* with a unique permalink (string)
	*
	* @param string $permalink We'll get all the posts with this permalink
	* @return resource
	* @access public
	*/
	function getContentThread($permalink)
	{
		 $query = "SELECT p.title, date_format(p.date,'%m/%d/%Y %T') as date, p.author, p.content, p.permalink_parent ". 
				  "FROM posts p ".
				  "WHERE permalink = '$permalink' OR permalink_parent = '$permalink'".
				  "ORDER BY p.date ASC"; //we get the initial post first 
		 
		return mysql_query($query);
	}
	
	/**
	 * Returns if it's a valid or invalid input to create a post.
	 * 
	 * @param array $input
	 * @param string $permalink
	 * @param boolean $newThread Is this a new thread?
	 * @return boolean
	 * @access private
	 */
	private function isValidPost($input, $permalink, $newThread)
	{                                                                                                     
 		if ($newThread) {
			return !empty($input['title']) 
				&& !empty($input['content']) 
				&& !empty($input['author']) 
				&& !empty($permalink);
		} else {
			return !empty($input['content']) 
				&& !empty($input['author']) 
				&& !empty($permalink);
		}
	}
	
	/** 
	* Saves a post and return the result of the query.
	* We have to be aware of a possible error, 
	* so we use an error code
	* 
	* The errorCode can be:                                          
	* 	-1 -> A field is empty                        
	* 	-2 -> Duplicated title
	* 	-3 -> Something is wrong with the INSERT query
	*
	* @param array  $input What we receive to be saved  
	* @param string $permalink The permalink to the thread 
	* @param boolean $newThread Boolean which indicates whether is a new thread or not.
	* @return int 1 if the query is OK, an error Code if not.
	* 
	* @access public
	*/
	function savePost($input, $permalink, $newThread)
	{   
		
		$postOK = $this->isValidPost($input, $permalink, $newThread);
		
		if (!$postOK) {
			return -1;  // something missing 
		}
		
		if ($newThread) {
			$query = 'INSERT INTO posts '
					. '(title, content, author, permalink, permalink_parent) VALUES'
					. '("%s","%s","%s","%s", NULL)'; 
					                                                          	
			$query = sprintf($query, 
							clean(strip_tags($input["title"])), 
							clean(strip_tags($input["content"])), 
							clean(strip_tags($input["author"])), 
							$permalink);      	
		} else {
			$query = 'INSERT INTO posts '
					. '(content, permalink_parent, author) VALUES' 
					. '("%s","%s","%s")'; 
					
			$query = sprintf($query, 
							clean(strip_tags($input['content'])), 
							$permalink, 
							clean(strip_tags($input['author'])));
		}                       
				
		if (mysql_query($query)) {
			return 1;   // Ok
		} elseif (mysql_errno() == 1062) {
			return -2;  // Duplicated title error
		} else {
			return -3;  // DB error
		}      
	}	
	
}
?>