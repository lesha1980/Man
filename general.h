#pragma once


/*
системні бібліотеки
*/

#include <iostream>
#include <string.h>
#include <ctime>
#include <conio.h>


/*
підключення кастомні
*/

#include "DateMan.h"
#include "Man.h"
using namespace std;
/*
Прототипи функцій
*/

template<typename T> T* dyn_arr_change(T*, size_t, size_t);

void sort_arr_man(void(*sort_arr)(Man*, size_t), Man*, size_t);
void sort_arr_name(Man*, size_t);
void sort_arr_lastname(Man*, size_t);
void lstBirthdayMen(Man*, size_t, Month);
Man* searchForName(Man*, size_t, char*);
Man* searchForLastName(Man*, size_t, char*);
Man* searchMan(Man* (*sm)(Man*, size_t, char*), Man*, size_t, char*);


