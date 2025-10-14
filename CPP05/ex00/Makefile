SRC = 
NAME = 
OBJ = 
CC = C++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp //add later
	$(CC) $(CPPFLAGS) -c $< -o $@
clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all 