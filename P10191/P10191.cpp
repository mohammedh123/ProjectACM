// Solution to problem 10191
// by: Mohammed Hossain
// Language: C++

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Date
{
public:
    int hours, minutes;

    Date() : hours(0), minutes(0) {}

    Date(const std::string& fmt)
    {
        size_t idx = fmt.find(':');
        
        hours = atoi(fmt.substr(0, idx).c_str());
        minutes = atoi(fmt.substr(idx+1).c_str());
    }

    Date(int hour, int mins) : hours(hour), minutes(mins)
    { }

    Date(int totalMinutes) : hours(totalMinutes/60), minutes(totalMinutes % 60)
    { }

    const int GetTotalMinutes() const { return hours*60 + minutes; }
    
};

static bool operator!=(const Date& lhs, const Date& rhs)
{
    return lhs.hours != rhs.hours || lhs.minutes != rhs.minutes;
}

static bool operator>(const Date& lhs, const Date& rhs)
{
    return lhs.GetTotalMinutes() > rhs.GetTotalMinutes();
}

static bool operator<(const Date& lhs, const Date& rhs)
{
    return lhs.GetTotalMinutes() < rhs.GetTotalMinutes();
}

static Date operator-(const Date& lhs, const Date& rhs)
{
    return Date(lhs.GetTotalMinutes() - rhs.GetTotalMinutes());
}

struct SortDatePairByLength
{
    bool operator()(const pair<Date, Date>& lhs, const pair<Date, Date>& rhs)
    {
        return lhs.second > rhs.second;
    }
};

struct SortDatePairByBeginDate
{
    bool operator()(const pair<Date, Date>& lhs, const pair<Date, Date>& rhs)
    {
        return lhs.first < rhs.first;
    }
};

class P10191
{
    static string GetEquivalent(const Date& date)
    {
        int totalMins = date.GetTotalMinutes();
        stringstream ss;

        if(totalMins < 60)
            ss << totalMins << " minutes";
        else
            ss << (totalMins / 60) << " hours and " << (totalMins % 60) << " minutes";

        return ss.str();
    }
public:
    static void Solve()
    {
        const Date tenAM(10, 0);
        const Date sixPM(18, 0);
        int numTestCases;
        string line, startHour, endHour;
        vector<pair<Date, Date> > appointments;
        vector<pair<Date, Date> > naps;
        
        line.reserve(255);
        startHour.reserve(6);
        endHour.reserve(6);

        int dayNum = 0;

        while(cin >> numTestCases) {
            appointments.clear();
            naps.clear();

            dayNum++;
            getline(cin, line);

            for(int i = 0; i < numTestCases; i++) {
                getline(cin, line);

                stringstream ss(line);
                ss >> startHour >> endHour;

                Date start(startHour), end(endHour);
                appointments.push_back(make_pair(start, end));
            }

            sort(appointments.begin(), appointments.end());
            
            if(appointments.front().first != tenAM) {
               naps.push_back(make_pair(Date(10,0), Date(appointments.front().first - tenAM)));
            }

            if(appointments.back().second.hours != sixPM) {
               naps.push_back(make_pair(appointments.back().second, sixPM - appointments.back().second));
            }

            for(int i = 0; i < appointments.size() - 1; i++) {
                if(appointments[i+1].first.GetTotalMinutes() != appointments[i].second.GetTotalMinutes()) {
                    naps.push_back(make_pair(appointments[i].second, Date(appointments[i+1].first - appointments[i].second)));
                }
            }
            
            sort(naps.begin(), naps.end(), SortDatePairByBeginDate());
            stable_sort(naps.begin(), naps.end(), SortDatePairByLength());

            int napMins = naps[0].first.minutes;
            cout << "Day #" << dayNum << ": the longest nap starts at " << naps[0].first.hours << ":" << (napMins < 10 ? "0" : "") << napMins << " and will last for " << GetEquivalent(naps[0].second) << "." << endl;
        }
    }
};

int main()
{    
    P10191::Solve();
}