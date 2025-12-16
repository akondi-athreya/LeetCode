/**
 * @param {number[]} order
 * @param {number[]} friends
 * @return {number[]}
 */
var recoverOrder = function(order, friends) {
    let ans = [];
    for(let num of order) {
        if (friends.includes(num)) ans.push(num);
    }
    return ans;
};