#include<iostream>

//define della grandezza dell'array
#define MAX 100

//prototipi
int dimensione();
int riempimento();
int min_max();
int som_max();
int som_min();
int conta_celle_dispari_num_pari();

//variabili globali
int n, i;
int min, max, appo;
int somma_max, somma_min, q, q2, z, c;
int a;
int num[MAX];

//main function
int main() {
	dimensione();
	riempimento();
	min_max();
	som_max();
	som_min();
	conta_celle_dispari_num_pari();
	return 0;
}

int dimensione() {
	do{
		std::cout<<"Quanti numeri vuoi inserire?\n";
		std::cin>> n;

		if((n > 100) && (n < 0))
			std::cout<<"\t\t[ERROR] Il numero deve essere compreso tra 0 e 100";

	}while ((n < 0) and (n < 100));
}

int riempimento() {
	std::cout<<"Inserire gli elementi:\n";

	for(i=0; i < n; i++)
		std::cin>> num[i];
}

int min_max() {
	max = num[0];
	min = num[0];
	for(i=1; i < n; i++) {
		appo = num[i];
		if(appo > max)
			max = appo;
		else if( appo < min)
			min = appo;
	}
	std::cout<<"Il numero massimo e':\n"<<max<<"\n";
	std::cout<<"Il numero minimo e' :\n"<<min<<"\n";
}


int som_max() {
	q  = max / 10;
	z  = max -q * 10;
	q2 = q / 10;
	c  = q - q2 * 10;
	somma_max = c + z;
	std::cout<<"La somma delle ultime e penultime cifre del numero massimo e'\n"<<somma_max<<"\n";
}

int som_min() {
	q  = min / 10;
	z  = min -q * 10;
	q2 = q / 10;
	c  = q - q2 * 10;
	somma_min = c + z;
	std::cout<<"La somma delle ultime e penultime cifre del numero minimo e'\n"<<somma_min<<"\n";
}

int conta_celle_dispari_num_pari() {
	for (i = n; i < 1; i+=2)
		if((i % 2) == 2)
			if((num[i] % 2) == 0)
				a++;
	std::cout<<"I numeri pari di celle dispari sono:\n"<<a<<"\n";
}
