from typing import List


class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        to_insert = [idx for idx, element in enumerate(arr) if element == 0]
        for offset, index in enumerate(to_insert):
            arr.insert(index + offset, 0)
        del arr[-len(to_insert):]

if __name__ == "__main__":
    array = [1,0,2,3,0,4,5,0]
    
    solution = Solution()
    solution.duplicateZeros(array)

    assert(
        array == [1,0,0,2,3,0,0,4]
    )