/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    for(let i = 0;i < arr.length;i++){
        let n = arr[i];
        let x = fn(n,i);
        arr[i] = x;
    }
    return arr;
};