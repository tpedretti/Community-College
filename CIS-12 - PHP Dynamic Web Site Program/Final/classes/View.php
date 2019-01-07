<?php

// we need the class db to make an object
require_once 'Database.php';

//we also need the recaptcha_helper
//require_once 'helpers/recaptcha.php';

/** 
 * Generates some useful html snippets using 
 * a db object for getting data from 
 * the database
 * 
 * @author Jose from TutToaster.com
 */
class View{

	/**
	* The object for getting data from the database
	*
	* @var object
	* @access private
	*/
	private $db;
	
	/**
	* Creates the db object
	* @access public
	*/
	function __construct()
	{
		$this->db = new Database();
	}
	
	/**
	* Generates the table with all the initial threads for the index page
	*
	* @return string | bool A string if everything was OK, false if not.
	* @access public
	*/	
	function tableThreads()
	{
		$content = "";
		
		if (($threads = $this->db->getThreads()) && mysql_num_rows($threads) > 0) {
			 $content .= '<h1>Threads</h1>';
			 $content .= '<table border="0" width="" id="posts_list">';
			 $content .= '<tr>';
			 $content .= '<th class="title">Title</td>';
			 $content .= '<th>Date</td>';
			 $content .= '<th>User</td>'; 	
			 $content .= '</tr>';
			
			while ($row = mysql_fetch_assoc($threads)) {			
				$content .= '<tr class="thread">';
				$content .= '<td class="title">';
				$content .= '<a href="view_thread.php?permalink=';
				$content .= htmlspecialchars($row['permalink']) . '">'.$row['title'].'</a>';
				$content .= '</td>';
				$content .= '<td class="date">'.htmlspecialchars($row['date']).'</td>';
				$content .= '<td class="author">'.htmlspecialchars($row['author']).'</td>';
				$content .= '</tr>';
			}
			$content .= '</table>';               
			return $content;
		} else {
			return false;
		} 
	} 
	
	/**
	* Composes a table with the content and info of a post
	*
	* @param array $post The post element not $_POST!
	* @param bool $fistPost Indicates whether the post is initial or not.
	* @param int $numRows Useful to know whether we have responses
	* @return string
	* @access private
	*/
	private function composeTable($post, $firstPost, $numRows)
	{
		$htmlTable = "";
		
		if ($firstPost)
			$htmlTable .= '<h1>'.htmlspecialchars($post['title']).'</h1>';

		$htmlTable .= '<table border="0" width="895">';
		$htmlTable .= '	<tr>';
		$htmlTable .= '		<th>Message</th>';
		$htmlTable .= '		<th>Date</th>';
		$htmlTable .= '		<th>Author</th>';
		$htmlTable .= '	</tr>';
	   	$htmlTable .= '	<tr>'; 
		$htmlTable .= '		<td class="title">'.htmlspecialchars($post['content']).'</td>';
		$htmlTable .= '		<td class="date">'.htmlspecialchars($post['date']).'</td>';
		$htmlTable .= '		<td class="author">'.htmlspecialchars($post['author']).'</td>';		 
		$htmlTable .= '	</tr>'; 	
		$htmlTable .= '</table>';               
		if ($firstPost && $numRows > 1)
			$htmlTable .= '<h1>Responses</h1>';
		
		return $htmlTable;  		
	}
		
	
	/**
	* Composes a set of tables, which are going to be the posts of a thread.
	*
	* @param string $permalink The permalink of the thread we want to get.
	* @return string | bool String if was OK, false if not
	* @access public
	* @see html_helper::compose_table() 
	*/
	function tableThreadContent($permalink)
	{
		$content = "";
		
		if ($posts = $this->db->getContentThread($permalink)) {
			$num_rows = mysql_num_rows($posts);   			
			if ($num_rows > 0) {
				while($row = mysql_fetch_assoc($posts))
					$content .= $this->composeTable($row,
						 							is_null($row['permalink_parent']), 
													$num_rows); 		
			}
			return $content;        
		} else {
			return false;  //database error
		}	
	}
	
	/** 
	 * Composes a HTML message, to explain there are not 
	 * threads(initial posts) or posts inside a thread with a title.
	 *
	 * @param bool $from_view_thread The call is from the view_thread.php page 
	 * @return string
	 * @access public
	*/    
	function htmlError($from_view_thread = false)
	{
		if ($from_view_thread) {
			//From view_thread.php
		   	$html = '<p class="error">There is no thread with this title. Sorry! ';
			$html .= 'You can go back to <a href="index.php">the main page</a>.</p>'; 
		}else{
			// From index.php
		   	$html = '<p class="error">There aren\'t any threads. Sorry! </p>';
		}
		return $html;
	}
	
	
	/**
	 * Composes a string with the box to write a post
	 *  
	 * @param bool $new	 Is it a new thread?
	 * @param string $recaptchaError 
	 * @param string $errorHTML Error validating input
	 */
	function messageBox($new, $recaptchaError = null, $errorHTML = null)
	{        
		$content = '<div id="box_message">';
		if (!empty($errorHTML)) {
			$content .= '<div id="message_header"><p class="error">' . $errorHTML . '</p></div>';
		}
		if ($new) {
			$content .= '<h1>Post a Message</h1>';
		} else {
			$content .= '<h1>Post a Response</h1>';
		}
		$content .= '<form action="" method="post" id="post_message" accept-charset="utf-8">';
		if ($new) {
			$content .= '<input id="input_title" type="text" name="title" value="Title of Thread" size="20" />';
		}	
		$content .= '<input type="text" name="author" value="Your Name" size="30" />';
		$content .= '<textarea name="content" rows="8" cols="88">Message</textarea>';
		$content .= recaptcha_get_html(RE_PUBLIC_KEY, $recaptchaError);
		$content .= '<input type="submit" id="submit_box" value="Post the message" />';
		$content .= '</form>';
		$content .= '</div>';
		
		return $content;
	}
	
	/**
	 * Creates a string with the HTML code of 
	 * a div to make a new thread
	 * 
	 * @return string
	 */
	function buttonPostThread()
	{
		return '<div class="newThread">'
			  .'<a href="post_message.php">Create a new thread</a>'
			  .'</div>';
	}
}
?>