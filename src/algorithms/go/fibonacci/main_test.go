package main

import (
	"fmt"
	"testing"
)

func TestFibonacci(t *testing.T) {
	fib3 := fibonacciFast(3)
	if fib3[3] != 2 {
		t.Error(fmt.Sprintf("Should be %v but found %v", fib3, 2))
	}
	fib10 := fibonacciFast(10)
	if fib10[10] != 55 {
		t.Error(fmt.Sprintf("Should be %v but found %v", fib10, 55))
	}
	var n int64
	for n = 2; n < 20; n++ {
		fibFastN := fibonacciFast(n)
		fibNaiveN := fibonacciNaive(n)
		if fibFastN[n] != fibNaiveN {
			t.Fatal(fmt.Sprintf("Should be %v but found %v", fibFastN, fibNaiveN))
		}
	}
}

func TestFibLastDigit(t *testing.T) {
	fib10Fast := fibLastDigitFast(10)
	fib10Naive := fibLastDigitNaive(10)
	if fib10Fast != fib10Naive {
		t.Error()
	}
	fib10Fast = fibLastDigitFast(61)
	fib10Naive = fibLastDigitNaive(61)
	if fib10Fast != fib10Naive {
		t.Error()
	}
}

func TestLcm(t *testing.T) {
	lcmF := lcmFast(6, 8)
	lcmN := lcmNaive(6, 8)
	if lcmF != lcmN {
		t.Error(fmt.Sprintf("Got %v, expected: %v", lcmF, lcmN))
	}
}

func TestFibHuge(t *testing.T) {
	for n := 1; n < 93; n++ {
		for m := 2; m < 100; m++ {
			naive := fibHugeNaive(int64(n), int64(m))
			fast := fibHugeFast(int64(n), int64(m))
			if fast != naive {
				t.Fatal(fmt.Sprintf("Got: %v; Expected: %v (n=%v, m=%v)", fast, naive, n, m))
			}
		}
	}
}

func TestFibSumLastDigit(t *testing.T) {
	for n := 0; n < 91; n++ {
		naive := fibLastDigitSumNaive(int64(n))
		fast := fibLastDigitSumFast(int64(n))
		if fast != naive {
			t.Error(fmt.Sprintf("Got: %v; Expected: %v", fast, naive))
		}
	}
}

func TestFibPartialSum(t *testing.T) {
	for n := 0; n < 71; n++ {
		naive := fibLastDigitSumFracNaive(int64(n), int64(n+20))
		fast := fibLastDigitSumFracFast(int64(n), int64(n+20))
		if fast != naive {
			t.Fatal(fmt.Sprintf("Got: %v; Expected: %v (n=%v, m=%v)", fast, naive, n, n+20))
		}
	}
}

func TestFibSumSquares(t *testing.T) {
	for n := 0; n < 47; n++ {
		naive := fibLastDigitSumSquareNaive(int64(n))
		fast := fibLastDigitSumSquareFast(int64(n))
		if fast != naive {
			t.Error(fmt.Sprintf("Got: %v; Expected: %v", fast, naive))
		}
	}
}
