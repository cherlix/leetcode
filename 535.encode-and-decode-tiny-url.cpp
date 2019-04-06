/*
 * @lc app=leetcode id=535 lang=cpp
 *
 * [535] Encode and Decode TinyURL
 *
 * https://leetcode.com/problems/encode-and-decode-tinyurl/description/
 *
 * algorithms
 * Medium (76.15%)
 * Total Accepted:    68.9K
 * Total Submissions: 90.4K
 * Testcase Example:  '"https://leetcode.com/problems/design-tinyurl"'
 *
 * Note: This is a companion problem to the System Design problem: Design
 * TinyURL.
 * 
 * TinyURL is a URL shortening service where you enter a URL such as
 * https://leetcode.com/problems/design-tinyurl and it returns a short URL such
 * as http://tinyurl.com/4e9iAk.
 * 
 * Design the encode and decode methods for the TinyURL service. There is no
 * restriction on how your encode/decode algorithm should work. You just need
 * to ensure that a URL can be encoded to a tiny URL and the tiny URL can be
 * decoded to the original URL.
 * 
 */
class Solution {
public:
    unordered_map<string, string> code_to_url;
    unordered_map<string, string> url_to_code;

    vector<char> library;

    int current_character_pos = 0;
    int current_index = 1;
    const int TOTAL_CHARACTERS = 7;

    Solution() {
        for (int i = 'a'; i <= 'z'; ++i) {
            library.push_back(char(i));
        }
        for (int i = 'A'; i <= 'Z'; ++i) {
            library.push_back(char(i));
        }
        for (int i = '0'; i <= '9'; ++i) {
            library.push_back(char(i));
        }
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (url_to_code.find(longUrl) != url_to_code.end()) {
            return url_to_code[longUrl];
        }

        string result;

        if (current_character_pos > 0) {
            result += string(current_character_pos, library[library.size() - 1]);
        }

        result += string(1, library[current_index]);

        current_index = current_index + 1 >= library.size() ? 1 : current_index + 1;

        if (current_index + 1 < TOTAL_CHARACTERS) {
            result += string(TOTAL_CHARACTERS - current_character_pos - 1, library[0]);
        }
        
        code_to_url[result] = longUrl;
        url_to_code[longUrl] = result;

        return result;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (code_to_url.find(shortUrl) != code_to_url.end()) {
            return code_to_url[shortUrl];
        }

        return string();
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

