// Solution to problem 10099
// by: Mohammed Hossain
// Language: C++

#include <iostream>
#include <bitset>
#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int Infinity = 100000;

class P10099
{
public:
    static void Solve()
    {
        int V, E;
        int graph[101][101];
        int n = 1;

        while(!cin.eof() && cin >> V >> E)
        {
            if(V == E && V == 0)
                break;


            //my crappy floyd's algorithm implementation

            for(int i = 1; i <= V; i++)
            {   
                for(int j = 1; j <= V; j++) graph[i][j] = -Infinity;

                graph[i][i] = 0;
            }
            for(int i = 0; i < E; i++)
            {
                int s, e, dist;

                cin >> s >> e >> dist;
                
                graph[s][e] = graph[e][s] = dist;
            }

            int S, E, GroupSize;

            cin >> S >> E >> GroupSize;

            if(S == E)
            {
                cout << "Scenario #" << n++ << endl;
                cout << "Minimum Number Of Trips = 1" << endl << endl;
            }
            else
            {
                int minChoice;
                for(int         k = 1; k <= V; k++) {
                    for(int     i = 1; i <= V; i++) {
                        for(int j = 1; j <= V; j++) {
                            minChoice = min(graph[i][k], graph[k][j]);

                            graph[i][j] = max(graph[i][j], minChoice);
                        }
                    }
                }         

                cout << "Scenario #" << n++ << endl;
                cout << "Minimum Number Of Trips = " << (int)ceil((float)GroupSize/(graph[S][E]-1)) << endl << endl;
            }
        }
    }
};

int main()
{    
    P10099::Solve();
}