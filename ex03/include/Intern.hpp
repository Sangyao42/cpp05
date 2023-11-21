/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:21:56 by sawang            #+#    #+#             */
/*   Updated: 2023/11/21 15:48:36 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &rhs);
		~Intern();

		AForm	*makeForm(std::string formName, std::string target);
		//exception
		class FormWrongNameException : public std::exception
		{
			virtual const char *what() const throw();
		};
	private:
		static std::string _formNames[3];
};
#endif
