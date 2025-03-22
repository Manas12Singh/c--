/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function (s) {
    regex = /[+-]?[0-9]*(.[0-9]*(e[+-]?[0-9]*)?)?$/
    return regex.test(s);
};