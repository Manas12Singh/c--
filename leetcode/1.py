from collections import deque

def findMovieWithHighestHorrorIndex(N, horrorList, similarities):
    graph = [[] for _ in range(N)]
    for a, b in similarities:
        graph[a].append(b)
        graph[b].append(a)
    HI = [float("inf")] * N
    q = deque()

    for h in horrorList:
        HI[h] = 0
        q.append(h)
    while q:
        movie = q.popleft()
        for neighbor in graph[movie]:
            if HI[neighbor] == float("inf"):
                HI[neighbor] = HI[movie] + 1
                q.append(neighbor)
    maxHI = -1
    result = -1
    for i in range(N):
        if HI[i] > maxHI:
            maxHI = HI[i]
            result = i
        elif HI[i] == maxHI and i < result:
            result = i

    return result