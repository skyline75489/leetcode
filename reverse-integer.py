class Solution:
    # @return an integer
    def reverse(self, x):
        a = abs(x);
        s = str(a);
        l = list(s)
        l.reverse()
        r = ''.join(l)
        if x > 0:
            return int(r)
        if x < 0:
            return -int(r)
        else:
            return 0