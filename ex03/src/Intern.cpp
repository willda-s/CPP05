/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 09:03:24 by williamguer       #+#    #+#             */
/*   Updated: 2026/03/13 09:26:31 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

static AForm* createPresidentialPardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

static AForm* createRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

Intern::Intern()
{
    std::cout << "Intern default constructed." << std::endl;
}

Intern::Intern(const Intern &other)
{
    (void)other;
    std::cout << "Intern copy constructed." << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructed." << std::endl;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
    std::string formNames[3] =
    {
        "presidential pardon",
        "robotomy request",
        "shrubbery creation"
    };
    
    AForm* (*formCreators[3])(std::string) =
    {
        &createPresidentialPardon,
        &createRobotomy,
        &createShrubbery
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    std::cout << "Error: Form '" << formName << "' not found" << std::endl;
    return NULL;
}

