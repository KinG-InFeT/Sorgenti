#!/bin/ksh

# Author: Luongo Vincenzo - Software Design S.P.A.
# Date: 30-07-2012
# Note: Questa utility serve per trasferire un file da un host 
#		all'altro su due nodi differenti in configurazione CLUSTER
# OS:	SunOS 5.9 (Oracle Application)

# Configurazione Login FTP
HOST="hostname or IP"
USER="username"
PASS="password"

#Configurazioni vari PATH
PATH_REMOTE="/dev/null" # PATH remota nella quale inserire il file .pdf
PATH_LOCAL="/dev/null" # PATH locale dove andar a prendere il file .out

#controllo se il parametro è stato passato
if [ -z "$1" ]; then
	echo "ERRORE! Il parametro non è stato passato!"
	exit 0;
fi

i=0; #inizializzo l'indice dell'array

#parso il parametro e lo divido mediante la "," così da avere 2 stringhe separate
for arg in $(echo "$1" | tr ',' "\n"); do 
	#estraggo il nome del file dal parametro
	params[$i]=$(basename "$arg" | cut -d. -f 1);
	let i=i+1;
done

# Rendo attiva la cartella con il file da copiare
echo '[DEBUG] Rendo attiva la cartella con il file da copiare: ' $PATH_LOCAL;
cd $PATH_LOCAL

#inizializzo il contatore
count=0;

# Connessione al server FTP e trasferimento file
for FILES in ${params[*]}; do
	
	FILE_FINAL_OUT=$PATH_LOCAL'o'$FILES'.out';
	echo '[DEBUG] File origine (out): '$FILE_FINAL_OUT;
	
	FILE_FINAL_PDF=$PATH_REMOTE$FILES'.pdf';
	echo '[DEBUG] File destinazione (pdf): '$FILE_FINAL_PDF;
	
	#avvio la connessione
	ftp -v -n $HOST <<END_OF_SESSION
user $USER $PASS
$FILETYPE
lcd $PATH_LOCAL
cd $PATH_REMOTE
get $FILE_FINAL_PDF $FILE_FINAL_PDF
bye
END_OF_SESSION
#send $FILE_FINAL_LOCAL $PATH_REMOTE$FILE_FINAL_PDF
#rename $FILE_FINAL_OUT $FILE_FINAL_PDF	
	let count=count+1;
done #end for

echo  '[DEBUG] Fine trasferimento di' $count 'file';