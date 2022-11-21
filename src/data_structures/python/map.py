from typing import Any, Callable, List, Optional


class Node:
    def __init__(self, key: Any = None, val: Any = None, next = None) -> None:
        self.key = key
        self.val = val
        self.next: Optional[Node] = next


def naive_hash(key: str) -> int:
    return ord(key.upper()) - ord('A')


class Map:
    def __init__(self, hash_func: Callable = hash) -> None:
        self._data: List[Node] = [Node()]
        self._n_entries = 0
        self._size = 1
        self._cap = 2
        self._hash = hash_func

    def _get_idx(self, key: str) -> int:
        return self._hash(key) % self._size

    def _adjust_data_array(self):
        if self._size == self._cap:
            self._cap *= 2
            for i in range(self._size, self._cap):
                self._data.append(Node())
        if self._size < (self._cap // 4):
            self._cap /= 2
            self._data = self._data[:self._cap//2]

    def __setitem__(self, key: str, val: Any) -> None:
        self._adjust_data_array()
        idx = self._get_idx(key)
        current_node = self._data[idx]
        prev_node = None
        while current_node is not None:
            if current_node.key == key:
                current_node.val = val
                return
            prev_node = current_node
            current_node = current_node.next
        prev_node.next = Node(key, val)
        self._n_entries += 1

    def __getitem__(self, key: str) -> Any:
        idx = self._get_idx(key)
        current_node = self._data[idx]
        while current_node is not None:
            if current_node.key == key:
                return current_node.val
            current_node = current_node.next
        return None

    def __delitem__(self, key: str) -> None:
        self._adjust_data_array()
        idx = self._get_idx(key)
        current_node = self._data[idx]
        prev_node = None
        while current_node is not None:
            if current_node.key == key:
                if prev_node is None:
                    self._data[idx] = Node()
                    self._size -= 1
                else:
                    prev_node.next = None
                    del current_node
                self._n_entries -= 1
                return
            prev_node = current_node
            current_node = current_node.next

    def __len__(self) -> int:
        return self._n_entries

if __name__ == "__main__":
    m = Map(naive_hash)
    m["a"] = 1
    m["A"] = 2
    m["b"] = 2
    m["c"] = 3
    del m["c"]

    assert(m["a"] == 1)
    assert(m["A"] == 2)
    assert(m["c"] == None)
    assert(len(m) == 3)
    assert(m._cap == 2)

    print("Tests passed!")
