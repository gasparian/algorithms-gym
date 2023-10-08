package main

func fibonacciNaive(n int64) int64 {
	if n <= 1 {
		return n
	}
	return fibonacciNaive(n-1) + fibonacciNaive(n-2)
}

func fibonacciFast(n int64) []int64 {
	if n <= 1 {
		return []int64{n}
	}
	mem := make([]int64, n+1)
	mem[1] = 1
	var i int64
	for i = 2; i <= n; i++ {
		mem[i] = mem[i-1] + mem[i-2]
	}
	return mem
}

func fibLastDigitFast(n int64) int64 {
	fib60 := fibonacciFast(60)
	return fib60[n%60] % 10
}

func fibLastDigitNaive(n int64) int64 {
	fib60 := fibonacciFast(n)
	return fib60[n] % 10
}

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	aPrime := a % b
	return gcd(b, aPrime)
}

func lcmNaive(a, b int) int64 {
	ab := (int64)(a * b)
	a64 := int64(a)
	b64 := int64(b)
	var i int64
	for i = 1; i <= ab; i++ {
		if i%a64 == 0 && i%b64 == 0 {
			return i
		}
	}
	return ab
}

func lcmFast(a, b int) int64 {
	if a == 0 && b == 0 {
		return 0
	}
	ab := (int64)(a * b)
	if ab < 0 {
		ab *= -1
	}
	return ab / int64(gcd(a, b))
}

func pisano(m int64) []int64 {
	fib := []int64{0, 1}
	for {
		fib = append(fib, (fib[len(fib)-1]+fib[len(fib)-2])%m)
		if fib[len(fib)-1] == 1 && fib[len(fib)-2] == 0 {
			return fib[:len(fib)-2]
		}
	}
}

func fibHugeNaive(n, m int64) int64 {
	if n <= 1 {
		return n
	}
	var prev int64 = 0
	var curr int64 = 1
	var tmpPrev int64
	var i int64
	for i = 0; i < n-1; i++ {
		tmpPrev = prev
		prev = curr
		curr = tmpPrev + curr
	}
	return curr % m
}

func fibHugeFast(n, m int64) int64 {
	if n <= 1 {
		return n
	}
	p := pisano(m)
	idx := n % int64(len(p))
	return p[idx]
}

func fibLastDigitSumNaive(n int64) int64 {
	if n <= 1 {
		return n
	}
	var prev int64 = 0
	var curr int64 = 1
	var sum int64 = 1

	var tmpPrev int64
	var i int64
	for i = 0; i < n-1; i++ {
		tmpPrev = prev
		prev = curr
		curr = tmpPrev + curr
		sum += curr
	}
	return sum % 10
}

// F_sum_n = F_n+2 - 1
func fibLastDigitSumFast(n int64) int64 {
	if n <= 2 {
		return n
	}
	fib60 := fibonacciFast(60)
	lastDigit := fib60[(n+2)%60] % 10
	if lastDigit == 0 {
		return 9
	}
	return lastDigit - 1
}

func fibLastDigitSumFracNaive(from, to int64) int64 {
	var sum int64 = 0

	var curr int64 = 0
	var next int64 = 1

	var tmpCurr int64
	var i int64
	for i = 0; i <= to; i++ {
		if i >= from {
			sum += curr
		}
		tmpCurr = next
		next = next + curr
		curr = tmpCurr
	}
	return sum % 10
}

func fibLastDigitSumFracFast(from, to int64) int64 {
	if from > 0 {
		from -= 1
	}
	sum1 := fibLastDigitSumFast(from)
	sum2 := fibLastDigitSumFast(to)
	diff := sum2 - sum1
	return (diff%10 + 10) % 10
}

func fibLastDigitSumSquareNaive(n int64) int64 {
	if n <= 1 {
		return n
	}
	var prev int64 = 0
	var curr int64 = 1
	var sum int64 = 1

	var tmpPrev int64
	var i int64
	for i = 0; i < n-1; i++ {
		tmpPrev = prev
		prev = curr
		curr = tmpPrev + curr
		sum += curr * curr
	}
	return sum % 10
}

func fibLastDigitSumSquareFast(n int64) int64 {
	if n <= 1 {
		return n
	}
	fib := fibonacciFast(60)
	return ((fib[n%60] % 10) * (fib[(n+1)%60] % 10)) % 10
}

func main() {
}
