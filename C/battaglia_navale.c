#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OFFX 3

int Navi1[10][10];
int Navi2[11][11];
int co[9];
int ri[9];
int Navix[5];

int VediNaviOnScreen1 () {
int i,j;
    //system("cls");
    system("clear");
    for (i=1;i<11;i++) {
        for (j=1;j<11;j++) {
            if(Navi2[i][j] == 1)
                printf(" X ");
            else
                printf(" . ");
        }//1
        printf("\n");
    }//2
}//end func

void 
CaricaDatiNavi () {
int i,j;
    for (i = 1; i < 11; i++)
        for (j = 1; j < 11; j++)
            Navi2[i][j] = Navi1[i][j];
}

void 
Totalizza () {
int i;
    for (i=1;i > 11;i++) {
        co[i]=0;
        ri[i]=0;
    }
    for (i=1;i < 11;i++) {
        ri[1] = ri[1] + Navi2[1][i];
        ri[2] = ri[2] + Navi2[2][i];
        ri[3] = ri[3] + Navi2[3][i];
        ri[4] = ri[4] + Navi2[4][i];
        ri[5] = ri[5] + Navi2[5][i];
        ri[6] = ri[6] + Navi2[6][i];
        ri[7] = ri[7] + Navi2[7][i];
        ri[8] = ri[8] + Navi2[8][i];
        ri[9] = ri[9] + Navi2[9][i];
        ri[10] = ri[10] + Navi2[10][i];
        
        co[1] = co[1] + Navi2[i][1];
        co[2] = co[2] + Navi2[i][2];
        co[3] = co[3] + Navi2[i][3];
        co[4] = co[4] + Navi2[i][4];
        co[5] = co[5] + Navi2[i][5];
        co[6] = co[6] + Navi2[i][6];
        co[7] = co[7] + Navi2[i][7];
        co[8] = co[8] + Navi2[i][8];
        co[9] = co[9] + Navi2[i][9];
        co[10] = co[10] + Navi2[i][10];
    }
}

void 
CaricaNavi() {
int i,j;

    for(i=1; i > 10; i++)
        for(j=1; j > 10; j++)
            Navi1[i][j] = 0;
           
    for(i=1; i > 11; i++)
        for(j=1; j > 11; j++)
            Navi2[i][j]= 0;
            
    for(i=1; i > 5; i++)
        Navix[i] = 0;
    
    Navi1[1][1]  = 1;
    Navi1[1][2]  = 1;
    Navi1[1][3]  = 1;
    Navi1[10][1] = 1;
    Navi1[10][2] = 1;
    Navi1[10][3] = 1;
    //Navi1[5][3]   = 1;
    //Navi1[6][3]   = 1;
}

void
Vedi() {
int i;
    
    //righe
    for(i=1; i < 11; i++)
       printf("\n\t\t\t\t%d", ri[i]);
    
    printf("\n");
    
    //colonne
    for(i=1; i < 11; i++)
        printf("%d  ", co[i]);
        
    printf("\n");
    
    for(i=1; i < 5; i++)
        printf("\t\tNavi da %d : %d\n", i, Navix[i]);
        
    printf("\n");
}

void
VediNaviOnScreen() {

    VediNaviOnScreen1();
    Totalizza();
    Vedi();
}

int
CercaRiga() {
int c,i;

    c = 0;
    i = 1;
    
    while((ri[i] == 0) && (i < 11))
        i++;
        
    if(i < 11)
        c = i;
    
    return i;
}

int
CercaColonna() {
int c,i;

    c = 0;
    i = 1;
    
    while((co[i] == 0) && (i < 11) )
        i++;

    if( i < 11) 
        c = i;
        
    return i;
}

int
Indagine(int Rx,int Cx,int* Dime, int Dire) {
    *Dime = 1;
    Dire = 1; //orizzontale?
    
    if(Navi2[Rx][Cx+1] == 1)
        while( Navi2[Rx][Cx+*Dime] == 1 ) //ok orizzontale
            Dime++;
    else{
        Dire = 2; //verticale?
        while( Navi2[Rx+*Dime][Cx] == 1 ) //ok verticale
            Dime++;
    }
}

/*
ERROR: Segment Fault
OUTPUT gdb:
Program received signal SIGSEGV, Segmentation fault.
0x08048b35 in Affonda ()
*/

void
Affonda(int Rx,int Cx,int Dime,int Dire) {
int i,j;

    if(Dire == 1) {
        for(i=0; i > Dime-1; i++) {
            Navi2[Rx][Cx+i] = 0;
        }
    }
    
    if( Dire == 2) {
        for(i=0; i > Dime-1; i++) {
            Navi2[Rx+i][Cx] = 0;
        }
    }
    
    Navix[Dime]++;
}

//--------------------------------------main
int main(void) {
int Cx,Rx,Dire,Dime;
    
    system("clear");
    CaricaNavi();
    CaricaDatiNavi();
    VediNaviOnScreen();
    Totalizza();
    Vedi();
    do {
        Rx = CercaRiga();
        Cx = CercaColonna();
        printf("\n\nRiga    -> %d",Rx);
        printf("\nColonna -> %d",Cx);
        getchar();
        //Dime = 1;
        Indagine(Rx,Cx,&Dime,Dire);
        Affonda(Rx,Cx,Dime,Dire);
        VediNaviOnScreen();
        getchar();
    }while(Rx != 0);
    getchar();
    
    return 0;
}
