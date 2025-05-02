/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    var n = nums.length;
    var sum = n*(n+1)/2;

    nums.forEach((num) => {
        sum -= num;
    });

    return sum;
};


var nums = [0,1,2,3,5,6];

console.log(missingNumber(nums));