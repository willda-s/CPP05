/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:58:26 by willda-s          #+#    #+#             */
/*   Updated: 2026/03/11 21:33:22 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string _name;
		bool _boolSigned;
		const int _gradeSign;
		const int _gradeExecute;
	
	public:
		AForm();
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		std::string getName() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		bool getBoolSigned() const;
		virtual void execute(Bureaucrat const & executor) const = 0;
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
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class FormAlreadySignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &out, const AForm &other);


#endif