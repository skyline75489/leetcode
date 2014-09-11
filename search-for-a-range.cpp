class Solution {
public:
    // 笨方法，两遍二分查找
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> result;
        int l = 0, r = n - 1;
        int mid = 0;
        int start_index = -1;
        int end_index = -1;
        while (l <= r) {
            mid = (l + r) / 2;
            if ((target == A[mid] && mid == 0) || (target == A[mid] && target != A[mid-1]) ) {
                start_index = mid;
                break;
            } else if (target > A[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        if (start_index == -1) {
            result.push_back(-1);
        } else {
            result.push_back(start_index);
        }
        
        l = 0, r = n - 1;
        mid = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            
            if ((target == A[mid] && mid == n-1) || (target == A[mid] && target != A[mid+1])) {
                end_index = mid;
                break;
            } else if (target >= A[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        if (end_index == -1) {
            result.push_back(-1);
        } else {
            result.push_back(end_index);
        }
        return result;
    
    }
};

// 我是真不会用 std 啊。。。
class Solution {
public:
     vector<int> searchRange(int A[], int n, int target) {
        const int l = distance(A, lower_bound(A, A + n, target));
        const int u = distance(A, prev(upper_bound(A, A + n, target)));
        if (A[l] != target) // not found
            return vector<int> { -1, -1 };
        else
            return vector<int> { l, u };
     }
};