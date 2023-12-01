// Elf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    std::ifstream file;
	file.open("c:\\Users\\mattg\\Desktop\\elves.txt", std::ios::in);
	
	if (!file.is_open())
	{
		std::cout << "File not found" << std::endl;
		return 1;
	}

	std::vector<int> elves;
	int elfcals = 0;

    while (!file.eof())
	{
		std::string line;
		std::getline(file, line);

		// if it's blank, we move onto the next elf.
		// if it's not blank, turn it into an int, accumulate the total
		
		if (line.empty())
		{
			elves.push_back(elfcals);
			elfcals = 0;
		}
		else
		{
			// convert to int
			elfcals += std::stoi(line);
		}
	}
	file.close();

	for (int i : elves)
	{
		std::cout << i << std::endl;
	}

	std::sort(elves.begin(), elves.end(), [](int a, int b)
		{
			return a > b;
		});

	if (elves.size() > 0)
	{
		std::cout << "\r\nfat elf: " << elves[0] << std::endl;
	}
}