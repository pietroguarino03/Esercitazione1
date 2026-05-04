#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "ordinamento2.hpp" 
#include "randfiller.h"
#include "timecounter.h"
#include <cmath>
#include <iomanip>
template <typename T>
void time_sort(randfiller& rf, int dimensione, std::string tipo){
	int num_vettori= 100;
	std::vector<std::vector<T>> V(num_vettori, std::vector<T>(dimensione));
	
	for (int i=0;i<num_vettori; i++){
		rf.fill(V[i],(T)-1000000,(T)1000000);
	}
	timecounter tempo;
	//Test Mergesort
	auto Vm=V;
	tempo.tic();
	for (int i=0; i<num_vettori;i++){
		mergesort(Vm[i]);
	}
	double tempo_merge=tempo.toc();
	double tempo_medio_m=tempo_merge/num_vettori;
	
	
	//Test Quicksort
	auto Vq=V;
	tempo.tic();
	for (int i=0; i<num_vettori;i++){
		quicksort(Vq[i]);
	}
	double tempo_quick=tempo.toc();
	double tempo_medio_q=tempo_quick/num_vettori;
	
	
	//Test Quicksort ottimizzato
	auto Vq2=V;
	tempo.tic();
	for (int i=0; i<num_vettori;i++){
		quicksort2(Vq2[i]);
	}
	double tempo_quick2=tempo.toc();
	double tempo_medio_q2=tempo_quick2/num_vettori;
	
	
	//Test Bubble sort
	auto Vb=V;
	tempo.tic();
	for (int i=0;i<num_vettori;i++){
		bubble_sort(Vb[i]);
	}
	double tempo_bubble=tempo.toc();
	double tempo_medio_b=tempo_bubble/num_vettori;
	
	
	//Test Inserstion sort
	auto Vi=V;
	tempo.tic();
	for (int i=0;i<num_vettori;i++){
		insertion_sort(Vi[i]);
	}
	double tempo_insertion=tempo.toc();
	double tempo_medio_i=tempo_insertion/num_vettori;
	
	//Test Selection sort
	auto Vs=V;
	tempo.tic();
	for (int i=0;i<num_vettori;i++){
		selection_sort(Vs[i]);
	}
	double tempo_selection=tempo.toc();
	double tempo_medio_s=tempo_selection/num_vettori;
		
	
	//Test sort
	auto Vsort=V;
	tempo.tic();
	for (int i=0; i<num_vettori;i++){
			std::sort(Vsort[i].begin(),Vsort[i].end());
	}
	double tempo_sort=tempo.toc();
	double tempo_medio_sort=tempo_sort/num_vettori;
	
	
	
	std::cout << std::left 
              << std::setw(8)  << tipo 
              << std::setw(6)  << dimensione 
              << std::fixed << std::setprecision(9) 
              << std::setw(14) << tempo_medio_q
			  << std::setw(14) << tempo_medio_q2
              << std::setw(14) << tempo_medio_m 
              << std::setw(14) << tempo_medio_b 
              << std::setw(14) << tempo_medio_i 
              << std::setw(14) << tempo_medio_s 
              << std::setw(14) << tempo_medio_sort 
              << "\n";
              
	
	
}

 
 int main(){
	 srand(time(NULL));
	 randfiller filler;
	 std::vector<int> dimensioni={10,20,30,40,50,100,200,250,300,400,500};
	std::cout << "Test tempo:" << "\n";
	std::cout << std::left 
			<< std::setw(8)  << "TIPO" 
			<< std::setw(6)  << "DIM" 
			<< std::setw(14) << "QUICK"
			<< std::setw(14) << "QUICK OTT."	
			<< std::setw(14) << "MERGE" 
			<< std::setw(14) << "BUBBLE" 
			<< std::setw(14) << "INSERT" 
			<< std::setw(14) << "SELECT" 
			<< std::setw(14) << "SORT" 
			<< "\n";
	std::cout << std::string(100, '-') << std::endl; 
	for(int d:dimensioni){
		time_sort<int>(filler,d,"INT");
		time_sort<double>(filler,d,"DOUBLE");
		time_sort<float>(filler,d,"FLOAT");
	}

	return 0;
 }
		