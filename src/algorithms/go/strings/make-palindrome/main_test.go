package main

import (
	"testing"
)

func TestMakePalindrome(t *testing.T) {
	t.Parallel()
	changes := countMakePalindrome("radecar")
	if changes == 0 {
		t.Error("There are no changes in string")
	}
	t.Log(changes)
}
