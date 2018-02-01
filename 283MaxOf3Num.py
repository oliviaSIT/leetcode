class Solution:
    """
    @param: num1: An integer
    @param: num2: An integer
    @param: num3: An integer
    @return: an interger
    """
    def maxOfThreeNumbers(self, num1, num2, num3):
        # write your code here
        m = num1;

        if num2 > m:
            m = num2

        if num3 > m:
            m = num3

        return m

