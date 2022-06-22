#include "general.h"

Man::Man()
{
	this->age = 0;
	this->last_name = nullptr;
	this->name = nullptr;
	this->date_birth = DateMan();
}

Man::Man(Man& man)
{
	this->age = man.getAge();
	this->date_birth = man.getDate();
	this->last_name = new char[strlen(man.getLastName())];
	strcpy_s(this->last_name, strlen(man.getLastName()) + 1, man.getLastName());
	this->name = new char[strlen(man.getName())];
	strcpy_s(this->name, strlen(man.getName()) + 1, man.getName());
}

Man::Man(Man* man)
{
	this->age = man->getAge();
	this->date_birth = man->getDate();
	this->last_name = new char[strlen(man->getLastName())];
	strcpy_s(this->last_name, strlen(man->getLastName()) + 1, man->getLastName());
	this->name = new char[strlen(man->getName())];
	strcpy_s(this->name, strlen(man->getName()) + 1, man->getName());
}

Man::Man(char* last_name, char* name, int age, DateMan* date)
{
	this->age = age;
	this->date_birth.setDay(date->getDay());
	this->date_birth.setMonth((Month)date->getMonth());
	this->date_birth.setYear(date->getYear());
	this->last_name = new char[strlen(last_name)];
	strcpy_s(this->last_name, strlen(last_name), last_name);
	this->name = new char[strlen(name)];
	strcpy_s(this->name, strlen(name), name);
}

void Man::setLastName(char* last_name)
{
	if (this->last_name != NULL)
	{
		delete[] this->last_name;
	}

	this->last_name = new char[strlen(last_name)];
	strcpy_s(this->last_name, strlen(last_name), last_name);
}

void Man::setName(char* name)
{
	if (this->name != NULL)
	{
		delete[] this->name;
	}
	this->name = new char[strlen(name)];
	strcpy_s(this->name, strlen(name), name);
}

void Man::setAge(int age)
{
	this->age = age;
}

void Man::setDate(DateMan date_birth)
{
	this->date_birth = date_birth;
}

char* Man::getLastName()
{
	return this->last_name;
}

char* Man::getName()
{
	return this->name;
}

int Man::getAge()
{
	return this->age;
}

DateMan Man::getDate()
{
	return this->date_birth;
}

void Man::printInfoMan()
{
	cout << "Дані про людину" << endl;
	cout << "Прізвище та ім'я : " << this->last_name << " " << this->name << endl;
	cout << "Дата народження : ";
	this->date_birth.printDate();
	cout << endl;
	cout << "Вік: " << this->age << endl;
}

Man::~Man()
{
	this->last_name = nullptr;
	delete[] this->last_name;
	this->name = nullptr;
	delete[] this->name;
}
