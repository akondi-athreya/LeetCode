/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let i = 0;
    let n = arr.length;
    let ans = [];
    let res = [];
    while (i < n) {
        res.push(arr[i]);
        if(res.length == size) {
            ans.push(res);
            res = [];
        }
        i++;
    }
    if(res.length > 0) ans.push(res);
    return ans;
};
