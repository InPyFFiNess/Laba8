#include <iostream>
#include <string>
#include <fstream>

struct Student {
    std::string name{};
    std::string surname{};
    int32_t cours{};
    std::string group{};
    int32_t marks[5];

};

void NumberStudent(int32_t&);
void StudentArray(Student*&, int32_t);
void InputArrayStudent(Student*&, int32_t);
double AverageScore(int32_t, int32_t);
void SortStudent(Student*&, int32_t);
void OutputSortStudent(Student*&, int32_t);
void DeleteArray(Student*&);

int main() {
    Student* student{};
    int32_t numberStudent{};
    try {
        NumberStudent(numberStudent);
        StudentArray(student, numberStudent);
        InputArrayStudent(student, numberStudent);
        SortStudent(student, numberStudent);
        OutputSortStudent(student, numberStudent);
        DeleteArray(student);
    }
    catch (const std::invalid_argument& e) {
        std::cout << '\n' << e.what() << '\n';
    }
    catch (const std::bad_alloc& e) {
        std::cout << '\n' << "Data Error!";
    }


    return 0;
}
void NumberStudent(int32_t& numberStudent) {
    std::cout << '\n' << "Input number of student:";
    std::cin >> numberStudent;
    if (numberStudent <= 0) {
        throw std::invalid_argument("Error number of students!");
    }
}
void StudentArray(Student*& student, int32_t numberStudent) {
    student = new Student[numberStudent];
}
void InputArrayStudent(Student*& student, int32_t numberStudent) {
    for (int32_t i = 0; i < numberStudent; ++i) {
        std::cout << '\n' << "Input name of " << i + 1 << " student:";
        std::cin >> student[i].name;
        std::cout << '\n' << "Input surname of " << i + 1 << " student:";
        std::cin >> student[i].surname;
        std::cout << '\n' << "Input course of " << i + 1 << " student:";
        std::cin >> student[i].cours;
        std::cout << '\n' << "Input group of " << i + 1 << " student:";
        std::cin >> student[i].group;
        for (int32_t j = 0; j < 5; ++j) {
            std::cout << '\n' << "Input" << j + 1 << " mark of " << i + 1 << "student:";
            std::cin >> student[i].marks[j];
        }
    }
}

double AverageScore(int32_t number[], int32_t size) {
    int32_t sum{};
    for (int32_t i = 0; i < size; ++i) {
        sum += number[i];
    }
    return sum / 5;
}
void SortStudent(Student*& student, int32_t numberStudent) {
    for (int32_t i = 0; i < numberStudent - 1; ++i) {
        int32_t min = i;
        for (int32_t j = i + 1; j < numberStudent; ++j) {
            if (AverageScore(student[j].marks, 5) < AverageScore(student[min].marks, 5)) {
                min = j;
            }
        }
        if (min != i) {
            std::swap(student[i], student[min]);
        }
    }
}
void OutputSortStudent(Student*& student, int32_t numberStudent) {
    std::cout << '\n' << "Top students: ";
    for (int32_t i = 0; i < numberStudent; ++i) {
        std::cout << '\n' << "Top " << i + 1;
        std::cout << student[i].name << " " << student[i].surname << " " << "(" << student[i].group << ")" << '\n';
        std::cout << "Avarge mark:" << AverageScore(student[i].marks, 5);
    }
}
void DeleteArray(Student*& student) {
    delete[] student;
}