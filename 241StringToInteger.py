class Solution:
    """
    @param: str: A string
    @return: An integer
    """

    def stringToInteger(self, str):
        # write your code here

        if len(str) == 0:
            return 0

        sgn, num, i = 0, 0, 0
        imin, imax = -1 << 31, (1 << 31) - 1

        while str[i] == ' ':
            i = i + 1

        if str[i] == '-' or str[i] == '+':
            sgn = 1 if str[i] == '-' else 0
            i = i + 1

        while i < len(str) and str[i] >= '0' and str[i] <= '9':
            num = num * 10 + ord(str[i]) - ord('0')
            x = -num if sgn else num

            if x < imin:
                return imin

            if x > imax:
                return imax

            i = i + 1

        return -num if sgn else num