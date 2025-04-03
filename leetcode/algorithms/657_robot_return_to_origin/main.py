class RobotReturnToOrigin:
    def judgeCircle(self, moves: str) -> bool:
        landscape: int = 0
        portrait: int = 0

        for c in moves:
            if c == 'U':
                portrait += 1
            elif c == 'D':
                portrait -= 1
            elif c == 'R':
                landscape += 1
            elif c == 'L':
                landscape -= 1

        return landscape == 0 and portrait == 0

    # Solution
    def solution(self, moves: str) -> bool:
        return moves.count("U") == moves.count("D") and moves.count("L") == moves.count("R")
