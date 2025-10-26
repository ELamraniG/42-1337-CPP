NAME = ex01
SRC = main.cpp Serializer.cpp 
OBJ = $(SRC:%.cpp=%.o)
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

all : $(NAME)
$(NAME) : $(OBJ)
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) is here"
%.o : %.cpp Serializer.hpp
	@echo "doing $<"
	@$(CPP) -c $(CPPFLAGS) $< -o $@
clean : 
	@rm -rf $(OBJ)
	@echo "deleted $(OBJ)!"
fclean : clean
	@echo "deleting $(NAME) ..."
	@rm -rf $(NAME)
re : fclean all
	
	