#include <iostream>
#define Log(msg) std::cout << msg << std::endl

int pointers(void) {
	// pointer - it's a number that holds/stores a memory address

	void* ptr = NULL; // #define NULL 0

	// 0 or NULL or nullptr (keyword) all means that the ptr is invalid

	int var = 10;
	int* varPtr = &var;
	// type of pointers do not matter, just helpful in reading/writing memory.

	*varPtr = 20;
	// if the pointer was of void type then you can't write
	// to it as it won't know how many bytes to write into memory

	std::cout << "Pointer Dereferencing: " << std::endl;
	Log(*varPtr); // dereferencing of pointer

	// below are stored in Heap memory
	char* buffer = new char[10];
	memset(buffer, 69, 10); // 69 -> default value

	// pointer to a pointer
	char** dptr = &buffer;

	std::cout << "Double Dereferencing: " << **dptr << std::endl;

	delete[] buffer;

	// references
	int data = 5;
	int& ref = data;

	ref = 10;
	std::cout << "data: " << std::endl;
	Log(data);

	int data2 = 100;
	ref = data2; // you can't set the reference to data2, it'll instead set data = 100

	return 0;
}