/*
You have a queue of integers, you need to retrieve the first unique integer in the queue.

Implement the FirstUnique class:

FirstUnique(int[] nums) Initializes the object with the numbers in the queue.
int showFirstUnique() returns the value of the first unique integer of the queue, and returns -1 if there is no such integer.
void add(int value) insert value to the queue.
 

Example 1:

Input: 
["FirstUnique","showFirstUnique","add","showFirstUnique","add","showFirstUnique","add","showFirstUnique"]
[[[2,3,5]],[],[5],[],[2],[],[3],[]]
Output: 
[null,2,null,2,null,3,null,-1]

Explanation: 
FirstUnique firstUnique = new FirstUnique([2,3,5]);
firstUnique.showFirstUnique(); // return 2
firstUnique.add(5);            // the queue is now [2,3,5,5]
firstUnique.showFirstUnique(); // return 2
firstUnique.add(2);            // the queue is now [2,3,5,5,2]
firstUnique.showFirstUnique(); // return 3
firstUnique.add(3);            // the queue is now [2,3,5,5,2,3]
firstUnique.showFirstUnique(); // return -1
*/

class FirstUnique {
    unordered_map<int, list<int>::iterator> hashMap;
    list<int> keys;

   public:
    FirstUnique(vector<int>& nums) {
        for (int elt : nums) {
            add(elt);
        }
    }

    int showFirstUnique() {
        if (keys.size() > 0) return keys.front();
        return -1;
    }

    void add(int value) {
        if (hashMap.find(value) != hashMap.end()) {
            list<int>::iterator it = hashMap[value];
            if (it != keys.end()) {
                keys.erase(it);
                hashMap[value] = keys.end();
            }
        } else {
            keys.push_back(value);
            list<int>::iterator it = keys.end();
            it--;
            hashMap[value] = it;
        }
    }
};