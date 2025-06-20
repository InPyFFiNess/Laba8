#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Header.h"

void CheckInputFile(std::ifstream& fin)
{
	if (!fin.good())
	{
		throw "file isn't exsist\n";
	}
	if (!fin)
	{
		throw "input file error\n";
	}
	if (fin.peek() == EOF)
	{
		throw "File is empty!\n";
	}
}

void CheckOutputFile(std::ofstream& fout)
{
	if (!fout.good())
	{
		throw "file isn't exsist\n";
	}
	if (!fout)
	{
		throw "input file error\n";
	}
}

void FillArrayFile(std::ifstream& fin, double* array, int32_t size)
{
	fin.clear();
	fin.seekg(0);
	double temp{};
	for (size_t i = 0; i < size; ++i)
	{
		fin >> temp;
		array[i] = temp;
	}
}

void FillArrayConsole(double *array, int32_t size)
{
	std::cout << "Input your array: ";
	for (size_t i = 0; i < size; ++i)
	{
		std::cin >> array[i];
	}
}

void OutputArrayFile(std::ostream& fout, double* array, int32_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		fout << array[i] << " ";
	}
}

void OutputArrayConsole(double* array, int32_t size)
{
	std::cout << "Your array: ";
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << array[i] << " ";
	}
}

int32_t Counter(std::ifstream& fin)
{
	int32_t counter{};
	double number{};
	while (fin >> number)
	{
		++counter;
	}
	return counter;
}

void QuickSort(double* array, int32_t left, int32_t right)
{
	double pivot = array[(left+right) / 2];
	int32_t i = left;
	int32_t j = right;
	while (i <= j)
	{
		while (array[i] < pivot)
		{
			++i;
		}
		while (array[j] > pivot)
		{
			--j;
		}
		if (i <= j)
		{
			std::swap(array[i], array[j]);
			++i;
			--j;
		}
		QuickSort(array, left, j);
		QuickSort(array, i, right);
	}
}

void InsertionSort(double* array, int32_t size)
{
	for (size_t i = 1; i < size; ++i)
	{
		double key = array[i];
		int32_t j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
}

void SelectionSort(double* array, int32_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		int32_t minIndex = i;
		for (size_t j = i + 1; j < size; ++j)
		{
			if (array[j] < array[minIndex])
			{
				minIndex = j;
			}
		}
		std::swap(array[i], array[minIndex]);
	}
}


void BubbleSort(double* array, int32_t size)
{
	for (size_t i = 0; i < size - 1; ++i)
	{
		for (size_t j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}

void Merge(double* array, int32_t left, int32_t mid, int32_t right)
{
	int32_t leftIndex = mid - left + 1;
	int32_t rightIndex = right - mid;
	double* leftArray = new double[leftIndex];
	double* rightArray = new double[rightIndex];
	for (size_t i = 0; i < leftIndex; ++i)
	{
		leftArray[i] = array[left + i];
	}
	for (size_t j = 0; j < rightIndex; ++j)
	{
		rightArray[j] = array[mid + 1 + j];
	}
	int32_t i = 0;
	int32_t j = 0;
	int32_t k = left;
	while (i < leftIndex && j < rightIndex)
	{
		if (leftArray[i] <= rightArray[j])
		{
			array[k] = leftArray[i];
			++i;
		}
		else
		{
			array[k] = rightArray[j];
			++j;
		}
		++k;
	}
	while (i < leftIndex)
	{
		array[k] = leftArray[i];
		++i;
		++k;
	}
	while (j < rightIndex)
	{
		array[k] = rightArray[j];
		++j;
		++k;
	}
	delete[] leftArray;
	delete[] rightArray;
}

void MergeSort(double* array, int32_t left, int32_t right)
{
	if (left < right)
	{
		int32_t mid = left + (right - left) / 2;
		MergeSort(array, left, mid);
		MergeSort(array, mid + 1, right);
		Merge(array, left, mid, right);
	}
}

void OutputTurnArrayFile(std::ostream& fout, double* array, int32_t size)
{
	for (int32_t i = size - 1; i > -1; --i)
	{
		fout << array[i] << " ";
	}
}

void OutputTurnArrayConsole(double* array, int32_t size)
{
	std::cout << "Your array: ";
	for (int32_t i = size - 1; i >= 0; --i)
	{
		std::cout << array[i] << " ";
	}
}

int32_t CountNumbersAfterPoint(double number)
{
	std::string numToStr = std::to_string(number);
	int32_t pointPos = numToStr.find('.');
	return numToStr.length() - pointPos - 1;
}

void FillArrayByNumAfterPoint(double* array, int32_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		array[i] = CountNumbersAfterPoint(array[i]);
	}
}