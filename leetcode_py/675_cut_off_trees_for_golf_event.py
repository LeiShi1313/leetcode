from collections import deque
class Solution:
    def cutOffTree(self, forest):
        """
        :type forest: List[List[int]]
        :rtype: int
        """
        if not forest or not forest[0]:
            return -1

        forest.append([0] * len(forest[0]))
        for row in forest:
            row.append(0)

        trees = [(h, i, j) 
                 for i, row in enumerate(forest)
                     for j, h in enumerate(row)
                         if h > 1]
        
        queue = [(0, 0)]
        reached = set()
        for i, j in queue:
            if (i, j) not in reached and forest[i][j]:
                reached.add((i, j))
                queue += (i+1, j), (i-1, j), (i, j+1), (i, j-1)
        if not all((i, j) in reached for _, i, j in trees):
            return -1

        def distance(ci, cj, ti, tj):
            cur, soon = [(ci, cj)], []
            visited = set()
            manhattan = abs(ci-ti) + abs(cj-tj)
            detours = 0

            while True:
                if not cur:
                    cur, soon = soon, []
                    detours += 1
                i, j = cur.pop()
                visited.add((i, j))
                if i == ti and j == tj:
                    return manhattan + 2 * detours
                for _i, _j, closer in (i+1, j, i<ti), (i-1, j, i>ti), (i, j+1, j<tj), (i, j-1, j>tj):
                    if (_i, _j) not in visited and forest[_i][_j]:
                        (cur if closer else soon).append((_i, _j))

        trees.sort()
        return sum(distance(ci, cj, ti, tj) for (_, ci, cj), (_, ti, tj) in zip([(0, 0, 0)]+trees, trees))


if __name__ == '__main__':
    print(Solution().cutOffTree([[1,2,3],[0,0,4],[7,6,5]]))
    print(Solution().cutOffTree([[2,4,6],[0,0,8],[3,5,7]]))
    print(Solution().cutOffTree([[0,0,0,3528,2256,9394,3153],[8740,1758,6319,3400,4502,7475,6812],[0,0,3079,6312,0,0,0],[6828,0,0,0,0,0,8145],[6964,4631,0,0,0,4811,0],[0,0,0,0,9734,4696,4246],[3413,8887,0,4766,0,0,0],[7739,0,0,2920,0,5321,2250],[3032,0,3015,0,3269,8582,0]]))