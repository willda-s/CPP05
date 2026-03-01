/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:58:26 by willda-s          #+#    #+#             */
/*   Updated: 2026/03/01 18:17:23 by willda-s         ###   ########.fr       */
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
		const size_t _gradeSign;
		const size_t _gradeExecute;
	
	public:
		Form(std::string name, size_t gradeSign, size_t gadeExec);
		~Form();
		std::string getName() const;
		size_t getGradeSign() const;
		size_t getGradeExecute() const;
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