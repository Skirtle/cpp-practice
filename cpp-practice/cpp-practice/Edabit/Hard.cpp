// Includes
#include <iostream>
#include <vector>

// Prototypes
int roots(int a, int b, int c);
double discount(int base, int discount);
std::vector<int> evenOddTransform(std::vector<int> arr, int n);

// Main
int main() {
}

int roots(int a, int b, int c) { return (-b + (sqrt(b*b - 4*a*c))) / (2 * a); }
double discount(int base, int discount) { return (base * (100 - discount) * 0.01l); }
std::vector<int> evenOddTransform(std::vector<int> arr, int n) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % 2 == 0) arr[i] -= n * 2;
		else arr[i] += n * 2;
	}
}