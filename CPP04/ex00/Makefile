SRC = Animal.cpp Cat.cpp Dog.cpp main.cpp  WrongCat.cpp WrongAnimal.cpp
NAME = zoo
OBJ = $(SRC:%.cpp=%.o)
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp Animal.hpp Cat.hpp Dog.hpp WrongCat.hpp WrongAnimal.hpp
	$(CC) -c $(CPPFLAGS) $< -o $@
clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all
