function solution(n, k) {
  var answer = 0;
  let numStr = "";

  while (n != 0) {
    numStr = (n % k) + numStr;
    n = parseInt(n / k);
  }

  const numArr = numStr
    .split("0")
    .filter((str) => str)
    .map((str) => parseInt(str));
  numArr.forEach((num) => (answer += isPrime(num)));

  return answer;
}

function isPrime(num) {
  if (num === 0 || num === 1) return false;
  for (let i = 2; i <= Math.sqrt(num); i++) {
    if (num % i == 0) return false;
  }
  return true;
}
