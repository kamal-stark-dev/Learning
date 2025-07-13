// Book Allocation Problem - https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1

/*
Problem - BOOK ALLOCATION PROBLEM
Requirements -
	- each book should be given.
	- each students should have at least one book.
	- distribute the books in a way that the max pages of books is the minimum and the order books are given is contiguous.
	- return the minimum number of maximum pages possible.
*/

#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> nums,  int totalStudents, int maxAllowedPages) {
	int students = 1, pages = 0;
	int size = nums.size();
	for (int i = 0; i < size; i++) {
		if (pages + nums[i] <= maxAllowedPages) pages += nums[i];
		else {
			students++;
			pages = nums[i];
		}
	}
	return students <= totalStudents;
}

int bookAllocationProblem(vector<int> nums, int totalStudents) {
	int size = nums.size();
	if (size < totalStudents) return -1;

	int totalPages = 0, maxPages = 0;
	for (int i = 0; i < size; i++) { // O(n)
		maxPages = max(maxPages, nums[i]);
		totalPages += nums[i];
	}
	int ans = -1;
	int left = maxPages, right = totalPages;
	while (left <= right) { // O(n logN) -> N is the range from maxPages to totalPages
		int mid = left + (right - left) / 2;
		if (isValid(nums, totalStudents, mid)) { // O(n)
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ans;
}

int main() {
	vector<int> nums = {22, 23, 67};
	int totalStudents = 8;

	cout << bookAllocationProblem(nums, totalStudents) << endl;
	return 0;
}

/*
Wrote this program fully in notepad and it run successfully in one try (no typos no nothing) ==> : )

Time complexity: O(n log.N)
Space complexity: O(1)
*/