#include <iostream>
#include <Windows.h>
#include <thread>

void OperationOne() {
	std::cout << "OperationOne\n";
}

void OperationTwo() {
	std::cout << "OperationTwo\n";
}

void OperationThree() {
	std::cout << "OperationThree\n";
}

void main() {
	std::thread first(OperationOne);
	std::thread second(OperationTwo);
	std::thread third(OperationThree);
	while (!GetAsyncKeyState(VK_END))
	{	
		first.join();
		second.join();               
		third.join();
	}
}
