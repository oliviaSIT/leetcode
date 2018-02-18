/*https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
 *time:22min
 *solution:binary search
 *easy
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		int st = 0, ed = (int)letters.size() - 1;

		if (target < letters[st] || target >= letters[ed])
			return letters[st];
		
		int mid;
		while (st +1 < ed) {
			mid = st + (ed - st) / 2;
			if (letters[mid] <= target) {
				st = mid; 
			} else {
				ed = mid;
			}
		}

		return letters[ed];

	}
};
