#pragma once

#include <chrono>

class Date {
public:
    std::chrono::year_month_day date;

    Date() = delete;

public:
    explicit Date(const std::chrono::year_month_day &date);

    explicit Date(std::chrono::year_month_day &&date);

    Date(int year, unsigned month, unsigned day);

    void set_date(const std::chrono::year_month_day &date);

    void setYear(int year);

    void setMonth(unsigned month);

    void setDay(unsigned day);

    std::chrono::year_month_day getDate() const;

    int getYearAsValue() const;

    unsigned getMonthAsValue() const;

    unsigned getDayAsValue() const;

    static std::chrono::time_point<std::chrono::system_clock> getLocalTime();

    static int getLocalYearAsValue();

    static unsigned getLocalMonthAsValue();

    static unsigned getLocalDayAsValue();

    static int getLocalHourAsValue();

    static int getLocalMinuteAsValue();

    static int getLocalSecondAsValue();

    static Date parseStringToDate(const std::string &date);

    static std::string parseDateToString(const Date &date);

    static std::string parseTimePointToString(const std::chrono::system_clock::time_point &tp);

    static std::string getLocalTimeOfTheDayAsString();

    static void validateYear(int &year);

    static void validateMonth(unsigned &month);

    static void validateDay(int year, unsigned month, unsigned &day);

    bool operator==(const Date &other) const;

    bool operator!=(const Date &other) const;

    bool operator<=(const Date &other) const;

    bool operator>=(const Date &other) const;

    bool operator<(const Date &other) const;

    bool operator>(const Date &other) const;
};
