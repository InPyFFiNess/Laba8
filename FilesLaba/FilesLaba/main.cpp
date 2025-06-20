#include <iostream>
#include <fstream>
#include "Header.h"

int main()
{
	int32_t choise{};
	int32_t size{};
	double* array = new double[size];
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");
	std::cout << "Choise variant for input: \n" << "1 - Console\n" << "2 - File\n";
	std::cin >> choise;
	if (choise == 1)
	{
		std::cout << "Input size: ";
		std::cin >> size;
		FillArrayConsole(array, size);
	}
	else if (choise == 2)
	{
		CheckInputFile(fin);
		size = Counter(fin);
		FillArrayFile(fin, array, size);
	}
	else
	{
		std::cout << "Wrong choise!";
		return 0;
	}
	choise = 0;
	std::cout << "Input variant of sort: \n" << "1 - Quick Sort\n" << "2 - Insertion Sort\n" << "3 - Selection Sort\n"
		<< "4 - Merge Sort\n" << "5 - Bubble Sort\n" << "6 - Qsort(number in descending order in fraction of number\n";
	std::cin >> choise;
	switch (choise)
	{
	case 1:
	{
		QuickSort(array, 0, size - 1);
		
		break;
	}
	case 2:
	{
		InsertionSort(array, size);
		break;
	}
	case 3:
	{
		SelectionSort(array, size);
		break;
	}
	case 4:
	{
		MergeSort(array, 0, size - 1);
		break;
	}
	case 5:
	{
		BubbleSort(array, size);
		break;
	}
	case 6:
	{
		FillArrayByNumAfterPoint(array, size);
		QuickSort(array, 0, size - 1);
		break;
	}
	default:
		std::cout << "Wrong choise!";
		return 0;
		break;
	}
	choise = 0;
	std::cout << "Choise variant of output: \n" << "1 - Console\n" << "2 - File\n";
	std::cin >> choise;
	if (choise == 1)
	{
		choise = 0;
		std::cout << "Choise variant of order of elements: \n" << "1 - Non reverse\n" << "2 - Reverse\n";
		std::cin >> choise;
		if (choise == 1)
		{
			OutputArrayConsole(array, size);
		}
		else if (choise == 2)
		{
			OutputTurnArrayConsole(array, size);
		}
		else
		{
			std::cout << "Wrong Choise!";
			return 0;
		}
	}
	else if (choise == 2)
	{
		choise = 0;
		std::cout << "Choise variant of order of elements: \n" << "1 - Non reverse\n" << "2 - Reverse\n";
		std::cin >> choise;
		if (choise == 1)
		{
			CheckOutputFile(fout);
			OutputArrayFile(fout, array, size);
			fin.close();
			fout.close();
			std::cout << "Data was writen!";
		}
		else if (choise == 2)
		{
			CheckOutputFile(fout);
			OutputTurnArrayFile(fout, array, size);
			fin.close();
			fout.close();
			std::cout << "Data was writen!";
		}
		else
		{
			std::cout << "Wrong Choise!";
			return 0;
		}
	}
	else
	{
		std::cout << "Wrong Choise!";
		return 0;
	}
	return 0;
}