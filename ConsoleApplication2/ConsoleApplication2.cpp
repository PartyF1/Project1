#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> sortArray(vector<int> array)
{
    vector<int> oddNums;
    int j = 0;
    auto i = array.begin();
    while (j != array.size()) {
        oddNums.push_back(-1);
        if (*i % 2 == 0) {
            oddNums[j] = *i;
            array.erase(i);
            i--;
            j--;
        }
        i++;
        j++;
    }
    sort(array.begin(), array.end());
    for (int i = 0; i < oddNums.size(); i++) {
        if (oddNums[i] != -1) array.insert(array.begin() + i, oddNums[i]);
    }
    return array;
}


int main()
{
    vector<int> a = { 5, 4, 3, 2, 1 };
    vector<int> b = sortArray(a);
}
