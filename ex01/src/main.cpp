/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:08:31 by sawang            #+#    #+#             */
/*   Updated: 2023/11/11 20:34:05 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	// Bureaucrat b0;
	Bureaucrat b1("Tom", 1);
	Bureaucrat b2("Jerry", 150);

	// std::cout << b0;
	std::cout << b1;
	std::cout << b2;

	// Bureaucrat b3;
	// b3 = b1;
	// std::cout << "copy assignment operator: " << b3;

	Bureaucrat b5("Mona", 2);

	try
	{
		Form fToHigh("form to high", 0, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form fToLow("form to low", 151, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f1("Anmeldung", 10, 2);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		b2.signForm(f1);
		std::cout << f1 << std::endl;
		b5.signForm(f1);
		std::cout << f1 << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form f2("Ummeldung", 10, 10);
		std::cout << f2 << std::endl;
		b2.signForm(f2);
		std::cout << f2 << std::endl;
		b5.signForm(f2);
		std::cout << f2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}







}