#pragma once

#include <exception>

class Errors: public std::exception
{

protected:

	int m_code;

public:

	Errors(const char *, int);
	~Errors();

	void getInfo();

};

Errors::Errors(const char *message, int code): exception{ message }, m_code{code}
{}

Errors::~Errors()
{}

void Errors::getInfo()
{

	if (m_code == 1)
	{

		std::cout << "Число должно быть в диапазоне от 0 до 3" << std::endl;

	}

	if (m_code == 2)
	{

		std::cout << "Невозможно подсчитать сумму элементов, так как в масивве нет нулей!!!" << std::endl;

	}

}
