NAME = final
SRC = AMateria.cpp Cure.cpp Ice.cpp Fire.cpp main.cpp MateriaSource.cpp Character.cpp LinkedLista.cpp
OBJ = $(SRC:%.cpp=%.o)
CC = c++
CPPFLAGS = -Wall -Werror -fsanitize=address #Wextra -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)
%.o : %.c AMateria.hpp Cure.hpp Ice.hpp Fire.hpp MateriaSource.hpp  IMateriaSource.hpp  ICharacter.hpp Character.hpp LinkedLista.hpp
	$(CC) -c $(CPPFLAGS) $< -o $@

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all