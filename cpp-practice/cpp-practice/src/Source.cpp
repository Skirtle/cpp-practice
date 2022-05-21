#include <iostream>
#include "../src/ComputerScienceh.h"
#include <bitset>
#include <cassert>

int main() {
	std::bitset<32> bs = 0b11000000110100000000000000000000;
	// std::cout << IEEE754_single_to_decimal(bs) << "\n";

	double fl = 85.125;
	std::bitset<32> binFl = decimal_to_IEEE754_single(fl);
	float newFl = IEEE754_single_to_decimal(binFl);
	std::cout << newFl << "\n";
	std::cout << binFl << "\n";

}