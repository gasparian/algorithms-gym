package main

import "errors"

type Node struct {
	Val  int
	Next *Node
	Prev *Node
}

func InsertPrev(n *Node, ins *Node) {
	if n == nil {
		return
	}
	ins.Next = n
	ins.Prev = n.Prev
	if n.Prev != nil {
		n.Prev.Next = ins
	}
	n.Prev = ins
}

func InsertNext(n *Node, ins *Node) {
	if n == nil {
		return
	}
	ins.Next = n.Next
	ins.Prev = n
	if n.Next != nil {
		n.Next.Prev = ins
	}
	n.Next = ins
}

func Delete(n *Node) {
	if n == nil {
		return
	}
	if n.Prev != nil {
		n.Prev.Next = n.Next
	}
	if n.Next != nil {
		n.Next.Prev = n.Prev
	}
}

type List struct {
	Head *Node
	Tail *Node
}

func (L *List) InsertHead(n *Node) {
	if L.Head == nil {
		L.Head = n
		L.Tail = n
		return
	}
	oldHead := *L.Head
	oldHead.Prev = n
	n.Next = &oldHead
	L.Head = n
	L.Tail = &oldHead
}

func (L *List) InsertTail(n *Node) {
	if L.Head == nil {
		L.Head = n
		L.Tail = n
		return
	}
	nn := L.Head
	for nn != nil {
		if nn.Next == nil {
			n.Prev = nn
			nn.Next = n
			L.Tail = n
			return
		}
		nn = nn.Next
	}
}

func (L *List) InsertPos(n *Node, pos int) {
	counter := 0
	nn := L.Head
	for nn != nil {
		if counter == pos {
			n.Prev = nn
			if nn.Next == nil {
				nn.Next = n
				L.Tail = n
				return
			}
			if nn.Next.Next != nil {
				tmpNode := *nn.Next.Next
				tmpNode.Prev = n
				n.Next = &tmpNode
			}
			nn.Next = n
			return
		}
		nn = nn.Next
		counter++
	}
}

func (L *List) Get(pos int) (int, error) {
	n := L.Head
	counter := 0
	for n != nil {
		if counter == pos {
			return n.Val, nil
		}
		n = n.Next
		counter++
	}
	return 0, errors.New("Can't find value")
}

func (L *List) Search(val int) int {
	n := L.Head
	counter := 0
	for n != nil {
		if n.Val == val {
			return counter
		}
		n = n.Next
		counter++
	}
	return -1
}

func (L *List) Delete(pos int) {
	n := L.Head
	for i := 0; i < pos; i++ {
		if n == nil {
			return
		}
		n = n.Next
	}
	Delete(n)
}

func main() {

}
