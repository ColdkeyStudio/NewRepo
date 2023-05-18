#include<string>
#include<bitset>
using namespace std;
//暴力
class Solution {
public:
	bool queryString(string s, int n) {
		for (int i = 1; i <= n; i++)//枚举n
		{
			string bin = bitset<32>(i).to_string();
			bin = bin.substr(bin.find('1'));//从第一个1开始转换子字符串
			if (s.find(bin) == string::npos)return false;//如果有没找到的n，就返回false
		}
		return true;
	}
};

//hash表存
class Solution {
public:
	bool queryString(string s, int n) {
		for (int i = 1; i <= n; i++)//枚举n
		{
			string bin = bitset<32>(i).to_string();
			bin = bin.substr(bin.find('1'));//从第一个1开始转换子字符串
			if (s.find(bin) == string::npos)return false;//如果有没找到的n，就返回false
		}
		return true;
	}
};

