/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:33:02 by sawang            #+#    #+#             */
/*   Updated: 2023/11/11 16:32:12 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

class Bureaucrat
{
	public:
		Bureaucrat(const std::string &name, const int &grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;

		void		incrementGrade(int offset);
		void		decrementGrade(int offset);

		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};

	private:
		const std::string	_name;
		int					_grade;

		Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &rhs);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);

#endif
