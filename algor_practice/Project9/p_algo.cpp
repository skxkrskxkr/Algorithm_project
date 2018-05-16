#include <iostream>


void Selection_sort(int *arr, int arr_size) {
	
	int min = INT_MAX; int min_index = 0; int temp;
	for (int a = 0; a < arr_size-1; a++) {
		min_index = a;
		for (int b = min_index + 1; b < arr_size; b++) {
			if (arr[min_index] > arr[b]) {
				min_index = b;
			}
			
		}
		if (min_index != a) {
			temp = arr[a];
			arr[a] = arr[min_index];
			arr[min_index] = temp;
		}
	}
}



int main() {

	int arr[8] = { 30, 20, 40, 10, 5, 10, 30, 15 };
	int arr_size = 8;

	Selection_sort(arr, arr_size);


	for (int i = 0; i < arr_size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}