/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:40 by araveala          #+#    #+#             */
/*   Updated: 2024/11/27 15:58:57 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include <iomanip>
#include <sstream>

Contacts::Contacts(){}
Contacts::~Contacts(){}

void Contacts::set_firstname(std:: string input) {this->m_firstname = input;}

void Contacts::set_lastname(std:: string input) {this->m_lastname = input;}

void Contacts::set_nickname(std:: string input) {this->m_nickname = input;}

void Contacts::set_phonenumber(std:: string input) {this->m_phonenumber = input;}

void Contacts::set_secret(std:: string input) {this->m_secret = input;}

void Contacts::get_contact()
{
	if (m_firstname.empty())
		return ;
	std::cout << "Firstname: " << m_firstname << std::endl;
	std::cout << "Lastname: " << m_lastname << std::endl;
	std::cout << "Nickname: " << m_nickname << std::endl;
	std::cout << "Phonenumber: " << m_phonenumber << std::endl;
	std::cout << "Deepest darkest secret: " << m_secret << std::endl;
}

std::string Contacts::formatField(std::string& field)
{
	std::string formattedString = field;
	if (field.length() > 10)
		formattedString = field.substr(0, 9) + ".";
	return formattedString;
}

/**
 * Using ostringstream so that i can change the input string directly, utalize stream insertion <<
 * and the formatting manipulators ::setw and ::right
 */
void	Contacts::formatContact(int i)
{
	std::ostringstream formattedString;
	formattedString << std::setw(10) << std::right << i + 1 << "|"
	<< std::setw(10) << std::right << formatField(m_firstname) << "|"
	<< std::setw(10) << std::right << formatField(m_lastname) << "|"
	<< std::setw(10) << std::right << formatField(m_nickname);
	std::cout<<formattedString.str()<<std::endl;
}
