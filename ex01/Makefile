FLAGS = -Wall -Wextra -Werror -std=c++98
CPP = c++
NAME = ex01
SRC = Contacts.cpp PhoneBook.cpp main.cpp
OBJ = $(SRC:%.cpp=%.o)
ALL : $(NAME)
$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp Contacts.hpp PhoneBook.hpp
	$(CPP) $(FLAGS) -c $< -o $@
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean ALL
