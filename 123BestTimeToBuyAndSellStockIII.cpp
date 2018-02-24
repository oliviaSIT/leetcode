/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *time:
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int len = prices.size();
		if (len == 0) return 0;

		vector<int> maxProfitFromStToI(len);
		int preMin = INT_MAX;
		for (int i = 0; i < (int)len; i++) {
			preMin = min(prices[i], preMin);
			maxProfitFromStToI[i] = max(prices[i] - preMin, i == 0 ? 0 : maxProfitFromStToI[i - 1]);
		}

		vector<int> maxProfitFromIToEd(len);
                int nxtMax = INT_MIN;
                for (int i = len - 1; i >= 0; i--) {
                        nxtMax = max(prices[i], nxtMax);
                        maxProfitFromIToEd[i] = max(nxtMax - prices[i], i ==  (len - 1) ? 0 : maxProfitFromIToEd[i + 1]);
		}

		int maxProfit = 0;
		for (int i = 0; i < len; i++) {
			maxProfit = max(maxProfitFromStToI[i] + maxProfitFromIToEd[i], maxProfit);
		}

		return maxProfit;
	}
};

int main() {
	Solution sol;
	vector<int> prices = {1,2,3};
	cout << sol.maxProfit(prices) << endl;
	return 0;
}
