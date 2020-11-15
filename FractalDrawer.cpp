#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "Fractal.h"

const int NUMBER_OF_TYPES = 3;
const int MAX_DIM = 6;
const int MIN_DIM = 1;

/**
 * Main function of FractalDrawer program
 * @param argc number of arguments
 * @param argv arguments
 * @return 0 when success
 */
int main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cerr << "Usage: FractalDrawer <file path>\n";
		return EXIT_FAILURE;
	}

	std::ifstream inputFile;
	inputFile.open(argv[1]);

	// if file doesn't exist or doesn't open
	if(!inputFile.is_open())  //note: the school solution only prints error when file doesn't exist
	{
		std::cerr << "Invalid input\n";
		return EXIT_FAILURE;
	}

	inputFile.clear();
	if(inputFile.peek() == std::ifstream::traits_type::eof())  //if file is empty
	{
		inputFile.close();
		return EXIT_FAILURE;
	}

	inputFile.clear();

	std::string line;
	int type, dim;
	unsigned long i;
	std::vector<std::string> input;
	std::vector<Fractal*> fractals;

	while(std::getline(inputFile, line))
	{
		input.push_back(line);
	}
	inputFile.close();

	unsigned long numOfLines = input.size();

	if(input[0].empty() && numOfLines == 1)
	{
		std::cerr << "Invalid input\n";
		return EXIT_FAILURE;
	}

	for(i = 0; i < numOfLines; i++)
	{
		if(input[i].empty()
		   || input[i].find(' ') != std::string::npos
		   || input[i].find('\t') != std::string::npos
		   || input[i].length() != 3
		   || input[i].find(',') != 1
		   || input[i].at(0) <= '0' || input[i].at(0) - '0' > NUMBER_OF_TYPES
		   || input[i].at(2) - '0' < MIN_DIM || input[i].at(2) - '0' > MAX_DIM)
		{
			std::cerr << "Invalid input\n";
			return EXIT_FAILURE;
		}

		type = input[i].at(0) - '0';
		dim = input[i].at(2) - '0';

		if(type == 1)
		{
			fractals.push_back(new SierpinskiCarpet(dim));
		}
		else if(type == 2)
		{
			fractals.push_back(new SierpinskiSieve(dim));
		}
		else
		{
			fractals.push_back(new CantorDust(dim));
		}
	}

	//drawing all fractals from input file in a reverse order
	while(!fractals.empty())
	{
		Fractal *fractal = fractals.back();
		fractal->draw();
		std::cout << std::endl;
		delete(fractal);
		fractals.pop_back();
	}

	inputFile.close();
	return 0;
}