#include "Character.hpp"
#include "MateriaSource.hpp"

// void	lopo(void)
// {
// 	system("leaks final");
// }
int	main(void)
{
	// atexit(lopo);
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Fire());
	src->learnMateria(new Zeus());
	src->learnMateria(new Sun());

	IMateriaSource *src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Sun());
	src2->learnMateria(new Fire());
	src2->learnMateria(new Zeus());

	std::cout<<"-------------"<<::std::endl;

	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	tmp = src->createMateria("zeus");
	me->equip(tmp);
	tmp = src->createMateria("sun");
	me->equip(tmp);
	std::cout<<"-------------"<<::std::endl;
	ICharacter *bob = new Character("bob");
	std::cout<<"---------- TEST 1 ---------"<<std::endl;
	std::cout << "----------------  Ability N1 using ICE -------------------------" << std::endl;
	me->use(0, *bob);
	std::cout << "----------------    Ability N2 using CURE-------------------------" << std::endl;
	me->use(1, *bob);
	std::cout << "----------------   Ability N3 using FIRE -------------------------" << std::endl;
	me->use(2, *bob);
	std::cout << "----------------   Ability N4 using Zeus -------------------------" << std::endl;
	me->use(3, *bob);
	std::cout << "----------------   Ability N5 using Sun -------------------------" << std::endl;
	me->use(4, *bob);
	std::cout << "----------------finished-------------------------\n\n\n\n\n" << std::endl;


	std::cout<<"---------- TEST 2 ---------"<<std::endl;
	std::cout << "----------------  Ability N1 using ICE -------------------------" << std::endl;
	me->use(0, *bob);
	std::cout << "----------------    Ability N2 using CURE-------------------------" << std::endl;
	me->use(1, *bob);
	std::cout << "----------------   Ability N3 using FIRE -------------------------" << std::endl;
	me->use(2, *bob);
	std::cout << "----------------   Ability N4 using Zeus -------------------------" << std::endl;
	me->use(3, *bob);
	me->unequip(2);
	tmp = src2->createMateria("sun");
	me->equip(tmp);
	std::cout << "----------------   Ability N5 using Sun -------------------------" << std::endl;
	me->use(2, *bob);
	std::cout << "----------------finished-------------------------\n\n\n" << std::endl;


	delete bob;
	delete me;
	delete src;
	delete src2;
}