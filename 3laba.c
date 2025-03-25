#include <stdio.h>
#include "functions.h"

int main() {
    int choice;

    do {
        printf("\nSelect a program to run:\n"); // printf("\nВыберите программу для запуска:\n");
        printf("1. Decrease the number by 4 times\n"); // printf("1. Уменьшение числа в 4 раза\n");
        printf("2. Working with an array of students\n"); // printf("2. Работа с массивом студентов\n");
        printf("3. Exit\n"); // printf("3. Выход\n");
        printf("Your choice: "); // printf("Ваш выбор: ");
        
        char buffer[10]; // Буфер для хранения ввода
        int isValidInput = 0; // Флаг для проверки корректности ввода
        
        while (!isValidInput) {
            if (scanf("%9s", buffer) == 1) { // Ограничиваем ввод до 9 символов
                char *endptr;
                choice = strtol(buffer, &endptr, 10); // Преобразуем строку в число
                
                if (*endptr == '\0') { // Проверяем, что весь ввод корректен
                    isValidInput = 1; // Устанавливаем флаг корректности
                } else {
                    printf("Incorrect input. Please enter a valid number: "); // Сообщение об ошибке
                }
            } else {
                printf("Input error. Try again: "); // Ошибка при вводе
            }
    
            while (getchar() != '\n'); // Очистка буфера ввода
        }
        
        switch (choice) {
            case 1:
                runProgram1(); // Запуск программы 1
                break;
            case 2:
                runProgram2(); // Запуск программы 2
                break;
            case 3:
                printf("Exit the program.\n"); // printf("Выход из программы.\n");
                break;
            default:
                printf("Incorrect input. Please try again.\n"); // printf("Некорректный ввод. Попробуйте снова.\n");
        }
    } while (choice != 3);
}
    
    