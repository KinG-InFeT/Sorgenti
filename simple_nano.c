/*
 * @author GsC_RuL3Z
 */

#include <stdio.h>
#include <stdlib.h>
 
char b[100];
char nome[100];
char cont[10000];
int testo;
FILE *f;
 
main (){
    system("clear");
    printf("+---------------------------------------------------------------+\n");
    printf("|                      SIMPLE NANO UNIX                         |\n");
    printf("|                  Professional Text editor                     |\n");
    printf("+---------------------------------------------------------------+\n");
    printf("\n\nPremi:\n");
    printf("w)Per creare un nuovo file\n");
    printf("r)Per visualizzare un file gia esistente\n");
    printf("q)Per uscire\n");
    while (1){
        printf("\n>");
        scanf("%s",b);
        if(strcmp(b,"w")==0){
            printf("\n\nInserisci il nome del file: ");
            scanf("%s",nome);
            f=fopen(nome,"w");
            system("clear");
            printf("%s          -     write mode    -      premi @ per uscire e salvare\n\n",nome);
            do{
                testo = getchar();
                if(testo != 64){
                    putc(testo, f);
                }
            } while (testo != 64);
 
            fclose(f);
 
            printf ("File scritto correttamente.\n");
 
        }else if(strcmp(b,"r")==0){
            printf("Inserisci il nome del file da visualizzare: ");
            scanf("%s",nome);
            f=fopen(nome,"r");
            system("clear");
            printf("%s          -     read mode    -      \n\n",nome);
            while (fgets(cont,10000,f)!=NULL)
            printf("%s",cont);
 
        }else if(strcmp(b,"q")==0){
            return 1;
        }else{
            printf("\nOperazione illegale\n");
        }
    }
    return 0;
}
