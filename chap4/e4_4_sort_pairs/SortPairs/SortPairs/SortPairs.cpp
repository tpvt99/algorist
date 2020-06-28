// SortPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <vector>
#include <iostream>
#include <utility>

using namespace std;

vector<pair<int, string>> sort_pair(vector<pair<int, string>>& vec, int size);

int main()
{
    vector< pair<int, string>> vec;
    int arr1[] = { 1, 3, 4, 9, 10, 12, 15, 19, 20, 25 };
    string arr2[] = { "blue", "red", "blue", "yellow", "red", "yellow", "blue", "blue", "red", "red" };
    for (int i = 0; i < 10; i++) {
        vec.push_back(make_pair(arr1[i], arr2[i]));
    }
    vector< pair<int, string>> new_vec = sort_pair(vec, 10);
    for (int i = 0; i < 10; i++) {
        printf("(%d, %s) ", new_vec[i].first, new_vec[i].second.c_str());
    }

}

vector<pair<int, string>> sort_pair(vector<pair<int, string>>& vec, int size) {
    vector<int> red_arrays;
    vector<int> blue_arrays;
    vector<int> yellow_arrays;
    for (int i = 0; i < size; i++) {
        string str = vec[i].second;
        if (str.compare("red") == 0) {
            red_arrays.push_back(i);
        }
        else if (str.compare("yellow") ==0) {
            yellow_arrays.push_back(i);
        }
        else if (str.compare("blue") == 0) {
            blue_arrays.push_back(i);
        }
    }
    vector<pair<int, string>> new_vec;
    for (auto v : red_arrays) {
        new_vec.push_back(vec[v]);
    }
    for (auto v : blue_arrays) {
        new_vec.push_back(vec[v]);
    }
    for (auto v : yellow_arrays) {
        new_vec.push_back(vec[v]);
    }
    return new_vec;
}
