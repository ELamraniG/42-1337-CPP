#include "RPN.hpp"
#include <cctype>
#include <cstring>

RPN::RPN() {}
RPN::RPN(std::string arg) : arg(arg) {}
RPN::~RPN() {}
RPN::RPN(const RPN &cpy) {
  arg = cpy.get_arg();
  numbers_stack = cpy.get_numbers_stack();
}
RPN &RPN::operator=(const RPN &cpy) {
  arg = cpy.get_arg();
  numbers_stack = cpy.get_numbers_stack();
  return *this;
}

const std::string RPN::get_arg() const { return (arg); }
const std::stack<int> RPN::get_numbers_stack() const { return (numbers_stack); }

bool RPN::is_operator(char c) {
  std::string s = "+-*/";

  if (s.find(c) == std::string::npos)
    return false;
  return true;
}

int RPN::calculate(int n1, int n2, char c) {
  if (c == '+')
    return n1 + n2;
  else if (c == '-')
    return n1 - n2;
  else if (c == '/')
    return n1 / n2;
  else if (c == '*')
    return n1 * n2;
  return 0;
}

bool RPN::parsing_and_calculation() {
  for (unsigned int i = 0; i < arg.length(); i++) {
    if (std::isspace(arg[i]))
      continue;
    else if (std::isdigit(arg[i])) {
      if (i + 1 == arg.length()) {
        if (numbers_stack.empty()) {
          numbers_stack.push(arg[i] - '0');
          break;
        }
        return false;
      } else if (std::isspace(arg[i + 1]) == false)
        return false;
      numbers_stack.push(static_cast<int>(arg[i]) - '0');
    } else if (is_operator(arg[i])) {
      if (std::isspace(arg[i + 1]) == false && i + 1 != arg.length())
        return false;
      int n1;
      int n2;
      if (numbers_stack.empty())
        return false;
      n1 = numbers_stack.top();
      numbers_stack.pop();
      if (numbers_stack.empty())
        return false;
      n2 = numbers_stack.top();
      numbers_stack.pop();
      if (arg[i] == '/' && n1 == 0)
        return false;
      int res = calculate(n2, n1, arg[i]);
      numbers_stack.push(res);
    } else
      return false;
  }
  if (numbers_stack.empty())
    return false;
  int final_res = numbers_stack.top();
  numbers_stack.pop();
  if (numbers_stack.empty() == false)
    return false;
  std::cout << final_res << std::endl;
  return true;
}

void RPN::performRPN(void) {
  if (parsing_and_calculation() == false)
    std::cerr << "Error" << std::endl;
}
