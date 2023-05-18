#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;
        int left = 0;
        int rig = 0;
        int sum = nums[0];
        while (rig != n)
        {
            if (sum < target)
            {
                ++rig;
                if (rig != n)
                {
                    sum += nums[rig];
                }
            }
            else
            {
                ans = min(ans, rig - left+1);
                sum -= nums[left];
                ++left;
            }
        }
        if (ans == n + 1)ans = 0;
        return ans;
    }
};