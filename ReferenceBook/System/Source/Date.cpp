#include <regex>

#include "../Headers/Date.h"


Date::Date(const std::chrono::year_month_day &date)
    : date{date} {
}

Date::Date(std::chrono::year_month_day &&date)
    : date{date} {
}

Date::Date(int year, unsigned month, unsigned day) {
    validateYear(year);
    validateMonth(month);
    validateDay(year, month, day);
    date = std::chrono::year_month_day(
        std::chrono::year(year),
        std::chrono::month(month),
        std::chrono::day(day));
}

void Date::set_date(const std::chrono::year_month_day &date) {
    this->date = date;
}

void Date::setYear(int year) {
    validateYear(year);
    std::chrono::year_month_day newDate{
        std::chrono::year(year),
        date.month(),
        date.day(),
    };
    this->date = newDate;
}

void Date::setMonth(unsigned month) {
    validateMonth(month);
    std::chrono::year_month_day newDate{
        date.year(),
        std::chrono::month(month),
        date.day(),
    };
    this->date = newDate;
}

void Date::setDay(unsigned day) {
    validateDay(getYearAsValue(), getMonthAsValue(), day);
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

Date Date::parseStringToDate(const std::string &date) {
    std::regex date_regex(R"((\d{4})[./\-](\d{1,2})[./\-](\d{1,2}))");
    std::smatch matches;

    if (std::regex_match(date, matches, date_regex)) {
        int year = std::stoi(matches[1]);
        unsigned month = std::stoi(matches[2]);
        unsigned day = std::stoi(matches[3]);
        validateYear(year);
        validateMonth(month);
        validateDay(year, month, day);
        return Date{year, month, day};
    } else {
        return Date{2000, 1, 1};
    }
}

std::string Date::parseDateToString(const Date &date) {
    return std::to_string(date.getYearAsValue())
                          + '/' + std::to_string(date.getMonthAsValue())
                          + '/' + std::to_string(date.getDayAsValue());
}

void Date::validateYear(int &year) {
    if (year < 0) {
        year = 2000;
    }
}

void Date::validateMonth(unsigned &month) {
    if (month < 1 || month > 12) {
        month = 1;
    }
}

void Date::validateDay(int year, unsigned month, unsigned &day) {
    if (day < 1) {
        day = 1;
    } else if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
        day = 30;
    } else if (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7
               || month == 8 || month == 10 || month == 12)) {
        day = 31;
    } else if (day > 29 && month == 2 && year % 4 == 0) {
        day = 29;
    } else if (day > 28 && month == 2 && year % 4 != 0) {
        day = 28;
    }
}

bool Date::operator==(const Date &other) const {
    return date == other.date;
}

bool Date::operator!=(const Date &other) const {
    return date != other.date;
}

bool Date::operator<(const Date &other) const {
    return date < other.date;
}

bool Date::operator>(const Date &other) const {
    return date > other.date;
}
