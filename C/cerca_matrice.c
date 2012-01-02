#include <stdio.h>
#define COL 3
#define RIG 4

int main(int argc, char **argv) {    

    char matrix[RIG][COL] = { 'p', 'a', 'b',
                              's', 'e', 'r',
                              'r', 'u', 'w',
                              't', 'y', 'e' };
    
    int i, x;
    char c;
    
    printf( "Carattere: ");
    c = getchar();
    
    for(i = 0; i < COL; i++)
        for(x = 0; x < RIG; x++)
            if(c == matrix[x][i])
                printf( "Carattere trovato");
    
    return 0;   
}
