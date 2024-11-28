# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 16:29:57 by araveala          #+#    #+#              #
#    Updated: 2024/11/28 11:00:41 by araveala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++11
BUILDDIR = build/

CPPFILES = run_phonebook.cpp Contacts.cpp PhoneBook.cpp main.cpp
OFILES = $(addprefix $(BUILDDIR), $(CPPFILES:.cpp=.o))
EXEC = open_phonebook

all:  $(BUILDDIR) $(EXEC)
	@echo "\033[0;95m Creating executable\033[0m "

$(BUILDDIR)%.o: %.cpp 
	$(CPP) $(CPP_FLAGS) -g -c $< -o $@

$(EXEC): $(OFILES)
	$(CPP) $(CPP_FLAGS) $(OFILES)  -o $(EXEC)

$(BUILDDIR):
	@echo "\033[0;91m Building folder\033[0m"
	mkdir -p $(BUILDDIR)

clean:
	@echo "\033[0;93m Cleaning ofiles\033[0m"
	rm -rf $(BUILDDIR)
	rm -rf $(OFILES)

fclean: clean
	@echo "\033[0;91m Cleaning all\033[0m"
	rm -rf $(EXEC)

re: fclean all $(EXEC)

.PHONY: all clean fclean re 	