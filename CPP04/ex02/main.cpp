#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// #include <cstdlib>
// void lopo()
// {
// 	system("leaks zoo");
// }

int	main(void)
{
	// atexit(lopo);
	int number = 4;
	Animal *animals[number];
	for (int i = 0; i < number; i++)
	{
		std::cout << "----------" << std::endl;
		if (i >= number / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << "----------" << std::endl;
	std::cout<<"ex main test"<<std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;	//should not create a leak
	delete i;

	// const Animal* f = new Animal();// doenst work anymore hitach abstract now
	const Animal* h = new Cat();
	delete h;
	std::cout << "----------" << std::endl;



	std::cout << "----------" << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << "----------" << std::endl;

	for (int i = 0; i < number; i++)
	{
		std::cout<<"----------"<<std::endl;
		delete animals[i];
	}
	std::cout << "----------" << std::endl;

	
	return (0);
}


