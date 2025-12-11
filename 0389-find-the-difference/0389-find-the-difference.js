/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    let ans = 0;
    for(let ch of s) ans ^= ch.charCodeAt(0);
    for(let ch of t) ans ^= ch.charCodeAt(0);

    return String.fromCharCode(ans);
};