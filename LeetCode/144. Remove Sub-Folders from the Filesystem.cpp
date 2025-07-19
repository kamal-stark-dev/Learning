// 1233. Remove Sub-Folders from the Filesystem

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end());

    vector<string> result;

    for (string path: folder) {
        if (result.size() == 0) result.push_back(path);
        else {
            string prev_path = result.back();
            int prev_len = prev_path.size();
            if (path.size() > prev_len && path.substr(0, prev_len) == prev_path && path[prev_len] == '/')
                continue;
            else
                result.push_back(path);
        }
    }
    return result;
}

int main(void) {
    vector<string> folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};

    vector<string> withoutSubfolders = removeSubfolders(folder);
    for (string folder: withoutSubfolders) {
        cout << folder << " ";
    }
    cout << "\n";

    return 0;
}

/*
Time Complexity: O(n * log n) + O(n) -> O(n * log n)
Space Complexity: O(n) -> to store the result
*/