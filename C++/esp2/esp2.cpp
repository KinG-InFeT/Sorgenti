#include<iostream>

#define MAX 100

int dim;

typedef struct{
	char citta[15];
	float temp_max;
	float temp_min;
}tabella;

tabella *vett[MAX];

void carica_tabella(int &dim, tabella *vett[]);
void visualizza_tabella(int dim, tabella *vett[]);

int main(void) {

	carica_tabella(dim, vett);
	visualizza_tabella(dim, vett);

	return 0;
}

void carica_tabella(int &dim, tabella *vett[]) {
	int i;

	std::cout<<"Quanti valori vuoi inserire?\n";
	std::cin>> dim;

	for(i=0;i < dim; i++) {
		std::cout<<"\nNome citta':\n";
		std::cin>>vett[i]->citta;
		std::cout<<"\nTemperatura Min:\n";
		std::cin>>vett[i]->temp_min;
		std::cout<<"\nTemperatura Max:\n";
		std::cin>>vett[i]->temp_max;
	}
}

void visualizza_tabella(int dim, tabella *vett[]) {
	int i;

	std::cout<<"La tabella inserita e':\n";
	
	for(i = 0; i < dim; i++) {
		if(vett[i]->temp_max > vett[dim]->temp_max) {
			std::cout<<"\nCitta': "<<vett[i]->citta;
			std::cout<<"\nTemperatura Min: "<<vett[i]->temp_min;
			std::cout<<"\nTemperatura Max: "<<vett[i]->temp_max;
		}else{
			std::cout<<"\nCitta': "<<vett[dim]->citta;
			std::cout<<"\nTemperatura Min: "<<vett[dim]->temp_min;
			std::cout<<"\nTemperatura Max: "<<vett[dim]->temp_max;
		}
	}
}
