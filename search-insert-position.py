# 这么暴力的Python方法也能过
# Leetcode的测试数据真是比较小
def search(A, target):
    try:
        return A.index(target)
    except ValueError:
        A.append(target)
        A.sort()
        return A.index(target)
        
