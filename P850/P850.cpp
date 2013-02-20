// Solution to problem 850
// by: Mohammed Hossain
// Language: C++

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class P850
{
    static bool FillCharMap(map<char,char>& charMap, const vector<string>& words, const vector<string>& brownFoxWords)
    {        
        //plot the mappings
        for(int j = 0; j < words.size(); j++) {
            for(int c = 0; c < words[j].size(); c++) {
                char mappee = words[j].at(c);
                char mapper = brownFoxWords[j].at(c);

                if(charMap.find(mappee) != charMap.end()) {
                    //if the character is already in the map, make sure that the character is correct
                    if(mapper != charMap[mappee])
                        return false;
                }
                else {
                    charMap[mappee] = mapper;
                }
            }
        }

        return charMap.size() == 26;
    }
public:
    static void Solve()
    {
        int numCases, lineNum;
        string line, word;
        vector<string> lines;
        vector<string> brownFoxWords;
        brownFoxWords.push_back("the");
        brownFoxWords.push_back("quick");
        brownFoxWords.push_back("brown");
        brownFoxWords.push_back("fox");
        brownFoxWords.push_back("jumps");
        brownFoxWords.push_back("over");
        brownFoxWords.push_back("the");
        brownFoxWords.push_back("lazy");
        brownFoxWords.push_back("dog");

        vector<vector<string> > words;
        map<char, char> charMap;

        cin >> numCases;

        for(int i = 0; i < numCases; i++) {
            lineNum = 0;
            lines.clear();
            words.clear();
            charMap.clear();
            
            if(i == 0) {
                getline(cin, line);
                getline(cin, line);
            }
            
            bool justStarted = true;

            while(true && cin.eof() != true)
            {
                getline(cin, line);
                if(line == "" && !justStarted)
                    break;

                justStarted = false;

                lines.push_back(line);
                words.push_back(vector<string>());

                stringstream ss(line);
                
                while(ss >> word)
                    words[lineNum].push_back(word);

                lineNum++;
            }
            
            //find the first mapping
            int lineMap = -1;
            for(int j = 0; j < lines.size(); j++) {
                if(words[j].size() == brownFoxWords.size()) {
                    bool allMatch = true;

                    for(int c = 0; c < words[j].size(); c++) {
                        if(words[j][c].size() != brownFoxWords[c].size()) {
                            allMatch = false;
                            break;
                        }
                    }

                    if(allMatch) {
                        if(FillCharMap(charMap, words[j], brownFoxWords))
                        {
                            lineMap = j;
                            break;
                        }
                        else
                            continue;
                    }
                    else
                        continue;
                }
            }

            if(lineMap == -1)
                cout << "No solution." << endl;
            else {
                for(int l = 0; l < lines.size(); l++) {
                    for(int w = 0; w < lines[l].size(); w++) {
                        cout << (lines[l][w] == ' ' ? ' ' : charMap[lines[l][w]]);
                    }

                    cout << endl;
                }
            }

            if(i < numCases - 1)
                cout << endl;
        }
    }
};

int main()
{    
    P850::Solve();
}