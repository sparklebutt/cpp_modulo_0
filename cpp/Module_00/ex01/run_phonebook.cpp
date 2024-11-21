/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_phonebook.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:32:21 by araveala          #+#    #+#             */
/*   Updated: 2024/11/21 21:01:47 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // put it in header file
#include <string>
#include <cstdlib>
#include "Contacts.hpp"
#include "PhoneBook.hpp"
#include <stdexcept>

void	addcontact(PhoneBook& phonebook)
{
	//crceating an instance of contact class
	Contacts contact;
	std::string input;
	std::cout<<"Enter first name: "<<std::endl;	
	std:: getline(std::cin, input);
	contact.set_firstname(input);
	
	std::cout<<"Enter last name: "<<std::endl;
	std:: getline(std::cin, input);
	contact.set_lastname(input);
	
	std::cout<<"Enter nickname: "<<std::endl;	
	std:: getline(std::cin, input);
	contact.set_nickname(input);
	
	std::cout<<"Enter phonenumber: "<<std::endl;
	std:: getline(std::cin, input);
	contact.set_phonenumber(input);
	
	std::cout<<"Enter deepest darkest secret: "<<std::endl;
	std:: getline(std::cin, input);
	contact.set_secret(input);
	//check details are valid		
	phonebook.addtoPhoneBook(contact);
	
}

int	checkInputNumberValidity(int num, std:: string input)
{
	try
	{
		num = std:: stoi(input);
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << "Invalild input, indexes are numbers" << std::endl;
		return -1;
	}
	if (num <= 0)
	{
		std::cout<<"handle number too low index starts from 1"<<std::endl;
		return -1;
	}
	if (num > 8)
	{
		std::cout<<"We do not have more than 8 contacts in this phonebook"<<num<<std::endl;
		return -1;
	}
	if (num < 9)
		num--;
	return num;
}

void	searchContact(PhoneBook& phonebook)
{
	int num;
	std::string input;
	phonebook.listAllContacts();
	std::cout<<"Enter index : "<<std::endl;
	std:: getline(std:: cin, input);
	if ((num = checkInputNumberValidity(0, input)) == -1)
		return ;
	printf("check num = %d\n", num);
	//need another to catch out of range
	clear_output();
	Contacts& contact = phonebook.get_array(num);
	contact.get_contact();

}