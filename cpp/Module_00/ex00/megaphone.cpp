/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:15:16 by araveala          #+#    #+#             */
/*   Updated: 2024/11/28 11:05:58 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

/**
 * Megaphhone, converting input to caps 
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
