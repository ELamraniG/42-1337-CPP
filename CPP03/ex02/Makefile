SRC= main.cpp ClapTrap.cpp ScavTrap.cpp
OBJ=$(SRC:%.cpp=%.o)
NAME = andopen
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
CC = c++


all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
%.o : %.cpp ClapTrap.hpp
	$(CC) -c $(CPPFLAGS) $< -o $@
clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all