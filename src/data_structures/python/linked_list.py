from typing import Any, Optional


class SinglyNode:
    def __init__(self, data: Any = None, next = None) -> None:
        self.data = data
        self.next: Optional[SinglyNode] = next


class SinglyLinkedList:
    def __init__(self) -> None:
        self.root: Optional[SinglyNode] = None
        self.front: Optional[SinglyNode] = None
        self.size = 0

    def insert(self, data: Any, pos: Optional[int] = None) -> None:
        new_node = SinglyNode(data)
        if not self.root:
            self.root = new_node
            self.front = self.root
        else:
            node = self.root
            max_i = self.size - 1
            if pos is not None:
                max_i = pos - 1
            for i in range(max_i):
                node = node.next
            next_node = node.next
            node.next = new_node
            if next_node:
                new_node.next = next_node
            if max_i == (self.size - 1):
                self.front = new_node
        self.size += 1

    def delete(self, pos: Optional[int] = None) -> None:
        if pos is None:
            pos = self.size - 1
        if pos > (self.size - 1) or not self.root:
            return
        if pos == 0:
            self.root = self.root.next
        else:
            node = self.root
            for i in range(pos-1):
                node = node.next
            prev_node = node
            next_node = prev_node.next.next
            if not next_node:
                prev_node.next = None
                self.front = prev_node
            else:
                prev_node.next = next_node 
        self.size -= 1

    def get(self, pos: int) -> Optional[SinglyNode]:
        if pos > (self.size - 1) or not self.root:
            return None
        node = self.root
        for i in range(pos):
            node = node.next
        return node


class DoublyNode:
    def __init__(self, data: Any = None, next = None, prev = None) -> None:
        self.data = data
        self.prev: Optional[DoublyNode] = prev
        self.next: Optional[DoublyNode] = next


class DoublyLinkedList:
    def __init__(self) -> None:
        self.root: Optional[DoublyNode] = None
        self.front: Optional[DoublyNode] = None
        self.size = 0

    def insert(self, data: Any, pos: Optional[int] = None) -> None:
        new_node = DoublyNode(data)
        if not self.root:
            self.root = new_node
            self.front = self.root
        else:
            node = self.root
            max_i = self.size - 1
            if pos is not None:
                max_i = pos - 1
            for i in range(max_i):
                node = node.next
            next_node = node.next
            new_node.prev = node
            node.next = new_node
            if next_node:
                new_node.next = next_node
            if max_i == (self.size - 1):
                self.front = new_node
        self.size += 1

    def delete(self, pos: Optional[int] = None) -> None:
        if pos is None:
            pos = self.size - 1
        if pos > (self.size - 1) or not self.root:
            return
        if pos == 0:
            self.root = self.root.next
            self.root.prev = None
        else:
            node = self.root
            max_i = self.size - 1
            if pos is not None:
                max_i = pos - 1
            for i in range(max_i):
                node = node.next
            prev_node = node
            next_node = prev_node.next.next
            if not next_node:
                prev_node.next = None
                self.front = prev_node
            else:
                prev_node.next = next_node
                next_node.prev = prev_node
        self.size -= 1

    def get(self, pos: int) -> Optional[DoublyNode]:
        if pos > (self.size - 1) or not self.root:
            return None
        node = self.root
        for i in range(pos):
            node = node.next
        return node


if __name__ == "__main__":
    print("Singly linked list")
    sll = SinglyLinkedList()
    sll.insert(0)
    sll.insert(1)
    sll.insert(2)
    node = sll.get(1)
    print(
        "size", sll.size, 
        "root", sll.root.data, 
        "front", sll.front.data, 
        "node", node.data,
        "node.next", node.next.data,
    )
    sll.delete()
    print("deleted!")
    print(
        "size", sll.size, 
        "root", sll.root.data, 
        "front", sll.front.data
    )
    print()

    print("Doubly linked list")
    sll = DoublyLinkedList()
    sll.insert(0)
    sll.insert(1)
    sll.insert(2)
    node = sll.get(1)
    print("prev", node.prev.data, "next", node.next.data)
    sll.delete()
    print("size", sll.size, "root", sll.root.data, "front", sll.front.data)
