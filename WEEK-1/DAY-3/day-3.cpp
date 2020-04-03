/*Given an integer array nums, find the contiguous subarray(containing at least one number)
 which has the largest sum and return its sum.

                             Example :

    Input : [ -2, 1, -3, 4, -1, 2, 1, -5, 4 ],
    Output : 6 Explanation : [ 4, -1, 2, 1 ] has the largest sum = 6.

                             Follow up :

If you have figured out the O(n) solution,try coding another solution using the 
divide and conquer approach, which is more subtle.*/

/*
there are 3 cases possible of this problem :
 1. If the array contains all non-negative numbers, 
     then the problem is trivial; a maximum subarray is the entire array.
 2. If the array contains all non-positive numbers,   
     then a solution is any subarray of size 1 containing the maximal value of the array 
     (or the empty subarray, if it is permitted).
 3. Several different sub-arrays may have the same maximum sum.

This problem can be solved using several different algorithmic techniques, including
 brute force,
 divide and conquer,
 dynamic programming,
 reduction to shortest paths.
*/

//kandane's ALgorithm
#include <bits/stdc++.h>
using namespace std;

int maxSubArray(int arr[], int n)
{
    int maxSum = 0;
    int currentSum = maxSum;
    for (int i = 0; i < n; i++)
    {
        if (currentSum + arr[i] > arr[i])
            currentSum += arr[i];
        else
        {
            currentSum = arr[i];
        }
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main()
{
    int n;
    cout << "enter the size of array ";
    cin >> n;
    int arr[n];
    cout << "\n enter array elements:";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "\n maxSum : " << maxSubArray(arr, n);
}
