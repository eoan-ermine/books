def get_result(arr, target):
	indeces = [0, 0]
	length = len(arr)

	for i in range(length):
		for j in range(i, length):
			if arr[i] + arr[j] == target:
				indeces = [i, j]
	return " ".join([str(e) for e in indeces])
	
arr = list(map(int, input().split()))
target = int(input())
print(get_result(arr, target))