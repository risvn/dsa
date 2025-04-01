def find_lps(pattern):
    pattern_len=len(pattern)

    lps=[0]*pattern_len
    i=1
    length=0
    while i<pattern_len:
        if pattern[i]==pattern[length]:
            length+=1
            lps[i]=length
            i+=1
        else:
            if length!=0:
                length=lps[length-1]
            else:
                lps[i]=0
                i+=1
    return lps

def find_kmp(text, pattern):
    text_len, pattern_len = len(text), len(pattern)
    lps = find_lps(pattern)  # Get the LPS array for the pattern
    i = 0  # pointer for text
    j = 0  # pointer for pattern

    while i < text_len:
        if text[i] == pattern[j]:  # Characters match
            i += 1
            j += 1
        if j == pattern_len:  # Pattern found
            return i - j  # Return the index of the first match
            j = lps[j - 1]  # Use LPS to avoid unnecessary comparisons
        elif text[i] != pattern[j]:  # Mismatch occurs
            if j != 0:
                j = lps[j - 1]  # Use the LPS array to shift the pattern
            else:
                i += 1  # No shift in pattern, just move the text pointer forward

    return -1  # If no match is found

text = "ABABDABACDABABCABAB"
pattern = "ABABCABAB"
result = find_kmp(text, pattern)
print(f"Pattern found at index: {result}")

