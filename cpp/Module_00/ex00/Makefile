# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 12:10:16 by araveala          #+#    #+#              #
#    Updated: 2024/11/12 16:52:43 by araveala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++11

CPPFILES = megaphone.cpp

OFILES = $(CFILES:.cpp=.o)

EXEC = megaphone

all: $(EXEC)
	@echo "\033[1:32 Creating executable\033[0m"

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -g -c $, -o $@

$(EXEC): $(OFILES)
	$(CPP) $(CPPFLAGS) $(CPPFILES) -o $(EXEC) $(OFILES)


clean:
	rm -rf $(OFILES)

fclean:
	rm -f $(EXEC)

re: fclean all $(EXEC)

.PHONY: all clean fclean re
