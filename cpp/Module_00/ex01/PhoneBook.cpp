/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:16 by araveala          #+#    #+#             */
/*   Updated: 2024/11/28 11:08:05 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contacts.hpp"


PhoneBook::PhoneBook() : index(0)
{
	std::cout << "PhoneBook is ready for input" << std::endl;	
 	for(int i = 0; i < 7; i++)
		isflag[i] = false;
	
}

PhoneBook::~PhoneBook() { std::cout << "PhoneBook has been destroyed" << std::endl;	}

/**
 * Checks if the given input number from user matches an index that has been 
 * updated with data.
 * @param num user input for index wanted 
 * @return Contact element from the array matching the index
 */
Contacts& PhoneBook:: get_array(int num)
{
	if (isflag[num] == false)
	{
		std::cout<<"Index "<<num + 1<<" is empty"<<std::endl;
		return page[num];
	}
	return page[num];
}

/**
 * Checks to see that the first element of the array has anything inside it so we dont
 * print empty data. 
 * 
 * Iterates through page[i] which is the contact array for formating into a readable table.
 */
void PhoneBook:: listAllContacts()
{	
	if (isflag[0] == false)
		return ;
	for (int i = 0; isflag[i] && i < 8; i++)
		page[i].formatContact(i);
}

/**
 * We put the filled conatact instance into the contact array based on index
 * that wraps around back to 0 when we reach end of array
 */
void PhoneBook::addtoPhoneBook(Contacts& contact)
{
	page[index] = contact;
	isflag[index] = true;
	index = (index + 1) % 8;
}