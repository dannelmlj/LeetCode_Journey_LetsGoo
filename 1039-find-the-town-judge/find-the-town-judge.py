class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        if n == 1:
            return 1
        trust_giver = {giver for giver, _ in trust} # Sets of [0] --> giver of trust
        trust_receiver_counter = Counter(receiver for _, receiver in trust) # Counter of [1] --> receiver of trust

        for person, trust_count in trust_receiver_counter.items():
            if trust_count == n-1 and person not in trust_giver:
                return person

        return -1