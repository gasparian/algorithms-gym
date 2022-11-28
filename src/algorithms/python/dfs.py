from collections import deque

def bfs(u, m):
    q = deque()
    visited = [0] * len(m)
    print(u)
    visited[u] = 1
    q.append(u)

    while len(q) != 0:
        u = q.popleft()
        for v in range(1, len(m)):
            if m[u][v] == 1 and visited[v] == 0:
                print(v)
                visited[v] = 1
                q.append(v)

def dfs_(u: int, visited, m) -> None:
    if visited[u] == 0:
        print(u)
        visited[u] = 1
        for v in range(1, len(m)):
            if m[u][v] == 1 and visited[v] == 0:
                dfs_(v, visited, m)
def dfs(u, m):
    visited = [0] * len(m)
    dfs_(u, visited, m)

if __name__ == "__main__":
    adj_matrix = [
        [0, 0, 0, 0, 0, 0, 0],
        [0, 0, 1, 1, 0, 0, 0],
        [0, 1, 0, 0, 1, 0, 0],
        [0, 1, 0, 0, 1, 0, 0],
        [0, 0, 1, 1, 0, 1, 1],
        [0, 0, 0, 0, 1, 0, 0],
        [0, 0, 0, 0, 1, 0, 0],
    ]
    dfs(1, adj_matrix)
    print()
    bfs(4, adj_matrix)
