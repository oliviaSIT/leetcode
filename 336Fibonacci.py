class Solution:
    """
    http://www.lintcode.com/en/problem/fibonacci/#
    time:1st 18min 2rd 2min
    @param: n: an integer
    @return: an ineger f(n)
    """
    """
        def fibonacci(self, n):
            # write your code here
            a, b = 0, 1

            for i in range(n - 1):
                a, b = b, a + b
            return a
    """
    def fibonacci(self, n):
        if n == 1:
            return 0
        elif n == 2:
            return 1
        else:
            return (self.fibonacci(n - 2) + self.fibonacci(n - 1))

n = 4
ans = Solution()
b = ans.fibonacci(n)
print(b)
