#include<iostream>

#define MAX 100

char vetC[MAX], num[MAX], maiusc[MAX];
int dim;

int dimensione(int &n);
char caricamento(int n, char caratteri[]);
void controllo(char caratteri[], int n, char M[], char N[]);
void stampa(char N[], char M[]);

void main() {
	dimensione(dim);
	caricamento(dim, vetC);
	controllo(vetC, dim, maiusc, num);
	stampa(num, maiusc);
}

int dimensione(int &n) {
	do{
		std::cout<<"Dammi la dimensione:\n";
		std::cin>>n;
		if((n > 100) && (n < 100))
			std::cout<<"[ERROR] Dimensione contenuta tra 0 e 100!";
	}while(!((n > 0) && (n < 100)));
}

char caricamento(int n, char caratteri[]) {
	int i;
	std::cout<<"Dammi i caratteri:\n";
	for(i = 0; i < n; i++)
		std::cin>>caratteri[i];
	return *caratteri;
}

void controllo(char caratteri[], int n, char M[], char N[]) {
	int j, i, k;

	j = NULL;
	k = NULL;

	for(i = 0; i < n; i++) {
		if((caratteri[i] >= 'A') && (caratteri[i] <= 'Z')) {
			M[k] = caratteri[i];
			k++;
		}else if((caratteri[i] >= 0) && (caratteri <= 9)) {
			N[j] = caratteri[i];
			j++;
		}
	}
	k++;
	j++;
	M[k] = '\0';
	N[j] = '\0';
}

void stampa(char N[], char M[]) {
	std::cout<<"L'array di caratteri maiuscoli e':\n";
	std::cout<<M;
	std::cout<<"L'array di caratteri numerici e':\n";
	std::cout<<N;
}


