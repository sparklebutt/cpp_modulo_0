# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 17:04:04 by araveala          #+#    #+#              #
#    Updated: 2024/11/28 11:29:49 by araveala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++11 -Wno-deprecated-declarations
BUILDDIR = build/

CPPFILES = Account.cpp tests.cpp
OFILES = $(addprefix $(BUILDDIR), $(CPPFILES:.cpp=.o))
EXEC = accounts

all: $(BUILDDIR) $(EXEC)
	@echo "\033[0;95m Creating executable\033[0m"

$(BUILDDIR)%.o: %.cpp
	$(CPP) $(CPPFLAGS) -g -c $< -o $@

$(EXEC): $(OFILES)
	$(CPP) $(CPPFLAGS) $(OFILES) -o $(EXEC) 

$(BUILDDIR):
	@echo "\033[0;91m Building folder\033[0m"
	mkdir -p $(BUILDDIR)
	
clean:
	@echo "\033[0;93m Cleaning ofiles\033[0m"
	rm -rf $(BUILDDIR)
	rm -rf $(OFILES)

fclean: clean
	@echo "\033[0;91m Cleaning all\033[0m"
	rm -f $(EXEC)

re: fclean all $(EXEC)

.PHONY: all clean fclean re