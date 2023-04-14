from datetime import date, datetime
from dateutil.relativedelta import relativedelta


def solution(today, terms, privacies):
    answer = []
    termMap = {}
    todayArray = today.split('.')
    todayDate = date(int(todayArray[0]), int(
        todayArray[1]), int(todayArray[2]))
    for term in terms:
        termArray = term.split(' ')
        termMap[termArray[0]] = termArray[1]

    for i in range(len(privacies)):
        privacyArray = privacies[i].split(' ')
        dateArray = privacyArray[0].split('.')
        date_after_term = date(
            int(dateArray[0]), int(dateArray[1]), int(dateArray[2])) + relativedelta(months=int(termMap[privacyArray[1]]))
        if date_after_term <= todayDate:
            answer.append(i+1)

    return answer


# best solution
def to_days(date):
    year, month, day = map(int, date.split("."))
    return year * 28 * 12 + month * 28 + day


def solution(today, terms, privacies):
    months = {v[0]: int(v[2:]) * 28 for v in terms}
    today = to_days(today)
    expire = [
        i + 1 for i, privacy in enumerate(privacies)
        if to_days(privacy[:-2]) + months[privacy[-1]] <= today
    ]
    return expire
