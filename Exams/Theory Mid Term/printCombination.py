# Recursive function to print all combinations of numbers from `i` to `n` having sum `n`. The `index` denotes the next free slot in the output list `out`
def printCombinations(i, n, out, index):
                                 # if the sum becomes `n`, print the combination
    if n == 0:
        print(out[:index])
    
    for j in range(i, n + 1):             # start from the previous element in the combination till `n`
        out[index] = j                    # place current element at the current index
        printCombinations(j, n - j, out, index + 1)     # recur with a reduced sum
 
 
if __name__ == '__main__':
 
    n = 5
    out = [None] * n
    
    printCombinations(1, n, out, 0)       # print all combinations of numbers from 1 to `n` having sum `n`