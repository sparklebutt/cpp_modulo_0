/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:17:19 by araveala          #+#    #+#             */
/*   Updated: 2024/11/21 17:47:32 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include "Contacts.hpp"
#include "PhoneBook.hpp"

void	clear_output()
{
	std::system("clear");
}

void	print_options()
{
	std::cout<<"Welcome to the phonebook menu, your options are as follows:\n";
	std::cout<<"ADD to add contact information to phonebook\n";
	std::cout<<"SEARCH to search through the phonebook for a contact using index number (max 8)\n";
	std::cout<<"EXIT to exit the phonebook and loose all data\n";
	std::cout<<"What would you like to do: \n";
}

int	main()
{
	int fun = 0;
	std:: string option;
	std:: string input;
	PhoneBook phonebook;

	while (1)
	{		
		print_options();
		std:: getline(std::cin, option);
		clear_output();
		if (option == "ADD")
			addcontact(phonebook);
		else if (option == "SEARCH")
			searchContact(phonebook);
		else if (option == "EXIT")
			return 0;

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