CX := c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g $(SAN)
LDFLAGS = -g $(SAN)
SHELL := /bin/bash

SRC := Bureaucrat.cpp AForm.cpp main.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp  Intern.cpp
OBJ := $(SRC:.cpp=.o)
INC := $(SRC:.cpp=.hpp)

SRC := $(addprefix src/, $(SRC))
OBJ := $(addprefix obj/, $(OBJ))
INC := $(addprefix include/, $(INC))
INC := $(filter-out include/main.hpp, $(INC))


NAME := exec

all : mkdir_obj $(NAME)

mkdir_obj :
	@mkdir -p obj

$(NAME) : $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LDFLAGS)


obj/%.o : src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	@rm -rf obj

fclean : clean
	@rm -f $(NAME)

re : fclean all

test: all
	@./$(NAME)

def_san : 
	$(eval SAN := -fsanitize=address)


san : def_san re

.PHONY : all clean fclean re mkdir_obj san def_san
