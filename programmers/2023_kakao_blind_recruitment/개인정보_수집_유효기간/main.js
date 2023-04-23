function solution(today, terms, privacies) {
  var answer = [];
  const todayDate = new Date(today);
  const termPair = new Map();
  Promise.all(
    terms.map((term) => {
      const termArray = term.split(' ');
      termPair.set(termArray[0], Number(termArray[1]));
    })
  );
  Promise.all(
    privacies.map((privacy, index) => {
      const privacyArray = privacy.split(' ');
      const date = new Date(privacyArray[0]);
      date.setMonth(date.getMonth() + termPair.get(privacyArray[1]));
      if (date <= todayDate) {
        answer.push(index + 1);
      }
    })
  );
  return answer;
}

// best solution
function solution(today, terms, privacies) {
  var answer = [];
  var [year, month, date] = today.split('.').map(Number);
  var todates = year * 12 * 28 + month * 28 + date;
  var t = {};
  terms.forEach((e) => {
    let [a, b] = e.split(' ');
    t[a] = Number(b);
  });
  privacies.forEach((e, i) => {
    var [day, term] = e.split(' ');
    day = day.split('.').map(Number);
    var dates = day[0] * 12 * 28 + day[1] * 28 + day[2] + t[term] * 28;
    if (dates <= todates) answer.push(i + 1);
  });
  return answer;
}
