class MyCalendarTwo {
public:
    map<int, int> M;
    
    MyCalendarTwo() {
            
    }
    
    bool book(int start, int end) {
            ++M[start];
            --M[end];
            int cur = 0;
            for (auto e: M) {
                    cur += e.second;
                    if (cur == 3) {
                            --M[start];
                            ++M[end];
                            return false;
                    }
            }
            return true;
    }
};