#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void decript(char *stringa);
void encript(char *stringa);

int main() {
    int i,l,n,s;

    char *stringa = (char*)malloc(1200*sizeof(char));  ///allocazione dinamica per evitare il buffer overflow
    
    system ("clear");
    printf("Inserisci la frase da elaborare: ");
    scanf("%s", stringa);
    
    l=strlen(stringa);
    
	if (l > 1200) {
		printf("Hai inserito una lunghezza non consentita!!!");
		getchar();
		return 0;
	}
	
    system("clear");
    printf("1) Decript\n2) Encript\n");
    scanf("%d", &n);
    if (n==1) {
		decript(stringa);
        printf("\nStringa convertita:\n%s\n\n",stringa);
	}else{
		encript(stringa);
        printf("\nStringa convertita:\n%s\n\n",stringa);
	}
    getchar();
    return 0;
}


void decript(char *stringa) {
int i;
int a;

     for (i=0;i<strlen(stringa);i++) {
	     if ( ((stringa[i] >= 'A') && (stringa[i] <= 'Z')) || ((stringa[i] >= 'a')&&(stringa[i] <= 'z')) || ((stringa[i] >= '0') && (stringa[i] <= '9')) )
		     a = stringa[i] += 3 ;
	     if ((a > '9') && (a < 'A'))
		     stringa[i] -= 10 ;
	     if ((a > 'Z') && (a < 'a'))
		     stringa[i] -= 26 ;
	     if (a > 'z')
		     stringa[i] -= 26 ;
     }
}

void encript(char *stringa) {
int i;
int a;

     for (i=0;i<strlen(stringa);i++) {
	     if ( ((stringa[i] >= 'A') && (stringa[i] <= 'Z')) || ((stringa[i] >= 'a')&&(stringa[i] <= 'z')) || ((stringa[i] >= '0') && (stringa[i] <= '9')) )
		     a = stringa[i] -= 3 ;
	     if (a < '0')
		     stringa[i] += 10 ;
	     if ((a < 'A') && (a > '9'))
		     stringa[i] += 26 ;
	     if ((a < 'a') && (a > 'Z'))
		     stringa[i] += 26 ;
     }
}
