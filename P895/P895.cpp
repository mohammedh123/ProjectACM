// Solution to problem 895
// by: Mohammed Hossain
// Language: C++

#include <string>
#include <cstring> //for memset
#include <iostream>

using namespace std;

class P895
{
public:
    static void Solve()
    {
        int freq[1000][26];
        int letterFreq[26];
        memset(freq, 0, 1000*26*sizeof(int));

        string line, word;
        bool dictionaryPart = true;

        int counter = 0;
        while(cin >> word) {
            if(word == "#")
                break;

            for(int i = 0; i < word.size(); i++) {
                freq[counter][word[i]-'a']++;
            }

            counter++;
        }

        getline(cin, line);

        while(getline(cin, line))
        {
            if(line == "#")
                break;
            
            memset(letterFreq, 0, 26*sizeof(int));
            for(int j = 0; j < line.size(); j++) {
                if(line[j] != ' ') {
                    letterFreq[line[j]-'a']++;
                }
            }

            int wordCount = 0;
            for(int i = 0; i < counter; i++) {
                //check against the frequency of letters of each word, if still valid at end, ++
                bool match = true;
                
                for(int r = 0; r < 26; r++) {
                    if(freq[i][r] > letterFreq[r]) {
                        match = false;
                        break;
                    }
                }

                if(match) wordCount++;
            }

            cout << wordCount << endl;
        }        
    }
};

int main()
{    
    P895::Solve();
}