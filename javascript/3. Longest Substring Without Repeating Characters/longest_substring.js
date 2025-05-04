/**
 * @param {string} s
 * @return {number}
 */
var length_of_longest_substring = function(s) {
    var window = new Map();
    var start = 0;
    var temp_len = 0;
    var max_len = 0;

    for(var i = 0; i < s.length; i++) {
        if(window.has(s[i])) {
            for(var j = start; j<window.get(s[i]); j++) window.delete(s[j]);

            temp_len += start - window.get(s[i]);
            start = window.get(s[i]) + 1;
        } else {
            temp_len += 1;
            max_len = Math.max(max_len, temp_len);
        }
        
        window.set(s[i], i);
    }

    return max_len;
}

var s = "hello world!";
console.log(length_of_longest_substring(s));