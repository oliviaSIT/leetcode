/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *time:40min
 *Solution:minPrice is the minimum price from day 0 to day i. And maxPro is the maximum profit we can get from day 0 to day i.Just get the larger one between current maxPro and prices[i] - minPrice.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
        int maxProfit(vector<int>& prices) {
        	int minPrice = INT_MAX;
		int maxPro = 0;
		for (int i = 0; i < prices.size() ; i++) {
			minPrice = min(minPrice, prices[i]);
			maxPro = max(maxPro, prices[i] - minPrice);
		}

		return maxPro;
        }
};

int main() {
	Solution sol;
	vector<int> prices{1, 2, 5, 7, 4};
	cout << "the max profit is " << sol.maxProfit(prices) << endl;
	return 0;
}
