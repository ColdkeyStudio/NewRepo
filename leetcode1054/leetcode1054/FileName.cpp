#include<vector>
using namespace std;
//11112233
//不能用，得用最大堆或者计数穿插
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		int l = barcodes.size();
		for (int i = 0; i < l; i++)
		{
			if (barcodes[i] == barcodes[i + 1])
			{
				for (int j = l - 1; j > -1; --j)
				{
					if (barcodes[i + 1] != barcodes[j])
					{
						swap(barcodes[i + 1], barcodes[j]);
						break;
					}
				}
			}
		}
		for (int i = l-1; i > 0; i--)
		{
			if (barcodes[i] == barcodes[i - 1])
			{
				for (int j = 0; j < l; j++)
				{
					if (barcodes[i - 1] != barcodes[j])
					{
						swap(barcodes[i - 1], barcodes[j]);
						break;
					}
				}
			}
		}
		return barcodes;
    }
};