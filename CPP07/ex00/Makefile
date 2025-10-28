NAME = ex00
SRC = main.cpp
OBJ = $(SRC:%.cpp=%.o)
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp whatever.hpp
	$(CPP) -c $(CPPFLAGS) $< -o $@

clean : 
	rm -rf $(OBJ)


fclean : clean
	rm -rf $(NAME)

re : fclean all