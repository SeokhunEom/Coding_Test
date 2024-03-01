function solution(id_list, report, k) {
  const obj = id_list.map((id) => {
    return {
      id,
      reportedList: new Set(),
      reportList: new Set(),
    };
  });

  report.forEach((item) => {
    const [reportUser, reportedUser] = item.split(" ");
    const reportUserObj = obj.find((user) => user.id === reportUser);
    const reportedUserObj = obj.find((user) => user.id === reportedUser);
    reportUserObj.reportList.add(reportedUser);
    reportedUserObj.reportedList.add(reportUser);
  });

  const blockedUserList = obj.reduce((acc, cur) => {
    if (cur.reportedList.size >= k) acc.push(cur.id);
    return acc;
  }, []);

  const answer = obj.map((user) => {
    let count = 0;
    blockedUserList.forEach((blockedUser) => {
      if (user.reportList.has(blockedUser)) count++;
    });
    return count;
  });

  return answer;
}
