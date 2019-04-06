/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 *
 * https://leetcode.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (34.60%)
 * Total Accepted:    44.6K
 * Total Submissions: 129K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct positive integers, find the largest subset such that
 * every pair (Si, Sj) of elements in this subset satisfies:
 * 
 * Si % Sj = 0 or Sj % Si = 0.
 * 
 * If there are multiple solutions, return any subset is fine.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2] (of course, [1,3] will also be ok)
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,4,8]
 * Output: [1,2,4,8]
 * 
 * 
 * 
 */
class Solution {
public:
 	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> memo;
		for (auto i : nums) {
			bool push = false;
			vector<vector<int>> cache;
			for (auto& vec : memo) {
				if (i % vec[vec.size() - 1] == 0) {
					vec.push_back(i);
					push = true;
				}
				else if (i % vec[0] == 0) {
					int max_index = 0;
					cache.push_back(vector<int>());
					cache[cache.size() - 1].push_back(vec[0]);
					for (int j = 1; j < vec.size() - 1; ++j) {
						if (i % vec[j] == 0) {
							cache[cache.size() - 1].push_back(vec[j]);
						} else {
							break;
						}
					}
					cache[cache.size() - 1].push_back(i);
					push = true;
				}
			}
			if (!push) {
				memo.push_back(vector<int>() = { i });
			}

			if (cache.size() != 0) {
				memo.insert(memo.end(), cache.begin(), cache.end());
			}
		}

		int largest = numeric_limits<int>::min();
		vector<int> result;
		for (auto& vec : memo) {
			if (largest < (int)vec.size()) {
				result = vec;
				largest = vec.size();
			}
		}

		return result;
	}
};

