int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    int total = 0;
    for (int i = 1; i < timeSeriesSize; i++) {
        if (timeSeries[i] > timeSeries[i - 1] + duration) {
            total += duration;
        } else {
            total += timeSeries[i] - timeSeries[i - 1];
        }
    }
    return total + duration;
}

// Best Solution
int bestSolution(int* timeSeries, int timeSeriesSize, int duration) {
    int res = 0;
    for (int i = 1; i < timeSeriesSize; i++) {
        if (timeSeries[i] - timeSeries[i - 1] < duration) {
            res += timeSeries[i] - timeSeries[i - 1];
        } else {
            res += duration;
        }
    }
    return res + duration;
}
