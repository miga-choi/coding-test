class NumberOfSegmentsInAString:
    def countSegments(self, s: str) -> int:
        return len(list(filter(lambda x: x != "", s.split(" "))))


    # Solution
    def solution(self, s: str) -> int:
        return len(s.split())
