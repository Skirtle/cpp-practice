#include <iostream>
#include "../src/ComputerScienceh.h"

int main() {
	Queue<int> queue = Queue<int>(10);

	for (int i = 0; i < 10; i++) {
		queue.enqueue(i + 1);
	}
	queue.print();
	std::cout << queue.isFull() << "\n";

	for (int i = 0; i < 10; i++) {
		std::cout << queue.dequeue() << " ";
	}

	std::cout << "\n";
	std::cout << queue.isEmpty() << "\n";
	queue.print();

	std::cout << queue.maxSize << "\n";
}