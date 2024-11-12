/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_phonebook.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:32:21 by araveala          #+#    #+#             */
/*   Updated: 2024/11/12 17:20:03 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // put it in header file
#include <string>
#include <cstdlib>

void	clear_output()
{
	std::system("clear");
}

void	print_options()
{
	std::cout<<"Welcome to the phonebook menu, your options are as follows:\n";
	std::cout<<"ADD to add contact information to phonebook\n";
	std::cout<<"SEARCH to search through the phonebook for a contact using index number (max 9)\n";
	std::cout<<"EXIT to exit the phonebook and loose all data\n";
	std::cout<<"What would you like to do: ";
}

int	main()
{
	int fun = 0;
	std:: string option;
	while (1)
	{		
		print_options();
		std:: getline(std::cin, option);
		clear_output();
		if (option == "ADD")
		{
			printf("testing ADD\n");
			// we go to function that adds contact details
		}
		else if (option == "SEARCH")
		{
			printf("testing SEARCH");
			// we search through the phone book func
		}
		else if (option == "EXIT")
		{
			std::cout<<"All data has been wiped"<<std::endl;
			return 0; // so we can quit ? maybe free??
		}
		else // error handling function 
		{
			fun++;
			if (fun > 3)
			{ //lol factor maybe no smart
				std::cout<<"INPUT ERROR: pay better attention to the options menu!!"<<std::endl;
				fun = 0;
			}
			else
				std::cout<<"Input error: please read your options again"<<std::endl;
		}		
	}
	return 0;
}