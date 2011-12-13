//Programma che simula la sequenza di fibonacci
//By KinG-InFeT

#include <stdio.h>

int
main() {
	int num_visu = 20; //quanti numeri da visualizzare?
	int primo    = 1;
	int ultimo   = 1;

	if(num_visu != 0) {
		printf("%d", primo);
		for(num_visu--; num_visu; num_visu--) {
          		printf(" %d", ultimo);
			ultimo += primo;
			primo = ultimo - primo;
		}
	}
	printf("\n");
	return 0;
}
