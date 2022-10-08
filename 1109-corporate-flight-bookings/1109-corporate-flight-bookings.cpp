class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
            vector<int> book(n + 1, 0);
            for (auto e: bookings) {
                    book[e[0]-1] += e[2];
                    book[e[1]] -= e[2];
            }
            for (int i = 1; i < n; ++i) {
                    book[i] += book[i - 1];
            }
            book.pop_back();
            return book;
    }
};