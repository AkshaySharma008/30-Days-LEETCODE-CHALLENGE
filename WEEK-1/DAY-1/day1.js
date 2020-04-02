/* Given a non-empty array of integers, every element appears twice except for one.
 Find that single one . note: Your algorithm should have a linear runtime complexity. 
  Could you implement it without using extra memory? */

const singleNumber = nums => nums.reduce((a, b) => a ^ b, 0);
