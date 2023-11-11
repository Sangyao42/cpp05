/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:29:54 by sawang            #+#    #+#             */
/*   Updated: 2023/11/11 22:21:53 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP
# include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &cpy);
		virtual ~AForm();

		//getters
		std::string getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;

		//exceptions
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};

		//member functions
		void	beSigned(const Bureaucrat &buro);

		//pure virtual functions
		virtual void	execute(const Bureaucrat &executor) const = 0;
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

		AForm();
		AForm &operator=(const AForm &rhs);

};

std::ostream &operator<<(std::ostream &os, const AForm &rhs);

#endif