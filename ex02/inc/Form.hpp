/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:58:26 by willda-s          #+#    #+#             */
/*   Updated: 2026/03/02 01:21:49 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _boolSigned;
		const int _gradeSign;
		const int _gradeExecute;
	
	public:
		Form(std::string name, int gradeSign, int gradeExec);
		~Form();
		std::string getName() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		bool getBoolSigned() const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &out, const Form &other);


#endif