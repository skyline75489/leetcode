class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        number_map = {}
        arr = num
        for index, num in enumerate(arr):
            number_map[num] = index

        for index, a in enumerate(arr):
		    if number_map.has_key(target - a) and index!=number_map[target-a]:
			    return (index+1, number_map[target-a]+1)
