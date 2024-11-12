# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 16:29:57 by araveala          #+#    #+#              #
#    Updated: 2024/11/12 17:02:01 by araveala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++11

CPPFILES = run_phonebook.cpp
OFILES = $(CFILES:.cpp=.o)

EXEC = open_phonebook

all: $(EXEC)
	@echo "\033[1:32 Creating executable\033[0m"

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -g -c $, -o $@

$(EXEC): $(OFILES)
	$(CPP) $(CPP_FLAGS) $(CPPFILES) -o $(EXEC) $(OFILES)
	
clean:
	rm -rf $(OFILES)

fclean:
	rm -rf $(EXEC)
re: fclean all $(EXEC)

.PHONY: all clean fclean re 	