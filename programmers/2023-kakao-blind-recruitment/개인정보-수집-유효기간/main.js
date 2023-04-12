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
