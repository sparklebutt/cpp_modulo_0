/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_phonebook.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:32:21 by araveala          #+#    #+#             */
/*   Updated: 2024/11/21 19:36:24 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> // put it in header file
#include <string>
#include <cstdlib>
#include "Contacts.hpp"
#include "PhoneBook.hpp"

void	addcontact(PhoneBook& phonebook)
{
	//crceating an instance of contact class
	Contacts contact;
	std::string input;
	std::cout<<"enter first name: "<<std::endl;	
	std:: getline(std::cin, input);
	contact.set_firstname(input);
	
	std::cout<<"enter last name: "<<std::endl;
	std:: getline(std::cin, input);
	contact.set_lastname(input);
	
	std::cout<<"enter nickname: "<<std::endl;	
	std:: getline(std::cin, input);
	contact.set_nickname(input);
	
	std::cout<<"enter phonenumber: "<<std::endl;
	std:: getline(std::cin, input);
	contact.set_phonenumber(input);
	
	std::cout<<"enter deepest darkest secret: "<<std::endl;
	std:: getline(std::cin, input);
	contact.set_secret(input);
	//check details are valid		
	phonebook.addtoPhoneBook(contact);
	
}

void	searchContact(PhoneBook& phonebook)
{
	int num = 0;
	std::string input;
	phonebook.listAllContacts();
	std::cout<<"index : \n";
	std:: getline(std:: cin, input);
	std::cout<<num<<std::endl;
	num = std:: stoi(input);
	clear_output();
	Contacts& contact = phonebook.get_array(num);
	printf("_________\n");
	contact.get_contact();

}