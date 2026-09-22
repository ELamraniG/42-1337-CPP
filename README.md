# 42 / 1337 C++ Modules

My solutions for the C++ modules from 42 / 1337.

The repository contains CPP00 to CPP09. I used these projects to learn C++98 step by step, starting from basic classes and ending with templates, STL containers and more algorithmic exercises.

## Modules

| Module | Main topics                                                           |
| ------ | --------------------------------------------------------------------- |
| CPP00  | C++ basics, namespaces, classes, member functions and streams         |
| CPP01  | Memory, references, pointers, file streams and basic class usage      |
| CPP02  | Orthodox Canonical Form, fixed-point numbers and operator overloading |
| CPP03  | Inheritance and class hierarchies                                     |
| CPP04  | Polymorphism, abstract classes, interfaces and deep copies            |
| CPP05  | Exceptions and more advanced class design                             |
| CPP06  | Type conversions and C++ casts                                        |
| CPP07  | Function and class templates                                          |
| CPP08  | STL containers, iterators and algorithms                              |
| CPP09  | STL-based problems: Bitcoin Exchange, RPN and PmergeMe                |

## Build

Most exercises have their own `Makefile`.

Example:

```bash
cd CPP06/ex00
make
```

Then run the executable created by that exercise.

To clean generated object files:

```bash
make clean
```

or:

```bash
make fclean
```

## Notes

These are learning projects, so the code reflects my progress through the C++ modules rather than one single finished application.

The projects were written for the 42 / 1337 C++ curriculum and mainly follow the C++98 standard.
