/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:08:31 by sawang            #+#    #+#             */
/*   Updated: 2023/11/10 20:47:05 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat b0;
	Bureaucrat b1("Tom", 1);
	Bureaucrat b2("Jerry", 150);

	std::cout << b0;
	std::cout << b1;
	std::cout << b2;

	Bureaucrat b3;
	b3 = b1;
	std::cout << b3;

	Bureaucrat b4(b2);
	std::cout << b4;

	try
	{
		Bureaucrat bToHigh("Tom", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat bToLow("Jerry", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		b1.incrementGrade(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << b1 << std::endl;
	try
	{
		b2.decrementGrade(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << b2 << std::endl;

	try
	{
		b1.decrementGrade(1);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << b1;
}