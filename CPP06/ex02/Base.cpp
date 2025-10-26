#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>

Base *Base::generate(void)
{
	Base *b;
	srand(time(NULL));
	int n = rand() % 3;
	if (n == 0)
		b = new A();
	if (n == 1)
		b = new B();
	if (n == 2)
		b = new C();
	return b;
}