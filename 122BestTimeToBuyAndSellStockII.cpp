/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description
 *time:33min
 *solution: gready
 *easy
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int res = 0;
		for (int i = 1; i < (int)prices.size(); i++) {
			res += max(prices[i] - prices[i - 1], 0);
		}

		return res;
	}
};

int main() {
	Solution sol;
	vector<int> v{1,3,2,4,6};

	cout << sol.maxProfit(v) << endl;

	return 0;
} 
