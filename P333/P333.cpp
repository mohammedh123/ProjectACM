// Solution to problem 333
// by: Mohammed Hossain
// Language: C++

#include <string>
#include <cstring> //for memset
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class P333
{
    static void inplace_trim(string& str)
    {
        size_t idx = str.find_last_not_of(" ");
        
        if(idx != string::npos)
            str.erase(idx+1);

        idx = str.find_first_not_of(" ");
        
        if(idx != string::npos)
            str.erase(0, idx);
    }

    static bool is_hyphen(char c) { return c == '-'; }
public:
    static void Solve()
    {
        string isbnLine, trimmedIsbn;
        isbnLine.reserve(80);
        trimmedIsbn.reserve(80);
        vector<int> partialSums;
        partialSums.reserve(10);

        while(getline(cin, isbnLine)) {
            partialSums.clear();

            //trim
            inplace_trim(isbnLine);

            trimmedIsbn = isbnLine;

            //erase hyphens
            isbnLine.erase(std::remove_if(isbnLine.begin(), isbnLine.end(), is_hyphen), isbnLine.end());

            int lastSum = 0, nbr;
            char ch;
            int s2 = 1;
            if(isbnLine.size() == 10)
            {
                s2 = 0;
                for(int i = 0; i < isbnLine.size(); i++) {
                    ch = isbnLine[i];

                    if(!((ch == 'X' && i == 9) || (ch >= '0' && ch <= '9'))) {
                        s2 = 1;
                        break;
                    }

                    nbr = (ch == 'X' ? 10 : ch-'0');

                    partialSums.push_back(lastSum + nbr);

                    lastSum += nbr;
                    s2 += lastSum;
                }
            }

            bool correct = s2 % 11 == 0;
            cout << trimmedIsbn << " is " << (correct ? "correct" : "incorrect") << "." << endl;
        }
    }
};

int main()
{    
    P333::Solve();
}