package main

func removeLeadingZeros(s string) string {
	start := 0
	for i, ch := range s {
		if ch != '0' {
			start = i
			break
		}
	}
	return s[start:]
}

func compareLargeNumbers(s1, s2 string) string {
	s1Cleaned := removeLeadingZeros(s1)
	s2Cleaned := removeLeadingZeros(s2)
	if len(s1Cleaned) > len(s2Cleaned) {
		return "A"
	}
	if len(s1Cleaned) < len(s2Cleaned) {
		return "B"
	}
	if len(s1Cleaned) == len(s2Cleaned) {
		for i := 0; i < len(s1Cleaned); i++ {
			if s1Cleaned[i] > s2Cleaned[i] {
				return "A"
			}
			if s1Cleaned[i] < s2Cleaned[i] {
				return "B"
			}
		}
	}
	return "="
}

func main() {
}
