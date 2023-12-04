import itertools
from typing import List
import numpy as np


class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        array = [y for x in mat for y in x]
        if len(array) != r * c:
            return mat

        result: List[List[int]] = []
        count = 0
        for rownum in range(r):
            row = []
            for colnum in range(c):
                row.append(array[count])
                count += 1
            result.append(row)

        return result


    # Best Solution
    def bestSolution1(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        flatten = []
        new_mat = []
        for row in mat:
            for num in row:
                flatten.append(num)

        if r * c != len(flatten):  # when given parameters is NOT possible and legal
            return mat
        else:
            for row_index in range(r):
                new_mat.append(flatten[row_index * c : row_index * c + c])
            return new_mat

    def bestSolution2(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        return (
            mat
            if len(sum(mat, [])) != r * c
            else map(list, zip(*([iter(sum(mat, []))] * c)))
        )

    def bestSolution3(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        flat = sum(mat, [])
        if len(flat) != r * c:
            return mat
        tuples = zip(*([iter(flat)] * c))
        return map(list, tuples)

    # Numpy
    def bestSolution4(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        try:
            return np.reshape(mat, (r, c)).tolist()
        except:
            return mat

    # itertools
    def bestSolution5(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        if r * c != len(mat) * len(mat[0]):
            return mat
        it = itertools.chain(*mat)
        return [list(itertools.islice(it, c)) for _ in xrange(r)]
