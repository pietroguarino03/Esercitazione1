#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include "ordinamento.hpp" 
#include "randfiller.h"
#include "timecounter.h"
#include <cmath>
template <typename T>
void time_sort(randfiller& rf, int size){
	
	std::vector<T> v(size);
	rf.fill(v, (T)-1000, (T)1000);
	std::vector<T> v_bubble(v), v_insertion(v), v_selection(v);
	timecounter tempo_bubble, tempo_insertion, tempo_selection, tempo_sort;
	tempo_bubble.tic();
	
	bubble_sort(v_bubble);
	double sec_bubble=tempo_bubble.toc();
	
	tempo_insertion.tic();
	
	insertion_sort(v_insertion);
	double sec_insertion=tempo_insertion.toc();
	
	tempo_selection.tic();
	
	selection_sort(v_selection);
	double sec_selection=tempo_selection.toc();
	
	tempo_sort.tic();
	
	std::sort( v.begin(), v.end() );
	double sec=tempo_sort.toc();
	
	std::cout << "N:" << size << "\t"
          << "|B:" << sec_bubble << "\t"
          << "|I:" << sec_insertion << "\t"
          << "|S:" << sec_selection << "\t"
          << "|STD:" << sec 
          << "\n";
}

void scelta_tipo(randfiller& rf, int size){
	int scelta=rand()%3;
	if (scelta==0){;
		time_sort<int>(rf,size);
		return;}
	
	if (scelta==1){;
		time_sort<double>(rf,size);
		return;}
	else{
		 time_sort<float>(rf,size);
		return;}
}
int main(){
	srand(time(NULL)); 
	randfiller filler;
	std::cout<< "Test tempo:"<<"\n";
	
	for (int i=2; i<14; i++){
		scelta_tipo(filler, pow(2,i));
			
            
		
	}
	
	return 0;
}