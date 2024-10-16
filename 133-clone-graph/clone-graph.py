"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        nodeDic={}
        queue = deque()
        queue.append(node)
        root = Node(node.val)
        nodeDic[node.val] = root
        # While there is something in queue, run the logic
        while queue:
            curr = queue.popleft()
            for neigh in curr.neighbors: 
                if neigh.val not in nodeDic: # if neighbour's value is not yet accessed, we need to write it's neighbor's value too 
                    nodeDic[neigh.val] = Node(neigh.val)
                    queue.append(neigh)
                nodeDic[curr.val].neighbors.append(nodeDic[neigh.val]) # Real logic, just append the neighbor's value to the properties neighbor list.
        return root