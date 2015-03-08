class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        enum = list(enumerate(num))
        enum.sort(key = lambda x: x[1])
        left = 0
        right = len(num) - 1
        while True:  #optimization
            while enum[left][1] + enum[right][1] > target:
                right -= 1
            if enum[left][1] + enum[right][1] == target:
                return sorted((enum[left][0] + 1, enum[right][0] + 1))
            left += 1
