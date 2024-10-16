class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        connection = Counter(a for a,_ in edges) + Counter(b for _,b in edges)
        for a,b in connection.items():
            if b == len(edges):
                return a
        return 0