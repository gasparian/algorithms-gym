package main

import (
	"math/rand"
	"reflect"
	"testing"
	"time"
)

func TestSort(t *testing.T) {
	t.Parallel()
	inputs := [][]int{
		[]int{6, 3, 5, 4, 1, 2},
		[]int{6, 3, 7, 5, 4, 1, 2},
		[]int{},
		[]int{0},
		[]int{-1, 1},
		[]int{1, 1},
	}
	answers := [][]int{
		[]int{1, 2, 3, 4, 5, 6},
		[]int{1, 2, 3, 4, 5, 6, 7},
		[]int{},
		[]int{0},
		[]int{-1, 1},
		[]int{1, 1},
	}

	t.Run("SelectionSort", func(t *testing.T) {
		for i, inp := range inputs {
			arr := make([]int, len(inp))
			copy(arr, inp)
			SelectionSort(arr)
			if !reflect.DeepEqual(answers[i], arr) {
				t.Error()
			}
			t.Log(arr)
		}
	})

	t.Run("BubbleSort", func(t *testing.T) {
		for i, inp := range inputs {
			arr := make([]int, len(inp))
			copy(arr, inp)
			BubbleSort(arr)
			if !reflect.DeepEqual(answers[i], arr) {
				t.Error()
			}
			t.Log(arr)
		}
	})

	t.Run("InsertionSort", func(t *testing.T) {
		for i, inp := range inputs {
			arr := make([]int, len(inp))
			copy(arr, inp)
			InsertionSort(arr)
			if !reflect.DeepEqual(answers[i], arr) {
				t.Error()
			}
			t.Log(arr)
		}
	})

	t.Run("MergeSort", func(t *testing.T) {
		for i, inp := range inputs {
			arr := make([]int, len(inp))
			copy(arr, inp)
			MergeSort(arr, 0, len(arr)-1)
			if !reflect.DeepEqual(answers[i], arr) {
				t.Error()
			}
			t.Log(arr)
		}
	})

	t.Run("QuickSort", func(t *testing.T) {
		rand.Seed(time.Now().UnixNano())
		for i, inp := range inputs {
			arr := make([]int, len(inp))
			copy(arr, inp)
			QuickSort(arr, 0, len(arr)-1)
			if !reflect.DeepEqual(answers[i], arr) {
				t.Error()
			}
			t.Log(arr)
		}
	})
}
