/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).


*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
		
        while(left <= right){
            int mid = (left + right)/2;
            int midElement = nums[mid], curLeft = nums[left], curRight = nums[right];
            
            // if target found, return the index
            if(midElement == target) return mid;
            
            // if middle element is less than the current left (mid element is in the right section of the rotation)
            if(midElement < curLeft){
                if (target <= curRight and target > midElement){
                    // target is in the right of midElement
                    left = mid +1;
                }
                else right = mid-1;
            }
            
            // if middle element is greater than the current right (mid element is in the left section of the rotation)
            else if(midElement > curRight){
                if (target >= curLeft and target < midElement){
                    // target is in the left of midElement
                    right = mid -1;
                }
                else left = mid +1;
            }
            // no rotation
            else{
                if(target > midElement) left = mid + 1;
                else right = mid -1;
            }
        }
        // value does not exist
        return -1;
    }
};