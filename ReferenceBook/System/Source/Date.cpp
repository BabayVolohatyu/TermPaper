#include "../Headers/Date.h"


Date::Date(const std::chrono::year_month_day &date)
    : date{date} {
}

Date::Date(std::chrono::year_month_day &&date)
    : date{date} {
}

Date::Date(int year, int month, int day) {
    if (year < 0) {
        year = 2000;
    }
    if (month < 1 || month > 12) {
        month = 1;
    }
    if (day < 1 || day > 31) {
        day = 1;
    }
    date = std::chrono::year_month_day(
        std::chrono::year(year),
        std::chrono::month(month),
        std::chrono::day(day));
}

void Date::set_date(const std::chrono::year_month_day &date) {
    this->date = date;
}

void Date::setYear(int year) {
    if (year < 0) {
        year = 2000;
    }
    std::chrono::year_month_day newDate{
        std::chrono::year(year),
        date.month(),
        date.day(),
    };
    this->date = newDate;
}

void Date::setMonth(int month) {
    if (month < 1 || month > 12) {
        month = 1;
    }
    std::chrono::year_month_day newDate{
        date.year(),
        std::chrono::month(month),
        date.day(),
    };
    this->date = newDate;
}

void Date::setDay(int day) {
    if (day < 1 || day > 31) {
        day = 1;
    }
    std::chrono::year_month_day newDate{
        date.year(),
        date.month(),
        std::chrono::day(day)
    };
    this->date = newDate;
}

std::chrono::year_month_day Date::getDate() const {
    return this->date;
}

int Date::getYearAsValue() const {
    return static_cast<int>(date.year());
}

unsigned Date::getMonthAsValue() const {
    return static_cast<unsigned>(date.month());
}

unsigned Date::getDayAsValue() const {
    return static_cast<unsigned>(date.day());
}

std::chrono::time_point<std::chrono::system_clock> Date::getLocalTime() {
    return std::chrono::system_clock::now();
}

int Date::getLocalYearAsValue() {
    std::chrono::time_point<std::chrono::system_clock> localTime = getLocalTime();
    std::chrono::year_month_day localDate(
        std::chrono::floor<std::chrono::days>(localTime));
    return static_cast<int>(localDate.year());
}

unsigned Date::getLocalMonthAsValue() {
    std::chrono::time_point<std::chrono::system_clock> localTime = getLocalTime();
    std::chrono::year_month_day localDate(
        std::chrono::floor<std::chrono::days>(localTime));
    return static_cast<unsigned>(localDate.month());
}

unsigned Date::getLocalDayAsValue() {
    std::chrono::time_point<std::chrono::system_clock> localTime = getLocalTime();
    std::chrono::year_month_day localDate(
        std::chrono::floor<std::chrono::days>(localTime));
    return static_cast<unsigned>(localDate.day());
}
