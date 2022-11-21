from typing import Any, Optional

from linked_list import SinglyLinkedList, SinglyNode

"""LIFO"""

class StackArray:
    def __init__(self, size: int) -> None:
        self.size = size
        self._data = [None for i in range(size)]
        self._top = -1

    def put(self, x: Any) -> bool:
        overflow = True
        if self._top < (self.size - 1):
            self._top += 1
            self._data[self._top] = x
            overflow = False
        return overflow

    def pop(self) -> Any:
        if self._top >= 0:
            x = self._data[self._top]
            self._top -= 1
            return x

    def peek(self, pos: int) -> Any:
        pos_ = self._top - pos
        if pos_ >= 0:
            return self._data[pos_]

    def is_empty(self) -> bool:
        if self._top < 0:
            return True
        return False

    def is_full(self) -> bool:
        if self._top == (self.size - 1):
            return True
        return False

    def front(self) -> Any:
        return self._data[self._top]

    def back(self) -> Any:
        if self._top > 0:
            return self._data[0]


class StackLinkedList:
    def __init__(self, size: int) -> None:
        self.size = size
        self._data = SinglyLinkedList()

    def put(self, x: Any) -> bool:
        overflow = True
        if self._data.size < self.size:
            self._data.insert(x)
            overflow = False
        return overflow

    def pop(self) -> Any:
        x = self._data.front
        self._data.delete()
        if x:
            return x.data
        return None

    def peek(self, pos: int) -> Any:
        pos_ = self._data.size - pos - 1
        x = self._data.get(pos_)
        if x:
            return x.data
        return None

    def is_empty(self) -> bool:
        if self._data.size == 0:
            return True
        return False

    def is_full(self) -> bool:
        if self._data.size == self.size:
            return True
        return False

    def front(self) -> Any:
        return self._data.front.data

    def back(self) -> Any:
        return self._data.root.data


if __name__ == "__main__":
    print("Stack based on array")
    s = StackArray(3)
    s.put(0)
    s.put(1)
    s.put(2)
    print(s.peek(0))
    print(s.is_full())
    print(s.pop(), s.pop(), s.pop())
    print(s.is_empty())
    print()

    print("Stack based on linked list")
    s = StackLinkedList(3)
    s.put(0)
    s.put(1)
    s.put(2)
    print(s.peek(0))
    print(s.is_full())
    print(s.pop(), s.pop(), s.pop())
    print(s.is_empty())