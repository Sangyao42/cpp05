/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:28:52 by sawang            #+#    #+#             */
/*   Updated: 2023/11/12 13:10:16 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("", 25, 5)
{
	printForTest("PresidentialPardonForm default constructor is called.");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	printForTest("PresidentialPardonForm constructor is called.");
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy), _target(cpy._target)
{
	printForTest("PresidentialPardonForm copy constructor is called.");
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	printForTest("PresidentialPardonForm copy assignment operator is called.");
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	printForTest("PresidentialPardonForm destructor is called.");
}

//funciton overload
void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->isExecutable(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}