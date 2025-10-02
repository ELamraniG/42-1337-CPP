#include "Animal.hpp"
#include "Brain.hpp"
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

	const Animal* f = new Animal();
	const Animal* h = new Cat();
	delete f;	//should not create a leak
	delete h;
	std::cout << "----------" << std::endl;

	std::cout<<"--- DEEP COPY TEST ---"<<std::endl; 
	Dog *dogi = new Dog;
	dogi->makeSound();
	dogi->print_ideas();


	Brain *b = new Brain;
	b->set_ideas("lopo");
	dogi->set_brain(b);

	
	Dog *d2 = new Dog(*dogi);
	d2->print_ideas();

	std::cout << "----------" << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << "----- Deleting -----" << std::endl;

	for (int i = 0; i < number; i++)
	{
		std::cout<<"----------"<<std::endl;
		delete animals[i];
	}
	delete dogi;
	delete d2;
	std::cout << "----------" << std::endl;

	



	return (0);
}


