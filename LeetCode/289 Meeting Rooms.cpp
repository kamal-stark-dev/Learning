// Meeting Rooms
// https://neetcode.io/problems/meeting-schedule

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Interval {
public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

bool canAttendMeetings(vector<Interval>& intervals) {
  sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
    return a.start < b.start;
  });

  int n = intervals.size();
  for (int i = 1; i < n; i++) {
    Interval i1 = intervals[i - 1];
    Interval i2 = intervals[i];

    if (i1.end > i2.start) return false;
  }
  return true;
}

int main() {
  vector<Interval> intervals = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
  cout << "Person can" << (canAttendMeetings(intervals) ? "" : " not") << " attend all the meetings without any conflicts.\n";

  return 0;
}
