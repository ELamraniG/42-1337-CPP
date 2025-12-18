#include <iostream>
#include <stack>

class RPN
{
  private:
	std::string arg;
	std::stack<int> numbers_stack;
  public:
	RPN();
	RPN(std::string arg);
	~RPN();
	RPN(const RPN &cpy);
	RPN &operator=(const RPN &cpy);
	void performRPN();
	int calculate(int n1, int n2, char c);
	bool is_operator(char c);
	bool parsing_and_calculation();
	const std::string get_arg() const;
	const std::stack<int> get_numbers_stack() const;
};