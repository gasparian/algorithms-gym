
# O(N^2)
def bubble(arr, n):
    for i in range(0, n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


# O(Nlog(N))
def quick_sort(arr, low, high):
    pivot = arr[low + (high-low)//2]
    i, j = low, high
    while i <= j:
        while arr[i] < pivot:
            i += 1
        while arr[j] > pivot:
            j -= 1
        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1

    if j > low:
        quick_sort(arr, low, j)
    if i < high:
        quick_sort(arr, i, high)


if __name__ == "__main__":
    arr = [3, 7, 9, 10, 6, 5, 12, 4, 11, 2]
    n = 10
    quick_sort(arr, 0, len(arr)-1)
    print(arr)
    assert(arr == sorted(arr))
