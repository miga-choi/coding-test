from typing import List


class FloodFill:
    def fill(self, image: List[List[int]], sr: int, sc: int, color: int, newColor: int) -> None:
        if sr < 0 or sc < 0 or sr >= len(image) or sc >= len(image[0]):
            return

        if image[sr][sc] != color:
            return

        image[sr][sc] = newColor

        self.fill(image, sr + 1, sc, color, newColor)
        self.fill(image, sr - 1, sc, color, newColor)
        self.fill(image, sr, sc + 1, color, newColor)
        self.fill(image, sr, sc - 1, color, newColor)

    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if image[sr][sc] != color:
            self.fill(image, sr, sc, image[sr][sc], color)

        return image

    # Solution
    def solution(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        R, C = len(image), len(image[0])
        oldColor = image[sr][sc]

        if oldColor == color:
            return image

        def dfs(r, c):
            if image[r][c] == oldColor:
                image[r][c] = color

                if r >= 1:
                    dfs(r - 1, c)
                if r + 1 < R:
                    dfs(r + 1, c)
                if c >= 1:
                    dfs(r, c - 1)
                if c + 1 < C:
                    dfs(r, c + 1)

        dfs(sr, sc)

        return image
