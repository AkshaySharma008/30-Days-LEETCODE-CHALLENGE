/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.\

soln:
 The outer loop picks all strings one by one. The inner loop checks whether remaining
  strings are anagram of the string picked by outer loop.

*/

#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

bool areAnagram(string str1, string str2)
{
    int count[NO_OF_CHARS] = {0};
    int i;
    for (i = 0; str1[i] && str2[i]; i++)
    {
        count[str1[i]]++;
        count[str2[i]]--;
    }
    if (str1[i] || str2[i])
        return false;

    for (i = 0; i < NO_OF_CHARS; i++)
        if (count[i])
            return false;
    return true;
}
void findAllAnagrams(string arr[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (areAnagram(arr[i], arr[j]))
                cout << arr[i] << " is anagram of " << arr[j] << endl;
}

int main()
{
    string arr[] = {"geeksquiz", "geeksforgeeks", "abcd",
                    "forgeeksgeeks", "zuiqkeegs"};
    int n = sizeof(arr) / sizeof(arr[0]);
    findAllAnagrams(arr, n);
    return 0;
}