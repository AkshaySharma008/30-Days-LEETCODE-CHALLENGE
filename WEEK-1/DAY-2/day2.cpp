/* Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the sum of the squares
of its digits, and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers.*/

#include <bits/stdc++.h>
using namespace std;

//to get square root of this number individually
int getIndividualSquare(int val)
{
    int ans = 0;
    while (val)
    {
        ans += (val % 10) * (val % 10);
        val = val / 10;
    }
    return ans;
}

//to check number is happy or not
bool isHappyNumber(int n)
{
    int rabbit, turtle;
    rabbit = turtle = n;
    do
    {
        turtle = getIndividualSquare(turtle);
        rabbit = getIndividualSquare(getIndividualSquare(rabbit));
    } while (turtle != rabbit);

    return (turtle == true);
}

int main()
{
    int n;
    cout << "\n enter the number to check :";
    cin >> n;
    if (isHappyNumber(n))
        cout << "\n this is happy number";
    else
        cout << "\n this is not a happy number";
}