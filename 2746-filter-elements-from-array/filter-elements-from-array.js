/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const filteredArray = [];
    for(let i = 0;i<arr.length;i++){
        const bool = fn(arr[i],i);
        if(bool){
            filteredArray.push(arr[i]);
        }
    }
    return filteredArray;
};