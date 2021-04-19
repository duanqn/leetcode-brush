class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        index1 = 0
        index2 = 0
        size = len(nums1) + len(nums2)
        if size == 0:
            return 0

        # size > 0
        needAvg = (size % 2 == 0)
        processed = 0
        while index1 <= len(nums1) and index2 <= len(nums2):
            if index1 < len(nums1) and index2 < len(nums2):
                candidate1 = nums1[index1]
                candidate2 = nums2[index2]
                if candidate1 < candidate2:
                    next = candidate1
                    index1 += 1
                else:
                    next = candidate2
                    index2 += 1
            elif index1 < len(nums1):
                next = nums1[index1]
                index1 += 1
            elif index2 < len(nums2):
                next = nums2[index2]
                index2 += 1
            else:
                break

            processed += 1
            if needAvg and processed == size // 2:
                save = next
            if needAvg and processed == size // 2 + 1:
                return (save + next) / 2
            if (not needAvg) and processed == (size + 1) // 2:
                return next

        return -1

if __name__ == '__main__':
    s = Solution()
    assert s.findMedianSortedArrays([0], []) == 0
    assert s.findMedianSortedArrays([2], []) == 2
    assert s.findMedianSortedArrays([], [1]) == 1
    assert s.findMedianSortedArrays([1, 2], [3, 4]) == 2.5
    assert s.findMedianSortedArrays([1, 3], [2]) == 2
    print('Verified')
