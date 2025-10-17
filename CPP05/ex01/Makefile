SRC = Bureaucrat.cpp main.cpp Form.cpp
NAME = ex01
OBJ = $(SRC:%.cpp=%.o)
CC = c++ 
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)
$(NAME) : $(OBJ)	
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp Bureaucrat.hpp Form.hpp
	$(CC) -c $(CPPFLAGS)  $< -o $@
clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all 