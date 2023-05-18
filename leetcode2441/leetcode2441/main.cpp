#include<vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int k = -1;
        for (auto a:nums)
        {
            if (a>0 && s.count(-a)==1)
            {
                k = max(k, a);
            }
        }
        return k;
    }
};