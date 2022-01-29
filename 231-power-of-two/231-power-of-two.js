/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
  let count=0;
  if(n<0){
      return 0;
  }
  while(n != 0){
      n=n&n-1;
      count++;
  }
    return count == 1;
};
