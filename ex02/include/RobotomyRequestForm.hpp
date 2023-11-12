/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:27:39 by sawang            #+#    #+#             */
/*   Updated: 2023/11/12 12:32:33 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		virtual ~RobotomyRequestForm();

		//funciton overload
		virtual void	execute(const Bureaucrat &executor) const;

	private:
		std::string		_target;
		
		RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
};

#endif