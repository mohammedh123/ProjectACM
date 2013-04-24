// Solution for problem 10161
// Mohammed Hossain 0392451

#include <iostream>
#include <math.h>

using namespace std;

class P10161
{
public:
    static void Solve()
    {
        int N;

        while(cin >> N)
        {
            if(N == 0) break;

            //find the maximum square
            double sqrtN = sqrt(N+1e-7);
            int rowOrCol;
            for(int i = 1;; i++)
            {
                if(i*i >= N)
                {
                    rowOrCol = i;
                    break;
                }
            }

            int val = 1;

            //find the maximum diagonal
            for(int i = 1;;i++)
            {
                val += 2*(i-1);

                if(i == rowOrCol)
                    break;
            }

            //val = the value at (rowOrCol, rowOrCol)
            if(val == N)
                cout << rowOrCol << " " << rowOrCol << endl;

            //try every value to the left, and below

            int newVal = val;
            bool found = false;
            for(int i = rowOrCol-1; i >= 1; i--)
            {
                newVal = newVal + (rowOrCol % 2 == 0 ? -1 : 1);

                if(newVal == N)
                {
                    cout << i << " " << rowOrCol << endl;
                    found = true;
                    break;
                }
            }

            newVal = val;
            if(!found)
            {
                for(int i = rowOrCol-1; i >= 1; i--)
                {
                    newVal = newVal + (rowOrCol % 2 == 0 ? 1 : -1);

                    if(newVal == N)
                    {
                        cout << rowOrCol << " " << i << endl;
                        break;
                    }
                }
            }
        }
    }
};

int main()
{
    P10161::Solve();
}