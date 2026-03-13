/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:12:48 by willda-s          #+#    #+#             */
/*   Updated: 2026/03/11 21:33:22 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _gradeSign(150), _gradeExecute(150)
{
	this->_boolSigned = false;
	std::cout << "AForm default constructed." << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExec)
{
	this->_boolSigned = false;
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
	this->_boolSigned = other._boolSigned;
	std::cout << "AForm " << this->_name << " copy constructed." << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_boolSigned = other._boolSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm " << this->_name << " destructed." << std::endl;
}

std::string AForm::getName() const
{
	return(this->_name);
}

int AForm::getGradeExecute() const
{
	return(this->_gradeExecute);
}

int AForm::getGradeSign() const
{
	return(this->_gradeSign);
}

bool AForm::getBoolSigned() const
{
	return(this->_boolSigned);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "AForm is not signed!";
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
	return "AForm is already signed!";
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (this->_boolSigned)
		throw FormAlreadySignedException();
	if (b.getGrade() <= this->getGradeSign())
	{
		this->_boolSigned = true;
	}
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &other)
{
    out << other.getName() << ", grade required to sign it is " << other.getGradeSign() << "." << std::endl;
	out << other.getName() << ", grade required to execute it is " << other.getGradeExecute() << "." << std::endl;
    out << other.getName() << ", signed: " << (other.getBoolSigned() ? "true" : "false") << "." << std::endl;
	return out;
}