#pragma once
#include <iostream>
#include <iterator>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;

  MutantStack() {};
  ~MutantStack() {};
  MutantStack(const MutantStack &cpy) : std::stack<T>(cpy) {};
  MutantStack &operator=(const MutantStack &cpy) {
    if (this == &cpy)
      return *this;
    const_iterator beg = this->begin();
    while (beg != this->end()) {
      this->pop();
    }
    const_iterator beg2 = cpy.begin();
    while (beg2 != cpy.end()) {
      this->push(*beg2);
      beg2++;
    }
    return *this;
  };
  iterator begin() { return (this->c.begin()); }
  iterator end() { return (this->c.end()); }
  const_iterator begin() const { return (this->c.begin()); }
  const_iterator end() const { return (this->c.end()); }
};