def BFS(matrix,q,m,n):
    dRow = [ -1, 0, 1, 0]
    dCol = [ 0, 1, 0, -1]

    while q:
        x,y = q.popleft()

        for i in range(4):
            adjx = x +dRow[i]
            adjy = y +dCol[i]
            if (0 <= adjx < m and 0<= adjy < n and matrix[adjx][adjy] > matrix[x][y]+1):
                q.append((adjx,adjy))
                matrix[adjx][adjy] = matrix[x][y]+1
                
    return matrix

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        m = len(mat)
        n = len(mat[0])
        q = deque()
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 0:
                    q.append((i,j))
                else:
                    mat[i][j]= m*n

        return BFS(mat,q,m,n)
