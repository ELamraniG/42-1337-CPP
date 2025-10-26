#include "Serializer.hpp"
#include <cstdint>
#include <memory>


int main()
{
	Data d;
	d.f = 101;
	d.i = -101;
	Data *e = &d;
	std::uintptr_t f = Serializer::serialize(e);
	Data *p = Serializer::deserialize(f);
	std::cout<<p->f<<"||||"<<p->i<<std::endl;
}