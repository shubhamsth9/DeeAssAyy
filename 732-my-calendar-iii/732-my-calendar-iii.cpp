class MyCalendarThree {
    map<int, int> mp;
    int maxCnt = 0;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int cnt = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) 
        {
            cnt += it->second;
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt; 
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */