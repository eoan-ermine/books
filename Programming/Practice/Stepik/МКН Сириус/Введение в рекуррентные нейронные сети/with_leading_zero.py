import numpy as np

def max_element_spec(arr):
    """
    Return max element in front of which is zero for input array.
    If appropriate elements are absent, then return None
    :param arr: array,
    :return: max element value or None
    """    

    target = []
    previous = arr[0]
    
    for element in arr[1:]:
        if previous == 0:
            target.append(element)
        previous = element
    
    return max(target) if target else None

arr = list(map(int, input().split()))
print(max_element_spec(arr))