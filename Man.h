#pragma once
#include "DateMan.h"

struct Man {

private:
	char* last_name;
	char* name;
	int age;
	DateMan date_birth;

public:

	Man();
	Man(Man&);
	Man(Man*);
	Man(char*, char*, int, DateMan*);

	void setLastName(char*);
	void setName(char*);
	void setAge(int);
	void setDate(DateMan);

	char* getLastName();
	char* getName();
	int getAge();
	DateMan getDate();

	void printInfoMan();


	~Man();
};