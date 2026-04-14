#include <optional>
template<typename T>



bool is_sorted(const std::vector<T>& vec){
	if (vec.size() <= 1) {
	return true;
	}


	for (size_t i = 1; i < vec.size(); i++) {
		if (vec[i]<vec[i-1]){
			return false;
		}
	
	}
	return true;
}
			 
		
//Bubble-sort
template<typename T>
void bubble_sort(std::vector<T>& vec) {
	int n=vec.size();
	for (int i=0; i<n-1; i++){
		for (int j=0; j<n-i-1; j++){
			if (vec[j]>vec[j+1]){
				std::swap(vec[j],vec[j+1]);
			}
		}
	}
}

//Insertion-sort
template<typename T>
void insertion_sort(std::vector<T>& vec) {
	int n=vec.size();
	for (int i=1;i<n; i++) {
		T key=vec[i];
		int j=i-1;
		
		while (j>=0 && vec[j]>key){
			vec[j+1]=vec[j];
			j=j-1;
		}
		vec[j+1]=key;
	}
}

//Selection-sort
template<typename T>
void selection_sort(std::vector<T>& vec) {
	int n=vec.size();
	for (int i=0; i<n-1; i++){
		int min_index=i;
		for (int j=i+1;j<n;j++){
			if (vec[j]<vec[min_index]){
				min_index=j;
			}
		}
		if (min_index!=i){
			std::swap(vec[min_index], vec[i]);
		}
	}
}
		
			
		