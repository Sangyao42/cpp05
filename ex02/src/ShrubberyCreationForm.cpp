/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:29:29 by sawang            #+#    #+#             */
/*   Updated: 2023/11/12 13:32:31 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", 145, 137)
{
	printForTest("ShrubberyCreationForm default constructor is called.");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	printForTest("ShrubberyCreationForm constructor is called.");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy), _target(cpy._target)
{
	printForTest("ShrubberyCreationForm copy constructor is called.");
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	printForTest("ShrubberyCreationForm copy assignment operator is called.");
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	printForTest("ShrubberyCreationForm destructor is called.");
}

//funciton overload
void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	this->isExecutable(executor);
	std::ofstream ofs(this->_target + "_shrubbery");
	std::string tree = "       _-_       \n"
					   "    /~~   ~~\\    \n"
 					   " /~~         ~~\\ \n"
					   "{               }\n"
					   " \\  _-     -_  / \n"
					   "   ~  \\ //  ~   \n"
					   "_- -   | | _- _  \n"
  					   "  _ -  | |   -_  \n"
     				   "      // \\      \n";
	if (!ofs)
		std::cerr << "Error: " << this->_target << "_shrubbery: " << strerror(errno) << std::endl;
	else
		ofs << tree;
	ofs.close();
}
