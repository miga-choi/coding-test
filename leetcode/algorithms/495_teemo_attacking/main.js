/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
var findPoisonedDuration = function (timeSeries, duration) {
  let result = 0;

  for (let i = 1; i < timeSeries.length; i++) {
    if (timeSeries[i] - timeSeries[i - 1] >= duration) {
      result += duration;
    } else {
      result += timeSeries[i] - timeSeries[i - 1];
    }
  }

  result += duration;

  return result;
};


// Solution
var solution = function (timeSeries, duration) {
  let ans = 0;

  for (let i = 0, len = timeSeries.length; i < len; i++) {
    if (i === len - 1) {
      ans += duration;
      continue;
    }

    let curItem = timeSeries[i],
      nextItem = timeSeries[i + 1];

    if (curItem + duration <= nextItem) {
      ans += duration;
    } else {
      ans += nextItem - curItem;
    }
  }

  return ans;
};
