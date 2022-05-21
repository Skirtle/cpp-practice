#include <iostream>
#include "../src/ComputerScienceh.h"
#include <bitset>
#include <cassert>

int main() {
	std::bitset<32> bs = 0b11000000110100000000010000000000;
	std::cout << IEEE754_to_decimal(bs) << "\n";;
}