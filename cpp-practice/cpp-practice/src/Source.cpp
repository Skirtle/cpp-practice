#include <iostream>
#include "../src/ComputerScienceh.h"
#include <bitset>
#include <cassert>
#include <string>

void floatToBinary(float f, std::string& str);

int main() {
	std::bitset<32> bs = 0b11000000110100000000000000000000;
	// std::cout << IEEE754_single_to_decimal(bs) << "\n";

    std::string str;
    float f = 0.1;
    floatToBinary(f, str);

    std::cout << str << "\n";
    std::cout << decimal_to_IEEE754_single(f) << "\n";

    std::cout << "Put in " << f << ", got " << IEEE754_single_to_decimal(decimal_to_IEEE754_single(f)) << "\n";


	/*for (float i = -1.5; i <= 1.5; i += 0.23) {
		// assert(i == IEEE754_single_to_decimal(decimal_to_IEEE754_single(i)));
		std::cout << i << " == " << IEEE754_single_to_decimal(decimal_to_IEEE754_single(i)) << "\n";
	}*/

}

void floatToBinary(float f, std::string& str)
{
    union { float f; uint32_t i; } u;
    u.f = f;
    str.clear();

    for (int i = 0; i < 32; i++)
    {
        if (u.i % 2)  str.push_back('1');
        else str.push_back('0');
        u.i >>= 1;
    }

    // Reverse the string since now it's backwards
    std::string temp(str.rbegin(), str.rend());
    str = temp;
}