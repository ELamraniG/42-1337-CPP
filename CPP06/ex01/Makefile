NAME = ex01
SRC = main.cpp Serializer.cpp 
OBJ = $(SRC:%.cpp=%.o)
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)
$(NAME) : $(OBJ)
	echo $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp Serializer.hpp
	$(CPP) -c $(CPPFLAGS) $< -o $@
clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all