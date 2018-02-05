/*https://leetcode.com/problems/min-stack/description/
  time:35 min
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinStack {
public:
	vector<int> minStack;
	   
        void push(int x) {
		minStack.push_back(x);
        }
    
        void pop() {
        	minStack.pop_back();
        }
    
        int top() {
        	return *(minStack.end() - 1);
        }
    
        int getMin() {
		return *(min_element(minStack.begin(), minStack.end()));        	
        }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {
	MinStack obj = new MinStack();
	obj.push(-2);
	obj.push(0);
	obj.push(-3);
	cout << "min: " << obj.getMin() << '\n';
	obj.pop();
	cout << "top: " << obj.top() << '\n';
	cout << "min: " << obj.getMin() << endl;

	return 0;
}
