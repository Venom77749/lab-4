#include "Time.h"

// Конструкторы
Time::Time() : hours(0), minutes(0) {}

Time::Time(short int h, short int m) : hours(h), minutes(m) {
    validateTime();
}

Time::Time(const Time& t) : hours(t.hours), minutes(t.minutes) {}

// Метод вычитания времени
Time Time::subtract(const Time& t) const {
    int totalMinutes1 = hours * 60 + minutes;
    int totalMinutes2 = t.hours * 60 + t.minutes;
    int resultMinutes = (totalMinutes1 - totalMinutes2 + 1440) % 1440; // Учёт перехода на предыдущие сутки

    return Time(resultMinutes / 60, resultMinutes % 60);
}

// Проверка корректности времени
void Time::validateTime() {
    if (minutes >= 60) {
        hours += minutes / 60;
        minutes %= 60;
    }
    if (minutes < 0) {
        hours -= 1 + (-minutes) / 60;
        minutes = 60 - (-minutes) % 60;
    }
    if (hours >= 24) {
        hours %= 24;
    }
    if (hours < 0) {
        hours = 24 - (-hours) % 24;
    }
}

// Перегрузка операторов ввода/вывода
ostream& operator<<(ostream& out, const Time& t) {
    out << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes;
    return out;
}

istream& operator>>(istream& in, Time& t) {
    cout << "Введите часы (0-23): ";
    in >> t.hours;
    cout << "Введите минуты (0-59): ";
    in >> t.minutes;
    t.validateTime();
    return in;
}

// Унарные операции
Time& Time::operator++() { // Префиксный ++
    minutes++;
    validateTime();
    return *this;
}

Time Time::operator++(int) { // Постфиксный ++
    Time temp = *this;
    ++(*this);
    return temp;
}

Time& Time::operator--() { // Префиксный --
    minutes--;
    validateTime();
    return *this;
}

Time Time::operator--(int) { // Постфиксный --
    Time temp = *this;
    --(*this);
    return temp;
}

// Преобразования типов
Time::operator int() const { // Неявное преобразование в int
    return hours * 60 + minutes;
}

Time::operator bool() const { // Явное преобразование в bool
    return hours != 0 || minutes != 0;
}

// Бинарные операции
bool Time::operator<(const Time& t) const {
    return int(*this) < int(t);
}

bool Time::operator>(const Time& t) const {
    return int(*this) > int(t);
}

