#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Перечисляемый тип
enum Gender { MALE = 0, FEMALE = 1 };

// Вложенная структура
struct Date {
    int day;
    int month;
    int year;
};

// Анкета ребенка (Вариант 11)
struct Child {
    char name[50];
    Gender gender;
    int height;
    Date birthDate;
};

// =========================================================
// ЗАДАНИЕ 1: Функция обновления данных из текстового файла
// =========================================================
void updateGenderFromTextFile(Child arr[], int size, const char* filename) {
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Ошибка: не удалось открыть текстовый файл " << filename << endl;
        return;
    }

    char tempName[50];
    int genderVal;

    // Считываем имя и пол (0 или 1) из файла построчно
    while (fin >> tempName >> genderVal) {
        // Ищем ребенка с таким же именем в массиве
        for (int i = 0; i < size; ++i) {
            if (strcmp(arr[i].name, tempName) == 0) {
                arr[i].gender = (Gender)genderVal; // Обновляем пол
                break; // Переходим к следующей строке файла
            }
        }
    }
    fin.close();
    cout << "Данные успешно обновлены из текстового файла.\n";
}

// Вспомогательная функция для вывода массива
void printArray(Child arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Фамилия: " << arr[i].name 
             << "\t| Пол: " << (arr[i].gender == MALE ? "Муж (0)" : "Жен (1)") 
             << "\t| Рост: " << arr[i].height 
             << "\t| Дата: " << arr[i].birthDate.day << "." 
             << arr[i].birthDate.month << "." 
             << arr[i].birthDate.year << endl;
    }
    cout << "--------------------------------------------------------\n";
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    const int SIZE = 4;
    // Инициализация массива. 
    // Намеренно поставим всем "Жен (1)", чтобы проверить, как файл обновит мальчиков.
    Child children[SIZE] = {
        {"Ivanov", FEMALE, 140, {15, 5, 2010}},
        {"Petrova", FEMALE, 135, {22, 8, 2011}},
        {"Sidorov", FEMALE, 142, {10, 12, 2010}},
        {"Smirnova", FEMALE, 138, {5, 3, 2012}}
    };

    cout << "--- Исходные данные массива ---\n";
    printArray(children, SIZE);

    // Выполнение Задания 1
    updateGenderFromTextFile(children, SIZE, "C:\\Users\\serge\\Desktop\\practica\\data.txt");
    
    cout << "\n--- Массив после чтения updates.txt ---\n";
    printArray(children, SIZE);

    return 0;
}