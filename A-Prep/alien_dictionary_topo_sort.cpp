class Solution 
{
	public:
    	string alienOrder(vector<string>& words) 
    	{
        	for(auto iter_1 = words.begin(); iter_1 != words.end(); iter_1++)
        	{
        		if(iter_1 + 1 == words.end())
        		{
        			break;
        		}
        		iter_2 = iter_1 + 1;
        		for(auto ch_1 = iter_1.begin(), ch_2 = iter_2.begin(); ch_1 != iter_1.begin() and ch_2 = iter_2.begin(); ch_1++, ch_2++)
        		{
        			cout << "ch_1: " << *ch_1 << " " << "ch_2: " << *ch_2 << "\n";
        		}
        	}
    	}
};