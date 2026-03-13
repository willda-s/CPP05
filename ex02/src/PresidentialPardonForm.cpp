/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:15:28 by williamguer       #+#    #+#             */
/*   Updated: 2026/03/13 09:52:52 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
    std::cout << "PresidentialPardonForm default constructed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm " << this->_target << " constructed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
    std::cout << "PresidentialPardonForm " << this->_target << " copy constructed." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm " << this->_target << " destructed." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getBoolSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeExecute())
        throw AForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}