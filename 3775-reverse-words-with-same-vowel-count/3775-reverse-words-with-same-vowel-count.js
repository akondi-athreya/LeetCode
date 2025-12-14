/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    let str = s;

    const words = str.split(" ");
    const vowels = new Set(['a','e','i','o','u']);

    const countVowels = (word) => {
        let count = 0;
        for (let ch of word) {
            if (vowels.has(ch)) count++;
        }
        return count;
    };

    const fwc = countVowels(words[0]);

    for (let i = 1 ; i < words.length ; i++) {
        if (countVowels(words[i]) === fwc) {
            words[i] = words[i].split('').reverse().join('');
        }
    }

    return words.join(" ");
};