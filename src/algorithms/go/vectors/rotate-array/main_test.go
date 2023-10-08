package main

import (
	"reflect"
	"testing"
)

func Test(t *testing.T) {
	t.Parallel()
	truth := []int{6, 7, 8, 1, 2, 3, 4, 5}
	vec := []int{1, 2, 3, 4, 5, 6, 7, 8}
	res := rotate(vec, 3)
	if !reflect.DeepEqual(truth, res) {
		t.Error()
	}
	t.Log(res)
}
