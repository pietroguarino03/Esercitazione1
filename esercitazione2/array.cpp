#include<iostream>
#include<algorithm>
#include<cmath>
int main()
{
	static const int N = 10;
	double arr[N]={1.2, 3.5, 5.3, 2.8, 6.8, 9.1, 1.0, 3.2, 8.6, 4.5};
	double massimo= arr[0];
	double minimo=arr[0];
	double somma=0;
	for(int i=0;i<N; i++){
		massimo=std::max(massimo, arr[i]);
		minimo=std::min(minimo,arr[i]);
		somma+=arr[i];
		
	}

	double media=somma/N;
	double somma_scarti_quad=0;
	for(int i=0;i<N;i++){
		somma_scarti_quad+=(arr[i]-media)*(arr[i]-media);
	}
	double dev_std=std::sqrt(somma_scarti_quad/N);
	
		
	std::cout<< "Il valore massimo è: "<<massimo<<"\n"<<"Il valore minimo è: "<<minimo<<"\n"<<"La media dei valori è: "<<media<<"\n"<<"La deviazione standard è: "<<dev_std<<"\n";
		
	
	return 0;
}