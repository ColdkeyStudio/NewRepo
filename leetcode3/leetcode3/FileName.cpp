#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> fd;
        int n = s.length();
        int ans = 0;
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            while (fd.find(s[r])!=fd.end())
            {
                fd.erase(s[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
            fd.insert(s[r]);
        }
        return ans;
    }
};