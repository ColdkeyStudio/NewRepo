#include<string>
#include<bitset>
using namespace std;
//����
class Solution {
public:
	bool queryString(string s, int n) {
		for (int i = 1; i <= n; i++)//ö��n
		{
			string bin = bitset<32>(i).to_string();
			bin = bin.substr(bin.find('1'));//�ӵ�һ��1��ʼת�����ַ���
			if (s.find(bin) == string::npos)return false;//�����û�ҵ���n���ͷ���false
		}
		return true;
	}
};

//hash���
class Solution {
public:
	bool queryString(string s, int n) {
		for (int i = 1; i <= n; i++)//ö��n
		{
			string bin = bitset<32>(i).to_string();
			bin = bin.substr(bin.find('1'));//�ӵ�һ��1��ʼת�����ַ���
			if (s.find(bin) == string::npos)return false;//�����û�ҵ���n���ͷ���false
		}
		return true;
	}
};

