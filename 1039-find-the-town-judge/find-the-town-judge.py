class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        arr_given = [False] * n
        arr_received = [0] * n

        for i in range(len(trust)):
            arr_given[trust[i][0]-1] = True
            arr_received[trust[i][1]-1] += 1
            
        for i in range(len(arr_received)):
            if arr_received[i] == n-1 and arr_given[i] == False:
                return i+1
     
        return -1