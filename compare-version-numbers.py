class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer
    def compareVersion(self, version1, version2):
        t1 = version1.split('.')
        t2 = version2.split('.')
        for i in range(0, max(len(t1), len(t2))):
            try:
                num1 = int(t1[i])
            except IndexError:
                num1 = 0
            try:
                num2 = int(t2[i])
            except IndexError:
                num2 = 0                
            if num1 > num2:
                return 1
            elif num1 < num2:
                return -1
            else:
                continue   
        return 0