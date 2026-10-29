#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <windows.h>

using namespace std;

int main() {
    // Принудительно переключаем консоль в кодировку UTF-8
    system("chcp 65001 > nul");

    // Настройки для корректного отображения русского языка
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, "Russian");

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // Загадываем число от 1 до 100
    int secretNumber = 1 + rand() % 100;
    int userGuess;
    int attempts = 0;
    bool isGuessed = false;

    cout << "=== Игра 'Угадай число' ===" << endl;
    cout << "Я загадал число от 1 до 100." << endl;
    cout << "Попробуй угадать! (Для выхода введи 0)" << endl;
    cout << endl;

    while (!isGuessed) {
        cout << "Твой вариант: ";

        // Проверка на корректный ввод (чтобы не было бесконечного цикла при вводе букв)
        if (!(cin >> userGuess)) {
            cout << "Ошибка! Введи целое число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; // Возвращаемся в начало цикла
        }

        // Условие выхода из программы
        if (userGuess == 0) {
            cout << "Вы вышли из игры. Загаданное число было: " << secretNumber << endl;
            break;
        }

        attempts++; // Считаем попытку

        if (userGuess == secretNumber) {
            cout << endl;
            cout << "Поздравляю! Ты угадал число " << secretNumber << "!" << endl;
            cout << "Ты потратил(а) на это " << attempts << " попыток." << endl;
            isGuessed = true;
        }
        else if (userGuess > secretNumber) {
            cout << "Твое число БОЛЬШЕ загаданного. Попробуй еще раз." << endl;
        }
        else {
            cout << "Твое число МЕНЬШЕ загаданного. Попробуй еще раз." << endl;
        }
        cout << endl;
    }

    return 0;
}
