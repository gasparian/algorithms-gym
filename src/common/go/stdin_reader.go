package utils

import (
	"bufio"
	"errors"
	"os"
	"strconv"
	"strings"
)

var (
	inputNumberErr = errors.New("Input sequence size not equals to the requested size")
)

type StdInReader struct {
	reader *bufio.Reader
}

func NewStdInReader() *StdInReader {
	return &StdInReader{
		reader: bufio.NewReader(os.Stdin),
	}
}

func (r *StdInReader) ReadString() string {
	s, _ := r.reader.ReadString('\n')
	return s[:len(s)-1]
}

func (r *StdInReader) ReadInt() int {
	s := r.ReadString()
	i, _ := strconv.Atoi(s)
	return i
}

func (r *StdInReader) ReadInt64() int64 {
	s := r.ReadString()
	i, _ := strconv.ParseInt(s, 10, 64)
	return i
}

func (r *StdInReader) ReadStrings(N int64) ([]string, error) {
	s := r.ReadString()
	ss := strings.Fields(s)
	if int64(len(ss)) != N {
		return nil, inputNumberErr
	}
	return ss, nil
}

func (r *StdInReader) ReadInts(N int64) ([]int, error) {
	ss, err := r.ReadStrings(N)
	if err != nil {
		return nil, err
	}
	ints := make([]int, N)
	var i int64
	for i = 0; i < N; i++ {
		ints[i], _ = strconv.Atoi(ss[i])
	}
	return ints, nil
}

func (r *StdInReader) ReadInts64(N int64) ([]int64, error) {
	ss, err := r.ReadStrings(N)
	if err != nil {
		return nil, err
	}
	ints := make([]int64, N)
	var i int64
	for i = 0; i < N; i++ {
		ints[i], _ = strconv.ParseInt(ss[i], 10, 64)
	}
	return ints, nil
}
