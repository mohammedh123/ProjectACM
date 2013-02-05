// Solution to problem 10038
// by: Mohammed Hossain
// Language: C++

#include <string>
#include <cstring> //for memset
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class P10038
{
    inline static unsigned int abs(int max) { return max < 0 ? -1*max : max; }
public:
    static void Solve()
    {
        int numNumbers;
        int numbers[3000];
        vector<int> numSet;
        numSet.reserve(2999);

        while(cin >> numNumbers) {
            memset(numbers, 0, numNumbers*sizeof(int));
            numSet.clear();

            for(int i = 0; i < numNumbers; i++) {
                cin >> numbers[i];

                if(i == 0)
                    continue;

                numSet.push_back(abs(numbers[i]-numbers[i-1]));
            }

            sort(numSet.begin(), numSet.end());

            bool jolly = true;
            for(int i = 0; i < numSet.size(); i++) {
                if(numSet[i] != i+1) {
                    jolly = false;
                    break;
                }
            }

            cout << (jolly ? "Jolly" : "Not jolly") << endl;
        }
    }
};

int main()
{    
    P10038::Solve();
}