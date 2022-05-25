#pragma once

#include <iostream>
#include "../src/ComputerScienceh.h"
#include <random>

unsigned nChooseK(unsigned n, unsigned k) {
	if (k > n) return 0;
	if (k * 2 > n) k = n - k;
	if (k == 0) return 1;

	int result = n;
	for (int i = 2; i <= k; ++i) {
		result *= (n - i + 1);
		result /= i;
	}

	return result;
}

double pmf(int k, int K, int n, int N) {
	/* From https://en.wikipedia.org/wiki/Hypergeometric_distribution
	* k is the number of observed successess (the amount of desired cards to draw)
	* K is the number of success states in the population (K desired cards in deck)
	* n is the number of draws
	* N is population size (size of deck)
	*/

	double top, bottom;
	top = nChooseK(K, k) * nChooseK(N - K, n - k);
	bottom = nChooseK(N, n);

	double n1, n2, n3;
	n1 = nChooseK(K, k);
	n2 = nChooseK(N - K, n - k);
	n3 = nChooseK(N, n);

	std::cout << n1 << " " << n2 << " " << n3 << "\n";

	return nChooseK(K, k) * nChooseK(N - K, n - k) / nChooseK(N, n);
}

int rollX(int sides) {
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.
	return gen() % sides + 1;
}

int rollKeepHighessst(int sides, int times = 1) {
	int highest = 0;
	srand(time(0));

	for (int i = 0; i < times; i++) {
		int r = rollX(sides);
		if (r == sides) return sides;
		else if (r > highest) {
			highest = r;
		}
	}

	return highest;
}


int delinaPixie() {
	int low = 15;
	int pixies = 1;

	while (rollKeepHighessst(20, pixies + 1) >= low) {
		pixies++;
		if (pixies > 100) return 100;
	}

	return pixies - 1;
}