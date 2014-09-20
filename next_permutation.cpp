class Solution {
public:
    void nextPermutation(vector<int> &num) {
        vector<int>::iterator first = num.begin();
        vector<int>::iterator last = num.end();
        // 空数组
        if (first == last) {
            return;
        }
        vector<int>::iterator i = first;
        ++i;
        // 只有一个元素
        if(i == last) {
            return;
        }
        i = last;
        --i;
        while(1)
        {
            vector<int>::iterator t = i;
            --i;
            if(*i < *t)
            {
                vector<int>::iterator j = last;
                while(!(*i < *--j));
                iter_swap(i,j);
                reverse(t,last);
                return;
            }
            if(i == first)
            {
                reverse(first,last);
                return;
            }
        }
    }
};