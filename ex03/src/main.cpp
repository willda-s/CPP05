/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:52:55 by willda-s          #+#    #+#             */
/*   Updated: 2026/07/10 16:11:31 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

static void separator(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========" << std::endl;
}

int main()
{
    std::srand(std::time(NULL));
    separator("Test 1 : Invalid grade");
    try { Bureaucrat bad(0, "TooHigh"); }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }
    try { Bureaucrat bad(151, "TooLow"); }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    separator("Test 2 : Bureaucrat display");
    Bureaucrat bob(1, "Bob");
    Bureaucrat alice(75, "Alice");
    Bureaucrat charlie(150, "Charlie");
    std::cout << bob;
    std::cout << alice;
    std::cout << charlie;

    separator("Test 3 : Increment / Decrement grade");
    try { bob.DecrementGrade(); std::cout << bob; }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }
    try { bob.IncrementGrade(); std::cout << bob; }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }
    try { charlie.IncrementGrade(); std::cout << charlie; }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }
    try { charlie.DecrementGrade(); std::cout << charlie; }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    separator("Test 4 : Sign with insufficient grade");
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm   robotomy("Bender");
    PresidentialPardonForm pardon("Zaphod");
    std::cout << shrubbery;
    std::cout << robotomy;
    std::cout << pardon;
    charlie.signForm(robotomy);
    charlie.signForm(pardon);

    separator("Test 5 : Execute unsigned form");
    bob.executeForm(shrubbery);
    bob.executeForm(robotomy);
    bob.executeForm(pardon);

    separator("Test 6 : Sign and execute correctly");
    bob.signForm(shrubbery);
    bob.signForm(robotomy);
    bob.signForm(pardon);
    bob.executeForm(shrubbery);
    bob.executeForm(robotomy);
    bob.executeForm(robotomy);
    bob.executeForm(robotomy);
    bob.executeForm(pardon);

    separator("Test 7 : Execute with insufficient grade");
    ShrubberyCreationForm shrubbery2("garden");
    bob.signForm(shrubbery2);
    charlie.executeForm(shrubbery2);

    separator("Test 8 : Double signature");
    ShrubberyCreationForm shrubbery3("office");
    bob.signForm(shrubbery3);
    bob.signForm(shrubbery3);

    separator("Test 9 : Form copy");
    ShrubberyCreationForm original("park");
    bob.signForm(original);
    ShrubberyCreationForm copy(original);
    std::cout << original;
    std::cout << copy;
    bob.executeForm(original);
    bob.executeForm(copy);

    separator("Test 10 : Intern creates forms");
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf)
    {
        bob.signForm(*rrf);
        bob.executeForm(*rrf);
        delete rrf;
    }

    return 0;
}
