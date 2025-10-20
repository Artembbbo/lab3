#include <iostream>
#include <algorithm>
#include <cstdlib>
bool is_correct(int);
int number_positive(int, int*);
void enter_elements(int, int*);
int last_zero(int, int*);
int sum_after_zero(int, int*);
int max_negative(int, int*);
int amount_positive(int, int*);
int amount_negative(int, int*);
int amount_zero(int, int*);
void output_zero(int, int*);
int find_negative(int, int, int*);
int min_negative(int, int*);
int min_el_array(int, int*);
int output_positive(int, int*);
void array_sort(int, int*);
int output_negative(int, int*);
int main()
{
	const int max_size = 32767;
	int n = 0;
	int* arr = new int[max_size];
	std::cout << "enter the number of array elements\n";
	std::cin >> n;
	if (is_correct(n) == 0) {
		std::cout << "error,wrong number"; return 0;
	}
	enter_elements(n, arr);
	std::cout << "the number of positive elements" << " " << number_positive(n, arr) << std::endl;
	if (last_zero(n, arr) == -1) {
		std::cout << "no zero in array" << std::endl;
	}
	else {
		std::cout << "the sum of the array elements located after the last element that is equal to zero" << " " << sum_after_zero(n, arr) << std::endl;
	}
	array_sort(n, arr);
	output_positive(n, arr);
	output_zero(n, arr);
	output_negative(n, arr);
	delete[] arr;
}
void enter_elements(int n, int* arr) {
	for (int i = 0; i < n; i++) {
		arr[i] =-10000 + rand() % (10000 - -10000) ;
		std::cout << arr[i] << " ";
	}
}
bool is_correct(int n) {
	if (n <= 0 || n > 32767) {
		return 0;
	}
	else return 1;
}
int number_positive(int n, int* arr) {
	int cntr = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			cntr++;
		}
	}
	return cntr;
}
int last_zero(int n, int* arr) {
	int cntr = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] == 0) {
			cntr = i; return cntr;
		}
	}
	return -1;
}
int sum_after_zero(int n, int* arr) {
	int sum = 0;
	for (int i = last_zero(n, arr); i < n; i++) {
		sum += arr[i];
	}
	return sum;
}
int max_negative(int n, int* arr) {
	int max_neg = -100000000000;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0 && arr[i] > max_neg) {
			max_neg = arr[i];
		}
	}
	return max_neg;
}
int amount_positive(int n, int* arr) {
	int am_pos = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			am_pos++;
		}
	}
	return am_pos;
}
int amount_negative(int n, int* arr) {
	int am_neg = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			am_neg++;
		}
	}
	return am_neg;
}
int amount_zero(int n, int* arr) {
	int am_zero = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			am_zero++;
		}
	}
	return am_zero;
}
void output_zero(int n, int* arr) {
	int i = amount_zero(n, arr);
	int j = 0;
	while (j < i) {
		std::cout << 0 << " ";
		j++;
	}
}
int find_negative(int i, int n, int* arr) {
	int cntr = min_el_array(n, arr);
	for (int j = 0; j < n; j++) {
		if (arr[j] < i && arr[j] > cntr) {
			cntr = arr[j];
		}
	}
	return cntr;
}
int min_negative(int n, int* arr) {
	int cntr = max_negative(n, arr);
	for (int i = 0; i < n; i++) {
		if (arr[i] < cntr) { cntr = arr[i]; }
	}
	return cntr;
}
int min_el_array(int n, int* arr) {
	int cntr = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < cntr) {
			cntr = arr[i];
		}
	}
	return cntr;
}
void array_sort(int n, int* arr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}
int output_positive(int n, int* arr) {
	if (amount_positive(n, arr) == 0) {
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] > 0) {
			std::cout << arr[i] << " ";
		}
	}
}
int output_negative(int n, int* arr) {
	if (amount_negative(n, arr) == 0) {
		return 0;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] < 0) {
			std::cout << arr[i] << " ";
		}
	}
}