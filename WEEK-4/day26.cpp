/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

 

If there is no common subsequence, return 0.
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
		int m = text1.size();
        int n = text2.size();
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp[0][0])*(m+1)*(n+1));
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(text1[i] == text2[j]) dp[i][j] = 1+dp[i+1][j+1];
                else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};