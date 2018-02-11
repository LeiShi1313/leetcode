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
                reached.add(i, j)
                queue += (i+1, j), (i-1, j), (i, j+1), (i, j-1)
        if not all((i, j) in reached for _,i,j in trees):
            return -1
        
        def distance(ci, cj, ti, tj):
            cur, soon = [(ci, cj)], []
            expanded = set()
            manhattan = abs(ci - ti) + abs(cj - tj)
            detours = 0
            while True:
                if not cur:
                    cur, soon = soon, []
                    detours += 1
                i, j = cur.pop()
                if (i, j) == (ti, tj):
                    return manhattan + 2 * detours
                if (i, j) not in expanded:
                    expanded.add((i, j))
                    for i, j, closer in (i+1, j, i<ti), (i-1, j, i>ti), (i, j+1, j<tj), (i, j-1, j>tj):
                        if forest[i][j]:
                            (cur if closer else soon).append((i, j))
            trees.sort()
            return (sum(distance(ci, cj, ti, tj) for (_, ci, cj), (_, ti, tj) in zip([(0, 0, 0)] + trees, trees)))

if __name__ == '__main__':
    print(Solution().maxSumOfThreeSubarrays([1,2,1,2,6,7,5,1], 2))
    print(Solution().maxSumOfThreeSubarrays([7,13,20,19,19,2,10,1,1,19], 3))
    print(Solution().maxSumOfThreeSubarrays([12,15,4,6,8,3,12,11,2,10,14,6,7,18,11,16,15,17,14,10,5,17,3,3,8,4,14,13,10,11,17,8,19,6,12,8,16,3,12,12,19,9,10,20,3,2,10,20,4,5,5,13,16,19,2,15,11,1,8,8,2,5,7,4,14,3,14,4,19,5,19,3,14,13,7,16,1,16,4,8,17,11,20,9,5,20,2,7,12,8,15,15,11,1,9,5,1,4,6,20], 15))