#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATE 11
#define MAX_SURNAME 50

// Структура для программы 2
typedef struct {
    int id;                     // Номер зачётки
    char surname[MAX_SURNAME];  // Фамилия
    char enrollmentDate[MAX_DATE]; // Дата зачисления
    float avgGrade;             // Средний балл
} Student;

// Прототипы функций для программы 1
int reduce_by_four(int number);
int correct_choice(int task);

// Прототипы функций для программы 2
int isValidId(int id);
int isValidSurname(const char *surname);
int isValidDate(const char *date);
int isValidGrade(float grade);

void inputStudent(Student *student);
void outputStudent(const Student *student);
void findBySurname(Student *students, int count, const char *surname);
void deleteById(Student **students, int *count, int threshold);
void menu(Student **students, int *count);

// Общие функции запуска программ
void runProgram1();
void runProgram2();

#endif // FUNCTIONS_H