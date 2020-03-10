#include "Sorts.h"
#include <iostream>

Sorts::Sorts(vector<int> input)
{
	this->input = input;
}

vector<int> Sorts::insertion() {
	this->start_clock = clock();
	vector<int> _temp = this->input;
	for (int k = 1; k < _temp.size(); k++)
	{
		int temp = _temp[k];
		int j = k - 1;
		while (j >= 0 && temp <= _temp[j])
		{
			_temp[j + 1] = _temp[j];
			j = j - 1;
		}
		_temp[j + 1] = temp;
	}
	this->estimated_time = (clock() - start_clock) / 1000.0;
	return _temp;
}

vector <int> Sorts::selection() {
	this->start_clock = clock();
	vector<int> _temp = this->input;
	for (int i = 0; i < input.size() - 1; ++i)
	{
		int smallestIndex = i;

		for (int currentIndex = i + 1; currentIndex < _temp.size(); ++currentIndex)
		{
			if (_temp[currentIndex] < _temp[smallestIndex])
				smallestIndex = currentIndex;
		}

		swap(_temp[i], _temp[smallestIndex]);
	}
	this->estimated_time = (clock() - start_clock) / 1000.0;
	return _temp;
}

vector <int> Sorts::bubble() {
	this->start_clock = clock();
	vector<int> _temp = this->input;

	for (int i = 0; i < _temp.size(); i++) {
		bool flag = 1;
		for (int j = 0; j < _temp.size() - (i + 1); j++)
			if (_temp[j] > _temp[j + 1]) {
				flag = 0;
				swap(_temp[j], _temp[j + 1]);
			}

		if (flag)
			break;

	}
	this->estimated_time = (clock() - start_clock) / 1000.0;
	return _temp;
}

vector<int> Sorts::shell() {
	this->start_clock = clock();
	vector<int> _temp = this->input;
	for (size_t gap = _temp.size() / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < _temp.size(); i += 1)
		{
			int temp = _temp[i];
			size_t j;
			for (j = i; j >= gap && _temp[j - gap] > temp; j -= gap)
				_temp[j] = _temp[j - gap];

			_temp[j] = temp;
		}
	}
	this->estimated_time = (clock() - start_clock) / 1000.0;
	return _temp;
}

vector<int> Sorts::shaker() {
	this->start_clock = clock();
	vector<int> _temp = this->input;
	int left = 0, right = _temp.size() - 1;
	bool flag = 1;
	while ((left < right) && flag != 0)
	{
		flag = 0;
		for (size_t i = left; i < right; ++i)
		{
			if (_temp[i] > _temp[i + 1])
			{
				swap(_temp[i], _temp[i + 1]);
				flag = 1;
			}
		}
		right--;
		for (size_t i = right; i > left; i--)
		{
			if (_temp[i - 1] > _temp[i])
			{
				swap(_temp[i], _temp[i - 1]);
				flag = 1;
			}
		}
		left++;
	}
	this->estimated_time = (clock() - start_clock) / 1000.0;
	return _temp;
}


vector<int> Sorts::merge() {
	this->start_clock = clock();
	vector<int> _temp = this->input;
	this->merge_sort(_temp, 0, _temp.size() - 1);
	this->estimated_time = (clock() - start_clock) / 1000.0;
	return _temp;
}

void Sorts::merge_sort(vector<int>& mas, int l, int r) {
	if (l < r)
	{

		int m = l + (r - l) / 2;
		merge_sort(mas, l, m);
		merge_sort(mas, m + 1, r);

		merge_support(mas, l, m, r);
	}
}


void Sorts::merge_support(vector<int>& mas, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<int> L(n1);
	vector<int> R(n2);

	for (i = 0; i < n1; i++)
		L[i] = mas[l + i];
	for (j = 0; j < n2; j++)
		R[j] = mas[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			mas[k] = L[i];
			i++;
		}
		else
		{
			mas[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		mas[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		mas[k] = R[j];
		j++;
		k++;
	}
}

vector<int> Sorts::natural_merge_sort() {
	vector<vector<int>> _mas_of_mases;
	int _counter = 0;
	if (this->input.size() > 10000)
		for (size_t i = 0; i < this->input.size(); i += 10000) {
			_mas_of_mases.push_back(vector<int>());
			for (size_t j = 0; j < 10000; ++j)
				_mas_of_mases[_counter].push_back(this->input[j]);
			_counter++;
		}
	else
		return merge();
		
	for (vector<int>& i : _mas_of_mases) {
		std::sort(i.begin(), i.end());
		for (int j : i)
			std::cout << j << " ";
		std::cout << std::endl;

	}
	
	

}