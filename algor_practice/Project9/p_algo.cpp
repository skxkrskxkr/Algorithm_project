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

void Bubble_sort(int *arr, int arr_size) {
	int temp;
	/*for (int a = 0; a < arr_size - 1; a++) {
		for (int b = 0; b < arr_size - 1 - a; b++) {
			if (arr[b] > arr[b + 1]) {
				temp = arr[b];
				arr[b] = arr[b + 1];
				arr[b + 1] = temp;
			}
		}
	}*/

	bool sorted = false;  //save time version
	while (!sorted) {
		sorted = true;
		for (int i = 1; i < arr_size; i++) {
			if (arr[i - 1] > arr[i]) {
				temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
				sorted = false;
			}
		}
	}
}

void insert_sort(int *arr, int arr_size) {
	int temp;
	for (int a = 1; a < arr_size; a++) {
		for (int b = a; b > 0; b--) {
			if (arr[b] < arr[b - 1]) {
				temp = arr[b];
				arr[b] = arr[b - 1];
				arr[b - 1] = temp;
			}
		}

		for (int c = 0; c <= a; c++) {
			std::cout << arr[c] << " ";
		}
		std::cout << std::endl;
	}
}

void shell_sort(int *arr, int arr_size) {
	int h = 1; int temp; int temp_index;

	do {
		h = 3 * h + 1;
	} while (h < arr_size);

	do {
		h = h / 3;

		for (int i = h; i < arr_size; i++) {
			temp = arr[i];
			temp_index = i;


			while (arr[temp_index - h] > temp) {
				arr[temp_index] = arr[temp_index - h];
				temp_index -= h;

				if (temp_index < h - 1) break;
			}
			arr[temp_index] = temp;
		}
		for (int i = 0; i < arr_size; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	} while (h > 1);

}
int main() {

	int arr[15] = { 30, 20, 40, 10, 5, 10, 30, 15 , 27, 35, 80, 22, 12, 5, 29};
	int arr_size = 15;

//	Selection_sort(arr, arr_size);
//	Bubble_sort(arr, arr_size);
//	insert_sort(arr, arr_size);
	shell_sort(arr, arr_size);
	for (int i = 0; i < arr_size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}