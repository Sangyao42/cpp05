/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:19:37 by sawang            #+#    #+#             */
/*   Updated: 2023/11/11 20:20:16 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name(""), _isSigned(false),  _gradeToSign(150), _gradeToExecute(150)
{
	// this->_isSigned = false;
	printForTest("Form default constructor is called.");
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (_gradeToSign > 150)
		throw Form::GradeTooLowException();
	if (_gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (_gradeToExecute > 150)
		throw Form::GradeTooLowException();
	printForTest("Form " + _name + " constructor is called.");
}

Form::Form(const Form &cpy) :
	_name(cpy._name), _isSigned(cpy._isSigned), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute)
{
	printForTest("Form copy constructor is called.");
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	printForTest("Form copy assignment operator is called.");
	return (*this);
}

Form::~Form()
{
	printForTest("Form destructor is called.");
}

//getters
std::string Form::getName() const
{
	return (this->_name);
}

bool		Form::getIsSigned() const
{
	return (this->_isSigned);
}

int			Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int			Form:: getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

//exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low.");
}

//member function
void	Form::beSigned(const Bureaucrat &buro)
{
	if (buro.getGrade() > this->_gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	else
		this->_isSigned = true;
}

//printer
std::ostream &operator<<(std::ostream &os, const Form &rhs)
{
	os << "Form name: " << rhs.getName() << std::endl;
	os << "Form signed: " << rhs.getIsSigned() << std::endl;
	os << "Form grade to sign: " << rhs.getGradeToSign() << std::endl;
	os << "Form grade to execute: " << rhs.getGradeToExecute() <<std::endl;
	return (os);
}