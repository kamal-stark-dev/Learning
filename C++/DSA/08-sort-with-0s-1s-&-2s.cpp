// sort array with 0s, 1s and 2s

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printArray(vector<int> nums) {
    for (int n: nums) cout << n << " ";
    cout << endl;
}

void bruteSort(vector<int>& nums) { // O(n log.n)
    sort(nums.begin(), nums.end());
}

void optimizedSort(vector<int>& nums) { // O(2 * n) => O(n)
    int zeros = 0, ones = 0, twos = 0;
    for (int n: nums) {
        if (n == 0) zeros++;
        else if (n == 1) ones++;
        else twos++;
    }

    int i = 0;
    while (zeros > 0) {
        nums[i] = 0;
        i++;
        zeros--;
    }
    while (ones > 0) {
        nums[i] = 1;
        i++;
        ones--;
    }
    while (twos > 0) {
        nums[i] = 2;
        i++;
        twos--;
    }
}

/*
Dutch National Flag Algorithm -> linear time complexity with single pass
    0s -> 0 to low - 1
    1s -> low to mid - 1
    unsorted -> mid to high - 1
    2s -> high to n - 1

2 0 2 1 1 0 1 2 0 0
m                 h
l
i
i = 2
swap(i, h)
h--

0 0 2 1 1 0 1 2 0 2
m                 h
l
i
i = 0
swap(m, l)
m++, l++, i++

0 0 2 1 1 0 1 2 0 2
  m             h
  l
  i
i = 0
swap(m, l)
m++, l++, i++

0 0 2 1 1 0 1 2 0 2
    m           h
    l
    i
i = 2
swap(i, h)
h--

0 0 0 1 1 0 1 2 2 2
    m         h
    l
    i
i = 0
m++, l++, i++

0 0 0 1 1 0 1 2 2 2
      m       h
      l
      i
i = 1
m++, i++

0 0 0 1 1 0 1 2 2 2
      l m     h
        i
i = 1
m++, i++

0 0 0 1 1 0 1 2 2 2
      l   m   h
          i
i = 0
swap(m, l)
m++, l++, i++

0 0 0 0 1 1 1 2 2 2
        l   m h
            i
i = 1
m++, i++

0 0 0 0 1 1 1 2 2 2
        l     m
              h
              i
m == h -> STOP

Q. WHY is it O(n)?
-> Well the mid pointer travels x times then the high pointer takes (n - x) times
   which makes it -> x + (n - x) = (n)
*/

void optimalSort(vector<int>& nums) { // using DNF Algorithm O(n) with single pass
    int size = nums.size();
    if (size == 1) return;
    int low = 0, mid = 0, high = size - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++; mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else { // for 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};

    printArray(nums);
    optimalSort(nums);
    printArray(nums);

    return 0;
}