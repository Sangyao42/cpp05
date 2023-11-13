/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 20:08:31 by sawang            #+#    #+#             */
/*   Updated: 2023/11/13 14:00:38 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

int main(void)
{
	// Bureaucrat b0;
	Bureaucrat b1("Tom", 1);
	Bureaucrat b2("Jerry", 150);

	// std::cout << b0;
	std::cout << b1;
	std::cout << b2;

	ShrubberyCreationForm f1("home");
	RobotomyRequestForm f2("Marvin");
	PresidentialPardonForm f3("one");

	b1.executeForm(f1);
	b2.signForm(f1);
	b1.signForm(f1);
	b2.executeForm(f1);
	b1.executeForm(f1);
	b1.executeForm(f1);

	std::cout << std::endl;

	b1.signForm(f2);
	b1.executeForm(f2);

	std::cout << std::endl;

	b2.signForm(f3);
	b2.executeForm(f3);
	b1.signForm(f3);
	b1.executeForm(f3);

	return (0);
}
