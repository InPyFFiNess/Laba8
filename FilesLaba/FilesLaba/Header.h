#pragma once
#include <iostream>
#include <fstream>

void CheckInputFile(std::ifstream&);
void CheckOutputFile(std::ofstream&);
void FillArrayFile(std::ifstream&, double*, int32_t);
void FillArrayConsole(double*, int32_t);
void OutputArrayFile(std::ostream&, double*, int32_t);
void OutputArrayConsole(double*, int32_t);
int32_t Counter(std::ifstream&);
void QuickSort(double*, int32_t, int32_t);
void InsertionSort(double*, int32_t);
void SelectionSort(double*, int32_t);
void MergeSort(double*, int32_t, int32_t);
void Merge(double*, int32_t, int32_t, int32_t);
void BubbleSort(double*, int32_t);
void OutputTurnArrayFile(std::ostream&, double*, int32_t);
void OutputTurnArrayConsole(double*, int32_t);
int32_t CountNumbersAfterPoint(double);
void FillArrayByNumAfterPoint(double*, int32_t);