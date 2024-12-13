/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:27 by araveala          #+#    #+#             */
/*   Updated: 2024/11/26 11:55:54 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Contacts.hpp"
#include <cstdlib>

class PhoneBook
{
	private:
		Contacts	page[8];
		bool		isflag[8];
		int			index;
	public:
		PhoneBook();
		~PhoneBook();
		Contacts &get_array(int num);
		void 	addtoPhoneBook(Contacts& contact);
		void	listAllContacts();
};

void	addcontact(PhoneBook& phonebook);
void	searchContact(PhoneBook& phonebook);
void	clear_output();
void	checkStream();
