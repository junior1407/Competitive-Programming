# Dynamic Programming :boom:

---

## Longest Commom Sequence (LCS)

* **Content**
  
  * https://youtu.be/ha_zA_0oofI](https://youtu.be/ha_zA_0oofI)
  - [https://www.youtube.com/watch?v=Qf5R-uYQRPk](https://www.youtube.com/watch?v=Qf5R-uYQRPk)
  
  - [https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/](https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/)



* **Problems:**
  
  + [Compromise](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=472) : Requires retrieval of the optimum solution's path.    

## Coin Change

> 1. https://youtu.be/1mtvm2ubHCY
> 
> 2. https://youtu.be/mA-6bHQ6-wc

* [The Coin Change Problem](https://www.hackerrank.com/challenges/coin-change): Pure

## Pure DP

> 1. [https://www.youtube.com/watch?v=OQ5jsbhAv_M](https://www.youtube.com/watch?v=OQ5jsbhAv_M) (Best video by far)
> 
> 2. [https://www.youtube.com/watch?v=YBSt1jYwVfU&t=1s](https://www.youtube.com/watch?v=YBSt1jYwVfU&t=1s)

* [Superman Celebrates Diwali](https://www.hackerrank.com/challenges/superman-celebrates-diwali/problem) Amazing problem. Requires iterative answer and some way to avoid computing problems that won't be useful.
* [Max Array Sum](https://www.hackerrank.com/challenges/max-array-sum/problem): Classic Problem. Pure.
* [Tournament](https://codeforces.com/contest/1260/problem/E): Really hard to see it as a DP.  Hard to model the data. Really hard question but it is simple once the concept is grasped.

# Backtracking :boom:

---

## Pure

> 1. [https://www.youtube.com/watch?v=GMQtrq-X4Sw](https://www.youtube.com/watch?v=GMQtrq-X4Sw)

* [Count Luck](https://www.hackerrank.com/challenges/count-luck/problem): Pure

# Graph:boom:

---

## Shortest Path (One vertex)

- **Content:**
  
  - Algorithms from fastest to slowest: Dijkstra (Only positive edges), SPFA, BellmanFord
  
  * [Really good paper for all algorithms](http://www.cs.cmu.edu/afs/cs/academic/class/15451-f17/www/lectures/lec13-dp2.pdf)
  
  * Dijkstra
    
    * [Slides](https://docs.google.com/presentation/d/1Xt6LbjTD0U_E3ca-FE3DsQUiH9wSoNcLCj-JAKGAMVs/edit#slide=id.g15c01fb3bb_0_605)
  
  * BellmanFord
    
    * [Slides](https://docs.google.com/presentation/d/1RoV5-y2zCea-tT_WOhffJlX3DEU8_mEL62b1TuyrMTM/edit#slide=id.p)

* **Problems:**
  
  * [Mania de Par](https://www.urionlinejudge.com.br/judge/pt/problems/view/1931): Interesting Shortest Path problem with DP. Keeping separate values for even and odd is helpful.  Can be solved with Dijkstra.
  
  * [Bomba](https://olimpiada.ic.unicamp.br/pratique/p2/2012/f2/bomba/): Djikstra-like problem where there is an extra state that is time.
  
  * [Zak Galou](https://www.urionlinejudge.com.br/judge/pt/problems/view/1409): DP Coin Change + Shortest Path ( Can be solved with Dijkstra).

## Shortest Path (All pairs)

> [Really good paper for all algorithms](http://www.cs.cmu.edu/afs/cs/academic/class/15451-f17/www/lectures/lec13-dp2.pdf)

* [Floyd: City of Blinding Lights](https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem): There are many queries and they can be repeated. Floyd-Warshall is recommended.
* [Roads in Berland](https://codeforces.com/contest/25/problem/C): Problem to add edges and compute new distances without running Floyd-Warshall again.  Possible O(V^2).
* [String Problem](https://codeforces.com/contest/33/problem/B): Floyd-Warshall problem with strings.
* [Arbitrag](https://www.spoj.com/problems/ARBITRAG/): Floydwarshall with different concept. Instead of minimizing, we're trying to maximize and not performing summation, instead multiplication.
* [Greg and Graph](https://codeforces.com/contest/295/problem/B):  Distance to all as edges are removed. 



## MaxFlow MinCost

* **Problems:**
  
  * [Amazing Race](https://www.hackerearth.com/pt-br/practice/algorithms/graphs/minimum-cost-maximum-flow/practice-problems/algorithm/amazing-race-3/): Can be solved by MaxFlowMinCost by connecting all racers to all checkpoints and filtering them on the sink.

# Search:boom:

---

* [Connected Cells in a Grid](https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem): Recursion with Flood Fill.

* [Hackerland Radio Transmitters](https://www.hackerrank.com/challenges/hackerland-radio-transmitters): Greedy Search 

* [Non-Divisible Subset](https://www.hackerrank.com/challenges/non-divisible-subset/problem): Requires math insight about what about what being evenly divisible means.

* [Pairs](https://www.hackerrank.com/challenges/pairs/problem): Search for pairing values according to criteria.  Hashmap is useful. 

* [Red Knight's Shortest Path](https://www.hackerrank.com/challenges/red-knights-shortest-path/problem): BFS problem.

* [New Year Chaos](https://www.hackerrank.com/challenges/new-year-chaos/submissions/code/149588080)

* [Dreamoon and Ranking Collection](https://codeforces.com/contest/1330/problem/A):  Search in array by counting gaps.

# Adhoc:boom:

---

- [Queen's Attack II](https://www.hackerrank.com/challenges/queens-attack-2/problem) : Interesting Problem.

- [Sherlock and Anagrams](https://www.hackerrank.com/challenges/sherlock-and-anagrams/) : Search for anagrams in a string.

- [Array Manipulation](https://www.hackerrank.com/challenges/crush): Cummulative Sum.

- [3D Surface Area](https://www.hackerrank.com/challenges/3d-surface-area/) :  Awesome Insight.

- [Forming a Magic Square](https://www.hackerrank.com/challenges/magic-square-forming) : Generate combinations and compare them.

- [Sherlock and Valid String](https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem): By sorting the frequency array and examining the boundaries, it is possible to get to the answer.

- [Bigger is greater](https://www.hackerrank.com/challenges/bigger-is-greater/problem): Really simple to do by using the std. 

# String:boom:

* [Encryption](https://www.hackerrank.com/challenges/encryption): String Manipulation
* [The time in words](https://www.hackerrank.com/challenges/the-time-in-words/problem): Dictionary of strings.

# Data Structures:boom:

* [Dreamoon Likes Permutations](https://codeforces.com/contest/1330/problem/B): Requires a simple way to check for a valid permutation.  By using a set, it's possible to check if the permutation is correct regardless the order and repeated elements. 
* [Minimum Array](https://codeforces.com/contest/1157/problem/E): Greedy problem. Can be solved easily by using multiset.

# Greedy:boom:

* [Dreamoon Likes Coloring](https://codeforces.com/contest/1330/problem/C): Hard to see it as a greedy problem. Requires cummulative sum.
* [Sushi for Two](https://codeforces.com/contest/1138/problem/A) : Greedy problem that requires creating an array of sizes.
* [Discounts](https://codeforces.com/problemset/problem/1132/B): Simple Greedy
* [Mishka and the Last Exam](https://codeforces.com/contest/1093/problem/C) : Greedy solution comes up by increasing the current minimum value and decreasing the maximum value according to some criteria.
* [Fight with Monsters](https://codeforces.com/problemset/problem/1296/D): Requires criteria to calculate minimum turns. Then, just goggle up all results that fit k.
* [Homecoming](https://codeforces.com/contest/1315/problem/B):  Greedy + DP. Requires a way to skip unnecessary paths.  Iterative is recommended.
* [Frog Jumps](https://codeforces.com/contest/1324/problem/C): Can be done in O(n) by using a trick to change the string, and realizing that going left is not necessary.
* [K-Complete Word](https://codeforces.com/problemset/problem/1332/C): Can be solved by realizing that the word needs to be the concatenation of many small palindromes of size n/k.
* [Little Artem](https://codeforces.com/contest/1333/problem/A) : There is a simple way out to this maze. Same solution for all cases.
* [Kind Atlon](https://codeforces.com/contest/1333/problem/B): If there are +1 and -1 then every number is possible.
* [Organizing Containers of Balls](https://www.hackerrank.com/challenges/organizing-containers-of-balls/problem): By taking notes on the desired number of balls and the number of existing balls of each type a greedy approach becomes possible.  
* [Eugene and an Array](https://codeforces.com/contest/1333/problem/C): Hard to see it as a greedy.  By realizing that a set { ai , ai+1 ...  aj} has a sum 0 if SuffixSum(ai-1) ==  SuffimSum(aj),  the number of sub good arrays is j - i -1.


