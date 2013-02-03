// Solution to problem 10189
// by: Mohammed Hossain
// Language: C++

#include <string>
#include <cstring> //for memset
#include <iostream>

using namespace std;

class P10189
{
    static void IncrementNeighbors(int* grid, int x, int y, int w, int h)
    {
        for(int r = y-1; r <= y+1; r++) {
            for(int c = x-1; c <= x+1; c++) {
                if(r == y && c == x) continue;

                if(r >= 0 && r < h && c >= 0 && c < w) {
                    if(grid[r*w+c] != -1) {
                        grid[r*w+c]++;
                    }
                }
            }
        }
    }

    static void PrintGrid(int* grid, int w, int h)
    {
        for(int y = 0; y < h; y++) {
            for(int x = 0; x < w; x++) {
                if(grid[y*w+x] == -1) {
                    cout << "*";
                }
                else {
                    cout << grid[y*w+x];
                }
            }

            cout << "\n";
        }
    }

public:
    static void Solve()
    {
        int w, h, idx=0;
        string line;
        int* grid;
        char spot;

        while(cin >> h >> w) {
            if(h == w && h == 0) {
                break;
            }

            idx++;
            
            if(idx > 1)
                cout << "\n";

            grid = new int[w*h];
            memset(grid, 0, w*h*sizeof(int)); //entire grid is of 0s

            for(int r = 0; r < h; r++) {
                cin >> line;

                for(int c = 0; c < w; c++) {
                    spot = line.at(c);

                    if(spot == '*') {
                        grid[r*w+c] = -1;
                        IncrementNeighbors(grid, c, r, w, h);
                    }
                }
            }

            cout << "Field #" << idx << ":" << "\n";
            PrintGrid(grid, w, h);

            delete[] grid;
        }
    }
};

int main()
{    
    P10189::Solve();
}