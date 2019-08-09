class Solution {
public:
    string numberToWords(int num) {
        string number_str_reversed = to_string(num);
        reverse(number_str_reversed.begin(), number_str_reversed.end());
        /*
        vector< string > splitted_strings_reversed;
        string token;
        istringstream token_tream(number_str_reversed);
        while(getline(token_stream, token)) // getline(token_stream, token, delimiter) can be used if space is not the delimiter
        {
            splitted_strings_reversed.push_back(token);
        }
        */
        vector< string > splitted_strings_reversed;
        int string_size = number_str_reversed.size();
        int number_of_strings = string_size / 3;
        for(int i = 0, j = 0; i < number_of_strings; i++)
        {
            splitted_strings_reversed.push_back(number_str_reversed.substr(j, j + 3));
            j = (i + 1) * 3;
        }
        if(string_size % 3 != 0)
        {
            number_of_strings += 1;
            splitted_strings_reversed.push_back(number_str_reversed.substr(string_size - string_size % 3, string_size % 3));
        }
        vector< string > splits_suffix;
        splits_suffix[0] = "";
        splits_suffix[1] = "thousand";
        splits_suffix[2] = "million";
        splits_suffix[3] = "billion";
        splits_suffix[4] = "trillion";
        vector< vector< string > > split_intermediates {{"", "", ""}, {"One", "Ten", "One Hundered"}, {"Two", "Twenty", "Two Hundred"}, {"Three", "Thirty", "Three Hundred"}, {"Four", "Forty", "Four Hundred"}, {"Five", "Fifty", "Five Hundred"}, {"Six", "Sixty", "Six Hundred"}, {"Seven", "Seventy", "Seven Hundred"}, {"Eight", "Eighty", "Eight Hundred"}, {"Nine", "Ninety", "Nine Hundred"}};
        string solution_string = "";
        for(int i = 0; i < number_of_strings; i++)
        {
            string internal_solution_string = "";
            string val = splitted_strings_reversed[i];
            for(int j = 0; j < val.length(); j++)
            {
                int k = val[j];
                if(split_intermediates[k][j] != "")
                {
                    if(internal_solution_string != "")
                    {
                        internal_solution_string = split_intermediates[k][j] + " " + internal_solution_string;
                    }
                    else
                    {
                        internal_solution_string = split_intermediates[k][j];
                    }
                }   
            }
            if(internal_solution_string != "")
            {
                if(i != 0)
                {
                    internal_solution_string = internal_solution_string + " " + splits_suffix[i];
                }
            }
            if(internal_solution_string != "")
            {
                if(solution_string != "")
                {
                    solution_string = internal_solution_string + " " + solution_string;
                }
                else
                {
                    solution_string = internal_solution_string;
                }
            }
        }
        return solution_string;
    }
};