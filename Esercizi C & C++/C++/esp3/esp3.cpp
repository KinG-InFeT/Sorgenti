#include<iostream>

float scambio(float *a, float *b);

float main(float) {
	float num_1, num_2;

	std::cout<<"Dammi 2 valori:\n";
	std::cin>>num_1;
	std::cin>>num_2;
	std::cout<<"Prima dello scambio:\n";
	std::cout<<"\t num_ = "<<num_1;
	std::cout<<"\n\t num_2 = "<<num_2;

	scambio(&num_1, &num_2);

	std::cout<<"Dopo lo scambio:\n";
	std::cout<<"\t num_ = "<<num_1;
	std::cout<<"\n\t num_2 = "<<num_2;

	
}

float scambio(float *a, float *b) {
	float app_1, app_2;

	app_1 = *a;
	app_2 = *b;
	*a = app_2;
	*b = app_1;

	return *a, *b;
}
