class Logger 
{
    public:
    /** Initialize your data structure here. */
        unordered_map< string, int > message_timestamp_map;
        Logger() 
        {
        }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
        bool shouldPrintMessage(int timestamp, string message) 
        {
            auto find_iter = message_timestamp_map.find(message);
            if(find_iter != message_timestamp_map.end())
            {
                if(timestamp - find_iter -> second >= 10)
                {
                    message_timestamp_map[message] = timestamp;
                    return true;
                }
                return false;
            }
            else
            {
                message_timestamp_map.insert(make_pair(message, timestamp));
                return true;
            }
        }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */