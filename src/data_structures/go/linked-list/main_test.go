package main

import (
	"testing"
)

func TestNodeInsertPrev(t *testing.T) {
	t.Parallel()
	n := &Node{Val: 2}
	prevNodes := []*Node{
		&Node{Val: 0},
		&Node{Val: 1},
	}
	InsertPrev(n, prevNodes[0])
	if !(n.Prev.Val == 0 && n.Next == nil) {
		t.Error()
	}
	t.Log(n.Prev, n.Next)
	InsertPrev(n, prevNodes[1])
	if !(n.Prev.Prev.Val == 0 && n.Prev.Val == 1 && n.Next == nil) {
		t.Error()
	}
	t.Log(n.Prev.Prev, n.Prev, n.Val, n.Next)
}

func TestNodeInsertNext(t *testing.T) {
	t.Parallel()
	n := &Node{Val: 0}
	nextNodes := []*Node{
		&Node{Val: 1},
		&Node{Val: 2},
	}
	InsertNext(n, nextNodes[0])
	if !(n.Prev == nil && n.Next.Val == 1) {
		t.Error()
	}
	t.Log(n.Prev, n.Next)
	InsertNext(n.Next, nextNodes[1])
	if !(n.Next.Next.Val == 2 && n.Next.Val == 1) {
		t.Error()
	}
	t.Log(n.Next.Val, n.Next.Next.Val)
}

func TestNodeDelete(t *testing.T) {
	t.Parallel()
	n := &Node{Val: 0}
	nextNodes := []*Node{
		&Node{Val: 3},
		&Node{Val: 2},
		&Node{Val: 1},
	}
	for _, node := range nextNodes {
		InsertNext(n, node)
	}
	Delete(n.Next)
	if !(n.Val == 0 && n.Next.Val == 2) {
		t.Error()
	}
	t.Log(n.Val, n.Next.Val)
}

func TestInsertHead(t *testing.T) {
	t.Parallel()
	l := List{}
	nodes := []*Node{
		&Node{Val: 1},
		&Node{Val: 2},
	}
	for _, node := range nodes {
		l.InsertHead(node)
	}
	if !(l.Head.Val == 2 && l.Tail.Val == 1) {
		t.Error()
	}
	t.Log(l.Head, l.Tail)
}

func TestInsertTail(t *testing.T) {
	t.Parallel()
	l := List{}
	nodes := []*Node{
		&Node{Val: 1},
		&Node{Val: 2},
	}
	for _, node := range nodes {
		l.InsertTail(node)
	}
	if !(l.Head.Val == 1 && l.Tail.Val == 2) {
		t.Error()
	}
	t.Log(l.Head, l.Tail)
}

func TestGetPos(t *testing.T) {
	t.Parallel()
	l := List{}
	nodes := []*Node{
		&Node{Val: 1},
		&Node{Val: 2},
		&Node{Val: 3},
	}
	for _, node := range nodes {
		l.InsertTail(node)
	}
	val, err := l.Get(1)
	if err != nil || val != 2 {
		t.Error()
	}
	t.Log(l.Head, l.Tail, val)
}

func TestInsertPos(t *testing.T) {
	t.Parallel()
	l := List{}
	nodes := []*Node{
		&Node{Val: 1},
		&Node{Val: 3},
	}
	for _, node := range nodes {
		l.InsertTail(node)
	}
	posNode := &Node{Val: 2}
	l.InsertPos(posNode, 0)
	val, _ := l.Get(1)
	if val != 2 {
		t.Error()
	}
	t.Log(l.Head, l.Tail, val)
}

func TestInsertSearch(t *testing.T) {
	t.Parallel()
	l := List{}
	nodes := []*Node{
		&Node{Val: 2},
		&Node{Val: 3},
		&Node{Val: 5},
	}
	for _, node := range nodes {
		l.InsertTail(node)
	}
	idx := l.Search(3)
	if idx != 1 {
		t.Error()
	}
	t.Log(l.Head, l.Head.Next, l.Tail, idx)
}

func TestDelete(t *testing.T) {
	t.Parallel()
	l := List{}
	nodes := []*Node{
		&Node{Val: 1},
		&Node{Val: 2},
		&Node{Val: 3},
	}
	for _, node := range nodes {
		l.InsertTail(node)
	}
	l.Delete(1)
	if l.Head.Next.Val != 3 {
		t.Error()
	}
	t.Log(l.Head.Next)
	l.Delete(1)
	if l.Head.Next != nil {
		t.Error()
	}
	t.Log(l.Head.Next)
}
