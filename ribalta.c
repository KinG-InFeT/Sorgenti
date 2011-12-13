//Ribalta una stringa data in INPUT By KinG-InFeT

#include <stdio.h>
#include <string.h>

void exit(int status);

int main (void) {
char stringa[51];
int i, lunghezza;
	
	//prendo la stringa da ribaltare da input
	printf("Inserisci stringa (MAX 50 Caratteri): ");
	scanf("%s", stringa);
	
	//controllo lunghezza stringa che non superi i 50 caratteri
	if(strlen(stringa) > 50) {
	    printf("ERRORE! Stringa troppo lunga!");
	    //esco dal programma in caso di errore
	    exit(0);
	}

	//aggiungo l'end stringa
	stringa[strlen(stringa)] = '\0';
	
	//calcolo la lunghezza della stringa
	lunghezza = strlen(stringa);
	
	//se voglio, visualizzo la lunghezza numerica della stringa
	//printf("\nLunghezza stringa: %d", lunghezza);
	
    printf("\nStringa al contrario: ");
	
	//genero la stringa ribaltata
    for(i = 0; i < lunghezza; i++) 
		printf("%c", stringa[lunghezza-1-i]);
	
	printf("\n\nPremere un tasto per uscire...\n");
	getchar();
	getchar();
	
	return;
}
