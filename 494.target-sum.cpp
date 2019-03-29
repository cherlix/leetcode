/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (44.92%)
 * Total Accepted:    87.6K
 * Total Submissions: 195.1K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * 
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * ⁠
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.  
 * 
 * 
 * Example 1:
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Note:
 * 
 * The length of the given array is positive and will not exceed 20. 
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */
class Solution {
public:
struct Key {
        int index;
        int number;

        Key() : index(0), number(0) {}
        Key(int _index, int _number) : index(_index), number(_number) {}
    };
    
    struct Hasher {
        std::size_t operator()(const Key& k) const {
            return (k.index << 16) | (k.number & 0xffff);
        }
    };
    
    struct Comparator {
        bool operator() (const Key& k1, const Key& k2) const {
            return k1.index == k2.index && k1.number == k2.number;
        }
    };

    unordered_map<Key, int, Hasher, Comparator> memo;

    int findTargetSumWays(vector<int>& nums, int index, int currentVal, int S) {
        if (index >= nums.size()) {
            return currentVal == S ? 1 : 0;
        }

        if (memo.find(Key(index, currentVal)) != memo.end()) {
            return memo[Key(index, currentVal)];
        }

        int sum = findTargetSumWays(nums, index + 1, currentVal + nums[index], S) +
            findTargetSumWays(nums, index + 1, currentVal - nums[index], S);

        memo.insert({Key(index, currentVal), sum});

        return sum;
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        return findTargetSumWays(nums, 0, 0, S);
    }
};

