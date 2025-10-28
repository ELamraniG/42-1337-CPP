#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>


 Base::~Base()
{

}
Base *Base::generate(void)
{
	Base *b;

	int n = rand() % 3;
	if (n == 0)
	{
		b = new A();
		std::cout<<"generated type A"<<std::endl;
	}
	else if (n == 1)
	{

		std::cout<<"generated type B"<<std::endl;
		b = new B();
	}
	else
	{

		std::cout<<"generated type C"<<std::endl;
		b = new C();
	}
	return b;
}

void Base::identify(Base* p)
{
	std::cout<<"identify with pointer"<<std::endl;
	if (p == NULL)
		return;
	if (dynamic_cast<A*>(p))
		std::cout<<"type is A"<<std::endl;
	if (dynamic_cast<B*>(p))
		std::cout<<"type is B"<<std::endl;
	if (dynamic_cast<C*>(p))
		std::cout<<"type is C"<<std::endl;
}
void Base::identify(Base& p)
{
	std::cout<<"identify with ref"<<std::endl;
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout<<"type is A"<<std::endl;
	}
	catch (const std::exception&)
	{

	
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout<<"type is B"<<std::endl;
	}
	catch (const std::exception&)
	{
		
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout<<"type is C"<<std::endl;
	}
	catch (const std::exception&)
	{
		
	}
}