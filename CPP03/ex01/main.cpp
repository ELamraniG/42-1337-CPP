// Test suite for ClapTrap edge cases
#include "ClapTrap.hpp"
#include <iostream>

int main() {
	std::cout << "==== EASY TESTS ====" << std::endl;
	// Easy 1: Default construction
	ClapTrap ct1;
	// Easy 2: Attack with default stats
	ct1.attack("Target1");
	// Easy 3: Take small damage
	ct1.takeDamage(2);

	std::cout << "\n==== MEDIUM TESTS ====" << std::endl;
	// Medium 1: Repair after damage
	ct1.beRepaired(5);
	// Medium 2: Take damage to zero
	ct1.takeDamage(100);
	// Medium 3: Copy construction
	ClapTrap ct2(ct1);
	// Medium 4: Assignment operator
	ClapTrap ct3;
	ct3 = ct1;


	std::cout << "\n==== EXTREME TESTS ====" << std::endl;
	// Extreme 1: Negative damage (should be rejected)
	ct1.takeDamage(-1);
	// Extreme 2: Repair with huge value (overflow)
	ct1.beRepaired(4294967295U);
	// Extreme 3: Take damage more than max hit points
	ct1.takeDamage(4294967295U);
	// Extreme 4: Attack after zero hit points
	ct1.attack("Target2");

	std::cout << "\n==== ADDITIONAL EXTREME TESTS ====" << std::endl;
	
	
	// Extreme 6: Chain assignment test
	std::cout << "\n--- Test 6: Chain assignment ---" << std::endl;
	ClapTrap ct5, ct6, ct7;
	ct5 = ct6 = ct7;
	
	// Extreme 7: Zero repair test
	std::cout << "\n--- Test 7: Zero repair ---" << std::endl;
	ClapTrap ct8;
	ct8.beRepaired(0);
	
	// Extreme 8: Zero damage test
	std::cout << "\n--- Test 8: Zero damage ---" << std::endl;
	ct8.takeDamage(0);
	
	// Extreme 9: Multiple consecutive attacks
	std::cout << "\n--- Test 9: Multiple consecutive attacks ---" << std::endl;
	ClapTrap ct9;
	for (int i = 0; i < 15; i++) {
		ct9.attack("Enemy" + std::to_string(i));
	}
	
	// Extreme 10: Copy of damaged ClapTrap
	std::cout << "\n--- Test 10: Copy of damaged ClapTrap ---" << std::endl;
	ClapTrap ct10;
	ct10.takeDamage(8);
	ClapTrap ct11(ct10);
	ct11.attack("LastTarget");
	
	// Extreme 11: Repair when already at max
	std::cout << "\n--- Test 11: Repair at maximum HP ---" << std::endl;
	ClapTrap ct12;
	ct12.beRepaired(1000);
	ct12.beRepaired(500);
	
	// Extreme 12: Attack with empty string target
	std::cout << "\n--- Test 12: Attack empty target ---" << std::endl;
	ClapTrap ct13;
	ct13.attack("");
	
	// Extreme 13: Massive damage then repair
	std::cout << "\n--- Test 13: Massive damage then repair ---" << std::endl;
	ClapTrap ct14;
	ct14.takeDamage(999999999);
	ct14.beRepaired(5);
	ct14.attack("TestTarget");
	
	// Extreme 14: Copy constructor with modified original
	std::cout << "\n--- Test 14: Copy then modify original ---" << std::endl;
	ClapTrap ct15;
	ClapTrap ct16(ct15);
	ct15.takeDamage(5);
	ct16.attack("IndependentTarget");

	return 0;
}