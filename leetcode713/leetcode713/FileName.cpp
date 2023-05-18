#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int c = 1;//³Ë»ý
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            c *= nums[r];
            while (l<=r&&c >= k)
            {
                c /= nums[l];
                l++;
            }
            cnt += r - l + 1;
        }
        return cnt;
    }
};