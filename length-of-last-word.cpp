class Solution {
public:
    int lengthOfLastWord(const char *s) {
        long len = strlen(s);
        int result = 0;
        const char *ptr = s + len - 1;
        // 从后往前扫描，遇到空格跳过
        while (*ptr == ' ') {
            ptr -- ;
        }
        // 碰到最后一个字符，继续往前扫，碰到空格或字符串开头结束
        while (*ptr != ' ' && ptr != s - 1) {
            result ++;
            ptr--;
        }
        return result;
    }
};