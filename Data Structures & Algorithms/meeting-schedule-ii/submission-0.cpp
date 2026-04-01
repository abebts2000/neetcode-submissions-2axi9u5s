/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

bool operator < (const Interval& a, const Interval &b)
{
    if(a.start != b.start)
        return a.start < b.start;
    return a.end < b.end;
}

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        std::sort(intervals.begin(), intervals.end());
        
        std::priority_queue<int, vector<int>, std::greater<int>> pq;
        for (auto& interval : intervals) {
            if (!pq.empty() && pq.top() <= interval.start) {
                pq.pop();
            }
            pq.push(interval.end);
        }

        return pq.size();
    }
};