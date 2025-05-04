def length_of_longest_substring(s: str) -> int:
    window = {}
    start = temp_len = max_len = 0

    for i in range(len(s)):
        if (type(window.get(s[i], False)) != bool):
            for j in range(start, window[s[i]]): window.pop(s[j], None)
            
            temp_len += start - window[s[i]]
            start = window[s[i]] + 1
        else:
            temp_len += 1
            max_len = max(max_len, temp_len)
        
        window[s[i]] = i
    
    return max_len


if __name__ == "__main__":
    s = "hello world!"

    print(length_of_longest_substring(s))