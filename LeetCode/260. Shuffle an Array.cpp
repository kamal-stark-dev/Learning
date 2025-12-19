// 384. Shuffle an Array

#include <cstdlib>    // for srand and rand
#include <ctime>      // for time
#include <iostream>
#include <vector>
using namespace std;

class Shuffler {
private:
    vector<int> original;
    int n;
public:
    Shuffler(vector<int>& nums) {
        original = nums;
        n = nums.size();
    }

    vector<int> reset() {
        return original;
    }

    vector<int> shuffle() {
        vector<int> shuffled = original;
        for (int idx = n - 1; idx > 0; idx--) {
            int randIdx = rand() % (idx + 1); // random idx between 0 and idx
            swap(shuffled[idx], shuffled[randIdx]);
        }
        return shuffled;
    }
};

int main(void) {
    srand(time(0)); // for changing seed value

    vector<int> nums = {1, 2, 3, 4, 5};
    Shuffler shuffler = Shuffler(nums);

    vector<int> shuffled1 = shuffler.shuffle();
    cout << "Shuffled: ";
    for (int n: shuffled1) cout << n << " ";
    cout << "\n";

    vector<int> shuffled2 = shuffler.shuffle();
    cout << "Shuffled: ";
    for (int n: shuffled2) cout << n << " ";
    cout << "\n";

    vector<int> original = shuffler.reset();
    cout << "Original: ";
    for (int n: original) cout << n << " ";
    cout << "\n";

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1) auxilary space, O(n) to create and store a shuffled array.
*/