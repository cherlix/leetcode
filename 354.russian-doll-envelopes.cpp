/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 *
 * https://leetcode.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (33.66%)
 * Total Accepted:    42.3K
 * Total Submissions: 125.6K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * You have a number of envelopes with widths and heights given as a pair of
 * integers (w, h). One envelope can fit into another if and only if both the
 * width and height of one envelope is greater than the width and height of the
 * other envelope.
 * 
 * What is the maximum number of envelopes can you Russian doll? (put one
 * inside other)
 * 
 * Note:
 * Rotation is not allowed.
 * 
 * Example:
 * 
 * 
 * 
 * Input: [[5,4],[6,4],[6,7],[2,3]]
 * Output: 3 
 * Explanation: The maximum number of envelopes you can Russian doll is 3
 * ([2,3] => [5,4] => [6,7]).
 * 
 * 
 * 
 */
class Solution {
public:
    struct Key {
        int width;
        int height;
        Key() : width(0), height(0) {}
        Key(int _width, int _height) : width(_width), height(_height) {}
    };

    struct HashFn {
        size_t operator() (const Key& key) const {
            return (key.width << 16) | key.height;
        }
    };

    struct CmpFn {
        bool operator() (const Key& k1, const Key& k2) const {
            return k1.width == k2.width && k1.height == k2.height;
        }
    };

    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        map<Key, int, HashFn, CmpFn> memo;
        for (int i = 0; i < envelopes.size(); ++i) {
            auto& pair = envelopes[i];

            vector<map::iterator> its;
            int max_cout = 0;
            auto it = memo.begin();
            while (it != memo.end()) {
                if (it->first.width < pair.first && it->second.height < pair.second) {
                    max_count = max(max_count, it->second);
                    it = memo.erase(it);
                } else {
                    ++it;
                }
            }
            ++max_count;

            memo.insert({Key(pair.first, pair.second), max_count});
        }

        for(auto pair : memo) {
            max_count = max(max_count, pair.second);
        }

        return max_count;
    }
};

