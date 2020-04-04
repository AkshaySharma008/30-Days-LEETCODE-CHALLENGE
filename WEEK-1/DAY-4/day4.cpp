/*
Given an array nums, write a function to move all 0's to the end of it while 
maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:

    You must do this in-place without making a copy of the array.
    Minimize the total number of operations.

Hint #1  
In-place means we should not be allocating any space for extra array. 
But we are allowed to modify the existing array. However, as a first step, 
try coming up with a solution that makes use of additional space. For this
 problem as well, first apply the idea discussed using an additional array
  and the in-place solution will pop up eventually.

Hint #2  
A two-pointer approach could be helpful here. The idea would be to
 have one pointer for iterating the array and another pointer that
  just works on the non-zero elements of the array.
*/

#include <bits/stdc++.h>
using namespace std;
void pushZeroToEnd(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            arr[count++] = arr[i];
    while (count < n)
        arr[count++] = 0;
}
int main()
{
    int n;
    cout << "\n enter the size of array:";
    cin >> n;
    int arr[n];
    cout << "\n enter array elements:";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    pushZeroToEnd(arr, n);
    cout << "\n sorted array in requitred way is:";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
