# Ryo-Currency-Test

0a edge cases and code explanation:

- check if ofstream object is true. If !outFile is true, output error message
- use 'long long' to ensure values of 2^30-1 are safely store and calculated
- not edge case** but I used mt19937 instead of rand for better distribution and faster number generation
- used \n to avoid flushing when printing 1000000 numbers as lots of memory can be taken up
- although for loop ensure a million numbers have generated; should have edge case to handle using counter to increment count of the numbers as a new number is added. Each number should also be compared to limit of 2^30-1 ensuring it is < 2^30-1

0b edge cases and code explanation:

- check if ofstream object is true. If !outFile is true, output error message
- a and b of range should be verified to be within their allowable values
     - a is less than 2^29-1
     - should have check to guarantee b is greater than a and and is in between (a+128 and a+1024) for every range
- although for loop ensure a 10000 ranges have been generated; should have edge case to handle using counter to increment count of the ranges as a new range is added.

Q1 and 2 edge cases and code explanation (I could not finish debugging the code so I will just explain my though process on how I went about it).

--- add_ranges(r)
- goal is to swap is inverted.
- create an empty result list that for each range can copy to result before, copy to result after and stretch bounds and add count.
- push r into result
- sort result by start
- replace store with result

--- contains(t)
- loop each range in store
- if start <= t <= end then return true
- if loop ends return false

--- get_ranges()
- if store is empty then return empty
- make current = first range
- for each remaining range calculate the gap and combined count, if both fit then exted current, if it doesn't fit then push current to = this range
- push current
- return result


- edge cases
- add_range(r): if it is inverted swap start and before anything, if the count is zero don't need to handle it specifically

- contain(t): if empty then loop won't run and returns false, and for the boundary use <= on boh side to limit the range and handle that edge case

--- get_ranges()
- if empty return early before touching anything, if there is single range skip loop and push and return,  if max_vc - 0 no merge will happen, if max_pd is 0 gap will be exactly 0


