#include "phonebook.hpp"

std::string touper(std::string str)
{
	for (size_t i = 0; str[i]; i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	return (str);
}

int main()
{
	PhoneBook a;
	std::string command;
	a.n = 0;

	while(1)
	{
		std::cout << "enter the command (ADD, SEARCH, EXIT) : ";
		std::getline(std::cin, command);

		if (std::cin.eof())
			break;
		command = touper(command);
		if (command == "ADD")
			a.add();
		else if (command == "SEARCH")
			a.search();
		else if (command == "EXIT")
			break;
		else
			std::cout << "invalid command" << std::endl;
	}
	return (0);
}
