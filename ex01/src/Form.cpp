/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:12:48 by willda-s          #+#    #+#             */
/*   Updated: 2026/03/01 18:33:15 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, size_t gradeSign, size_t gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExec)
{
	this->_boolSigned = false;
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

size_t Form::getGradeExecute() const
{
	return(this->_gradeExecute);
}

size_t Form::getGradeSign() const
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
    out << other.getName() << ",  grade " << other.getGrade() << "." << std::endl;
    return out;
}