/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function (n) {
    var i = n;
    return function () {
        return i++;

    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */