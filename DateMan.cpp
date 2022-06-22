#include "general.h"

DateMan::DateMan()
{
	this->day = 0;
	this->month = Month::None;
	this->year = 0;
}

DateMan::DateMan(DateMan& date)
{
	this->day = date.day;
	this->month = date.month;
	this->year = date.year;
}

DateMan::DateMan(int day, Month month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

void DateMan::printDate()
{
	cout << "Дата: " << this->day << "." << this->month << "." << this->year;
}

void DateMan::setDay(int day)
{
	this->day = day;
}

void DateMan::setMonth(Month month)
{
	this->month = month;
}

void DateMan::setYear(int year)
{
	this->year = year;
}

int DateMan::getDay()
{
	return this->day;
}

int DateMan::getMonth()
{
	return this->month;
}

int DateMan::getYear()
{
	return this->year;
}


DateMan::~DateMan()
{
}
