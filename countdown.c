#include <stdio.h>
#include <time.h>

void aspetta(int secondi);

int main (int argc, char *argv[]) {
int n, q;
	printf ("\n[...]\n");
	q =  argv[1];
	for (n = q; n > 0; n--) {
		printf ("%d\n",n);
		aspetta (1);
	}

	printf ("[FINE]\n");
	return 0;
}

void aspetta ( int secondi ) {
	clock_t fine_attesa;

	fine_attesa = clock () + secondi * CLOCKS_PER_SEC ;

	while (clock() < fine_attesa) {
		//niente
	}
}
