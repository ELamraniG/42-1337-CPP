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

	// Implement a Brain class. It contains an array of number
		// / 20 std::string called ideas.
	// This way, Dog and Cat will have a /private Brain* attribute.
	// Upon construction, Dog and Cat will create their Brain using new Brain();
	// Upon destruction, Dog and Cat will delete their Brain.
	// In your main function,
		// create and fill an array of Animal objects. Half of it will
	// be Dog objects and the other half will be Cat objects. At the end of your program
	// execution,
		// loop over this array and delete every Animal. You must delete directly dogs
	// and cats as Animals. The appropriate destructors must be called in the expected order.
	// Don’t forget to check for memory leaks.
	// A copy of a Dog or a Cat mustn’t be shallow. Thus,
		// you have to test that your copies
	// are deep copies!
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


