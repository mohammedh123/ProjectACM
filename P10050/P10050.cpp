// Solution to problem 10050
// by: Mohammed Hossain
// Language: C++

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class P10050
{
public:
    static void Solve()
    {
        int numTestCases;
        
        cin >> numTestCases;

        vector<short> hartalParameters;
        hartalParameters.resize(100, 0);

        while(numTestCases--) {
            short numDays, numParties;

            cin >> numDays >> numParties;
            
            for(int i = 0; i < numParties; i++) {
                cin >> hartalParameters[i];
            }

            int hartalDays = 0;
            for(int d = 2; d <= numDays; d++) {
                for(int p = 0; p < numParties; p++) { 
                    if((d % (hartalParameters[p]) == 0) && (d % 7 != 6) && (d % 7 != 0)) {
                        hartalDays++;
                        break;
                    }
                }
            }

            cout << hartalDays << endl;
        }
    }
};

int main()
{    
    P10050::Solve();
}