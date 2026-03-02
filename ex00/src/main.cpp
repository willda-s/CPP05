/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: williamguerreiro <williamguerreiro@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:52:55 by willda-s          #+#    #+#             */
/*   Updated: 2026/03/02 01:30:29 by williamguer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "--- Test 1: Valid bureaucrat creation ---" << std::endl;
	try
	{
		Bureaucrat b1(75, "Alice");
		std::cout << b1;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 2: Increment grade ---" << std::endl;
	try
	{
		Bureaucrat b2(2, "Bob");
		std::cout << "Before: " << b2;
		b2.IncrementGrade();
		std::cout << "After increment: " << b2;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 3: Increment at grade 1 (exception expected) ---" << std::endl;
	try
	{
		Bureaucrat b3(1, "Carl");
		std::cout << "Before: " << b3;
		b3.IncrementGrade();
		std::cout << "After increment: " << b3;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 4: Decrement grade ---" << std::endl;
	try
	{
		Bureaucrat b4(149, "Diana");
		std::cout << "Before: " << b4;
		b4.DecrementGrade();
		std::cout << "After decrement: " << b4;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 5: Decrement at grade 150 (exception expected) ---" << std::endl;
	try
	{
		Bureaucrat b5(150, "Eve");
		std::cout << "Before: " << b5;
		b5.DecrementGrade();
		std::cout << "After decrement: " << b5;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 6: Invalid grade too high (< 1) ---" << std::endl;
	try
	{
		Bureaucrat b6(0, "Frank");
		std::cout << b6;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Test 7: Invalid grade too low (> 150) ---" << std::endl;
	try
	{
		Bureaucrat b7(151, "Grace");
		std::cout << b7;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
