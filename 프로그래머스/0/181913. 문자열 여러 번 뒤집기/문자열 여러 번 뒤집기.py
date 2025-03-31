def solution(my_string, queries):
    my_string = list(my_string)
    for i, j in queries:
        index = i
        while i <= (index+j)//2:
            my_string[i], my_string[j-i+index] =\
            my_string[j-i+index], my_string[i]
            i += 1
    return ''.join(my_string)