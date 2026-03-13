/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:16:13 by williamguer       #+#    #+#             */
/*   Updated: 2026/03/13 09:52:52 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm default constructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm " << this->_target << " constructed." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
    std::cout << "RobotomyRequestForm " << this->_target << " copy constructed." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm " << this->_target << " destructed." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getBoolSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeExecute())
        throw AForm::GradeTooLowException();
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << this->_target << "." << std::endl;
}