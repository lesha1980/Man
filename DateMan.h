#pragma once
#include "EnumMonth.h"

struct DateMan {

private:
	int day;
	Month month;
	int year;
public:
	DateMan();
	DateMan(DateMan&);
	DateMan(int, Month, int);

	void printDate();
	void setDay(int);
	void setMonth(Month);
	void setYear(int);
	int getDay();
	int getMonth();
	int getYear();


	~DateMan();
};