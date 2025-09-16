CC = c++
CPPFLAGS = -c -Wall -Werror -Wextra -std=c++98
SRC = Fixed.cpp main.cpp 
OBJ = $(SRC:%.cpp=%.o)
NAME = a.out

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
%.o : %.cpp Fixed.hpp
	$(CC) $(CPPFLAGS) $< -o $@

clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)

re : fclean all