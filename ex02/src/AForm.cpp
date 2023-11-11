/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:19:37 by sawang            #+#    #+#             */
/*   Updated: 2023/11/11 20:20:16 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _isSigned(false),  _gradeToSign(150), _gradeToExecute(150)
{
	printForTest("AForm default constructor is called.");
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToSign > 150)
		throw AForm::GradeTooLowException();
	if (_gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (_gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	printForTest("AForm " + _name + " constructor is called.");
}

AForm::AForm(const AForm &cpy) :
	_name(cpy._name), _isSigned(cpy._isSigned), _gradeToSign(cpy._gradeToSign), _gradeToExecute(cpy._gradeToExecute)
{
	printForTest("AForm copy constructor is called.");
}

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	printForTest("AForm copy assignment operator is called.");
	return (*this);
}

AForm::~AForm()
{
	printForTest("AForm destructor is called.");
}

//getters
std::string AForm::getName() const
{
	return (this->_name);
}

bool		AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int			AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int			AForm:: getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

//exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: Grade is too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: Grade is too low.");
}

//member function
void	AForm::beSigned(const Bureaucrat &buro)
{
	if (buro.getGrade() > this->_gradeToSign)
	{
		throw AForm::GradeTooLowException();
	}
	else
		this->_isSigned = true;
}

//printer
std::ostream &operator<<(std::ostream &os, const AForm &rhs)
{
	os << "AForm name: " << rhs.getName() << std::endl;
	os << "AForm signed: " << rhs.getIsSigned() << std::endl;
	os << "AForm grade to sign: " << rhs.getGradeToSign() << std::endl;
	os << "AForm grade to execute: " << rhs.getGradeToExecute() <<std::endl;
	return (os);
}