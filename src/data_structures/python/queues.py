# TODO: 
#     - queue on array
#     - queue on singly linked list
#     - circular queue
#     - dequeue (double ended)

import queue


"""FIFO"""

class QueueArray:
    def __init__(self) -> None:
        pass


if __name__ == "__main__":
    q = queue.Queue(2)
    q.put(1)
    q.put(2)

    print(q.qsize())