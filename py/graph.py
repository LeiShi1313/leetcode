class SimpleGraph:
    def __init__(self):
        self.edges = {}

    def neighbors(self, _id):
        return self.edges[_id]


class SquareGrid:
    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.walls = []

    def in_bound(self, _id):
        x, y = _id
        return 0 <= x < self.width and 0 <= y < self.height

    def passable(self, _id):
        return _id not in self.walls

    def neighbors(self, _id):
        x, y = _id
        res = [(x+1, y), (x, y-1), (x-1, y), (x, y+1)]
        # if (x + y) % == 2: res.reverse()
        return filter(self.in_bound, filter(self.passable, res))
    
    def draw_point(self, _id, style):
        

    def draw(self):
        for y in range(self.height):
            for x in range(self.width):
                print(self.draw_point((x, y)), end='')
            print()


def from_id_width(_id, width):
    return (_id % width, _id // width)

if __name__ == '__main__':
    graph = SimpleGraph()
    graph.edges = {
        'A': ['B'],
        'B': ['A', 'C', 'D'],
        'C': ['A'],
        'D': ['E', 'A'],
        'E': ['B']
    }

    grid = SquareGrid(30, 15)
    grid.walls =  [from_id_width(_id, width=30) for _id in [21,22,51,52,81,82,93,94,111,112,123,124,133,134,141,142,153,154,163,164,171,172,173,174,175,183,184,193,194,201,202,203,204,205,213,214,223,224,243,244,253,254,273,274,283,284,303,304,313,314,333,334,343,344,373,374,403,404,433,434]]
    grid.draw()

    

