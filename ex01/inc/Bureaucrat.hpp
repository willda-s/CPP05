/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: willda-s <willda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:53:31 by willda-s          #+#    #+#             */
/*   Updated: 2026/03/01 18:23:21 by willda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

class Form;

class Bureaucrat
{
  private:
	const std::string _name;
	size_t _grade;

  public:
	Bureaucrat(size_t grade, std::string name);
	~Bureaucrat();
	std::string getName() const;
	size_t getGrade() const;
	void IncrementGrade();
	void DecrementGrade();
	class GradeTooHighException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	void signForm(const Form &f);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &other);

#endif