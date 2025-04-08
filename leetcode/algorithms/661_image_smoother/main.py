from typing import List


class ImageSmoother:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        xLen: int = len(img)
        yLen: int = len(img[0])
        result: List[List[int]] = [[0] * yLen for _ in range(xLen)]

        for i in range(0, xLen):
            for j in range(0, yLen):
                sum: int = 0
                count: int = 0
                for k in range(-1, 2):
                    x: int = i + k
                    for l in range(-1, 2):
                        y: int = j + l
                        if x < 0 or x >= xLen or y < 0 or y >= yLen:
                            continue
                        sum += img[x][y]
                        count += 1
                result[i][j] = sum // count

        return result

    # Solution
    def smoothen(self, img: List[List[int]], x: int, y: int) -> int:
        m, n = len(img), len(img[0])
        _sum, count = 0, 0

        for i in range(-1, 2):
            for j in range(-1, 2):
                nx, ny = x + i, y + j
                if 0 <= nx < m and 0 <= ny < n:
                    _sum += img[nx][ny]
                    count += 1

        return _sum // count

    def solution(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])
        res = [[0] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                res[i][j] = self.smoothen(img, i, j)

        return res
