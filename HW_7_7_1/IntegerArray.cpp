#include "IntegerArray.h"

IntegerArray::IntegerArray()
{
	length = 0;
	data = new int[0];
}

IntegerArray::IntegerArray(int lenght)
{
	{
		if (lenght < 0)
		{
			throw "Lenght of array cannot be less 0";
		}

		this->length = lenght;
		data = new int[length] {};
	}
}

IntegerArray::IntegerArray(const IntegerArray& other)
{

	if (other.length < 0)
	{
		throw "Lenght of array cannot be less 0";
	}
	length = other.length;
	data = new int[length];

	for (int i = 0; i < length; i++)
	{
		data[i] = other.data[i];
	}
}

IntegerArray::~IntegerArray()
{
	if (data)
		delete[] data;
}

IntegerArray& IntegerArray::operator=(const IntegerArray& other)
{
	if (&other != this)
	{
		if (other.length < 0)
		{
			throw "Lenght of array cannot be less 0";
		}
		length = other.length;
		data = new int[length];

		for (int i = 0; i < length; i++)
		{
			data[i] = other.data[i];
		}
	}
	return *this;
}

int IntegerArray::get_data(int index)
{
	if (0 > index || index >= length)
	{
		throw "You are trying to look at an element outside the array";
	}
	return data[index];
}

void IntegerArray::resize(int lenght_tmp)
{
	if (lenght_tmp < 0)
	{
		throw "Lenght of array cannot be less 0";
	}
	else if (lenght_tmp < this->length)
	{
		throw "Reducing the length of the array can lead to data loss";
	}
	else if (lenght_tmp == this->length)
	{
		return;
	}

	IntegerArray tmp_array(lenght_tmp);
	for (int i = 0; i < length; i++)
	{
		tmp_array.data[i] = data[i];
	}
	length = lenght_tmp;
	delete[] data;
	data = tmp_array.data;
	tmp_array.data = nullptr;
}

void IntegerArray::set_data(int index, int value)
{
	if (index < 0)
	{
		throw "The value of the array index cannot be negative";
	}

	else if (0 <= index && index < length)
	{
		data[index] = value;
	}

	else
	{
		resize(index + index / 2);
		data[index] = value;
	}
}

void IntegerArray::add_data(int index, int value)
{
	if (index < 0)
	{
		throw "The value of the array index cannot be negative";
	}

	if (index >= length)
	{
		set_data(index, value);
		return;
	}

	IntegerArray tmp_array(this->length + 1);

	for (int i = 0; i < index; i++)
	{
		tmp_array.data[i] = data[i];
	}

	tmp_array.data[index] = value;

	for (int i = index + 1; i < tmp_array.length; i++)
	{
		tmp_array.data[i] = data[i - 1];
	}

	length = tmp_array.length;
	delete[] data;
	data = tmp_array.data;
	tmp_array.data = nullptr;
}

void IntegerArray::del_data(int index)
{
	if (index < 0)
	{
		throw "The value of the array index cannot be negative";
	}

	if (index >= length)
	{
		throw "You are trying to delete an element outside the array";
	}

	IntegerArray tmp_array(this->length - 1);

	for (int i = 0; i < index; i++)
	{
		tmp_array.data[i] = data[i];
	}

	for (int i = index; i < tmp_array.length; i++)
	{
		tmp_array.data[i] = data[i + 1];
	}

	length = tmp_array.length;
	delete[] data;
	data = tmp_array.data;
	tmp_array.data = nullptr;
}

bool IntegerArray::has_an_element(int element)
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == element)
		{
			std::cout << "Index of element " << element << " is " << i << '\n';
			return true;
		}
	}
	std::cout << "The element " << element << " not found" << '\n';
	return false;
}

void IntegerArray::show()
{
	for (int i = 0; i < length; i++)
	{
		std::cout << data[i] << '\t';
	}
	std::cout << '\n';

}
