#pragma once
#include <iostream>

class IntegerArray
{
private:
	int length;
	int* data;

public:
	IntegerArray();
	IntegerArray(int lenght);
	IntegerArray(const IntegerArray& other);
	~IntegerArray();
	IntegerArray& operator=(const IntegerArray& other);
	int get_data(int index);
	void resize(int lenght_tmp);
	void set_data(int index, int value);
	void add_data(int index, int value);
	void del_data(int index);
	bool has_an_element(int element);
	void show();
};
