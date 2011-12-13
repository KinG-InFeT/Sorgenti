/*
 * @title gestione di una rubrica telefonica
 * @author KinG-InFeT
 * @data 04/02/2011
 *
 *	v0.1 - Prima versione con possibilità di inserire, visualizzare e ricercare un elemento
 *	v0.2
 *		[+] Aggiunte altre funzioni come la modifica, la cancellazione e la ricerca per numero telefonico
 *		[+] Cambiato il controllo sulla scelta, ora utiliza lo switch
 *		[+] Inserito controllo sul sistema per definire la variabile pulisci per la system()
 *		[+] Completa reindentazione del codice sorgente :S
 */
 
#include<stdio.h>
#include<stdlib.h>

//dichiarazione struttura record file

struct Rub_Tel {
	int id;
	char nome[20];
	char cognome[20];
	char num[20];
};

typedef struct Rub_Tel Anagrafica;
Anagrafica Rubrica;

FILE *rubrica;

//prototipi
void Pulisci(void);
void Scrivi(void);
void Leggi(void);
void CercaMatricola(void);
void CercaNumeroTel(void);

int main() {
int scelta, risp;

	do{
		Pulisci();
		do{
			Pulisci();
			printf("\t\t# MENU #\n\n");
			printf("1) Inserisci (Digita 1)\n");
			printf("2) Visualizza la Rubrica (Digita 2)\n");
			printf("3) Cerca nella Rubrica Tramite Matricola (Digita 3)\n");
			printf("4) Cerca nella Rubrica Tramite Numero Telefono (Digita 4)\n\n");
			printf("Scelta: ");
			scanf("%d",&scelta);
			if((scelta > 5) || (scelta < 1)) {
				Pulisci();
				printf("Errore! Scelta non esistente!");
			}
		}while((scelta > 5) || (scelta < 1));

		switch(scelta) {
			case 1:
				Pulisci();      
				//apro il file in sola scrittura
				rubrica = fopen("rubrica.txt", "w");
				Scrivi();
				fclose(rubrica);
			break;
			
			case 2:
				Pulisci();
				//apro il file in sola lettura
				rubrica = fopen("rubrica.txt", "r");
				Leggi();
				fclose(rubrica);
			break;
			
			case 3:
				Pulisci();
				//apro il file in sola lettura
				rubrica = fopen("rubrica.txt", "r");
				CercaMatricola();
				fclose(rubrica);
			break;
			
			case 4:
				Pulisci();
				//apro il file in sola lettura
				rubrica = fopen("rubrica.txt", "r");
				CercaNumeroTel();
				fclose(rubrica);
			break;
			
			default:
				printf("Scelta non esistente!");
			break;
		}
   
	printf("\n\nVuoi tornare al menu iniziale? ( 0 = no , 1 = si)");
	scanf("%d", &risp);
   
	}while(risp == 1);
	
   return 0;
}

void Scrivi(void) {
int risposta;

	printf("-Inserimento Dati Rubrica-\n");
	do{
	  printf("Matricola: ");
      scanf("%d", &Rubrica.id);
      printf("Nome: ");
      scanf("%s", Rubrica.nome);
      printf("Cognome: ");
      scanf("%s", Rubrica.cognome);
      printf("Numero Telefonico: ");
      scanf("%s", Rubrica.num);
      fwrite(&Rubrica, sizeof(Anagrafica), 1, rubrica);

      printf("\n\nHai finito di caricare l'elenco? (0 = no, 1 = si)\n");
      scanf("%d", &risposta);
   }while(!risposta);

   return;
}

void Leggi(void) {

	fread(&Rubrica, sizeof(Anagrafica), 1, rubrica);

	Pulisci();
	while(!feof(rubrica)) {
		printf("Matricola: %d\n", Rubrica.id);	
		printf("Nome: %s\n", Rubrica.nome);
		printf("Cognome: %s\n", Rubrica.cognome);
		printf("Numero Telefonico: %s\n\n", Rubrica.num);
		fread(&Rubrica, sizeof(Anagrafica), 1, rubrica);
	}
	getchar();
	getchar();
	return;
}

void CercaMatricola(void) {
int matricola;
long posizione;
     
     printf("Inserisci il numero di Matricola: ");
     scanf("%d", &matricola);
     
     posizione = (matricola - 1)*sizeof(Anagrafica);
     
     while(!feof(rubrica)) {
          fseek(rubrica, posizione, 0);
          if(fread(&Rubrica, sizeof(Anagrafica) ,1, rubrica)) {
               Pulisci();
               printf("Matricola n°: %d Trovata!\n\n", matricola);
               printf("Nome: %s\n", Rubrica.nome);
               printf("Cognome: %s\n", Rubrica.cognome);
               printf("Numero Telefonico: %s\n", Rubrica.num);
               
               getchar();
          }else{
                Pulisci();
                printf("Matricola non trovata!\n");
          }     
     }       
     
     getchar();
          
     return;
}

void CercaNumeroTel(void) {
char Num[20];	//numero da cercare
int error;		//variabile che mi consente di controllare se il contatto è stato trovato oppure no

	Pulisci();
	printf("\nInserisci il numero telefonico: ");
	scanf("%s", Num);
	
	fread(&Rubrica, sizeof(Anagrafica), 1, rubrica);

	while(!feof(rubrica)) {
		if(Rubrica.num == Num) {
			printf("\nContatto TROVATO!\n\n");
			printf("Matricola: %d\n", Rubrica.id);
			printf("Nome: %s\n", Rubrica.nome);
			printf("Cognome: %s\n", Rubrica.cognome);
			printf("Numero Telefonico: %s\n\n", Rubrica.num);
		}else{
			error = 1;
		}
		fread(&Rubrica, sizeof(Anagrafica), 1, rubrica);
	}
	if(error == 1) {
		printf("\n\nContatto associato al numero %s, NON Trovato!", Num);
	}
	getchar();
	return;
}

void Pulisci(void) {
	//controllo il sistema se è Windows (WIN32) oppure Linux (LINUX)
	#ifdef WIN32
		system("cls");
	#endif
	#ifdef LINUX
		system("clear");
	#endif
}
