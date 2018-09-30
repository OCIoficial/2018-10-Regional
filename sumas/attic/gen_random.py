import sys
import random

LIMIT = 1e9
MAX_DIGITS = 9

def compute_num(digits, i, j):
    x = 0
    for k in range(i,j+1):
        x = x * 10 + digits[k]
    return x

def count_digits(x):
    c = 1
    pt = 10
    while pt <= x:
        c += 1
        pt *= 10
    return c

def generate_num(nd):
    x = 0
    for _ in range(nd):
        x = x * 10 + random.randint(1, 9)
    return x

def has_zeroes(x):
    if x == 0:
        return True
    while x > 0:
        if x % 10 == 0:
            return True
        x //= 10
    return False

def search(target_sum, k_addends, nd_left, testcase):
    assert nd_left > 0
    assert target_sum > 0

    k_addends += 1
    
    nd_target_sum = count_digits(target_sum)
    nd_k_addends = count_digits(k_addends)
    
    if nd_target_sum + nd_k_addends > nd_left:
        return False

    for _ in range(20):
        nd_num = random.randint(1, nd_target_sum)
        num = generate_num(nd_num)
        if (num < target_sum and search(
                target_sum - num, k_addends, nd_left - nd_num, testcase)):
            testcase.append(num)
            return True
    
    if k_addends < 2 or has_zeroes(target_sum):
        return False
    
    testcase.append(k_addends)
    testcase.append(target_sum)
    return True

# candidate_split = [] # DEBUGGING

def count_valid_solutions(digits, k, i, acc, nd, n):
    if k == 0:
        if nd != n - i:
            return 0
        if compute_num(digits, i, n-1) != acc:
            return 0
        # candidate_split.append(acc) # DEBUGGING
        # print('  ***', candidate_split) # DEBUGGING
        # candidate_split.pop() # DEBUGGING
        return 1
    
    if n - i - k < nd:
        return 0

    ans = 0
    maxj = min(n-k-nd, i+8)
    for j in range(i, maxj+1):
        num = compute_num(digits,i,j)
        tmp = acc + num
        if tmp >= LIMIT:
            break
        # candidate_split.append(num) # DEBUGGING
        ans += count_valid_solutions(digits, k-1, j+1, tmp, count_digits(tmp), n)
        # candidate_split.pop() # DEBUGGING
        if ans >= 2:
            break

    return ans

def validate_testcase(testcase, maxlen):
    n = len(testcase)
    assert n == testcase[0] + 2
    assert sum(testcase[i] for i in range(1, n-1)) == testcase[n-1]
    assert all(x < LIMIT for x in testcase)
    digits = [int(c) for c in ''.join(map(str,testcase))]
    assert len(digits) <= maxlen
    count = 0
    for i in range(2):
        k = compute_num(digits, 0, i)
        # candidate_split.append(k) # DEBUGGING
        count += count_valid_solutions(digits,k,i+1,0,1,len(digits))
        # candidate_split.pop() # DEBUGGING
        if count >= 2:
            break
    assert count > 0
    return count == 1

def main():
    random.seed(sys.argv[1])
    maxlen = int(sys.argv[2])
    assert maxlen >=4
    # print('maxlen = ', maxlen) # DEBUGGING

    testcase = []

    max_nd = min((maxlen - 1)//3 + 1, MAX_DIGITS)
    min_nd = max(max_nd - 8, 1)
    # tries = 0 # DEBUGGING
    while True:
        # tries += 1 # DEBUGGING
        nd = random.randint(min_nd, max_nd)
        totalsum = generate_num(nd)
        if search(totalsum, 0, maxlen - nd, testcase):
            testcase.append(totalsum)
            if validate_testcase(testcase, maxlen):
                testcase_input = ''.join(map(str,testcase))
                print(testcase_input)
                # DEBUGGING
                # testcase_output = ' '.join(map(str,testcase))
                # print('final tries: ', tries)
                # print('nd = ', nd)
                # print('totalsum = ', totalsum)
                # print('testcase = ', testcase)
                # print('input: ', testcase_input)
                # print('output: ', testcase_output)
                break
        testcase.clear()
        # DEBUGGING
        # if tries % 10 == 0:
        #     print(tries, 'failed tries')

main()