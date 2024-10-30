#include <regex>

#include "../Headers/Date.h"


Date::Date(const std::chrono::year_month_day &date)
    : date{date} {
}

Date::Date(std::chrono::year_month_day &&date)
    : date{date} {
}

Date::Date(int year, unsigned month, unsigned day) {
    //перевірка правильності введених даних
    validateYear(year);
    validateMonth(month);
    validateDay(year, month, day);
    //переведення числових типів даних до типів даних часу
    date = std::chrono::year_month_day(
        std::chrono::year(year),
        std::chrono::month(month),
        std::chrono::day(day));
}

void Date::set_date(const std::chrono::year_month_day &newDate) {
    date = newDate;
}

void Date::setYear(int newYear) {
    validateYear(newYear);
    std::chrono::year_month_day newDate{
        std::chrono::year(newYear),
        date.month(),
        date.day(),
    };
    date = newDate;
}

void Date::setMonth(unsigned newMonth) {
    validateMonth(newMonth);
    std::chrono::year_month_day newDate{
        date.year(),
        std::chrono::month(newMonth),
        date.day(),
    };
    date = newDate;
}

void Date::setDay(unsigned newDay) {
    validateDay(getYearAsValue(), getMonthAsValue(), newDay);
    std::chrono::year_month_day newDate{
        date.year(),
        date.month(),
        std::chrono::day(newDay)
    };
    date = newDate;
}

std::chrono::year_month_day Date::getDate() const {
    return date;
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

int Date::getLocalHourAsValue() {
    // Отримуємо поточний час в форматі time_t (кількість секунд, що минули з 1 січня 1970 року).
    std::time_t now = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now());

    // Перетворюємо time_t у структуру tm, що містить локальний час.
    std::tm localTime = *std::localtime(&now);

    // Повертаємо годину з локального часу.
    return localTime.tm_hour;
}

int Date::getLocalMinuteAsValue() {
    // Отримуємо поточний час в форматі time_t.
    std::time_t now = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now());

    // Перетворюємо time_t у локальний час.
    std::tm localTime = *std::localtime(&now);

    // Повертаємо хвилину з локального часу.
    return localTime.tm_min;
}

int Date::getLocalSecondAsValue() {
    // Отримуємо поточний час в форматі time_t.
    std::time_t now = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now());

    // Перетворюємо time_t у локальний час.
    std::tm localTime = *std::localtime(&now);

    // Повертаємо секунду з локального часу.
    return localTime.tm_sec;
}

Date Date::parseStringToDate(const std::string &date) {
    // Визначаємо регулярний вираз для розпізнавання дат у форматах рррр.мм.дд і подібні
    std::regex date_regex(R"((\d{4})[./\-](\d{1,2})[./\-](\d{1,2}))");
    std::smatch matches;

    // Перевіряємо, чи рядок дати відповідає регулярному виразу
    if (std::regex_match(date, matches, date_regex)) {
        // Перетворюємо знайдені підрядки на цілі числа для року, місяця та дня
        int year = std::stoi(matches[1]);
        unsigned month = std::stoi(matches[2]);
        unsigned day = std::stoi(matches[3]);

        // Валідація року, місяця та дня
        validateYear(year);
        validateMonth(month);
        validateDay(year, month, day);
        return Date{year, month, day};
    }
    return Date{2000, 1, 1};
}


std::string Date::parseDateToString(const Date &date) {
    return std::to_string(date.getYearAsValue())
           + '/' + std::to_string(date.getMonthAsValue())
           + '/' + std::to_string(date.getDayAsValue());
}

std::string Date::parseTimePointToString(const std::chrono::system_clock::time_point &tp) {
    // Перетворюємо time_point у year_month_day, отримуючи лише рік, місяць і день
    std::chrono::year_month_day ymdTemp = std::chrono::floor<std::chrono::days>(tp);

    // Формуємо початкову частину рядка з днем
    std::string str = "Today is: " + std::to_string(static_cast<unsigned>(ymdTemp.day()));

    // Додаємо закінчення до дня
    switch (static_cast<unsigned>(ymdTemp.day())) {
        case 1:
            str += "st ";
            break;
        case 2:
            str += "nd ";
            break;
        case 3:
            str += "rd ";
            break;
        case 21:
            str += "st ";
            break;
        case 22:
            str += "nd ";
            break;
        case 23:
            str += "rd ";
            break;
        default:
            str += "th ";
            break;
    }

    str += "of ";

    // Додаємо назву місяця
    switch (static_cast<unsigned>(ymdTemp.month())) {
        case 1:
            str += "January ";
            break;
        case 2:
            str += "February ";
            break;
        case 3:
            str += "March ";
            break;
        case 4:
            str += "April ";
            break;
        case 5:
            str += "May ";
            break;
        case 6:
            str += "June ";
            break;
        case 7:
            str += "July ";
            break;
        case 8:
            str += "August ";
            break;
        case 9:
            str += "September ";
            break;
        case 10:
            str += "October ";
            break;
        case 11:
            str += "November ";
            break;
        case 12:
            str += "December ";
            break;
        default:
            break;
    }

    str += std::to_string(static_cast<int>(ymdTemp.year()));

    return str;
}


std::string Date::getLocalTimeOfTheDayAsString() {
    std::string str =
            ((getLocalHourAsValue() < 10) // Перевірка, чи години менше 10
                 ? '0' + std::to_string(getLocalHourAsValue()) // Якщо так, додаємо '0' перед годинами
                 : std::to_string(getLocalHourAsValue())) + // Інакше просто конвертуємо години в рядок
            ":" + // Додаємо роздільник між годинами і хвилинами
            ((getLocalMinuteAsValue() < 10) // Перевірка, чи хвилини менше 10
                 ? '0' + std::to_string(getLocalMinuteAsValue()) // Якщо так, додаємо '0' перед хвилинами
                 : std::to_string(getLocalMinuteAsValue())) + // Інакше конвертуємо хвилини в рядок
            ":" + // Додаємо роздільник між хвилинами і секундами
            ((getLocalSecondAsValue() < 10) // Перевірка, чи секунди менше 10
                 ? '0' + std::to_string(getLocalSecondAsValue()) // Якщо так, додаємо '0' перед секундами
                 : std::to_string(getLocalSecondAsValue())); // Інакше конвертуємо секунди в рядок

    return str;
}

void Date::validateYear(int &year) {
    if (year < 0) {
        year = 2000;
    } else if (year > 9999) {
        year = 9999;
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
        // Перевірка на дні для місяців з 30 днями
        day = 30;
    } else if (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7
                            || month == 8 || month == 10 || month == 12)) {
        // Перевірка на дні для місяців з 31 днем
        day = 31;
    } else if (day > 29 && month == 2 && year % 4 == 0) {
        // Перевірка на дні для лютого у високосний рік
        day = 29;
    } else if (day > 28 && month == 2 && year % 4 != 0) {
        // Перевірка на дні для лютого у невисокосний рік
        day = 28;
    }
}

bool Date::operator==(const Date &other) const {
    return date.month() == other.date.month() && date.day() == other.date.day();
}

bool Date::operator!=(const Date &other) const {
    return date.month() != other.date.month() || date.day() != other.date.day();
}

bool Date::operator<=(const Date &other) const {
    return (date.month() == other.date.month()) ? date.day() <= other.date.day() : date.month() <= other.date.month();
}

bool Date::operator>=(const Date &other) const {
    return (date.month() == other.date.month()) ? date.day() >= other.date.day() : date.month() >= other.date.month();
}

bool Date::operator<(const Date &other) const {
    return (date.month() == other.date.month()) ? date.day() < other.date.day() : date.month() < other.date.month();;
}

bool Date::operator>(const Date &other) const {
    return (date.month() == other.date.month()) ? date.day() > other.date.day() : date.month() > other.date.month();;
}
