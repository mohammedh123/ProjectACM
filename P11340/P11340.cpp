// Solution to problem 11340
// by: Mohammed Hossain
// Language: C++

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class P11340
{
public:
    static void Solve()
    {
        int numTests;

        cin >> numTests;

        for(int i = 0; i < numTests; i++) {
            int paidCharNum;

            cin >> paidCharNum;

            map<unsigned char, long long> theMap;
            unsigned char c;
            long long cents;
            while(paidCharNum > 0) {
                cin >> c >> cents;

                theMap[c] = cents;

                paidCharNum--;
            }

            int numLines;
            cin >> numLines;
        
            vector<string> lines;
            lines.reserve(numLines);
            string line;
            getline(cin, line);

            long long totalCents = 0;
            while(numLines > 0) {
                getline(cin, line);

                for(int c = 0; c < line.size(); c++) {
                    totalCents += theMap[line[c]];
                }

                numLines--;
            }

            cout << totalCents/100 << "." << ((totalCents % 100) <= 9 ? "0" : "") << totalCents % 100 << "$" << endl;
        }
    }
};

int main()
{    
    P11340::Solve();
}