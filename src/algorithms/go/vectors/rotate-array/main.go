package main

func rotate(arr []int, d int) []int {
	res := make([]int, len(arr))
	firstIdx := len(arr) - d
	copy(res[:d], arr[firstIdx:])
	for i := d; i < len(arr); i++ {
		res[i] = arr[i-d]
	}
	return res
}

func main() {
}
