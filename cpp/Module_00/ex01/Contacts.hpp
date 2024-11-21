/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:50 by araveala          #+#    #+#             */
/*   Updated: 2024/11/21 18:54:10 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Contacts
{
	private:
		std::string m_name;
		std::string m_firstname;
		std::string m_lastname;
		std::string m_nickname;
		std::string m_phonenumber;
		std::string m_secret;
	public:
		Contacts();
		~Contacts();
		void	set_firstname(std:: string input);
		void	set_lastname(std:: string input);
		void	set_nickname(std:: string input);
		void	set_phonenumber(std:: string input);
		void	set_secret(std:: string input);		
		void	get_contact();
		void	formatContact(int i);
		std::string formatField(std::string& field);

};
