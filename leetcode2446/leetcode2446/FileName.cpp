#include<vector>
#include<string>
using namespace std;
//废案，直接拿vec[ ]来比较就行
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int e1s = event1[0][0] * 600 + event1[0][1] * 60 + event1[0][3] * 10 + event1[0][4];
        int e1e = event1[1][0] * 600 + event1[1][1] * 60 + event1[1][3] * 10 + event1[1][4];
        int e2s = event2[0][0] * 600 + event2[0][1] * 60 + event2[0][3] * 10 + event2[0][4];
        int e2e = event2[1][0] * 600 + event2[1][1] * 60 + event2[1][3] * 10 + event2[1][4];
        if (true)
        {

        }
    }
};