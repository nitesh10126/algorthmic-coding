bool isOverlapping(Interval a, Interval b) {
    // a:     [     ]                                   [      ]                            [       ]                                   [   ]
    // b:  [     ]                                          [         ]                         [ ]                                 [          ]
    if ((a.start <= b.end && a.start >= b.start) | (a.end >= b.start && a.end <= b.end) | (a.start <= b.start && a.end >= b.end) | (a.start >= b.start && a.end <= b.start)) {
        return true;
    }
    return false;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<Interval> result;
    // handle corner cases. 
    if (intervals.size() == 0) {
        result.push_back(newInterval);
        return result;
    }
    bool merged = false;
    for (int i=0; i<intervals.size(); i++){
        Interval current = intervals[i];
	// if newInterval comes easrlier than current interval. add newInterval to result.
        if (!merged && newInterval.end < intervals[i].start){
            result.push_back(newInterval);
            merged = true;
        }
	// if newInterval is overlapping with current interval. Check all upcoming intervals which are overlapping with newInterval.
        if (!merged && isOverlapping(current, newInterval)){
            Interval x;
            x.start = min(current.start, newInterval.start);
            x.end = max(current.end, newInterval.end);
            i++;
            while (i < intervals.size() && isOverlapping(intervals[i], newInterval)){
                x.end = max(x.end, intervals[i].end);
                i++;
            }
            result.push_back(x);
            merged = true;
            i--;
	// if not any of the above case, add current to result.
        } else {
            result.push_back(current);
        }
    }
    if (!merged){
        result.push_back(newInterval);
    }
    return result;
}
