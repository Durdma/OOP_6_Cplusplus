#define NOMINMAX

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>
#include <string>

#include "MyArray.h"
#include "Errors.h"

void InputLength(int &length)
{

	int tmp{};

	std::cout << "Введите длину массива: ";
	std::cin >> tmp;

	if ((!std::cin.good() || std::cin.peek() != '\n') || tmp <= 0)
	{

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw Errors("invalid_argument", 0);

	}

	length = tmp;

}

void FillArray(MyArray &arr)
{

	int tmp{};

	std::cout << "Заполните массив:" << std::endl;

	for (int i = 0; i < arr.getLength(); i++)
	{

		std::cout << "Эл." << i << " равен ";
		std::cin >> tmp;
		std::cout << std::endl;

		arr.setElem(tmp, i);

	}

	arr.ShowArr();

}

void main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int length{};
	int choice{ -10 };
	bool flag = false;

	while (flag == false)
	{

		try
		{

			InputLength(length);
			flag = true;

		}
		catch (std::exception &ex)
		{

			std::cerr << "Error: " << ex.what() << std::endl;
			std::cerr << "Вводимое значение должно быть целым положительным числом!" << std::endl;

		}

	}

	flag = false;

	MyArray arr{ length };

	FillArray(arr);

	while (choice != 0)
	{

		std::cout << "Выберите действие: " << std::endl;
		std::cout << "1 - Вывести минимальный по модулю элемент массива" << std::endl;
		std::cout << "2 - Вывести сумму модулей элементов массива после первого 0" << std::endl;
		std::cout << "3 - Преобразовать массив в вид: все эл. с четных позиций в начало, нечетные в конец" << std::endl;
		std::cout << "0 - Закончить выполнение программы" << std::endl;

		std::cout << "Ваш выбор: ";
		
		while (flag == false)
		{

			try
			{

				std::cin >> choice;
				if ((!std::cin.good() || std::cin.peek() != '\n') || choice < 0 || choice > 3)
				{

					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					throw Errors("invalid_argument", 1);

				}
				flag = true;

			}
			catch (Errors &ex)
			{

				std::cerr << "Error: " << ex.what() << std::endl;
				ex.getInfo();
				std::cout << "Выберите действие: " << std::endl;
				std::cout << "1 - Вывести минимальный по модулю элемент массива" << std::endl;
				std::cout << "2 - Вывести сумму модулей элементов массива после первого 0" << std::endl;
				std::cout << "3 - Преобразовать массив в вид: все эл. с четных позиций в начало, нечетные в конец" << std::endl;
				std::cout << "0 - Закончить выполнение программы" << std::endl;

				std::cout << "Ваш выбор: ";

			}

		}

		flag = false;
		
		std::cout << std::endl;

		if (choice == 1)
		{

			arr.ShowArr();

			int index = arr.GetMin();

			std::cout << "Минимальный элемент массива это ";
			std::cout << "Эл." << index << " равный " << arr.getElem(index) << std::endl;

		}

		if (choice == 2)
		{

			arr.ShowArr();

			try
			{

				int countZeros{};

				for (int i = 0; i < arr.getLength(); i++)
				{

					if (arr.getElem(i) == 0)
					{

						countZeros++;

					}

				}

				if (countZeros == 0)
				{

					throw Errors("cant_find_zero", 2);

				}

				int res = arr.GetSum();

				std::cout << "Сумма модулей элементов после первого нуля равна: " << res << std::endl;

			}
			catch (Errors &ex)
			{

				std::cerr << "Error: " << ex.what() << std::endl;
				ex.getInfo();
				

			}

		}

		if (choice == 3)
		{

			std::cout << "Исходный массив: " << std::endl;
			arr.ShowArr();
			std::cout << std::endl;
			std::cout << "Полученный массив: " << std::endl;
			arr.ReshapeArr();

		}

	}

}