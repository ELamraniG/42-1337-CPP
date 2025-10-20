SRC = Bureaucrat.cpp main.cpp
NAME = ex00
OBJ = $(SRC:%.cpp=%.o)
CPP = c++ 
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)
$(NAME) : $(OBJ)	
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp Bureaucrat.hpp
	$(CPP) -c $(CPPFLAGS)  $< -o $@
clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all 