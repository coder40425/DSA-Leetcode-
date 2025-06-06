/* Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 
Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0                                             


APPROACH:-
-INITIALIZE TWO POINTERS LEFT = 0 AND RIGHT = 0, AND A VARIABLE SUM = 0.
-MOVE THE RIGHT POINTER FORWARD AND ADD NUMS[RIGHT] TO SUM.
-WHEN SUM BECOMES GREATER THAN OR EQUAL TO TARGET, UPDATE MINIMUM LENGTH.
-SHRINK THE WINDOW BY MOVING LEFT FORWARD WHILE SUM >= TARGET, UPDATING MINIMUM EACH TIME.
-RETURN 0 IF NO VALID SUBARRAY IS FOUND, ELSE RETURN THE MINIMUM LENGTH.

              TIME COMPLEXITY :- O(N)
              SPACE COMPLEXITY:- O(1)                                                                                          */


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, sum = 0, minLen = INT_MAX;            //INT_MAX is the largest possible value an integer datatype can hold. (used for the first pass)
        
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        
        return (minLen == INT_MAX) ? 0: minLen;
    }
};
