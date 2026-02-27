/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 16:45:07 by willda-s          #+#    #+#             */
/*   Updated: 2026/02/27 19:31:09 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(size_t grade, std::string name): _name(name), _grade(grade) 
{
	if (grade < 1 || grade > 150)
		throw e;
	std::cout << "Bureaucrat " << this->_name << " constructed." << std::endl;
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->_name << " destructed." << std::endl;
}

std::string Bureaucrat::getName() const
{
	return(this->_name);
}

size_t Bureaucrat::getGrade() const
{
	return(this->_grade);
}

void Bureaucrat::IncrementGrade()
{
	if (this->_grade > 0 && this->_grade < 151)
		this->_grade--;
}

void Bureaucrat::DecrementGrade()
{
	if (this->_grade > 0 && this->_grade < 151)
		this->_grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other)
{
    out << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
    return out;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}