#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	srand(time(NULL));
	Base f;
	std::cout<<"-------------"<<std::endl;
	Base *r = f.generate();
	std::cout<<"-------------"<<std::endl;
	Base *g = f.generate();
	std::cout<<"-------------"<<std::endl;
	Base *b = f.generate();
	std::cout<<"-------------"<<std::endl;

	f.identify(r);
	f.identify(*r);
	std::cout<<"-------------"<<std::endl;

	f.identify(g);
	f.identify(*g);
	std::cout<<"-------------"<<std::endl;

	f.identify(b);
	f.identify(*b);
	std::cout<<"-------------"<<std::endl;
// delete r;
// delete g;
// delete b;
}