NAME = RPN
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp RPN.cpp
OBJ = $(SRC:.cpp=.o)
all: $(NAME)
$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)
%.o: %.cpp RPN.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

