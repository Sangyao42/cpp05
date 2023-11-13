/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:29:44 by sawang            #+#    #+#             */
/*   Updated: 2023/11/12 13:12:22 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("", 72, 45)
{
	printForTest("RobotomyRequestForm default constructor is called.");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	printForTest("RobotomyRequestForm constructor is called.");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy), _target(cpy._target)
{
	printForTest("RobotomyRequestForm copy constructor is called.");
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	printForTest("RobotomyRequestForm copy assignment operator is called.");
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	printForTest("RobotomyRequestForm destructor is called.");
}

//funciton overload
void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->isExecutable(executor);
	std::cout << "* some drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " robotomization failed." << std::endl;
}