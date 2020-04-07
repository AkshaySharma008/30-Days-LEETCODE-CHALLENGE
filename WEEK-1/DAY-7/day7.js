function sortAsc(a, b) {
  return a - b;
}

/**
 * @param {number[]} arr
 * @return {number}
 */
var countElements = function(arr) {
  let obj = {},
    count = 0;

  arr.forEach(item => {
    if (!obj[item]) {
      obj[item] = 1;
    } else {
      obj[item]++;
    }
  });

  arr = arr.sort(sortAsc);

  for (let i = 0; i < arr.length - 1; i++) {
    if (arr[i + 1] - arr[i] == 1) {
      count += obj[arr[i]];
    }
  }

  return count;
};
