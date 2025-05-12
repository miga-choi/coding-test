/**
 * @param {number[]} score
 * @return {string[]}
 */
var findRelativeRanks = function (score) {
  const sortedScore = score.slice().sort((p, n) => n - p);
  const result = [];

  for (const v of score) {
    if (sortedScore.indexOf(v) === 0) {
      result.push("Gold Medal");
    } else if (sortedScore.indexOf(v) === 1) {
      result.push("Silver Medal");
    } else if (sortedScore.indexOf(v) === 2) {
      result.push("Bronze Medal");
    } else {
      result.push((sortedScore.indexOf(v) + 1).toString());
    }
  }

  return result;
};


// Solution
var solution = function (score) {
  const ranks = new MaxPriorityQueue();

  for (let i = 0; i < score.length; i++) {
    ranks.enqueue(i, score[i]);
  }

  for (let i = 0; i < score.length; i++) {
    const item = ranks.dequeue();
    let rank;

    switch (i) {
      case 0:
        rank = "Gold Medal";
        break;
      case 1:
        rank = "Silver Medal";
        break;
      case 2:
        rank = "Bronze Medal";
        break;
      default:
        rank = (i + 1).toString();
    }

    score[item.element] = rank;
  }

  return score;
};
