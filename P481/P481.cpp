// Solution to problem 481
// by: Mohammed Hossain
// Language: C++

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
    
class P481
{
    static void LongestIncreasingSubsequence(const vector<int>& numbers, vector<int>& outputVec)
    {
        vector<int> parents;
        parents.resize(numbers.size());
        int x,y;

        if(numbers.empty())
            return;

        outputVec.push_back(0);

        for(int i = 1; i < numbers.size(); i++) {
            if(numbers[i] > numbers[outputVec.back()])
            {
                parents[i] = outputVec.back();
                outputVec.push_back(i);
                continue;
            }

            for(x = 0, y = outputVec.size()-1; x < y;)
            {
                int c = (x+y)/2;
                if(numbers[outputVec[c]] < numbers[i])
                    x = c+1;
                else
                    y = c;
            }

            if(numbers[i] < numbers[outputVec[x]])
            {
                if(x > 0) parents[i] = outputVec[x-1];
                outputVec[x] = i;
            }
        }

        for(x = outputVec.size(), y = outputVec.back(); x--; y = parents[y])
            outputVec[x] = y;
    }
public:
    static void Solve()
    {
        vector<int> nums;
        int num;

        while(cin >> num)
            nums.push_back(num);

        vector<int> answerIndexes;
        LongestIncreasingSubsequence(nums, answerIndexes);

        cout << answerIndexes.size() << endl;
        cout << "-" << endl;
        for(int i = 0; i < answerIndexes.size(); i++)
            cout << nums[answerIndexes[i]] << endl;
    }
};

int main()
{   
    P481::Solve();
}