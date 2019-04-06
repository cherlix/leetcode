/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 *
 * https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (34.90%)
 * Total Accepted:    26.1K
 * Total Submissions: 75K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * Given a non-empty 2D matrix matrix and an integer k, find the max sum of a
 * rectangle in the matrix such that its sum is no larger than k.
 * 
 * Example:
 * 
 * 
 * Input: matrix = [[1,0,1],[0,-2,3]], k = 2
 * Output: 2 
 * Explanation: Because the sum of rectangle [[0, 1], [-2, 3]] is
 * 2,
 * and 2 is the max number no larger than k (k = 2).
 * 
 * Note:
 * 
 * 
 * The rectangle inside the matrix must have an area > 0.
 * What if the number of rows is much larger than the number of columns?
 * 
 */
class Solution {
public:
    struct Range {
        int x0, y0, x1, y1;

        Range(int _x0, int _y0, int _x1, int _y1) : x0(_x0), y0(_y0), x1(_x1), y1(_y1) {}
    };

    struct HashFn {
        size_t operator() (const Range& r) const {
            return ((r.x0 & 0xff) << 24) + ((r.x1 & 0xff) << 16) + ((r.y0 & 0xff) << 8) + (r.y1 & 0xff);
        }
    };

    struct CmpFn {
        bool operator() (const Range& r0, const Range& r1) const {
            return r0.x0 == r1.x0 && r0.y0 == r1.y0 && r0.x1 == r1.x1 && r0.y1 == r1.y1;
        }
    };

    typedef unordered_map<Range, pair<int, int>, HashFn, CmpFn> Memo;

    int maxSumSubmatrixDP(const vector<vector<int>>& matrix, Range range, Memo& memo, int k) {
        if (memo.find(range) != memo.end()) {
            return memo[range].first;
        }

        if (range.x0 == range.x1 && range.y0 == range.y1) {
			memo[range] = make_pair(matrix[range.y0][range.x0], matrix[range.y0][range.x0]);
            return matrix[range.y0][range.x0];
        }
        
        int max_val = numeric_limits<int>::min();
        if (range.x0 < range.x1) {
            int val = maxSumSubmatrixDP(matrix, Range(range.x0, range.y0, range.x1 - 1, range.y1), memo, k);
            if (val <= k) {
                max_val = max(max_val, val);
            }

            val = maxSumSubmatrixDP(matrix, Range(range.x0 + 1, range.y0, range.x1, range.y1), memo, k);
            if (val <= k) {
                max_val = max(max_val, val);
            }
        }
        if (range.y0 < range.y1) {
            int val = maxSumSubmatrixDP(matrix, Range(range.x0, range.y0, range.x1, range.y1 - 1), memo, k);
            if (val <= k) {
                max_val = max(max_val, val);
            }

            val = maxSumSubmatrixDP(matrix, Range(range.x0, range.y0 + 1, range.x1, range.y1), memo, k);
            if (val <= k) {
                max_val = max(max_val, val);
            }          
        }
        
        int val = 0;
        if (range.x0 < range.x1) {
            val = memo[Range(range.x0, range.y0, range.x1 - 1, range.y1)].second;
            for (int i = range.y0; i <= range.y1; ++i) {
                val += matrix[i][range.x1];
            }
        } else {
            val = memo[Range(range.x0, range.y0, range.x1, range.y1 - 1)].second;
            for (int i = range.x0; i <= range.x1; ++i) {
                val += matrix[range.y1][i];
            }    
        }

        if (val <= k) {
            max_val = max(max_val, val);
        }

        memo[range] = make_pair(max_val, val);
        return max_val;
    }

    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        Memo memo;
        return maxSumSubmatrixDP(matrix, Range(0, 0, matrix[0].size() - 1, matrix.size() - 1), memo, k);
    }
};

