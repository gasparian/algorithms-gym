package main

import (
	"reflect"
	"testing"
)

func TestSieve(t *testing.T) {
	t.Parallel()
	primes := []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29}
	res := sieve(30)
	if !reflect.DeepEqual(primes, res) {
		t.Error()
	}
	t.Log(res)
}

func TestSegmentedSieve(t *testing.T) {
	t.Parallel()
	primes := []int{100000007, 100000037, 100000039, 100000049, 100000073, 100000081}
	res := segmentedSieve(100000000, 100000100)
	if !reflect.DeepEqual(primes, res) {
		t.Error()
	}
	t.Log(res)
}
