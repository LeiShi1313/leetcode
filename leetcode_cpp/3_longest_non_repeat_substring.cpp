#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charIndex(256, -1);
        int longest = 0;
        int i=0, j=0;
        for (i=0; i<s.length(); i++) {
            cout << s[i] << charIndex[s[i]] << endl;
            j = max(charIndex[s[i]]+1, j);
            charIndex[s[i]] = i;
            longest = max(longest, i-j+1);
        }
        return longest;
    }
};

int main() {
    cout << Solution().lengthOfLongestSubstring("abcabcbb") << endl;
}
