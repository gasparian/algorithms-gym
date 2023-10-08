package main

import (
	"testing"
)

func Test(t *testing.T) {
	t.Parallel()
	vec := []int{1, 2, 4, 8, 16}
	sumVec := prefixSum(vec)
	sum := sumSubArr(sumVec, 1, 3)
	if sum != int64(14) {
		t.Error()
	}
	t.Log(vec, 1, 3, sum)
}
