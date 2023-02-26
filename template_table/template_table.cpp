/*
Задача 2. Таблица

Нужно написать шаблонный класс для двумерного массива (таблицы).
Все ячейки таблицы имеют один и тот же тип данных T.

Требования к классу:

Должен быть конструктор, получающий на входе два целых числа — количество строк и
столбцов соответственно.
Должны быть константная и неконстантная версии оператора [],
возвращающего массив, к которому снова можно применить оператор [].
Нужно, чтобы работали конструкции вида:
* cout << table[i][j]; * table[i][j] = value;.

Должна быть константная функция Size, возвращающая размер таблицы.
*/

#include <iostream>
#include <vector>

template <class T>
class Table
{
private:
	T** elem;
	int sz;
	int _row;
public:
	Table(const Table&) = delete;
	Table& operator = (const Table&) = delete;
	Table(int row, int col) : _row(row) // про выброс исключения в случае значений < 0, в задаче нет указаний
	{
		elem = new T* [row];
		for (int k = 0; k < row; k++)
		{
			elem[k] = new T[col];
		}
		sz = sizeof(T) * row * col;
	}
	~Table()
	{
		for (int i = 0; i < _row; i++)
		{
			delete[] elem[i];
		}
		delete elem;
	}

	T* operator[] (int i)
	{
		return elem[i];
	}
	T& operator[] (int i) const
	{
		return elem[i];
	}

	int size() const 
	{
		return sz;
	}
};


int main()
{
	auto table = Table<int>(2, 10);
	table[0][1] = 5;
	table[1][2] = 222;
	std::cout << table[0][1] << '\n';
	std::cout << table[1][2] << '\n';
	std::cout << table.size() << '\n';

	std::cout << '\n';

	auto test = Table<double>(5, 5);
	test[0][0] = 12.25;
	test[4][4] = 324.255;
	std::cout << test[0][0] << '\n';
	std::cout << test[4][4] << '\n';
	std::cout << test.size() << '\n';

	return 0;
}
