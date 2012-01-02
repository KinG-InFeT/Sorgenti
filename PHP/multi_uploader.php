<html>
<head>
<title>Uploader Multiplo</title>
</head>
<body>
<!-- form uploader -->
<form action="<?php print htmlspecialchars($_SERVER['PHP_SELF']); ?>" method="POST" enctype="multipart/form-data">
<input type="file" name="file[]" multiple="" />
<input type="submit" name="Uppa!" value="go" />
</form>
<?php

function singleUpload($i, $cartella, $maxSize, $acceptType) {

    if(@$_FILES['file']['name'][$i] != "") {
    
        $destinazione = $cartella.basename( $_FILES['file']['name'][$i]);
        
        if($_FILES['file']['size'][$i] <= $maxSize*1024) {
        
            if(in_array($_FILES['file']['type'][$i], $acceptType)) {
            
                if(move_uploaded_file($_FILES['file']['tmp_name'][$i], $destinazione))
                    return "File caricato con successo!";
                else
                    return "Errore nell'upload del file";
            }else
                return "Tipo di file non accettato!";
            }else
                return "Dimensione del file troppo grande, massima dimensione accettata: ".$maxSize." kilobyte";
            }else
                if(isset($_REQUEST['go']))
                    return "Nessun file inserito!";

}

$acceptType = array( //tipi di file accettati, in questo caso solo immagini
     'png' => 'image/png',
     'jpe' => 'image/jpeg',
     'jpeg' => 'image/jpeg',
     'jpg' => 'image/jpeg',
     'gif' => 'image/gif',
     'bmp' => 'image/bmp',
     'ico' => 'image/vnd.microsoft.icon',
);

$maxSize = 50000000000; //Grandezza limite file
$cartella = "./album/"; //cartella dove vengono caricati i file nel server

if(!file_exists($cartella))
    die("[ERROR] Cartella di destinazione INESISTENTE!");

if(!is_writable($cartella))
    die("[ERROR] Cartella di destinazione NON scrivibile!");

if(isset($_FILES['file']['name'])) {

    $numero = count($_FILES['file']['name']);

    for($i = 0;$i < $numero; $i++)
        print "\nRisultato file ".($i+1).": ".singleUpload($i, $cartella, $maxSize, $acceptType)."<br />";

}
?>
</body>
</html>
