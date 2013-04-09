// Solution to problem 10194
// by: Mohammed Hossain
// Language: C++

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Team
{
public:
    string name;
    int gamesPlayed, wins, ties, losses, goalsScored, goalsAgainst;

    Team() : gamesPlayed(0), wins(0), ties(0), losses(0), goalsScored(0), goalsAgainst(0)
    {

    }

    int totalPointsEarned() const 
    {
        return wins*3 + ties;
    }

    int goalDiff() const
    {
        return goalsScored - goalsAgainst;
    }
};

class Tournament
{
public:
    string name;
    map<const string, Team> teamInfos;
};

bool LowerCaseCmpFunc(char l, char r)
{
    return tolower(l) < tolower(r);
}

struct SortTeams
{
    bool operator()(const Team& lhs, const Team& rhs)
    {
        if(lhs.totalPointsEarned() < rhs.totalPointsEarned())
            return true;
        else if(lhs.totalPointsEarned() == rhs.totalPointsEarned())
        {
            if(lhs.wins < rhs.wins)
                return true;
            else if(lhs.wins == rhs.wins)
            {
                if(lhs.goalDiff() < rhs.goalDiff())
                    return true;
                else if(lhs.goalDiff() == rhs.goalDiff())
                {                
                    if(lhs.goalsScored < rhs.goalsScored)
                        return true;
                    else if(lhs.goalsScored == rhs.goalsScored)
                    {
                        if(lhs.gamesPlayed > rhs.gamesPlayed)
                            return true;
                        else if(lhs.gamesPlayed == rhs.gamesPlayed)
                        {
                            return lexicographical_compare(rhs.name.begin(), rhs.name.end(),lhs.name.begin(), lhs.name.end()
                                , LowerCaseCmpFunc);
                        }
                
                        return false;
                    }
                
                    return false;
                }
                
                return false;
            }

            return false;
        }
        
        return false;
    }
};

static bool operator<(const Team& lhs, const Team& rhs)
{
    return SortTeams()(lhs, rhs);
}

class P10194
{
public:
    static void Solve()
    {
        int numTeams, numGamesPlayed, numTournies, team1goals, team2goals;
        string tournamentName, line, team1name, team2name, teamName, temp;
        vector<Tournament> tournies;
        vector<Team> tournyTeams;

        tournamentName.reserve(100);
        teamName.reserve(30);

        cin >> numTournies;
        getline(cin, line);

        for(int cd = 0; cd < numTournies; cd++) {
            if(cd != 0)
                cout << endl;

            Tournament tourny;
            getline(cin, tournamentName);
            
            cin >> numTeams;
            getline(cin, line);

            for(int i = 0; i < numTeams; i++) { 
                getline(cin, teamName);

                tourny.teamInfos[teamName].name = teamName;
            }

            cin >> numGamesPlayed;
            getline(cin, line);

            for(int i = 0; i < numGamesPlayed; i++) {
                getline(cin, line);

                team1name = line.substr(0, line.find('#'));
                line = line.substr(line.find('#')+1);

                temp = line.substr(0, line.find('@'));
                line = line.substr(line.find('@')+1);
                team1goals = atoi(temp.c_str());
                                                
                temp = line.substr(0, line.find('#'));
                team2name = line.substr(line.find('#')+1);
                team2goals = atoi(temp.c_str());
                
                tourny.teamInfos[team1name].goalsScored += team1goals;
                tourny.teamInfos[team2name].goalsScored += team2goals;
                tourny.teamInfos[team2name].goalsAgainst += team1goals;
                tourny.teamInfos[team1name].goalsAgainst += team2goals;
                tourny.teamInfos[team1name].gamesPlayed++;
                tourny.teamInfos[team2name].gamesPlayed++;

                if(team1goals > team2goals)
                {
                    tourny.teamInfos[team1name].wins++;
                    tourny.teamInfos[team2name].losses++;
                }
                else if(team1goals == team2goals) {                    
                    tourny.teamInfos[team1name].ties++;
                    tourny.teamInfos[team2name].ties++;
                }
                else {            
                    tourny.teamInfos[team2name].wins++;
                    tourny.teamInfos[team1name].losses++;
                }
            }

            tournyTeams.clear();

            for(map<const string, Team>::iterator it = tourny.teamInfos.begin(); it != tourny.teamInfos.end(); it++)
                tournyTeams.push_back(it->second);
            
            sort(tournyTeams.begin(), tournyTeams.end(), SortTeams());

            cout << tournamentName << endl;
            for(int i = tournyTeams.size()-1; i >= 0; i--) {
                cout << (tournyTeams.size()-i) << ") " << tournyTeams[i].name << " " << tournyTeams[i].totalPointsEarned() << "p, " << tournyTeams[i].gamesPlayed << "g (" << tournyTeams[i].wins << "-" << tournyTeams[i].ties << "-" << tournyTeams[i].losses << "), " << tournyTeams[i].goalDiff() << "gd (" << tournyTeams[i].goalsScored << "-" << tournyTeams[i].goalsAgainst << ")" << endl;
            }
        }
    }
};

int main()
{    
    P10194::Solve();
}