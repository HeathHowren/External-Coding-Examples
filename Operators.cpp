#include <iostream>

int main()
{
	// * is a pointer operator aka a dereference operator
	// & is a reference operator aka address of operator
	int x;
	int *ptr; //this is how to initialize a pointer

	x = 5;
	ptr = &x; //setting ptr to be reference of x

	std::cout << "Reading ptr value: " << ptr << std::endl;
	std::cout << "Value of pointer: " << *ptr << std::endl; 
	std::cout << "Address of pointer: " << "0x" << &ptr << std::endl;

	system("pause");
	return 0;
}