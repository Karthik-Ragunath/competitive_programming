// class CompareKeys
// {
//     public:
//         bool operator()(const pair< string, int > &pair_1, const pair< string, int > &pair_2)
//         {
//             int compare_val = strcmp(pair_1.first.c_str(), pair_2.first.c_str());
//             if(compare_val > 0)
//             {
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }
// };

class Solution 
{
    public:
        string mostCommonWord(string paragraph, vector<string>& banned) 
        {
            /*
        	stringstream ss(paragraph);
        	string token;
        	vector< string > tokens;
        	unordered_set< string > banned_set{banned.begin(), banned.end()};
            vector< string > banned_strings{"!", "?", ".", "'", ",", ":"};
            banned_set.insert(banned_strings.begin(), banned_strings.end());
        	while(getline(ss, token, ' '))
        	{
        	    string s;
        	    s += token[token.size() - 1];
        		auto find_iter = banned_set.find(s);
        		if(find_iter != banned_set.end())
        		{
        			cout << "punct: " << token.substr(0, token.size() - 1) << "\n";
        			tokens.push_back(token.substr(0, token.size() - 1));
        		}
        		else
        		{
        			cout << token << "\n";
        			tokens.push_back(token);
        		}
        	}
            */
            
        	// cout << "--------" << "\n";
        	// while(ss >> token)
        	// {
        	// 	cout << token << "\n";
        	// }
            
            // stringstream ss("karthik, ragnunath");
            // string token;
            // vector< string > tokens;
            // while(getline(ss, token, ','))
            // {
            //     cout << token << "\n";
            //     tokens.push_back(token);
            //     if(ss.peek() == ' ')
            //     {
            //         ss.ignore();
            //     }
            // }
            // return tokens; // {"karthik", "ragunath"}
            
            // stringstream ss("karthik, ragnunath");
            // string token;
            // vector< string > tokens;
            // while(ss >> token)
            // {
            //     cout << token << "\n";
            //     tokens.push_back(token);
            //     if(ss.peek() == ' ')
            //     {
            //         ss.ignore();
            //     }
            // }
            // return tokens; // {"karthik,", "ragunath"}
            
            ///Similarly intergers breakeven at intergers
            // stringstream ss("123, 234");
            // int token;
            // vector< int > tokens;
            // while(ss >> token) //getline wont work for integer case
            // {
            //     cout << token << "\n";
            //     tokens.push_back(token);
            //     if(ss.peek() == ',')
            //     {
            //         ss.ignore();
            //     }
            //     if(ss.peek() == ' ')
            //     {
            //         ss.ignore();
            //     }
            // }
            // return tokens; // {123, 234}
            
            
            int max_val = 0; 
            string max_word = "";
            unordered_set< string > banned_set{banned.begin(), banned.end()};
            unordered_map< string, int > balanced_string_tree;
            string separator{" \t\r\n,.!?;:'"};
            transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
            size_t start = 0, end;
            do
            {
                start = paragraph.find_first_not_of(separator, start); // remove leading discrepancies
                if (start==string::npos) // stop if no word left
                {   
                    break;
                }
                end=paragraph.find_first_of(separator, start);   // find next separator 
                string word(paragraph.substr(start,end-start));      // construct the word
                auto find_iter = banned_set.find(word);
                if(find_iter == banned_set.end())
                {
                    balanced_string_tree[word] += 1;
                    if(balanced_string_tree[word] > max_val)
                    {
                        max_word = word;
                        max_val = balanced_string_tree[word];
                    }
                }
                start=end+1; 
            } while(end != string::npos);
            
            // for(auto iter = balanced_string_tree.begin(); iter != balanced_string_tree.end(); iter++)
            // {
            //     cout << "word: " << iter -> first << " count: " << iter -> second << "\n";
            // }
            return max_word;
        }
};