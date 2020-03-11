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
vector<int> mergeArrays(vector<int>& arr1, vector<int>& arr2)
{
	int i = 0, j = 0, k = 0;
	vector<int> arr3(arr1.size() + arr2.size());
	while (i < arr1.size() && j < arr2.size())
	{
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}

	while (i < arr1.size())
		arr3[k++] = arr1[i++];

	while (j < arr2.size())
		arr3[k++] = arr2[j++];
	sort(arr3.begin(), arr3.end());
	return arr3;
}
vector<int> Sorts::natural_merge_sort() {
	this->start_clock = clock();
	vector<int> _temp = this->input;
	vector< vector<int> > _mas_of_mases;
	int _counter = 0;
	if (_temp.size() >= 10)
	for (size_t i = 0; i < _temp.size(); i += _temp.size() / 10) {
		_mas_of_mases.push_back(vector<int>());
		for (size_t j = 0; j < _temp.size() / 10; ++j)
			_mas_of_mases[_counter].push_back(_temp[j]);
		_counter++;
	}
	else
		for (size_t i = 0; i < _temp.size(); i++) {
			_mas_of_mases.push_back(vector<int>());
			_mas_of_mases[_counter].push_back(_temp[i]);
			_counter++;
		}

	
	while (_mas_of_mases.size() != 1) {
		for (size_t i = 0; i < _mas_of_mases.size() - 1; i += 2) {
			_mas_of_mases[i] = mergeArrays(_mas_of_mases[i], _mas_of_mases[i + 1]);
			_mas_of_mases[i + 1].clear();
		}
		for (size_t i = 0; i < _mas_of_mases.size(); ++i)
			if (_mas_of_mases[i].size() == 0)
				_mas_of_mases.erase(_mas_of_mases.begin() + i);
			
			
	}
	this->estimated_time = (clock() - start_clock) / 1000.0;
	return _mas_of_mases[0];
	
	

}

