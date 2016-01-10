/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insertInterval(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        int n = intervals.size();
        int i = 0;
        bool inserted = false;
        for (i = 0; i < n; i++){
            if (newInterval.start > intervals[i].end || inserted){
                ret.push_back(intervals[i]);
            } else{
                if (newInterval.end < intervals[i].start){
                    ret.push_back(newInterval);
                    ret.push_back(intervals[i]);
                    inserted = true;
                } else if (newInterval.end >= intervals[i].start && newInterval.end <= intervals[i].end){
                    newInterval.start = min(newInterval.start, intervals[i].start);
                    newInterval.end = intervals[i].end;
                    ret.push_back(newInterval);
                    inserted = true;
                } else{
                    newInterval.start = min(newInterval.start, intervals[i].start);
                }
            }
        }
        if (!inserted)  ret.push_back(newInterval);
        return ret;
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        for (const auto &interval : intervals){
            ret = insertInterval(ret, interval);
        }    
        return ret;
    }
};