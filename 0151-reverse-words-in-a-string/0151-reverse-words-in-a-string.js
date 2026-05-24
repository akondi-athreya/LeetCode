/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let arr = s.split(' ');
    arr.reverse();
    let res = '';
    arr.forEach((item) => {
        if (item.length !== 0) {
            res += item;
            res += ' ';
        }
    })
    return res.substr(0, res.length-1);
};