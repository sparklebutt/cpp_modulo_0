/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:15:16 by araveala          #+#    #+#             */
/*   Updated: 2024/11/12 15:00:54 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>


/**
 * Inllcuding al llibraries even though iostream can handle this function alone, 
 * this is good practice incase other systems have different types of depencies.
 * 
 * std:: stands for standard library, so we only want to use eg toupper from the standard library
 * 
 * we iterate using a range based iterator we take refrence of a character : from first location of out
 * when using a range based for loop the : symbol is to inform that we will iterate .
 * We can safley use range based here because we have a c lear direction of iteration (forwards)
 * and we have no intention to skip over any elements . 
 */
int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
		return 1;	
	}
	std::string out;
	for (int i = 1; i < argc; i++)
		out += argv[i];
	for (char &c : out)
		c = std::toupper(static_cast<unsigned char>(c));
	std::cout<<out<<std::endl;
	return 0;
}
