/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_phonebook.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:32:21 by araveala          #+#    #+#             */
/*   Updated: 2024/11/28 11:17:04 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include "PhoneBook.hpp"

#include <stdexcept>
#include <regex>
#include <cctype>

bool	isWhiteSpace(std::string &input)
{
	for (char &c : input)
	{
		if (!std::isspace(static_cast<unsigned char>(c)))
			return false;
	}
	return true;
}

bool	validateTelNumber(std::string &input)
{
	std::regex regrule("^\\+?[0-9]{3,15}$");
	return std::regex_match(input, regrule);
}

/**
 * @param prompt The output that tells user what input we are waiting for eg, Enter first name
 * @param input The user input passed as refrennce so we do nnot have to send a copy in return to setters
 * @param checkNum Boolean flag to tell function if we handle phonenumber so we can validate input
 * based on the phonenumber requirements like it needing to be digits
 * @return Bool true: inpupt valid, false: input invalid , will continue to loop untill 
 * valid input recieved.
 */
bool	checkInput(const std::string &prompt, std::string &input, bool checkNum)
{
	std::cout<<prompt<<std::endl;	
	std:: getline(std::cin, input);
	checkStream();
	if (input.empty() == true || isWhiteSpace(input))
	{
		std::cout<<"Input can not be empty, please enter valid input"<<std::endl;
		return false;
	}
	if (checkNum == true && validateTelNumber(input) == false)
	{
		std::cout<<"Phonenumber in digits, mini 3 max 10 digits, please enter valid input"<<std::endl;
		return false;
	}
	return true;
}

/**
 * Here we create an instance of contact. We first validate all inputs, then add to phonebook.
 */
void	addcontact(PhoneBook& phonebook)
{
	Contacts contact;
	std::string input;
	while (checkInput("Enter first name: ", input, false) == false);
	contact.set_firstname(input);
	while (checkInput("Enter last name: ", input, false) == false);
	contact.set_lastname(input);
	while (checkInput("Enter nick name: ", input, false) == false);
	contact.set_nickname(input);
	while (checkInput("Enter phonenumber: ", input, true) == false);
	contact.set_phonenumber(input);
	while (checkInput("Enter deepest darkest secret: ", input, false) == false);
	contact.set_secret(input);
	phonebook.addtoPhoneBook(contact);
}

/**
 * Validation that number is in range then translating index value to start from 1 and not zero
 * for better user experience.
 * 
 * @param num The input number for dessired index we want to display data for
 * @param input User input we change from string to digit
 * 
 * @return num: validated and converted number for the index of the phonebook
 */
int	checkIndexNumberValidity(int num, std:: string input)
{
	try
	{
		num = std:: stoi(input);
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr<<"Invalild input, index numbers range 1 - 8"<< std::endl;
		return -1;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr<<"Nobody has that many friends, phonebook has max 8"<< std::endl;
		return -1;
	}
	if (num <= 0)
	{
		std::cerr<<"Number too low index range 1 - 8"<<std::endl;
		return -1;
	}
	if (num > 8)
	{
		std::cerr<<"We do not have more than 8 contacts in this phonebook"<<std::endl;
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
	if ((num = checkIndexNumberValidity(0, input)) == -1)
		return ;
	clear_output();
	Contacts& contact = phonebook.get_array(num);
	contact.get_contact();
}