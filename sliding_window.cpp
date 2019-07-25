class Solution {
public:
    string minWindow(string s, string t) {
        bool solution_found = false;
        int s_length = s.size();
        int t_length = t.size();
        int unique_characters_in_s = 0;
        int unique_characters_in_t = 0;
        unordered_map< int, int > s_alphabets(26);
        unordered_map< int, int > t_alphabets(26);
        for(int i = 0; i < s_length; i++)
        {
            s_alphabets[(int)(s[i] - 'A')] += 1;
            if(s_alphabets[(int)(s[i] - 'A')] == 1)
            {
                unique_characters_in_s++;
            }
        }
        for(int i = 0; i < t_length; i++)
        {
            t_alphabets[(int)(t[i] - 'A')] += 1;
            if(t_alphabets[(int)(t[i] - 'A')] == 1)
            {
                unique_characters_in_t++;
            }
        }
        int left_pointer = 0, right_pointer = -1;
        unordered_map< int, int > window_alphabets;
        int unique_chars_found_in_window = 0;
        pair< int, int > solution_pair;
        int min_length_of_window = 1000000000;
        while((left_pointer + t_length - 1) <= (s_length - 1) and (right_pointer + 1 < s_length))
        {
            right_pointer++;
            int char_val = (int)(s[right_pointer] - 'A');
            auto find_iter = t_alphabets.find(char_val);
            if(find_iter != t_alphabets.end())
            {
                window_alphabets[char_val] += 1;
                if(window_alphabets[char_val] == find_iter -> second)
                {
                    unique_matching_chars_found_in_window++;
                }
            }
            if(unique_characters_in_t == unique_chars_found_in_window)
            {
                int length_of_window = right_pointer - left_pointer + 1;
                if(solution_found)
                {
                    if(length_of_window == t_length)
                    {
                        solution_pair = make_pair(left_pointer, right_pointer);
                        break;
                    }
                    else if(length_of_window < min_length_of_window)
                    {
                        min_length_of_window = length_of_window;
                    }
                }
                else
                {
                    solution_found = true;
                    min_length_of_window = length_of_window;
                }
            }
        }
    }
};