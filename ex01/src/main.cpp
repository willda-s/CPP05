/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:52:55 by willda-s          #+#    #+#             */
/*   Updated: 2026/03/11 21:33:22 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

static void separator(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========" << std::endl;
}

int main()
{
    separator("Test 1 : Invalid grades");
    try { Bureaucrat bad(0, "TooHigh"); }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }
    try { Bureaucrat bad(151, "TooLow"); }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }
    try { Form form1("InvalidForm1", 0, 50); }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }
    try { Form form2("InvalidForm2", 50, 200); }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    separator("Test 2 : Bureaucrat and Form display");
    Bureaucrat bob(1, "Bob");
    Bureaucrat alice(75, "Alice");
    Bureaucrat charlie(150, "Charlie");
    Form form1("Form1", 50, 25);
    Form form2("Form2", 100, 75);
    std::cout << bob;
    std::cout << alice;
    std::cout << charlie;
    std::cout << form1;
    std::cout << form2;

    separator("Test 3 : Increment / Decrement grade");
    try { bob.DecrementGrade(); std::cout << bob; }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }
    try { bob.IncrementGrade(); std::cout << bob; }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }
    try { charlie.IncrementGrade(); std::cout << charlie; }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }
    try { charlie.DecrementGrade(); std::cout << charlie; }
    catch (std::exception &e) { std::cout << "Exception: " << e.what() << std::endl; }

    separator("Test 4 : Sign with sufficient grade");
    bob.signForm(form1);
    std::cout << form1;
    alice.signForm(form2);
    std::cout << form2;

    separator("Test 5 : Sign with insufficient grade");
    Form form3("Form3", 10, 5);
    charlie.signForm(form3);
    std::cout << form3;

    separator("Test 6 : Double signature");
    bob.signForm(form1);
    std::cout << form1;

    separator("Test 7 : Form copy");
    Form original("Original", 50, 30);
    bob.signForm(original);
    Form copy(original);
    std::cout << original;
    std::cout << copy;

    return 0;
}
