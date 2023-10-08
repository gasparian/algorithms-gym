package main

import (
	"math/rand"
)

// N^2
func SelectionSort(arr []int) {
	for i := 0; i < len(arr); i++ {
		minIdx := i
		for j := i + 1; j < len(arr); j++ {
			if arr[j] < arr[minIdx] {
				minIdx = j
			}
		}
		arr[i], arr[minIdx] = arr[minIdx], arr[i]
	}
}

// N^2
func BubbleSort(arr []int) {
	for i := 0; i < len(arr); i++ {
		for j := 1; j < len(arr)-i; j++ {
			if arr[j] < arr[j-1] {
				arr[j], arr[j-1] = arr[j-1], arr[j]
			}
		}
	}
}

// N^2
func InsertionSort(arr []int) {
	for i := 0; i < len(arr); i++ {
		j := i
		for j > 0 && arr[j-1] > arr[j] {
			arr[j-1], arr[j] = arr[j], arr[j-1]
			j--
		}
	}
}

func mergeSorted(arr []int, start, mid, end int) {
	arrL := make([]int, mid-start+1)
	arrR := make([]int, end-mid)
	copy(arrL, arr[start:mid+1])
	copy(arrR, arr[mid+1:])
	// Merge sorted arrays L and R into arr[start...end]
	i, j, k := 0, 0, start
	for i < len(arrL) && j < len(arrR) {
		if arrL[i] < arrR[j] {
			arr[k] = arrL[i]
			i++
		} else {
			arr[k] = arrR[j]
			j++
		}
		k++
	}
	// one of L or R will exhaust first, we'll copy the remaining to arr
	if i < len(arrL) {
		copy(arr[k:], arrL[i:])
		k += len(arrL) - i
	}
	if j < len(arrR) {
		copy(arr[k:], arrR[j:])
	}
}

// NlogN
func MergeSort(arr []int, start, end int) {
	if start >= end {
		return
	}
	mid := (start + end) / 2
	MergeSort(arr, start, mid)
	MergeSort(arr, mid+1, end)
	mergeSorted(arr, start, mid, end)
}

func generateRandomInt(min, max int) int {
	return rand.Intn(max-min+1) + min
}

func partition(arr []int, l, r int) int {
	pIdx := generateRandomInt(l, r)
	// move pivot point to the end of an array
	arr[r], arr[pIdx] = arr[pIdx], arr[r]
	i, j := l-1, l
	for j < r {
		if arr[j] < arr[r] {
			i++
			arr[j], arr[i] = arr[i], arr[j]
		}
		j++
	}
	i++
	arr[i], arr[r] = arr[r], arr[i]
	return i
}

// NlogN
func QuickSort(arr []int, l, r int) {
	if l >= r {
		return
	}
	p := partition(arr, l, r)
	QuickSort(arr, l, p-1)
	QuickSort(arr, p+1, r)
}

// TODO:
func CountingSort(arr []int) {

}

// TODO:
func RadixSort(arr []int) {

}

// TODO:
func BucketSort(arr []int) {

}

func main() {

}
