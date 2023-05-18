#include<vector>
using namespace std;
//f(i)=max(f(i-1),f(i-2)+nums[i])
//f(i+2)=max(f(i+1),f(i)+nums[i])

class Solution {
public:
    int rob(vector<int>& nums) {
        int f2 = -1;
        int f1 = 0;
        int f0 = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            f2 = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = f2;
        }
        return f1;
    }
};