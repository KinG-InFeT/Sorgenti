<div align="center">
<form method="POST" action="" />
Codice da Offuscare:<br />
<textarea rows="20" cols="60" name="contenuto"></textarea><br />
<input type="submit" value="Generate Code" /><br />
<font size="1">Note: Non inserire all'interno del codce &lt;?php e ?&gt;</font>
</form>
<?php

/*
 * @author KinG-INFeT
 * @version 1.0
 * @licence GPL
 */

if(!empty($_POST['contenuto'])) {
	
	/*
	//controllare se si inseriscono le tag <?php o ?>
	*/
	$contents = trim($_POST['contenuto']);


	$crypt = "<?php \r\n"
			. 'eval(gzinflate(base64_decode(str_replace("\\n",\'\',\''
			. chunk_split(base64_encode(gzdeflate($contents, 9)), 80, "\r\n")
			. "'))));\r\n"
			. "?>";
	
	print "<textarea rows=\"20\" cols=\"60\" >";
	print htmlspecialchars($crypt);
	print "</textarea>";
}
?>
</p>
