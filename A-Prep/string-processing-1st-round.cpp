// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
#include <bits/stdc++.h>
using namespace std;
/*
class CompareNodes
{
    public:
        bool operator()(const int val_1, const int val_2) const
        {
            if(val_1 < val_2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};
*/
class CompareStrings
{
    public:
        bool operator()(const pair< string, string > pair_1, const pair< string, string > pair_2) const
        {
            string str_1_1 = pair_1.first;
            string str_1_2 = pair_1.second;
            string str_2_1 = pair_2.first;
            string str_2_2 = pair_2.second;
            transform(str_1_1.begin(), str_1_1.end(), str_1_1.begin(), ::tolower);
            transform(str_1_2.begin(), str_1_2.end(), str_1_2.begin(), ::tolower);
            transform(str_2_1.begin(), str_2_1.end(), str_2_1.begin(), ::tolower);
            transform(str_2_2.begin(), str_2_2.end(), str_2_2.begin(), ::tolower);
            if(str_1_2.compare(str_2_2) < 0)
            {
                return true;
            }
            else if(str_1_2.compare(str_2_2) == 0)
            {
                if(str_1_1.compare(str_2_1) < 0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            {
                return false;
            }
        }
};

vector<string> reorderLines(int logFileSize, vector<string> logLines)
{
    vector< pair< string, string > > string_vectors;
    vector< pair< string, string > > int_vectors;
    for(auto log_line: logLines)
    {
        int start = 0, end;
        end = log_line.find_first_of(" ", start);
        string word_1 = log_line.substr(start, end);
        string word_2 = log_line.substr(end, log_line.length());
        bool is_digit = (word_2.find_first_of("0123456789") != string::npos);
        if(is_digit)
        {
            int_vectors.push_back(make_pair(word_1, word_2));
        }
        else
        {
            string_vectors.push_back(make_pair(word_1, word_2));   
        }
        sort(string_vectors.begin(), string_vectors.end(), CompareStrings());
        for(auto str: string_vectors)
        {
            cout << str.first << " " << str.second << "\n";
        }
        // cout << word_1 << " " << word_2 << " " << is_digit << "\n";
    }
    return vector< string >{"aa"};
    // WRITE YOUR CODE HERE
}
// FUNCTION SIGNATURE ENDS