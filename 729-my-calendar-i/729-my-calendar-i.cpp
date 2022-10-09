class MyCalendar {
public:
    set<pair<int, int>> period;
    
    MyCalendar() {
            
    }
    
    bool book(int start, int end) {
            for (auto e: period) {
                    if ((e.second <= start) || (e.first >= end)) {
                            
                    } else return false;
            }
            period.emplace(start, end);
            return true;
    }
};