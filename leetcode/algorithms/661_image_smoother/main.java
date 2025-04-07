class ImageSmoother {
    public int[][] imageSmoother(int[][] img) {
        int[][] result = new int[img.length][img[0].length];
        for (int i = 0; i < img.length; i++) {
            for (int j = 0; j < img[i].length; j++) {
                int sum = 0;
                int count = 0;
                for (int k = -1; k < 2; k++) {
                    for (int l = -1; l < 2; l++) {
                        int m = i + k, n = j + l;
                        if (m < 0 || m >= img.length || n < 0 || n >= img[i].length) {
                            continue;
                        }
                        sum += img[m][n];
                        count++;
                    }
                }
                result[i][j] = sum / count;
            }
        }
        return result;
    }

    // Solution
    int smoothen(int[][] img, int x, int y) {
        int m = img.length;
        int n = img[0].length;
        int sum = 0;
        int count = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nx = x + i;
                int ny = y + j;
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                sum += img[nx][ny];
                count++;
            }
        }
        return sum / count;

    }

    public int[][] solution(int[][] img) {
        int res[][] = new int[img.length][img[0].length];
        for (int i = 0; i < img.length; i++) {
            for (int j = 0; j < img[0].length; j++) {
                res[i][j] = smoothen(img, i, j);
            }
        }
        return res;
    }
}
