/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 *
 * https://leetcode.com/problems/predict-the-winner/description/
 *
 * algorithms
 * Medium (46.68%)
 * Total Accepted:    47.4K
 * Total Submissions: 101.5K
 * Testcase Example:  '[1,5,2]'
 *
 * Given an array of scores that are non-negative integers. Player 1 picks one
 * of the numbers from either end of the array followed by the player 2 and
 * then player 1 and so on. Each time a player picks a number, that number will
 * not be available for the next player. This continues until all the scores
 * have been chosen. The player with the maximum score wins. 
 * 
 * Given an array of scores, predict whether player 1 is the winner. You can
 * assume each player plays to maximize his score. 
 * 
 * Example 1:
 * 
 * Input: [1, 5, 2]
 * Output: False
 * Explanation: Initially, player 1 can choose between 1 and 2. If he chooses 2
 * (or 1), then player 2 can choose from 1 (or 2) and 5. If player 2 chooses 5,
 * then player 1 will be left with 1 (or 2). So, final score of player 1 is 1 +
 * 2 = 3, and player 2 is 5. Hence, player 1 will never be the winner and you
 * need to return False.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [1, 5, 233, 7]
 * Output: True
 * Explanation: Player 1 first chooses 1. Then player 2 have to choose between
 * 5 and 7. No matter which number player 2 choose, player 1 can choose
 * 233.Finally, player 1 has more score (234) than player 2 (12), so you need
 * to return True representing player1 can win.
 * 
 * 
 * 
 * Note:
 * 
 * 1 
 * Any scores in the given array are non-negative integers and will not exceed
 * 10,000,000.
 * If the scores of both players are equal, then player 1 is still the winner.
 * 
 * 
 */
class Solution {
public:
	vector<long long> GetScoresDP(const vector<int>& nums, int i, int j, int player, map<int, vector<long long>>& memo) {
		vector<long long> result(2, 0);
        int key = (i << 16) | j;
		if (i == j) {
			result[player] = nums[i];
			result[player ^ 0x1] = 0;
		} else if (memo.find(key) != memo.end()) {
            result = memo[key];
        } else {
			vector<long long> score1 = GetScoresDP(nums, i + 1, j, player ^ 0x1, memo);
			vector<long long> score2 = GetScoresDP(nums, i, j - 1, player ^ 0x1, memo);
			if (score1[player ^ 0x1] == score2[player ^ 0x1]) {
				result[player] = nums[i] > nums[j] ? nums[i] + score1[player] : nums[j] + score2[player];
				result[player ^ 0x1] = score1[player ^ 0x1];
			} else if (score1[player ^ 0x1] < score2[player ^ 0x1]) {
				result[player] = nums[i] + score1[player];
				result[player ^ 0x1] = score1[player ^ 0x1];
			} else {
				result[player] = nums[j] + score2[player];
				result[player ^ 0x1] = score2[player ^ 0x1];
			}
            memo[key] = result;
		}
		return result;
	}

	bool PredictTheWinner(vector<int>& nums) {
        map<int, vector<long long>> memo;
		vector<long long> result = GetScoresDP(nums, 0, nums.size() - 1, 0, memo);

		return result[0] >= result[1];
	}
};

