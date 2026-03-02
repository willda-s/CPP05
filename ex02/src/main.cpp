/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:52:55 by willda-s          #+#    #+#             */
/*   Updated: 2026/03/02 01:28:21 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    std::cout << "--- Test 1: Valid form, bureaucrat with sufficient grade ---" << std::endl;
    try 
    {
        Form form1("Form1", 50, 20);
        Bureaucrat b1(5, "Alice");
        std::cout << form1 << std::endl;
        b1.signForm(form1);
        std::cout << form1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Bureaucrat with insufficient grade ---" << std::endl;
    try
    {
        Form form2("Form2", 10, 5);
        Bureaucrat b2(50, "Bob");
        std::cout << form2 << std::endl;
        b2.signForm(form2);
        std::cout << form2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Bureaucrat with invalid grade (> 150) ---" << std::endl;
    try
    {
        Bureaucrat b3(200, "Charlie");
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Form with invalid grade (> 150) ---" << std::endl;
    try 
    {
        Form form4("Form4", 200, 10);
    }
    catch (std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 5: Form with invalid grade (< 1) ---" << std::endl;
    try {
        Form form5("Form5", 0, 10);
    }
    catch (std::exception &e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
