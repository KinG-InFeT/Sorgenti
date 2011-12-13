#include<stdio.h>

int num, max, min, n, count;

void main() {

	printf("Quanti numeri vuoi controllare?\n");
	scanf("%d", &n);
	printf("Inserisci i numeri da controllare:\n");
	scanf("%d", &num);

	min = num;
	max = num;

	count = 1;

	while(!(count == n)) {
		scanf("%d", &num);

		if(num >= max)
			max = num;

		if(num <= min)
			min = num;

		count = count + 1;
	}

	printf("Il numero maggiore della serie e': %d\n", max);
	printf("Il numero minore della serie e': %d\n", min);
}
