// https://leetcode.com/problems/concatenated-words/discuss/159348/Python-DFS-readable-solution
class Solution 
{
	public:
		bool dfs(string word, unordered_set< string > &words_hash, unordered_set< string > &memo_set)
		{
			if(memo_set.find(word) != memo_set.end())
			{
				return true;
			}
			int word_length = word.length();
			for(int i = 0; i < word_length - 1; i++)
			{
				string prefix = word.substr(0, i + 1);
				string suffix = word.substr(i + 1, word_length - (i + 1));
				if(words_hash.find(prefix) != words_hash.end() and words_hash.find(suffix) != words_hash.end())
				{
					return true;
				}
				if(words_hash.find(prefix) != words_hash.end() and dfs(suffix, words_hash, memo_set))
				{
					memo_set.insert(suffix);
					return true;
				}
			}
			return false;
		}

    	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    	{
    		unordered_set< string > words_hash;
    		unordered_set< string > memo_set;
    		for(int i = 0; i < words.size(); i++)
    		{
    			words_hash.insert(words[i]);
    		}
    		vector< string > concatenated_string;
    		for(int i = 0; i < words.size(); i++)
    		{
    			int word_length = words[i].length();
                // cout << "Word: " << words[i] << "\n";
    			for(int j = 0; j < word_length - 1; j++)
    			{
    				string prefix = words[i].substr(0, j + 1);
    				string suffix = words[i].substr(j + 1, word_length - (j + 1));
                    // cout << "Prefix: " << prefix << " Suffix: " << suffix << "\n";
    				if(words_hash.find(prefix) != words_hash.end() and words_hash.find(suffix) != words_hash.end())
    				{
    					concatenated_string.push_back(words[i]);
    					break;
    				}
    				if(words_hash.find(prefix) != words_hash.end() and dfs(suffix, words_hash, memo_set))
    				{
    					concatenated_string.push_back(words[i]);
    					memo_set.insert(suffix);
                        break;
    				}
    			}
    		}
    		return concatenated_string;
    	}
};