#include "general.h"
#include "EnumMonth.h"

int main() {

	setlocale(LC_ALL, "");

	cout << "��������� Man" << endl;
	Man* men = new Man[]{
		new Man(new char[] {"�������_1"}, new char[] {"������� ��������_1"}, 20, new DateMan(30, Month::April, 2002)),
		new Man(new char[] {"�������_2"}, new char[] {"������� ��������_2"}, 41, new DateMan(12, Month::August, 1980)),
		new Man(new char[] {"�������_3"}, new char[] {"������� ��������_3"}, 20, new DateMan(30, Month::April, 2002)),
		new Man(new char[] {"�������_4"}, new char[] {"������� ��������_4"}, 20, new DateMan(30, Month::April, 2002)),
		new Man(new char[] {"�������_5"}, new char[] {"������� ��������_5"}, 20, new DateMan(30, Month::April, 2002)),
		new Man(new char[] {"�������_6"}, new char[] {"������� ��������_6"}, 20, new DateMan(30, Month::April, 2002)),
		new Man(new char[] {"�������_7"}, new char[] {"������� ��������_7"}, 20, new DateMan(30, Month::April, 2002)),
		new Man(new char[] {"�������_8"}, new char[] {"������� ��������_8"}, 20, new DateMan(30, Month::April, 2002)),
	};

	cout << "����� �� �������" << endl;
	Man* m = searchMan(searchForLastName, men, 8, new char[] {"������� ��������_8"});

	cout << m->getName() << " " << m->getLastName() << endl;

	cout << "����� �� �����" << endl;
	Man* m1 = searchMan(searchForName, men, 8, new char[] {"�������_4"});

	cout << m1->getName() << " " << m1->getLastName() << endl;

	//���������� �� �����

	sort_arr_man(sort_arr_name, men, 8);

	//���������� �� �������

	sort_arr_man(sort_arr_lastname, men, 8);

	return 0;
}

template<typename T>
inline T* dyn_arr_change(T* arr, size_t size, size_t nsize)
{
	bool ctrl = false;
	T* temp = new T[size];
	if (arr != NULL) {

		ctrl = true;
		for (size_t i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		arr = nullptr;
		delete[] arr;
	}

	arr = new T[nsize];
	if (ctrl) {
		for (size_t i = 0; i < size; i++) {
			arr[i] = temp[i];
		}
	}
	temp = nullptr;
	delete[] temp;
	return arr;
}


Man* searchMan(Man* (*sm)(Man*, size_t, char*), Man* arr, size_t size, char* name) {
    return sm(arr, size, name);
}

Man* searchForName(Man* arr, size_t size, char* name) {

	Man man;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i].getName(), name) == 0)
		{
			man = arr[i];
			break;
		}
	}

	return &man;
}

Man* searchForLastName(Man* arr, size_t size, char* lastname) {

	Man man;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i].getLastName(), lastname) == 0)
		{
			man = arr[i];
			break;
		}
	}

	return &man;
}

void lstBirthdayMen(Man* arr, size_t size, Month month) {

	for (size_t i = 0; i < size; i++) {
		if (arr[i].getDate().getMonth() == month) {
			arr[i].printInfoMan();
		}
	}
}

void sort_arr_man(void(*sort_arr)(Man*, size_t), Man* arr, size_t size) {
	sort_arr(arr, size);
}


void sort_arr_name(Man* arr, size_t size) {

		Man min = arr[0];
		for (size_t i = 0; i < size; i++) {

			for (size_t j = i + 1; j < size; j++) {
				if (strcmp(arr[j].getName(), arr[0].getName()) < 0) {
					min = arr[j];
					Man temp = arr[i];
					arr[i] = min;
					arr[j] = temp;
				}
			}
		}

}

void sort_arr_lastname(Man* arr, size_t size) {

	Man min = arr[0];
	for (size_t i = 0; i < size; i++) {

		for (size_t j = i + 1; j < size; j++) {
			if (strcmp(arr[j].getLastName(), arr[0].getLastName()) < 0) {
				min = arr[j];
				Man temp = arr[i];
				arr[i] = min;
				arr[j] = temp;
			}
		}
	}

}