/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:

Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.

Example 2:

Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.

Note: The length of the given binary array will not exceed 50,000. 
*/





class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int c=0, length=0;
         map<int,int> m;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                c++;
            }
            else
                c--;
            if(c==0)
                length=max(length,i+1);
            
            else if(m.find(c)!=m.end())
            {    
                // cout<<i<<" "<<m[c];
                length=max(length,i-m[c]);
            }
            else
                m[c]=i;
            
        }
        return length;
        
    }
};