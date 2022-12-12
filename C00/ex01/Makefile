CXX := c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinclude -g $(SAN)
LDFLAGS = -g $(SAN)
SHELL := /bin/bash

SRC := main.cpp Contact.cpp PhoneBook.cpp
OBJ := $(SRC:.cpp=.o)

SRC := $(addprefix src/, $(SRC))
OBJ := $(addprefix obj/, $(OBJ))


NAME := phonebook

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
