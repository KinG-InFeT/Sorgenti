<div align="center">
<form method="POST" action="" />
Inserisci un URL lungo per generarne uno pi&ugrave; corto<br />
<input type="text" name="url" /><br />
<input type="submit" value="Build" />
</form>
<?php
function get_tiny_url($url)  {
	$ch = curl_init();
	$timeout = 5;
	
	curl_setopt($ch,CURLOPT_URL,'http://tinyurl.com/api-create.php?url=' . $url);
	curl_setopt($ch,CURLOPT_RETURNTRANSFER,1);
	curl_setopt($ch,CURLOPT_CONNECTTIMEOUT,$timeout);
	$data = curl_exec($ch);
	curl_close($ch);
	
	return $data;
}

if(!empty($_POST['url'])) {
	
	if(!preg_match("/\b(?:(?:https?|ftp):\/\/|www\.)[-a-z0-9+&@#\/%?=~_|!:,.;]*[-a-z0-9+&@#\/%=~_|]/i", $_POST['url']))
		die("URL non corretto! Ex. http://www.sito.com/");
		
	$new_url = get_tiny_url(trim($_POST['url']));
	
	print "Text Link: <h3>".$new_url."</h3><br /><br />\n";
}
?>
<br /><br />
<font size="1">TinyURL.com API</font>
</div>
