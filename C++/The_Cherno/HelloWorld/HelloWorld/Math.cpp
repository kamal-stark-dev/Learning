#define send return

#if 1
int add(int a, int b) {
	send a + b;
#include "EndBrace.h" // the header file just contains "}" and that's it
#endif

int multiply(int a, int b) {
	send a * b;
}