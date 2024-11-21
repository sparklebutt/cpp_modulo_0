/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:29:40 by araveala          #+#    #+#             */
/*   Updated: 2024/11/21 18:53:44 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

Contacts::Contacts(){}
Contacts::~Contacts(){}

void Contacts::set_firstname(std:: string input) {
	this->m_firstname = input;
}

void Contacts::set_lastname(std:: string input) {
	this->m_lastname = input;
}

void Contacts::set_nickname(std:: string input) {
	this->m_nickname = input;
}

void Contacts::set_phonenumber(std:: string input) {
	this->m_phonenumber = input;
}

void Contacts::set_secret(std:: string input) {
	this->m_secret = input;
}

void Contacts::get_contact()
{
	std::cout << m_firstname << std::endl;
	std::cout << m_lastname << std::endl;
	std::cout << m_nickname << std::endl;
	std::cout << m_phonenumber << std::endl;
	std::cout << m_secret << std::endl;
}

std::string Contacts::formatField(std::string& field)
{
	std::string formattedString = field;
	if (field.length() > 10)
		formattedString = field.substr(0, 9) + ".";
	return formattedString;
}

void	Contacts::formatContact(int i)
{
	std::ostringstream formattedString;
	formattedString << std::setw(10) << std::right << i << "|"
	<< std::setw(10) << std::right << formatField(m_firstname) << "|"
	<< std::setw(10) << std::right << formatField(m_lastname) << "|"
	<< std::setw(10) << std::right << formatField(m_nickname);
	std::cout<<formattedString.str()<<std::endl;
}
