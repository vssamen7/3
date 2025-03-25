#include "functions.h"

// Реализация функций для программы 1
int reduce_by_four(int number) {
    return number >> 2; // Сдвиг вправо на 2 позиции
}

int correct_choice(int task) {
    while (1) {
        char b;
        if (scanf("%d%c", &task, &b) == 2 && b == '\n') {
            break;
        } else {
            printf("Incorrect input. Please try again."); //printf("Некорректный ввод. Попробуйте снова: ");
            while (getchar() != '\n'); // Очистка буфера ввода
        }
    }
    return task;
}

// Реализация функций для проверки корректности данных (программа 2)
int isValidId(int id) {
    return id > 0;
}

int isValidSurname(const char *surname) {
    for (int i = 0; surname[i] != '\0'; i++) {
        if (!isalpha((unsigned char)surname[i])) return 0;
    }
    return 1;
}

int isValidDate(const char *date) {
    if (strlen(date) != 10 || date[2] != '.' || date[5] != '.') return 0;
    for (int i = 0; i < 10; i++) {
        if ((i == 2 || i == 5) && date[i] == '.') continue;
        if (!isdigit(date[i])) return 0;
    }
    return 1;
}

int isValidGrade(float grade) {
    return grade >= 0 && grade <= 10;
}

// Функции работы со студентами (программа 2)
void inputStudent(Student *student) {
    do {
        printf("Enter your record book number: ");// printf("Введите номер зачётки: ");
        scanf("%d", &student->id);
        if (!isValidId(student->id)) printf("Ошибка: номер зачётки должен быть положительным.\n");
    } while (!isValidId(student->id));

    do {
        printf("Enter your last name: "); //printf("Введите фамилию: ");
        scanf("%s", student->surname);
        if (!isValidSurname(student->surname)) printf("Error: The last name must contain only letters.\n"); //printf("Ошибка: фамилия должна содержать только буквы.\n")
    } while (!isValidSurname(student->surname));

    do {
        printf("Enter the date of crediting (DD.MM.YYYY): "); //printf("Введите дату зачисления (ДД.ММ.ГГГГ): ")
        scanf("%s", student->enrollmentDate);
        if (!isValidDate(student->enrollmentDate)) printf("Error: Invalid date.\n");//printf("Ошибка: некорректная дата.\n")
    } while (!isValidDate(student->enrollmentDate));

    do {
        printf("Enter your average score: ");// printf("Введите средний балл: ")
        scanf("%f", &student->avgGrade);
        if (!isValidGrade(student->avgGrade)) printf("Error: The average score must be between 0 and 10.\n");//printf("Ошибка: средний балл должен быть от 0 до 10.\n")
    } while (!isValidGrade(student->avgGrade));
}

void outputStudent(const Student *student) {
    printf("\nRecord book number: %d\n", student->id);//printf("\nНомер зачётки: %d\n", student->id);
    printf("Surname: %s\n", student->surname);// printf("Фамилия: %s\n", student->surname);
    printf("Date of enrollment: %s\n", student->enrollmentDate);// printf("Дата зачисления: %s\n", student->enrollmentDate);
    printf("Average score: %.2f\n", student->avgGrade);//printf("Средний балл: %.2f\n", student->avgGrade);
}


void findBySurname(Student *students, int count, const char *surname) {
    int found = 0;
    for (int i = 0; i < count; ++i) {
        if (strcmp(students[i].surname, surname) == 0) {
            outputStudent(&students[i]);
            found = 1;
        }
    }
    if (!found) printf("\nStudents with the last name \"%s\" not found.\n", surname);//printf("\nСтуденты с фамилией \"%s\" не найдены.\n", surname)
}

void deleteById(Student **students, int *count, int threshold) {
    for (int i = 0; i < *count;) {
        if ((*students)[i].id < threshold) {
            for (int j = i; j < *count - 1; ++j) {
                (*students)[j] = (*students)[j + 1];
            }
            --(*count);
            *students = realloc(*students, (*count) * sizeof(Student));
            if (*students == NULL && *count > 0) {
                printf("Memory allocation error.\n");//printf("Ошибка выделения памяти.\n");
                exit(1);
            }
        } else {
            ++i;
        }
    }
}

void menu(Student **students, int *count) {
    int choice;
    do {
        printf("\nMenu:\n");//printf("\nМеню:\n");
        printf("1. Add a student\n");// printf("1. Добавить студента\n");
        printf("2. Bring out all students\n");//printf("2. Вывести всех студентов\n");
        printf("3. Find students by last name\n");//printf("3. Найти студентов по фамилии\n");
        printf("4. Remove students with a record book number less than the specified one\n");//printf("4. Удалить студентов с номером зачётки меньше заданного\n");
        printf("5. Exit\n");//printf("5. Выйти\n");
        printf("Your choice: ");// printf("Ваш выбор: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                *count += 1;
                *students = realloc(*students, (*count) * sizeof(Student));
                if (*students == NULL) {
                    printf("Memory allocation error.\n");//printf("Ошибка выделения памяти.\n");
                    exit(1);
                }
                inputStudent(&(*students)[*count - 1]);
                break;
            case 2:
                for (int i = 0; i < *count; ++i) outputStudent(&(*students)[i]);
                break;
            case 3: {
                char surname[MAX_SURNAME];
                printf("Enter last name to search: ");//printf("Введите фамилию для поиска: ");
                scanf("%s", surname);
                findBySurname(*students, *count, surname);
                break;
            }
            case 4: {
                int threshold;
                printf("Enter the threshold for the record book number: ");//printf("Введите порог для номера зачётки: ");
                scanf("%d", &threshold);
                deleteById(students, count, threshold);
                break;
            }
            case 5:
                printf("Exit the program.\n");//printf("Выход из программы.\n");
                break;
            default:
                printf("Incorrect input. Please try again.\n");//printf("Некорректный ввод. Попробуйте снова.\n");
        }
    } while (choice != 5);
}

// Общие функции запуска программ
void runProgram1() {
    int number, result;

    printf("Enter an integer: ");//printf("Введите целое число: ")
    number = correct_choice(0); // Проверка ввода

    result = reduce_by_four(number); // Уменьшение числа

    printf("Number reduced by 4 times: %d\n", result);//printf("Число, уменьшенное в 4 раза: %d\n", result);
}

void runProgram2() {
    Student *students = NULL;
    int count = 0;

    menu(&students, &count);

    free(students); // Освобождение памяти
}