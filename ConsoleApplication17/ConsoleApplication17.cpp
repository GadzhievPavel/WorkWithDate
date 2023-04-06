// ConsoleApplication17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int month[12]{ 31,28,31,30,31,30,31,31,30,31,30,31 };
struct Date {
	int day;
	int month;
	int year;

	int getAllDays() {
		int days = day;
		for (int i = month - 2; i >= 0; i--) {
			days += ::month[i];
		}
		days += 365 * (year - 1);
		return days;
	}

	string info() {
		string str = "";
		if (day >= 10) {
			str.append(std::to_string(day));
		}
		else
		{
			str.append("0");
			str.append(std::to_string(day));
		}

		str.append(".");
		if (month >= 10) {
			str.append(std::to_string(month));
		}
		else {
			str.append("0");
			str.append(std::to_string(month));
		}
		str.append(".");
		str.append(std::to_string(year));

		str.append("    ");
		str.append(std::to_string(getAllDays()));
		return str;
	}
};
struct Task {
	string name;
	int prior;
	Date date;

	string info() {
		string str = "";
		str.append("Название: ");
		str.append(name);
		str.append("\n");
		str.append("Приоритет: ");
		str.append(std::to_string(prior));
		str.append("\n");
		str.append("Дата: ");
		str.append(date.info());
		str.append("\n");
		return str;
	}
};
string reversString(string s) {
	string res = "";
	for (int i = s.length() - 1; i > -1; i--) {
		res += s[i];
	}
	return res;
}
void bubbleSort(Task* arr, int n);

// Function to print an array
void printArray(Task* arr, int size);


int main()
{
	setlocale(LC_ALL, "RUS");
	Date date = { 1,1,2023 };
	Task task = { "проснуться", 1, { 1,1,2023 } };
	Task tasks[4] = {
		{ "проснуться", 1, { 15,4,2023 } },
		{ "проснуться", 1, { 7,4,2023 } },
		{ "проснуться", 1, { 1,4,2023 } },
		{ "проснуться", 1, { 24,4,2023 } }
	};
	//cout << task.info();
	printArray(tasks, 4);

	bubbleSort(tasks, 4);
	cout << endl << endl << endl;
	printArray(tasks, 4);

}

void printArray(Task* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i].info() << "\n\n";
	cout << endl;
}

void bubbleSort(Task* arr, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j].date.getAllDays() > arr[j + 1].date.getAllDays()) {
				swap(arr[j], arr[j + 1]);
			}

		}

	}

	// Last i elements are already
	// in place

}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
