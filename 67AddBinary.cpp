/*https://leetcode.com/problems/add-binary/description/
 *time:
 *solution:
 *easy
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int na = a.length();
		int nb = b.length();
		vector<int> res;
		
		int i = 0, j = 0, x = 0;
		
		while (i < na && j < nb ) {
			int y = (a[i] - '0' ) + (b[j] - '0') + x;	
			if (y < 2) {
				x = 0;
				res.push_back(y);
			} else {
				x = 1;
				res.push_back(0);
			}

			i++;j++;
		
		}	

		while (i < na) {
			int y = (a[i] - '0' ) + x;
			if (y < 2) {
                                x = 0;
                                res.push_back(y);
                        } else {
                                x = 1;
                                res.push_back(0);
                        }
			i++;
		}

		
		
		while (j < nb) {
                        int y = (b[j] - '0' ) + x;
                        if (y < 2) {
                                x = 0;
                                res.push_back(y);
                        } else {
                                x = 1;
                                res.push_back(0);
                        }
                        j++;
                }

		reverse(res.begin(), res.end());
		return res;
	}
};
