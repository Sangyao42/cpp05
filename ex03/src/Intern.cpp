/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:24:34 by sawang            #+#    #+#             */
/*   Updated: 2023/11/13 14:58:50 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	printForTest("Intern Default Constructor called");
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
	printForTest("Intern Copy Constructor called");
}

Intern &Intern::operator=(const Intern &rhs)
{
	if (this != &rhs)
	{
		(void)rhs;
	}
	printForTest("Intern Assignation Operator called");
	return (*this);
}

Intern::~Intern()
{
	printForTest("Intern Destructor called");
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	AForm *form;
	form = NULL;
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while(i < 3 && formName != formNames[i])
		i++;
	switch (i)
	{
		case (0):
			form = new ShrubberyCreationForm(target);
			break;
		case (1):
			form = new RobotomyRequestForm(target);
			break;
		case (2):
			form = new PresidentialPardonForm(target);
			break;
		default:
			break;
	}
	if (form == NULL)
	{
		throw Intern::FormWrongNameException();
	}
	std::cout << "Intern creates " << formName << std::endl;
	return (form);
}

const char *Intern::FormWrongNameException::what() const throw()
{
	return ("Form does not exist.");
}