/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxRt = 0;
        for(int i=0;i<n;i++){
            if(i>maxRt) return false;
        maxRt = max(i+nums[i] , maxRt);
           
       }  return true;  
    }
};