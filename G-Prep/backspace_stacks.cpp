class Solution {
public:
    bool backspaceCompare(string S, string T) {        
        stack< char > backspace_stack_s, backspace_stack_t;
        for(int i = 0, j = 0; i < S.length() or j < T.length(); i++, j++)
        {
            if(i < S.length())
            {
                if(S[i] != '#')
                {
                    backspace_stack_s.push(S[i]);
                }
                else
                {
                    if(not backspace_stack_s.empty())
                    {
                        backspace_stack_s.pop();
                    }
                }
            }
            if(j < T.length())
            {
                if(T[j] != '#')
                {
                    backspace_stack_t.push(T[j]);
                }
                else
                {
                    if(not backspace_stack_t.empty())
                    {
                        backspace_stack_t.pop();
                    }
                }
            }
        }
        bool are_same_strings = true;
        while(not backspace_stack_t.empty() and not backspace_stack_s.empty())
        {
            char s = backspace_stack_s.top();
            char t = backspace_stack_t.top();
            if(s != t)
            {
                are_same_strings = false;
                break;
            }
            backspace_stack_s.pop();
            backspace_stack_t.pop();
        }
        if(are_same_strings and backspace_stack_s.empty() and backspace_stack_t.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};