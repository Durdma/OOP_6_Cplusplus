#pragma once

#include <cmath>

class MyArray
{

protected:

	int *m_arr;
	int m_length;

public:

	MyArray(int length);
	~MyArray();

	int getLength(){ return m_length; };

	void setElem(const int &value, const int &index) { m_arr[index] = value; };
	int getElem(const int &index) { return m_arr[index]; };

	void ShowArr();
	int GetMin();
	int GetSum();
	void ReshapeArr();

};

MyArray::MyArray(int length): m_length{ length }
{

	m_arr = new int[m_length];

}

MyArray::~MyArray()
{

	delete[] m_arr;

}

void MyArray::ShowArr()
{

	std::cout << std::endl;

	for (int i = 0; i < m_length; i++)
	{

		if (i % 5 == 0)
		{

			std::cout << std::endl;

		}

		std::cout << "Эл." << i << " равен " << m_arr[i] << " ";

		
	}

	std::cout << std::endl;

}

int MyArray::GetMin()
{

	int resValue{ m_arr[0] };
	int resIndex{ 0 };

	for (int i = 1; i < m_length; i++)
	{

		if (abs(m_arr[i]) < abs(resValue))
		{

			resValue = m_arr[i];
			resIndex = i;

		}

	}

	return resIndex;

};

int MyArray::GetSum()
{

	int index{ -1 };
	int res{ 0 };

	for (int i = 0; i < m_length; i++)
	{

		if (m_arr[i] == 0)
		{

			index = i;
			break;

		}

	}

	if (index != (m_length - 1))
	{

		for (int i = index; i < m_length; i++)
		{

			res += abs(m_arr[i]);

		}

	}
	//Блок исключения добавить
	else
	{

		return -1;

	}

	return res;

}

void MyArray::ReshapeArr()
{

	int *tmp = new int[100];

	int j{ 0 };

	for (int i = 0; i < m_length; i++)
	{

		if (i % 2 == 0)
		{

			tmp[j] = m_arr[i];
			j++;

		}

	}

	for (int i = 0; i < m_length; i++)
	{

		if (i % 2 != 0)
		{

			tmp[j] = m_arr[i];
			j++;

		}

	}

	for (int i = 0; i < m_length; i++)
	{

		m_arr[i] = tmp[i];

	}

	delete[] tmp;

	ShowArr();

}


