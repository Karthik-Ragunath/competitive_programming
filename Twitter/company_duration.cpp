#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'maxEvents' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arrival
 *  2. INTEGER_ARRAY duration
 */
 
 class ComparatorVals
 {
    public:
        bool operator()(const pair< int, int > &pair_1, const pair< int, int > &pair_2) const
        {
            if(pair_1.second <= pair_2.second)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
 };
 

int maxEvents(vector<int> arrival, vector<int> duration) 
{
    int solution = -1;
    int num_companies;
    cin >> num_companies;
    vector< int > company_arrival_times;
    for(int i = 0; i < num_companies; i++)
    {
        int input;
        cin >> input;
        company_arrival_times.push_back(input);
    }
    int num_duration;
    cin >> num_duration;
    for(int i = 0; i < num_duration; i++)
    {
        int input;
        cin >> input;
        duration.push_back(input);
    }
    vector< pair<int, int>  > end_times;
    for(int i = 0; i < num_companies; i++)
    {
        end_times.push_back(make_pair(company_arrival_times[i], company_arrival_times[i] + duration[i]));
    }
    sort(end_times.begin(), end_times.end(), ComparatorVals());
    int cur_end_time = -1;
    for(auto pair_val: end_times)
    {
        if(solution == -1)
        {
            solution = 1;
            cur_end_time = pair_val.second;
        }
        else {
            if(pair_val.first >= cur_end_time)
            {
                solution++;
                cur_end_time = pair_val.second;
            }
        }
    }
    return solution;
}

int main()