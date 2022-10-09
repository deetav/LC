class MyCalendar {
public:
    map<int, int> M;
    
    MyCalendar() {
            
    }
    
    bool book(int start, int end) {
            if (M.empty()) {
                    M[start] = end;
                    return true;
            }
            auto I = M.lower_bound(end);
            if (I == M.begin()) {
                    M[start] = end;
                    return true;
            }
            --I;
            if ((I->second) > start) return false;
            M[start] = end;
            return true;
    }
};