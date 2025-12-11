/**
 * @param {string} input
 * @return {number}
 */
var lengthLongestPath = function(input) {
    let lines = input.split("\n");
    let ans = 0;
    let hmap = {0: 0};
    for(let word of lines) {
        let name = word.replace(/\t/g, "");
        let height = word.length - name.length;

        if (name.includes('.')) {
            ans = Math.max(ans, hmap[height] + name.length);
        }
        else {
            hmap[height + 1] = hmap[height]+name.length+1;
        }
    }
    return ans;
};