package main

func countMakePalindrome(s string) int {
	i, j := 0, len(s)-1
	changes := 0
	for i < j {
		if s[i] != s[j] {
			changes++
		}
		i++
		j--
	}
	return changes
}

func main() {

}
