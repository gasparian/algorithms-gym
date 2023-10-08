package main

import (
	"testing"
)

func TestRemoveZeros(t *testing.T) {
	t.Parallel()
	orig := "00042"
	cleaned := removeLeadingZeros("00042")
	if len(cleaned) >= len(orig) {
		t.Error()
	}
	t.Log(cleaned)
}

func TestCompareLargeNumbers(t *testing.T) {
	t.Parallel()
	cases := map[string][]string{
		"B": []string{"6", "19"},
		"A": []string{"23567", "0023534"},
		"=": []string{"63", "0063"},
	}
	for k, v := range cases {
		answer := compareLargeNumbers(v[0], v[1])
		if answer != k {
			t.Fatal()
		}
		t.Log(v, answer)
	}
}
