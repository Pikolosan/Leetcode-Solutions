/*
Given an integer array nums and an integer k, modify the array in the following way:

choose an index i and replace nums[i] with -nums[i].
You should apply this process exactly k times. You may choose the same index i multiple times.

Return the largest possible sum of the array after modifying it in this way.

Example 1:
Input: nums = [4,2,3], k = 1
Output: 5
Explanation: Choose index 1 and nums becomes [4,-2,3].
Example 2:

Input: nums = [3,-1,0,2], k = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].
Example 3:

Input: nums = [2,-3,-1,5,-4], k = 2
Output: 13
Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].
 
*/

/* 
* Now if we have an array of all positive integers, then conjugating the smallest number will lead to least difference in final rsult.
* And an array containg mix of both positive and negative int , then too we will first invert the smallest int(negative int).
* Due to small elements , we will use "Minheap"

* Now as we focused only small int, ignoring the larger int in the given array , 
* thwewfore , we focused on one path outof many possible pathways , i.e Greedy Algo.
*/


// CODE : 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {   //O(klogn+n)
        priority_queue<int,vector<int>,greater<int> > pq(nums.begin(),nums.end());  // conv n-length arr to pq -> O(n)
        int sum=0;
        for(auto n : nums) sum+=n;  // O(n)
        while(k--){                 // O(klogn)
            int el =pq.top(); //returns the smalllest ele
            if(el==0){ // if el=0 , then we keep negating it again n again giving back 0
                break;
            }
            pq.pop(); // remove the smallest ele
            sum -= el;
            pq.push(-1*el); // negating pushing back in pq.
            sum += (-el); 
        }
        return sum;
    }
};

// Exaplanation for Beginners :
/* 
* Meaning of : priority_queue<int,vector<int>,greater<int> > pq(nums.begin(),nums.end());

priority_queue<int, vector<int>, greater<int>>: This part declares a priority_queue data structure where:
    int is the type of elements stored in the queue.
    vector<int> is the underlying container used to store the elements.
    greater<int> is the comparator used to determine the order of elements. 
    In this case, it means the queue will store elements in ascending order (from smallest to largest). 
    If not specified, the default comparator (less<int>) is used, which stores elements in descending order (from largest to smallest).
pq(nums.begin(), nums.end()): This initializes the priority_queue pq with elements from the range [nums.begin(), nums.end()). 
It effectively constructs the priority queue with the elements of the nums vector. The elements are inserted into the queue, 
and the queue maintains its order based on the specified comparator (greater<int> in this case).

* One push and pop operation takes time = logn individually.  
*/ 
