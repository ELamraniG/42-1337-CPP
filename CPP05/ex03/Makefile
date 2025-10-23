SRC = Bureaucrat.cpp main.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp
NAME = ex03
OBJ = $(SRC:%.cpp=%.o)
CPP = c++ 
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 

all : $(NAME)
$(NAME) : $(OBJ)	
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
%.o : %.cpp Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp Intern.hpp
	$(CPP) -c $(CPPFLAGS)  $< -o $@
clean : 
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all 