package main

import (
	"reflect"
	"testing"
)

func TestNormal(t *testing.T) {
	t.Parallel()
	truth := []int{1, 2, 3, 4, 5, 6, 7, 8}
	arr1 := []int{2, 3, 4, 6}
	arr2 := []int{1, 5, 7, 8}
	merged := mergeSorted(arr1, arr2)
	if !reflect.DeepEqual(merged, truth) {
		t.Errorf("Merge failed: %v", merged)
	}
	t.Log(merged)
}

func TestSingleEmpty(t *testing.T) {
	t.Parallel()
	arr1 := []int{}
	arr2 := []int{1, 5, 7, 8}
	merged := mergeSorted(arr1, arr2)
	if !reflect.DeepEqual(merged, arr2) {
		t.Errorf("Merge failed: %v", merged)
	}
	t.Log(merged)
}

func TestBothEmpty(t *testing.T) {
	t.Parallel()
	arr1 := []int{}
	arr2 := []int{}
	merged := mergeSorted(arr1, arr2)
	if len(merged) != 0 {
		t.Errorf("Merge failed: %v", merged)
	}
	t.Log(merged)
}
