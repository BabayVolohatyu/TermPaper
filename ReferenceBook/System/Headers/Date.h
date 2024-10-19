#pragma once

#include <chrono>

class Date {
public:
    std::chrono::year_month_day date;

    Date() = delete;

public:
    explicit Date(const std::chrono::year_month_day &date);

    explicit Date(std::chrono::year_month_day &&date);

    Date(int year, int month, int day);

    void set_date(const std::chrono::year_month_day& date);

    void setYear(int year);

    void setMonth(int month);

    void setDay(int day);

    std::chrono::year_month_day getDate() const;

    int getYearAsValue() const;

    unsigned getMonthAsValue() const;

    unsigned getDayAsValue() const;

    static std::chrono::time_point<std::chrono::system_clock> getLocalTime();

    static int getLocalYearAsValue();

    static unsigned getLocalMonthAsValue();

    static unsigned getLocalDayAsValue();



};
