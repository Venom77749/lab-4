#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time {
private:
    short int hours;
    short int minutes;

    // Проверка корректности времени
    void validateTime();

public:
    // Конструкторы
    Time();
    Time(short int h, short int m);
    Time(const Time& t); // Копирования

    // Метод вычитания времени
    Time subtract(const Time& t) const;

    // Перегрузка операторов ввода/вывода
    friend ostream& operator<<(ostream& out, const Time& t);
    friend istream& operator>>(istream& in, Time& t);

    // Унарные операции
    Time& operator++(); // Префиксный ++
    Time operator++(int); // Постфиксный ++
    Time& operator--(); // Префиксный --
    Time operator--(int); // Постфиксный --

    // Преобразования типов
    operator int() const; // Неявное преобразование в int
    explicit operator bool() const; // Явное преобразование в bool

    // Бинарные операции
    bool operator<(const Time& t) const;
    bool operator>(const Time& t) const;
};

#endif // TIME_H
