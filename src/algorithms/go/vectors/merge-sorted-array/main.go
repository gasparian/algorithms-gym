package main

func mergeSorted(arr1 []int, arr2 []int) []int {
	res := make([]int, len(arr1)+len(arr2))
	i, j, k := 0, 0, 0
	for i < len(arr1) && j < len(arr2) {
		if arr1[i] < arr2[j] {
			res[k] = arr1[i]
			i++
		} else {
			res[k] = arr2[j]
			j++
		}
		k++
	}
	if i < len(arr1) {
		copy(res[k:], arr1[i:])
	}
	if j < len(arr2) {
		copy(res[k:], arr2[j:])
	}
	return res
}

func main() {
}
