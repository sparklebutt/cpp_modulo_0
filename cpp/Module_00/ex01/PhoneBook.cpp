/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:16 by araveala          #+#    #+#             */
/*   Updated: 2024/11/21 19:35:23 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contacts.hpp"

/**
 * phonebook constructor body is defined with index set to 0, this is called a 
 * initializer list , its benefit is that the varaible gets set before entering
 * the body of the constructor which has a higher value when constructors maye 
 * contain more dtails that rely on varaibles in said list???
 */
PhoneBook::PhoneBook() : index(0)
{
	std::cout << "PhoneBook is ready for input" << std::endl;	
 	for(int i = 0; i < 7; i++)
		isflag[i] = false;
	
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook has been destroyed" << std::endl;	
}

Contacts& PhoneBook:: get_array(int num)
{
	if (isflag[num] == false)
	{
		std::cout<<"This index is empty"<<num<<std::endl;
		return page[num];
	}
	return page[num];
}

void PhoneBook:: listAllContacts()
{	
	if (isflag[0] == false)
	{
		printf("no field please handle\n");
		return ;
	}
	for (int i = 0; isflag[i]; i++)
		page[i].formatContact(i);
}

void PhoneBook::addtoPhoneBook(Contacts& contact)
{
	page[index] = contact;
	isflag[index] = true;
	index = (index + 1) % 7;
}