/*https://leetcode.com/problems/can-place-flowers/description/
 *time:
 *solution:
 *easy
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		for (int i = 0; i < (int)flowerbed.size(); i++) {
			if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 1)) {
				flowerbed[i] = 1;
				n--;
			}

			if (n <= 0)
				return true;
		}
		if (n <= 0)
                        return true;
		else return false;
	}
};
