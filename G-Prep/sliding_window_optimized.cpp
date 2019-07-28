class Solution {
public:
    void min_window_compare(int left_pointer, int right_pointer, int t_length, bool &solution_found, int &min_length_of_window, bool &solution_fixed, pair< int, int > &solution_pair)
    {
        int length_of_window = right_pointer - left_pointer + 1;
        if(solution_found)
        {
            if(length_of_window < min_length_of_window)
            {
                min_length_of_window = length_of_window;
                solution_pair = make_pair(left_pointer, right_pointer);
                if(length_of_window == t_length)
                {
                    solution_fixed = true;
                }    
            }
        }
        else
        {
            solution_found = true;
            min_length_of_window = length_of_window;
            solution_pair = make_pair(left_pointer, right_pointer);
            if(length_of_window == t_length)
            {
                solution_fixed = true;
            }
        }
        // tuple< bool, bool, int, pair< int, int > > return_tuple = make_tuple(solution_found, solution_fixed, min_length_of_window, make_pair(left_pointer, right_pointer));
        // return return_tuple;
        return;
    }

    string minWindow(string s, string t) 
    {
        bool solution_found = false, solution_fixed = false;
        int s_length = s.size();
        int t_length = t.size();
        int unique_characters_in_s = 0;
        int unique_characters_in_t = 0;
        unordered_map< int, int > s_alphabets;
        unordered_map< int, int > t_alphabets;
        pair< int, int > solution_pair;
        for(int i = 0; i < t_length; i++)
        {
            t_alphabets[(int)(t[i] - 'A')] += 1;
            if(t_alphabets[(int)(t[i] - 'A')] == 1)
            {
                unique_characters_in_t++;
            }
        }
        vector< pair< char, int > > char_index_pair_vec;
        for(int i = 0; i < s_length; i++)
        {
            s_alphabets[(int)(s[i] - 'A')] += 1;
            if(s_alphabets[(int)(s[i] - 'A')] == 1)
            {
                unique_characters_in_s++;
            }
            char_index_pair_vec.push_back(make_pair(s[i], i));
        }
        int left_pointer = 0, right_pointer = -1;
        unordered_map< int, int > window_alphabets;
        int unique_matching_chars_found_in_window = 0;
        int min_length_of_window = 1000000000;
        int modified_s_length = char_index_pair_vec.size();
        while((char_index_pair_vec[left_pointer].second + t_length - 1) <= (s_length - 1) and (right_pointer + 1 < modified_s_length))
        {
            right_pointer++;
            int char_val = (int)(char_index_pair_vec[right_pointer].first - 'A');
            window_alphabets[char_val] += 1;
            auto find_iter = t_alphabets.find(char_val);
            if(find_iter != t_alphabets.end())
            {
                if(window_alphabets[char_val] == find_iter -> second)
                {
                    unique_matching_chars_found_in_window++;
                }
            }
            if(unique_characters_in_t == unique_matching_chars_found_in_window)
            {
                // cout << "left pointer: " << left_pointer << " right pointer: " << right_pointer << " substring: " << s.substr(left_pointer, (right_pointer - left_pointer + 1)) << "\n";
                min_window_compare(char_index_pair_vec[left_pointer].second, char_index_pair_vec[right_pointer].second, t_length, solution_found, min_length_of_window, solution_fixed, solution_pair);
                if(solution_fixed)
                {
                    break;
                }
                while(char_index_pair_vec[left_pointer].second <= char_index_pair_vec[right_pointer].second)
                {
                    int local_left_pointer = left_pointer;
                    int char_val_left = (int)(char_index_pair_vec[local_left_pointer].first - 'A');
                    left_pointer++;
                    window_alphabets[char_val_left] -= 1;
                    auto find_iter = t_alphabets.find(char_val_left);
                    if(find_iter != t_alphabets.end())
                    {
                        if(window_alphabets[char_val_left] >= find_iter -> second)
                        {
                            // cout << "-----" << window_alphabets[char_val_left] << ": " << char_val_left << "-----" << "\n";
                            // cout << "Inside while (found): " << "left pointer: " << left_pointer << " right pointer: " << right_pointer << " substring: " << s.substr(left_pointer, (right_pointer - left_pointer + 1)) << "\n";
                            min_window_compare(char_index_pair_vec[left_pointer].second, char_index_pair_vec[right_pointer].second, t_length, solution_found, min_length_of_window, solution_fixed, solution_pair);
                            if(solution_fixed)
                            {
                                break;
                            }
                        }
                        else
                        {
                            // cout << "Inside while (found break): " << "left pointer: " << left_pointer << " right pointer: " << right_pointer << " substring: " << s.substr(left_pointer, (right_pointer - left_pointer + 1)) << "\n";
                            unique_matching_chars_found_in_window--;
                            break;
                        }
                    }
                    else
                    {
                        // cout << "Inside while (not found): " << "left pointer: " << left_pointer << " right pointer: " << right_pointer << " substring: " << s.substr(left_pointer, (right_pointer - left_pointer + 1)) << "\n";
                        min_window_compare(char_index_pair_vec[left_pointer].second, char_index_pair_vec[right_pointer].second, t_length, solution_found, min_length_of_window, solution_fixed, solution_pair);
                        if(solution_fixed)
                        {
                            break;
                        }
                    }
                }
                if(solution_fixed)
                {
                    break;
                }
            }
        }
        if(solution_found)
        {
            return s.substr(solution_pair.first, solution_pair.second - solution_pair.first + 1);
        }
        else
        {
            return "";
        }
    }
};