// Solution to problem 259
// by: Mohammed Hossain
// Language: C++

#include <iostream>
#include <math.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;



// 0 is source
// 1-26 is A-Z
// 27-36 = 0-9
// 37 is end

const int MAX_V = 38;
const int Infinity = 100000;
int res[MAX_V][MAX_V], mf, f, s, t;

vector<int> p;

void augment(int v, int minEdge) { 
    // reach the source, record minEdge in a global variable 'f' 
    if (v == s) { f = minEdge; return; } 
    // recursive call 
    else if (p[v] != -1) { 
        augment(p [v], min(minEdge, res[p[v]][v])); 
        // alter residual capacities 
        res[p[v]][v] -= f; res[v][p[v]] += f;
    } 
}

struct ComputerProgram
{
    char program;
    int numPeople;
    vector<int> allocatedComputers;
};

class P259
{
    static void CalculateFlow()
    {        
        while (1) {
            f = 0;

            vector<int> dist(MAX_V, Infinity); dist[s] = 0;

            queue<int> q; q.push(s);
            p.assign(MAX_V, -1);
            while (!q.empty()) {

                int u = q.front(); q.pop();
                if (u == t) break;

                for (int v = 0; v < MAX_V; v++)

                    if (res[u][v] > 0 && dist[v] == Infinity) dist[v]
                    = dist[u] + 1, q.push(v), p[v] = u;
            }
            augment(t, Infinity);

            if (f == 0) break;

            mf += f;
        }
    }

    static void ResetGraph()
    {
        memset(res, 0, MAX_V*MAX_V*sizeof(int));
    }

    static void SetupGraph(const vector<ComputerProgram>& progs)
    {
        s = 0;
        t = 37;

        int progCode;
        int compCode;

        for(int i = 0; i < progs.size(); i++)
        {
            progCode = progs[i].program-'A'+1;

            res[s][progCode] += progs[i].numPeople;

            for(int x = 0; x < progs[i].allocatedComputers.size(); x++)
            {
                compCode = 27 + progs[i].allocatedComputers[x];
                
                res[progCode][compCode] = 1;
            }
        }

        for(int i = 27; i <= 36; i++)
            res[i][t] = 1;
    }
public:
    static void Solve()
    {
        
        int idx = 0;
        while(!cin.eof())
        {
            int totalApps = 0;

            ResetGraph();

            string str;
            vector<ComputerProgram> programs;
            
            if(idx > 0)
            {
                getline(cin,str);
            }

            while(getline(cin,str) && !cin.eof())
            {
                string progPeople, computers;

                if(str == "")
                    break;

                stringstream ss;
                ss << str;
                ss >> progPeople >> computers;

                ComputerProgram prog;
                prog.program = progPeople[0];
                prog.numPeople = progPeople[1] - '0';

                totalApps += prog.numPeople;
                
                for(int i = 0; i < computers.size()-1; i++)
                {
                    prog.allocatedComputers.push_back(computers[i]-'0');
                }

                programs.push_back(prog);
            }

            SetupGraph(programs);
            
            CalculateFlow();

            string output;
            output.resize(10,'_');

            for(int i = 27; i <= 36; i++)
            {
                for(int j = 1; j <= 26; j++)
                {
                    if(res[i][j] == 1)
                    {
                        output[i-27] = (char)('A' + j-1);
                        break;
                    }
                }
            }

            if(mf == totalApps)
                cout << output << endl;
            else
                cout << "!" << endl;

            idx++;
        }
    }
};

int main()
{    
    P259::Solve();
}