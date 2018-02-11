from graph import SimpleGraph
from collections import deque

class Queue:
    def __init__(self):
        self.queue = deque()

    def empty(self):
        return len(self.queue) == 0

    def push(self, x):
        self.queue.append(x)
    
    def pop(self):
        return self.queue.popleft()

def BFS(graph, start, visit = lambda x: print("Visiting {}".format(x))):
    queue = Queue()
    queue.push(start)
    visited = set()

    while not queue.empty():
        current = queue.pop()
        visit(current)
        visited.add(current)
        for neighbor in graph.neighbors(current):
            if neighbor not in visited:
                queue.push(neighbor)


if __name__ == '__main__':
    graph = SimpleGraph()
    graph.edges = {
        'A': ['B'],
        'B': ['A', 'C', 'D'],
        'C': ['A'],
        'D': ['E', 'A'],
        'E': ['B']
    }
    BFS(graph, 'A')