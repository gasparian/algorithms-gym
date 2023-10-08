package main

func sieve(N int) []int {
	isPrime := make([]bool, N+1)
	for i := range isPrime {
		isPrime[i] = true
	}
	for i := 2; i*i <= N; i++ {
		if isPrime[i] {
			for j := i + i; j <= N; j += i {
				isPrime[j] = false
			}
		}
	}
	var res []int
	for i, val := range isPrime {
		if val && i > 1 {
			res = append(res, i)
		}
	}
	return res
}

func segmentedSieve(N, M int) []int {
	isPrime := make([]bool, M-N+1)
	for i := range isPrime {
		isPrime[i] = true
	}
	for i := 2; i*i <= M; i++ {
		start := ((N-1)/i + 1) * i
		for j := start; j <= M; j += i {
			if j >= N && j <= M {
				isPrime[j-N] = false
			}
		}
	}
	var res []int
	for i, val := range isPrime {
		if val && i > 1 {
			res = append(res, i+N)
		}
	}
	return res
}

func main() {
}
