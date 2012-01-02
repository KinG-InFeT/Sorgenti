#include<stdio.h>

int n;

int fattoriale(int n);

int main () {
	printf("Inserire un numero intero: ");
	scanf("%d", &n);
	printf("Il fattoriale e': %d\n", fattoriale(n));
}

int fattoriale(int n) {
	if(n < 1)
		return 1;
	else
		return (n * fattoriale( n - 1 ));
}
