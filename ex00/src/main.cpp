/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:52:55 by willda-s          #+#    #+#             */
/*   Updated: 2026/02/27 19:32:24 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	
	try
	{
		throw Bureaucrat b(160, "Carl");
	}
	catch (std::exception & e)
	{
		e.what();
	}
}

/*
Any attempt to instantiate a Bureaucrat with an invalid grade must throw an exception:
	either a Bureaucrat::GradeTooHighException or a Bureaucrat::GradeTooLowException.

If the grade goes out of range, both functions must throw the same exceptions as the
constructor.

*/