/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:12:48 by willda-s          #+#    #+#             */
/*   Updated: 2026/03/02 01:23:23 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExec)
{
	this->_boolSigned = false;
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
	std::cout << "Form " << this->_name << " constructed." << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " destructed." << std::endl;
}

std::string Form::getName() const
{
	return(this->_name);
}

int Form::getGradeExecute() const
{
	return(this->_gradeExecute);
}

int Form::getGradeSign() const
{
	return(this->_gradeSign);
}

bool Form::getBoolSigned() const
{
	return(this->_boolSigned);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form Grade is too low!";
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeSign())
	{
		this->_boolSigned = true;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &other)
{
    out << other.getName() << ", grade required to sign it is " << other.getGradeSign() << "." << std::endl;
	out << other.getName() << ", grade required to execute it is " << other.getGradeExecute() << "." << std::endl;
    out << other.getName() << ", signed: " << (other.getBoolSigned() ? "true" : "false") << "." << std::endl;
	return out;
}