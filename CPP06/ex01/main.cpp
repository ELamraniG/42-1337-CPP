#include "Serializer.hpp"


int main()
{
	Data d;
	d.f = 101;
	d.i = -101;
	uintptr_t f = Serializer::serialize(&d);
	Data *p = Serializer::deserialize(f);
	if (p == &d)
		std::cout<<p->f<<"||||"<<p->i<<std::endl;
		
}