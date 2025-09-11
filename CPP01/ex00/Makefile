NAME = BraiiiiiiinnnzzzZ
SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJ = $(SRC:%.cpp=%.o)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

ALL : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
%.o : %.c Zombie.hpp
	$(CC) $(FLAGS) $< -o $@

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean ALL