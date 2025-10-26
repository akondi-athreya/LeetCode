/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let cnt = init;
    let temp = init;
    
    function increment() {
        cnt++;
        return cnt;
    }

    function reset() {
        cnt = temp;
        return cnt;
    }

    function decrement() {
        cnt--;
        return cnt;
    }

    return {
        increment, reset, decrement
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */