Route:
    integer id
    travel_distance
    forward/returning

id is only unique for the same type (forward or returning)

Aircraft:
    two shipping routes (one forward, one returning)
    maximum travel distance

Goal is to optimize the operating travle time of the aircraft as close to max
as possible.


Example 1: 

Input:
Max travel distance 7000
Forward route [1, 2000], [2, 4000], [3, 6000]
returning [1, 2000]
()

Output:
Pair 2,1 (4000 + 2000 = 6000),

Example 2: 

Input:
Max travel distance 10000
Forward route [1, 3000], [2, 5000], [3, 7000], [4, 10000]
returning [1, 2000], [2, 3000], [3, 4000] , [4, 5000]

Output:
Pair 2,4 and 3,2 