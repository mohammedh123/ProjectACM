// Solution to problem 846
// by: Mohammed Hossain
// Language: C++

#include <iostream>

using namespace std;

class P846
{
public:
    static void Solve()
    {
        int numTestCases;

        cin >> numTestCases;
        while(numTestCases--)
        {
            int totalSteps = 0, currentStepSize = 1;
            int left, right;

            cin >> left >> right;

            while(true)
            {
                if(left < right)
                {
                    left += currentStepSize;
                    totalSteps++;
                }
                else break;
                
                if(right > left)
                {
                    right -= currentStepSize;
                    totalSteps++;
                }
                else break;

                currentStepSize++;
            }

            cout << totalSteps << endl;
        }
    }
};

int main()
{    
    P846::Solve();
}