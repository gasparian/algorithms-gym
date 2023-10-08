package main

func sumSubArr(sum []int64, l, r int) int64 {
	return sum[r] - sum[l-1]
}

func prefixSum(arr []int) []int64 {
	res := make([]int64, len(arr))
	res[0] = (int64)(arr[0])
	for i := 1; i < len(arr); i++ {
		res[i] = (int64)(arr[i]) + res[i-1]
	}
	return res
}

func main() {
}
