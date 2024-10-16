class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        score_sorted = copy.deepcopy(score)
        score_sorted.sort(reverse=True)
        output= []
        for i in range(len(score)):
            position = score_sorted.index(score[i])
            position += 1
            if position is 1:
                position = "Gold Medal"
            elif position is 2:
                position = "Silver Medal"
            elif position is 3:
                position = "Bronze Medal"
            output.append(str(position))
        
        return output