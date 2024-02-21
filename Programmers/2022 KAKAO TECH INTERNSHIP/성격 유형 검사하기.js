function solution(survey, choices) {
  const score = {
    R: 0,
    T: 0,
    C: 0,
    F: 0,
    J: 0,
    M: 0,
    A: 0,
    N: 0,
  };

  choices.forEach((choice, idx) => {
    score[survey[idx][0]] += Math.max(4 - choice, 0);
    score[survey[idx][1]] += Math.max(choice - 4, 0);
  });

  let answer = "";
  answer += score["R"] >= score["T"] ? "R" : "T";
  answer += score["C"] >= score["F"] ? "C" : "F";
  answer += score["J"] >= score["M"] ? "J" : "M";
  answer += score["A"] >= score["N"] ? "A" : "N";

  return answer;
}
