package main

func reverseArray(arr []int, l, r int) {
	i, j := l, r
	for i < j {
		arr[i], arr[j] = arr[j], arr[i]
		i++
		j--
	}
}

func main() {
}
