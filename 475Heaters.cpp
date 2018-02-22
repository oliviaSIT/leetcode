/*https://leetcode.com/problems/heaters/description/
 *time:
 *solution:
 *easy
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		if (houses.size() == 0)
			return 0;

		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());

		vector<int> closestHeater(houses.size() + 1, -1);
		closestHeater[0] = 0;

		int radius = 0;
		for (int i = 1; i < (int)houses.size(); i++) {
			int heaterSt = closestHeater[i - 1];
			long smallestDis = INT_MAX;

			for (int h = heaterSt; h < (int)heaters.size(); h++) {
				long dis = abs((long)houses[i - 1] - (long)heaters[h]);
				if (dis <= smallestDis) {
					smallestDis = dis;
					closestHeater[i] = h;
				} else {
					break;
				}
			}

			if (smallestDis > radius)
				radius = smallestDis;
		}

		return radius;
	}
};

int main() {
	Solution sol;
	vector<int> houses = {1,2,3,4}, heaters = {1,4};
	cout << sol.findRadius(houses, heaters) << endl;

	return 0;
}
