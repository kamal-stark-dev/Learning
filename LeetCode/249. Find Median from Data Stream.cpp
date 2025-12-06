// 295. Find Median from Data Stream

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder_Brute {
private:
    vector<int> nums;
public:
    MedianFinder_Brute() {
    }

    void addNum(int num) {
        // insert in sorted manner
        int i = 0, n = nums.size();
        while (i < n && nums[i] < num) {
            i++;
        }
        nums.insert(nums.begin() + i, num);
    }

    double findMedian() {
        int n = nums.size(), mid = n / 2;
        if (n % 2 == 1) return double(nums[mid]);
        return (nums[mid] + nums[mid - 1]) / 2.0;
    }
};

class MedianFinder {
private:
    priority_queue<int> smallHeap; // max-heap
    priority_queue<int, vector<int>, greater<int>> largeHeap; // min-heap
public:
    MedianFinder() {
    }

    void addNum(int num) {
        smallHeap.push(num);
        if (!largeHeap.empty() && smallHeap.top() > largeHeap.top()) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        // balance heaps
        if (smallHeap.size() > largeHeap.size() + 1) {
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        else if (largeHeap.size() > smallHeap.size() + 1) {
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }

    double findMedian() {
        int n1 = smallHeap.size(), n2 = largeHeap.size();
        if (n1 == n2)
            return (smallHeap.top() + largeHeap.top()) / 2.0;
        else if (n1 > n2)
            return smallHeap.top();
        return largeHeap.top();
    }
};

int main(void) {
    MedianFinder m;

    m.addNum(1);
    m.addNum(2);
    cout << m.findMedian() << "\n";
    m.addNum(3);
    cout << m.findMedian() << "\n";

    return 0;
}

/*
Brute:
    Time Complexity:
        - addNum: O(n)
        - findMedian: O(1)
    Space Complexity: O(n)

Optimal:
    Time Complexity:
        - addNum: O(logn)
        - findMedian: O(1)
    Space Complexity: O(n)
*/