class Solution 
{
    public:
        string mostCommonWord(string paragraph, vector<string>& banned) 
        {   
            unordered_set< string > banned_set{banned.begin(), banned.end()};
            int max_val = 0; 
            string max_word = "";
            unordered_map< string, int > balanced_string_tree;
            string separator{" \t\r\n,.!?;:'"}; // string initialization
            // string separator = " \t\r\n,.!?;:'"; also works
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
            return max_word;
        }
};