package main

import (
	"reflect"
	"testing"
)

func Test(t *testing.T) {
	t.Parallel()
	reversedSub := []int{1, 2, 6, 5, 4, 3}
	arr := []int{1, 2, 3, 4, 5, 6}
	reverseArray(arr, 2, 5)
	if !reflect.DeepEqual(reversedSub, arr) {
		t.Error()
	}
	t.Log(arr)
}
