/* Написать программу, которая выводит на экран таблицу стоимости, например, яблок 
в диапазоне от 100 г до 1 кг с шагом 100 г. */

#include <iostream>
#include <clocale>  // для кириллицы

using std::cout; using std::cin; using std::endl;

namespace constants
{
	const unsigned short gramms_in_one_kg = 1000;
	const unsigned short difference_in_weight = 100;
}

// получаем от пользователя положительное число
double get_number()
{
	double answer;
	cin >> answer;
	while (cin.fail() || (answer < 0))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Вы ввели нечто некорректное, введите целое положительное число: ";
		cin >> answer;
	}
	return answer;
}

void price_for_each_100g(double price_for_1kg)
{
	const double price_for_one_gramm = price_for_1kg / constants::gramms_in_one_kg;
	cout << "Вес     Стоимость" << endl << "(г)      (руб.) " << endl;
	for (unsigned short each_weight = constants::difference_in_weight; each_weight < constants::gramms_in_one_kg; each_weight += constants::difference_in_weight)
		cout << each_weight << "       " << each_weight * price_for_one_gramm << endl;
	cout << endl;
}

int main()
{
	setlocale(LC_CTYPE, "rus"); // для вывода сообщений на кириллице

	while (true)
	{
		cout << "Введите цену за 1 килограмм: ";
		price_for_each_100g(get_number());
	}
	return 0;
}