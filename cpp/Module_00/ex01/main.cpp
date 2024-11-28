/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:17:19 by araveala          #+#    #+#             */
/*   Updated: 2024/11/27 15:59:24 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "PhoneBook.hpp"

#include <csignal>
#include <cstdlib>

void	checkStream()
{
	if (std::cin.eof())
		exit(0);
}

void	checkSignal(int sig)
{
	if (sig == SIGINT)
		std::cout<<"Cntrl c handled, closing phonebook"<<std::endl;
	else if (sig == SIGTERM)
		std::cout<<"Handled this too smarty pants, closing phonebook"<<std::endl;
	exit(0);
}

void	clear_output() {std::system("clear");}

void	print_options()
{
	std::cout<<"Welcome to the phonebook menu, your options are as follows:"<<std::endl;
	std::cout<<"ADD to add contact information to phonebook, can not be empty"<<std::endl;
	std::cout<<"SEARCH to search through the phonebook for a contact using index number (max 8)"<<std::endl;
	std::cout<<"EXIT to exit the phonebook and loose all data"<<std::endl;
	std::cout<<"What would you like to do: "<<std::endl;
}

void	print_err(int &fun)
{
	fun++;
	if (fun > 5)
	{
		std::cerr<<"\033[31m"<<"INPUT ERROR: pay better attention to the options menu!!"<<"\033[0m"<<std::endl;
		fun = 0;
		return;
	}
	if (fun > 3)
	{
		std::cerr<<"INPUT ERROR: pay better attention to the options menu!!"<<std::endl;
		return ;
	}
	std::cerr<<"Input error: please read your options again"<<std::endl;
}

int	main()
{
	int fun = 0;
	std:: string option;
	std::signal(SIGINT, checkSignal);
	std::signal(SIGTERM, checkSignal);
	PhoneBook phonebook;
	while (1)
	{
		print_options();
		std:: getline(std::cin, option);
		checkStream();
		clear_output();
		if (option == "ADD")
			addcontact(phonebook);
		else if (option == "SEARCH")
			searchContact(phonebook);
		else if (option == "EXIT")
			return 0;
		else
			print_err(fun);
	}
	return 0;
}