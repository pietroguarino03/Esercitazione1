//Test Bubble sort
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "ordinamento.hpp" 
#include "randfiller.h"



template <typename T>
bool verify_sort(randfiller& rf){
	int size=rand()%101;
	std::vector<T> v(size);
	rf.fill(v, (T)-1000, (T)1000);
	bubble_sort(v);
	
	return is_sorted(v);
}

bool scelta_tipo(randfiller& rf){
	int scelta=rand()%3;
	if (scelta==0)
		return verify_sort<int>(rf);
	if (scelta==1)
		return verify_sort<double>(rf);
	else
		return verify_sort<float>(rf);
}
	
int main(){
	srand(time(NULL)); 
	randfiller filler;
	std::cout<< "Test bubble sort:"<<"\n";
	int falliti=0;
	for (int i=0; i<100; i++){
		if (!scelta_tipo(filler)){
			std::cout << "Errore: Test numero " << i << " fallito!" << "\n";
            falliti++;
		}
	}
	if (falliti==0){
	std::cout<<"Esito test int,float,double: positivo"<<"\n";
	}
	else{
		std::cout<<"numero test falliti: "<<falliti<<"\n";
	}
	std::vector<std::string> s={"Giovanni","Marco","Alberto","Riccardo","Giacomo","Mario","Daniele","Giorgio","Francesco","Pietro"};
	bubble_sort(s);
	if (!is_sorted(s)){
		std::cout<<"Test stringa fallito"<<"\n";
	}
	else
		std::cout<<"Test stringa riuscito"<<"\n";
	return 0;
}

		