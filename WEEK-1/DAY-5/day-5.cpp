/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions
 as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:
Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Example 2:
Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
             are engaging multiple transactions at the same time. You must sell before 
             buying again.

Example 3:
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(int price[], int n)
{
    //profit array initialised to zero
    int *profit = new int[n];
    for (int i = 0; i < n; i++)
        profit[i] = 0;
    //max profit on one transaction
    int max_price = price[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (price[i] > max_price)
            max_price = price[i];
        profit[i] = max(profit[i + 1], max_price - price[i]);
    }

    //max profit on second one
    int min_price = price[0];
    for (int i = 0; i < n; i++)
    {
        if (price[i] < min_price)
            min_price = price[i];
        profit[i] = max(profit[i - 1], profit[i] +
                                           (price[i] - min_price));
    }
    int result = profit[n - 1];

    delete[] profit; // To avoid memory leak

    return result;
}
int main()
{
    int price[] = {2, 30, 15, 10, 8, 25, 80};
    int n = sizeof(price) / sizeof(price[0]);
    cout << "maximum profit:" << maxProfit(price, n);
    return 0;
}
