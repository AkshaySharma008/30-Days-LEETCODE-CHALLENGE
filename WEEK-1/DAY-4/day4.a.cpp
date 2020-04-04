//using vectors
#include <bits/stdc++.h>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0);
}
int main()
{
    int size;
    vector<int> vec;
    cout << "\n enter the size of array:";
    cin >> size;
    cout << "\n enter array:";
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    moveZeroes(vec);
    cout << "\n rearranged array is: ";
    for (int i = -0; i < size; i++)
    {
        cout << vec[i] << " ";
    }
    return 0;
}