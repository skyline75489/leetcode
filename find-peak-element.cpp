class Solution {
public:
    // 感觉这样二分其实不太对，这样是假定只有有个Peak，然后根据mid和它左右的大小进行二分
    // 但是如果有多个Peak的话，没办法用二分，因为整个就是没规律的，不大可能做到log的复杂度
    int findPeakElement(const vector<int> &num) {
        int n = num.size();
        if (n <= 1) return 0;
        if (num[0] > num[1]) return 0;
        if (num[n-2] < num[n-1]) return n-1;
        int l ,mid ,r;
        l = 1;
        r = n-1;
        while(l < r) {
        	mid = (l+r) >> 1;
        	if (num[mid-1] < num[mid] && num[mid] > num[mid + 1])
        	{
        		return mid;
        	}
        	if (num[mid] > num[mid+1])
        	{
        		r = mid;
        	} else {
        		l = mid;
        	}
        }
        return l;
    }
};