#include <optional>
#include <vector>
#include <algorithm>
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


//MERGESORT

template<typename T>
void merge(T A[], int p, int q, int r, T B[]) {
    int i = p;
    int j = q + 1;
    int k = p;
    while (i <= q && j <= r) {
        if (A[i] <= A[j]){
			B[k++] = A[i++];
		}
        else B[k++] = A[j++];
    }
    while (i <= q) {
		B[k++] = A[i++];
	}
    while (j <= r){
		B[k++] = A[j++];
	}	
    for (k = p; k <= r; k++){
		A[k] = B[k];
	}
}
template<typename T>
void mergesort_ricorsiva(T A[], int p, int r, T B[]) {
    if (p < r) {
        int q = p + (r - p) / 2;
        mergesort_ricorsiva(A, p, q, B);
        mergesort_ricorsiva(A, q + 1, r, B);
        merge(A, p, q, r, B);
    }
}

template<typename T>
void mergesort(std::vector<T>& vec) {
    if (vec.size() <= 1) return;
    std::vector<T> buffer(vec.size());
    mergesort_ricorsiva(vec.data(), 0, (int)vec.size() - 1, buffer.data());
}
		
		
//QUICKSORT

template<typename T>
int partition(T A[], int p, int r){
	T pivot=A[r];
	int i=p-1;
	
	for (int j=p; j<r; j++){
		if (A[j]<=pivot){
			i++;
			std::swap(A[i],A[j]);
		}
	}
	std::swap(A[i+1],A[r]);
	
	return i+1;
}
	
	
template<typename T>
void quicksort_ricorsiva(T A[], int p, int r) {
    if (p < r) {
		int pivot_index = p + (r - p)/2; 
        std::swap(A[pivot_index], A[r]);
        int q = partition(A, p, r);
        quicksort_ricorsiva(A, p, q - 1);
        quicksort_ricorsiva(A, q + 1, r);
    }
}

template<typename T>
void quicksort(std::vector<T>& vec) {
    if (vec.size() <= 1) return;
    quicksort_ricorsiva(vec.data(), 0, (int)vec.size() - 1);
}
//INSERTIONSORT(per quicksort otttimizzato)
template<typename T>
void insertion_sort_2(T A[], int p, int r) {
    for (int i = p + 1; i <= r; i++) {
        T key = A[i];
        int j = i - 1;
        while (j >= p && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
//QUICKSORT(OTTIMIZZATO)
template<typename T>
int partition2(T A[], int p, int r){
	T pivot=A[r];
	int i=p-1;
	
	for (int j=p; j<r; j++){
		if (A[j]<=pivot){
			i++;
			std::swap(A[i],A[j]);
		}
	}
	std::swap(A[i+1],A[r]);
	
	return i+1;
}
	
	
template<typename T>
void quicksort_ricorsiva_2(T A[], int p, int r) {
    if (p < r) {
		int pivot_index = p + (r - p)/2; 
        std::swap(A[pivot_index], A[r]);
		if (r-p+1<200){
			insertion_sort_2(A,p,r);
			return;
		}
        int q = partition(A, p, r);
        quicksort_ricorsiva_2(A, p, q - 1);
        quicksort_ricorsiva_2(A, q + 1, r);
    }
}

template<typename T>
void quicksort2(std::vector<T>& vec) {
    if (vec.size() <= 1) return;
    quicksort_ricorsiva_2(vec.data(), 0, (int)vec.size() - 1);
}

			 
		
//BUBBLESORT

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

//INSERTIONSORT
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


//SELECTIONSORT

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