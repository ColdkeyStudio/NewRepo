#include<iostream>
#include<string>
using namespace std;

class leet2437 {
public:

    int countTime(string time)
    {
        int counthour = 0;
        int countminute = 0;
        for (int i = 0; i < 24; i++)
        {
            int h1 = i / 10;
            int h2 = i % 10;
            if ((time[0] == '?' || time[0] == h1 + '0') && (time[1] == '?' || time[1] == h2 + '0'))
            {
                ++counthour;
            }
        }
        for (int i = 0; i < 60; i++)
        {
            int m1 = i / 10;
            int m2 = i % 10;
            if ((time[3] == '?' || time[3] == m1 + '0') && (time[4] == '?' || time[4] == m2 + '0'))
            {
                ++countminute;
            }
        }return counthour * countminute;
    }

};

int leet2437test(string t)
{
    leet2437 tes;
    return tes.countTime(t);
}

int main()
{
    cout << leet2437test("?0:??");
}