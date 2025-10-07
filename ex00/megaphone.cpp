#include <iostream>
#include <cctype> // For islower and toupper
#include <cstring>

int main(int argc, char* argv[])
{
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; ++i)
	{
        char* arg = argv[i];
        for (int j = 0; arg[j] != '\0'; ++j)
		{
            if (std::islower(arg[j]))
                std::cout << (char)std::toupper(arg[j]);
			else if (j == 0 && arg[j] == ' ')
				continue;
			else
                std::cout << arg[j];
        }
        // Add a space between arguments (optional)
		size_t len = strlen(arg);
        if (len > 0 && arg[len - 1] != ' ' && i < argc - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
