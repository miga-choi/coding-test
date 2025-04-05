#include <vector>
using namespace std;

class ImageSmoother {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> result(img.size(), vector<int>(img[0].size(), 0));
        for (int i = 0; i < img.size(); i++) {
            for (int j = 0; j < img[i].size(); j++) {
                int sum = 0;
                int count = 0;
                if (i == 0) {
                    if (j == 0) {
                        sum += img[i][j];
                        count++;
                        if (i + 1 < img.size()) {
                            sum += img[i + 1][j];
                            count++;
                        }
                        if (j + 1 < img[i].size()) {
                            sum += img[i][j + 1];
                            count++;
                        }
                        if (i + 1 < img.size() && j + 1 < img[i].size()) {
                            sum += img[i + 1][j + 1];
                            count++;
                        }
                    } else if (j == img[i].size() - 1) {
                        sum += img[i][j - 1] + img[i][j];
                        count += 2;
                        if (i + 1 < img.size()) {
                            sum += img[i + 1][j - 1] + img[i + 1][j];
                            count += 2;
                        }
                    } else {
                        sum += img[i][j - 1] + img[i][j] + img[i][j + 1];
                        count += 3;
                        if (i + 1 < img.size()) {
                            sum += img[i + 1][j - 1] + img[i + 1][j] + img[i + 1][j + 1];
                            count += 3;
                        }
                    }
                } else if (i == img.size() - 1) {
                    if (j == 0) {
                        sum += img[i - 1][j] + img[i][j];
                        count += 2;
                        if (j + 1 < img[i].size()) {
                            sum += img[i - 1][j + 1] + img[i][j + 1];
                            count += 2;
                        }
                    } else if (j == img[i].size() - 1) {
                        sum += img[i - 1][j - 1] + img[i - 1][j] + img[i][j - 1] + img[i][j];
                        count += 4;
                    } else {
                        sum += img[i - 1][j - 1] + img[i - 1][j] + img[i - 1][j + 1] + img[i][j - 1] + img[i][j] + img[i][j + 1];
                        count += 6;
                    }
                } else {
                    if (j == 0) {
                        sum += img[i - 1][j] + img[i][j] + img[i + 1][j];
                        count += 3;
                        if (j + 1 < img[i].size()) {
                            sum += img[i - 1][j + 1] + img[i][j + 1] + img[i + 1][j + 1];
                            count += 3;
                        }
                    } else if (j == img[i].size() - 1) {
                        sum += img[i - 1][j - 1] + img[i - 1][j] + img[i][j - 1] + img[i][j] + img[i + 1][j - 1] + img[i + 1][j];
                        count += 6;
                    } else {
                        sum += img[i - 1][j - 1] + img[i - 1][j] + img[i - 1][j + 1] + img[i][j - 1] + img[i][j] + img[i][j + 1] + img[i + 1][j - 1] + img[i + 1][j] + img[i + 1][j + 1];
                        count += 9;
                    }
                }
                result[i][j] = sum / count;
            }
        }
        return result;
    }

    // Solution
    vector<vector<int>> solution(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        if (m == 0 || n == 0) {
            return {{}};
        }
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = img[i][j], cnt = 1;
                for (int k = 0; k < dirs.size(); k++) {
                    int x = i + dirs[k][0], y = j + dirs[k][1];
                    if (x < 0 || x > m - 1 || y < 0 || y > n - 1) {
                        continue;
                    }
                    sum += (img[x][y] & 0xFF);
                    cnt++;
                }
                img[i][j] |= ((sum / cnt) << 8);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                img[i][j] >>= 8;
            }
        }
        return img;
    }
};
