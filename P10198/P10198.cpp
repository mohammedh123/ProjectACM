// Solution to problem 10198
// by: Mohammed Hossain
// Language: C++

#include <cstring> //for gcc compile
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class BigInteger
{
    static const int MAX_SIZE = 407;
public:
    int data[MAX_SIZE];

    BigInteger() { memset(data, 0, sizeof(data)); }
    BigInteger(const string& s) 
    {
        memset(data, 0, sizeof(data)); 
        int idx = MAX_SIZE-1;
        for(int i = s.size()-1; i >= 0; i--)
        {
            data[idx] = s[i]-'0';

            idx--;
        }
    }

    void SetData(const BigInteger& bi) { memcpy(data, bi.data, sizeof(data)); }
    void SpecializedAddOn(const BigInteger& b1, const BigInteger& b2, const BigInteger& b3)
    {
        for(int i = MAX_SIZE-1; i >= 0; i--)
        {
            data[i] += b1.data[i];
            data[i] += b1.data[i];
            data[i] += b2.data[i];
            data[i] += b3.data[i];

            if(data[i] >= 10)
            {
                int remainder = data[i] / 10;

                data[i] %= 10;
                data[i-1] += remainder;
            }
        }
    }

    string str() const
    {
        stringstream ss;
        bool leadingZero = true;
        for(int i = 0; i < MAX_SIZE-1; i++)
        {
            if(data[i] != 0)
                leadingZero = false;

            if(!leadingZero)
            {
                ss << data[i];    
            }
        }

        ss << data[MAX_SIZE-1];

        return ss.str();
    }
};

class P10198
{
public:
    static void Solve()
    {
        BigInteger* dp = new BigInteger[1001];

        dp[0] = BigInteger("1");
        dp[1] = BigInteger("2");
        dp[2] = BigInteger("5");

        for(int i = 3; i < 1001; i++)
        {
            dp[i].SpecializedAddOn(dp[i-1],dp[i-2],dp[i-3]);
        }

        int n;
        while(cin >> n)
            cout << dp[n].str() << endl;

        delete[] dp;
    }
};

int main()
{    
    P10198::Solve();
}