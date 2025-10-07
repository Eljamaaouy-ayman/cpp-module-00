#include "phonebook.hpp"

std::string ten_char(std::string str)
{
	if (str.length() >= 10)
		return (str.substr(0, 9)) + ".";
	return (str);
}

void	PhoneBook::search()
{
	std::string str;
	if (n == 0)
	{
		std::cout << "empty PhoneBook\n";
		return ;
	}
	std::cout << '|' << std::setw(10) << "index";
	std::cout << '|' << std::setw(10) << "first name";
	std::cout << '|' << std::setw(10) << "last name";
	std::cout << '|' << std::setw(10) << "nickname" << '|' << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		str = ten_char(con[i].get_firstname());
		if (!str[0])
			break;
		std::cout << "_____________________________________________" << std::endl;
		std::cout << '|' << std::setw(10) << i;
		std::cout << '|' << std::setw(10) << str;
		str = ten_char(con[i].get_lastname());
		std::cout << '|' << std::setw(10) << str;
		str = ten_char(con[i].get_nickname());
		std::cout << '|' << std::setw(10) << str << '|' << std::endl;
	}
	std::cout << "enter the index of the contact";
	std::getline(std::cin, str);
	if (std::cin.eof())
		exit(1);
	if (str.length() != 1 || (str[0] < '0' || str[0] > '7'))
	{
		std::cout << "bad address" << std::endl;
		return ;
	}
	int i = str[0] - '0';
	str = con[i].get_firstname();
	if (!str[0])
		std::cout << "bad address!!!" << std::endl;
	else
		con[i].get_all();
}

int allnumber(std::string data)
{
	if (!data[0])
		return (1);
	for (size_t i = 0; data[i]; i++)
	{
		if (data[i] < '0' || data[i] > '9')
			return (1);
	}
	return (0);
}

void	PhoneBook::add()
{
	std::string data;

	if (n == 8)
	n = 0;
	while (1)
	{
		std::cout << "enter the first name: ";
		std::getline(std::cin, data);
		if (std::cin.eof())
			exit(1);
		if (data[0])
		{
			con[n].set_firstname(data);
			break;
		}
		std::cout << "bad input !\n";
	}

	while (1)
	{
		std::cout << "enter the last name: ";
		std::getline(std::cin, data);
		if (std::cin.eof())
			exit(1);
		if (data[0])
		{
			con[n].set_lastname(data);
			break;
		}
		std::cout << "bad input !\n";
	}

	while (1)
	{
		std::cout << "enter the nick name: ";
		std::getline(std::cin, data);
		if (std::cin.eof())
			exit(1);
		if (data[0])
		{
			con[n].set_nickname(data);
			break;
		}
		std::cout << "bad input !\n";
	}

	while (1)
	{
		std::cout << "enter the phone number: ";
		std::getline(std::cin, data);
		if (std::cin.eof())
			exit(1);
		if (allnumber(data) == 0)
		{
			con[n].set_phone_number(data);
			break;
		}
		std::cout << "enter numbers !";
	}

	while (1)
	{
		std::cout << "enter the darkest number: ";
		std::getline(std::cin, data);
		if (std::cin.eof())
			exit(1);
		if (data[0])
		{
			con[n].set_darkest_secret(data);
			break;
		}
		std::cout << "bad input !\n";
	}
	n++;
}
