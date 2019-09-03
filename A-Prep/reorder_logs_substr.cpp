// https://leetcode.com/problems/reorder-log-files/solution/
class VectorSorter
{
    public:
        bool operator()(const string &str_1, const string &str_2) const
        {
            int str_1_space_index = str_1.find(' ');
            int str_2_space_index = str_2.find(' ');
            // substr expects two char * (pointers) and doesnt accept strings, c_str() returns pointer to null terminated string
            int compare_value = strcmp(str_1.substr(str_1_space_index + 1).c_str(), str_2.substr(str_2_space_index + 1).c_str());
            if(compare_value < 0)
            {
                return true;
            }
            else
            {
                if(compare_value == 0 and strcmp(str_1.substr(0, str_1_space_index).c_str(), str_2.substr(0, str_2_space_index).c_str()) < 0)
                {
                    return true;
                }
                return false;
            }
        }
};

class Solution 
{
	public:
    	vector<string> reorderLogFiles(vector<string>& logs) 
    	{
    		vector< string > texts;
    		vector< string > numbers;
        	for(int i = 0; i < logs.size(); i++)
        	{
        		int space_index = logs[i].find(' ');
        		if(isdigit(logs[i][space_index + 1]))
        		{
        			numbers.push_back(logs[i]);
        		}
        		else
        		{
        			texts.push_back(logs[i]);
        		}
        	}
        	sort(texts.begin(), texts.end(), VectorSorter());
        	texts.insert(texts.end(), numbers.begin(), numbers.end());
        	return texts;
    	}
};