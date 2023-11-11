/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:34:11 by sawang            #+#    #+#             */
/*   Updated: 2023/11/11 20:37:06 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void	printForTest(std::string str)
{
	#ifdef TEST
		std::cout << str << std::endl;
	#else
		(void)str;
	#endif
}

Bureaucrat::Bureaucrat() : _grade(150)
{
	printForTest("Bereaucrat default constructor is called.");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	printForTest("Bereaucrat " + _name + " constructor is called.");
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
	this->_grade = copy._grade;
	printForTest("Bereaucrat copy constructor is called.");
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
		this->_grade = rhs._grade;
	printForTest("Bereaucrat copy assignment operator is called.");
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	printForTest("Bereaucrat destructor is called.");
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(int offset)
{
	if ((this->_grade - offset) < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= offset;
}

void	Bureaucrat::decrementGrade(int offset)
{
	if ((this->_grade + offset) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += offset;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade is too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade is too low.");
}

//member function
void	Bureaucrat::signForm(Form &formToSign) const
{
	if (formToSign.getIsSigned() == true)
	{
		std::cout << formToSign.getName() << " is already signed." << std::endl;
	}
	else
	{
		try
		{
			formToSign.beSigned(*this);
			std::cout << this->_name << " signed " << formToSign.getName() <<std::endl;;
		}
		catch(const std::exception& e)
		{
			std::cerr << this->_name << " couldn't sign " << formToSign.getName() << " because " << e.what() << std::endl;
		}
	}
}

//printer
std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (os);
}
