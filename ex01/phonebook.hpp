#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <cstdlib>

class Contact
{
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		void	get_all(void)
		{
			std::cout << "firstname: " << firstname << '\n';
			std::cout << "lastname: " << lastname << '\n';
			std::cout << "nickname: " << nickname << '\n';
			std::cout << "phone number: " << phone_number << '\n';
			std::cout << "darkest secret: " << darkest_secret << '\n';
		};
		void		set_firstname(std::string fname) {firstname = fname;}
		std::string	get_firstname(void)	{return (firstname);}

		void		set_lastname(std::string lname) {lastname = lname;}
		std::string get_lastname(void) {return (lastname);}

		void		set_nickname(std::string nname) {nickname = nname;}
		std::string	get_nickname(void) {return (nickname);}

		void		set_phone_number(std::string number) {phone_number = number;}
		std::string	get_phone_number(void) {return (phone_number);}

		void		set_darkest_secret(std::string secret) {darkest_secret = secret;}
		std::string	get_darkest_secret(void) {return (darkest_secret);}

};

class PhoneBook
{
	private:
		Contact con[8];
	public:
		int n;
		void search();
		void add();
};

#endif
