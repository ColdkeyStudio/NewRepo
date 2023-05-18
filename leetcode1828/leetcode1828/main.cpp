#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
		int m = points.size();
		int n = queries.size();
		vector<int> ans(n,0);
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++)
			{
				if (pow(queries[j][2],2)>=pow((points[i][0]-queries[j][0]),2)+pow((points[i][1] - queries[j][1]),2))
				{
					++ans[j];
				}
			}
		}
		return ans;
    }
};

int main() {
	int i = pow(10,2);
	cout << i;
}