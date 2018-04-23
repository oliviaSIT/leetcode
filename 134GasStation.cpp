/*https://leetcode.com/problems/gas-station/description/
 *time:43min
 *solution: 0. 如果对所有加油站的sum(gas[i] - cost[i])<0，则无解。否则进入1
            1. 从0开始计算sum(gas[i] - cost[i])，当遇到i1使sum<0时，说明从0出发无法到达i1,0~i1 - 1一定不是正确的起始点,此时i1为起始点的候选
            2. 将sum清0，并从i1出发，假如又遇到i2使sum(gas[i] - cost[i]) < 0 时，说明i1出发无法绕一圈，更具性质1，排除i1。又因为i1+1 ~ i2-1都能从i1出发到达,。根据性质2，它们也必然不是起始点。此时i2为起始点的候选。             
            3. 以此类推，直到遇到ik，使从ik出发可以到达ik+1 ~ n-1。
*/


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curGas = 0, nextGas = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curGas += gas[i] - cost[i];
            nextGas += gas[i] - cost[i];
            
            if (curGas < 0) {
                start = i + 1;
                curGas = 0;
            }
        }
        
        if (nextGas < 0)
            return -1;
        
        return start;
    }
};
