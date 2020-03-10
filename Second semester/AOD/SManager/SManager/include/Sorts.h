#ifndef SORTS_H
#define SORTS_H
#pragma comment(linker, "/STACK:20000000")
#pragma comment(linker, "/HEAP:20000000")

#include <vector>
#include <algorithm> 
#include <ctime>

using std::vector;
using std::swap;

class Sorts {

private:
    vector<int> input;
    double start_clock;
    
    void merge_support(vector<int> &mas, int l, int m, int r);
    void merge_sort(vector<int>& mas, int l, int r);
    vector<int> merge_arrays(vector<int>& arr1, vector<int>& arr2);

public:
    double estimated_time;

    Sorts(vector<int> input);

    vector<int> insertion();
    vector<int> selection();
    vector<int> bubble();
    vector<int> shell();
    vector<int> shaker();
    vector<int> merge();
    vector<int> natural_merge_sort();



};

#endif