#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		int l = secret.size();

		unordered_map<char, int> map;
		for (int i = 0; i < l; i++) 
			map[secret[i]]++;
			
		int bulls = 0, cows = 0;
		vector<int> index;
		for (int i = 0; i < l; i++) {
			if (secret[i] == guess[i]) {
				map[secret[i]]--;
				bulls++;
			} else index.push_back(i);
		}

		for (int i = 0; i < (int)index.size(); i++) {
			if (map.find(guess[index[i]]) != map.end() && map[guess[index[i]]] > 0) {
				map[guess[index[i]]]--;
				cows++;
			}
		}

		return to_string(bulls) + "A" + to_string(cows) + "B";
	}
};

int main() {
	Solution sol;
	cout << sol.getHint("1123", "0111") << endl;

	return 0;
}
