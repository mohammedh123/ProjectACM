// Solution to problem 10069
// by: Mohammed Hossain
// Language: C++

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

class BigInteger
{
public:
    int data[101];

    BigInteger() { memset(data, 0, sizeof(data)); }
    BigInteger(const string& s) 
    {
        memset(data, 0, sizeof(data)); 
        int idx = 100;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            data[idx] = s[i]-'0';

            idx--;
        }
    }

    void SetData(const BigInteger& bi) { memcpy(data, bi.data, sizeof(data)); }
    void AddOn(const BigInteger& bi)
    {
        for(int i = 100; i >= 0; i--)
        {
            data[i] += bi.data[i];

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
        for(int i = 0; i < 100; i++)
        {
            if(data[i] != 0)
                leadingZero = false;

            if(!leadingZero)
            {
                ss << data[i];    
            }
        }

        ss << data[100];

        return ss.str();
    }
};

class P10069
{
    static BigInteger* NumDistinctSequences(const string& X, const string& Z)
    {
        int xWidth = X.size()+1;
        int zWidth = Z.size()+1;
        vector<BigInteger> dp;
        dp.resize(xWidth*zWidth);

        for(int i = 0; i < xWidth; i++) {
        
            dp[Z.size()*xWidth + i] = BigInteger("1");
        }

        for(int i = X.size() - 1; i >= 0; i--) {
            for(int j = Z.size()-1; j >= 0; j--) {
                dp[i + j*xWidth].SetData(dp[i+1+j*xWidth]);

                if(X[i] == Z[j])
                    dp[i + j*xWidth].AddOn(dp[i+1+(j+1)*xWidth]);
            }
        }

        BigInteger* bi = new BigInteger(dp[0]);

        return bi;
    }
public:
    static void Solve()
    {
        int numCases;

        cin >> numCases;

        string X, Z;    
        for(int i = 0; i < numCases; i++) {
            cin >> X >> Z;

            BigInteger* answer = NumDistinctSequences(X,Z);
        
            cout << answer->str() << endl;

            delete answer;
        }
    }
};

int main()
{
    P10069::Solve();
}