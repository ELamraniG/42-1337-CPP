FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = account
CPP = c++
SRC = Account.cpp tests.cpp
OBJ = $(SRC:%.cpp=%.o)

ALL : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp Account.hpp
	$(CPP) $(FLAGS) -c $< -o $@
clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean ALL