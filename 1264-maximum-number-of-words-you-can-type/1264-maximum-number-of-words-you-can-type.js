/**
 * @param {string} text
 * @param {string} brokenLetters
 * @return {number}
 */
var canBeTypedWords = function(text, brokenLetters) {
    const x = brokenLetters.split("");
    const words = text.split(" ");
    var ans = 0;
    words.map(word => {
        var flag = true;
        x.map(item => {
            if(word.includes(item)) {
                flag = false;
            }
        });
        if(flag) ans++;
    });
    return ans;
};