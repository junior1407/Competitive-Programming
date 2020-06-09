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

- **Content:**
  
  - [https://youtu.be/1mtvm2ubHCY](https://youtu.be/1mtvm2ubHCY)
  
  - [https://youtu.be/mA-6bHQ6-wc](https://youtu.be/mA-6bHQ6-wc)

- **Problems:**
  
  - [The Coin Change Problem](https://www.hackerrank.com/challenges/coin-change): Pure

## Pure DP

- **Content:**
  
  - [https://www.youtube.com/watch?v=OQ5jsbhAv_M](https://www.youtube.com/watch?v=OQ5jsbhAv_M) (Best video by far)
  
  - [https://www.youtube.com/watch?v=YBSt1jYwVfU&t=1s](https://www.youtube.com/watch?v=YBSt1jYwVfU&t=1s)
  
  - 

- **Problems:** 
  
  - [Superman Celebrates Diwali](https://www.hackerrank.com/challenges/superman-celebrates-diwali/problem) Amazing problem. Requires iterative answer and some way to avoid computing problems that won't be useful.
  
  - [Max Array Sum](https://www.hackerrank.com/challenges/max-array-sum/problem): Classic Problem. Pure.
  
  - [Tournament](https://codeforces.com/contest/1260/problem/E): Really hard to see it as a DP.  Hard to model the data. Really hard question but it is simple once the concept is grasped.
  
  - [Nastya and Scorebord](https://codeforces.com/contest/1341/problem/D): DP problem. Requires greedy retrieval.
  
  - [SuperSale](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1071): Simple Knapsack.
  
  - [Corte de Hastes](https://www.thehuxley.com/problem/874): Classic DP Problem.
  
  - [Subsequence Hate](https://codeforces.com/contest/1363/problem/B): DP problem of subsequence.
  
  - [Phoenix and Berries](https://codeforces.com/contest/1348/problem/E): Great DP Problem. Requires user to calculate how many will be left, instead of the given question. 

# Backtracking :boom:

---

## Pure

- **Content:**
  
  - [https://www.youtube.com/watch?v=GMQtrq-X4Sw](https://www.youtube.com/watch?v=GMQtrq-X4Sw)

- **Problems:**
  
  - [Count Luck](https://www.hackerrank.com/challenges/count-luck/problem): Pure

# 

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
  
  * [Jack goes to Rapture](https://www.hackerrank.com/challenges/jack-goes-to-rapture/problem): Minimum distance with different parameter for distance. 

## Shortest Path (All pairs)

* Content:
  
  * Floyd-Warshall
    
    * [https://www.youtube.com/watch?v=4OQeCuLYj-4&t=9s](https://www.youtube.com/watch?v=4OQeCuLYj-4&t=9s) 

* **Problems:**
  
  * [Floyd: City of Blinding Lights](https://www.hackerrank.com/challenges/floyd-city-of-blinding-lights/problem): There are many queries and they can be repeated. Floyd-Warshall is recommended.
  
  * [Roads in Berland](https://codeforces.com/contest/25/problem/C): Problem to add edges and compute new distances without running Floyd-Warshall again.  Possible O(V^2).
  
  * [String Problem](https://codeforces.com/contest/33/problem/B): Floyd-Warshall problem with strings.
  
  * [Arbitrag](https://www.spoj.com/problems/ARBITRAG/): Floydwarshall with different concept. Instead of minimizing, we're trying to maximize and not performing summation, instead multiplication.
  
  * [Greg and Graph](https://codeforces.com/contest/295/problem/B):  Distance to all as edges are removed. 

## MaxFlow

- Content:
  
  - a

- **Problems:**
  
  - [The Dog Task](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=611): Maxflow to choose maximum number of matchings. Retrieval of paths can be done by looking at the residual graph.

## MaxFlow MinCost

- **Content:**
  
  - I haven't found any good content.
* **Problems:**
  
  * [Amazing Race](https://www.hackerearth.com/pt-br/practice/algorithms/graphs/minimum-cost-maximum-flow/practice-problems/algorithm/amazing-race-3/): Can be solved by MaxFlowMinCost by connecting all racers to all checkpoints and filtering them on the sink.

## General Problems:

- Problems:
  
  - [Tarzan](https://olimpiada.ic.unicamp.br/pratique/p2/2012/f1/tarzan/): Check if it`s possible to go to all vertices.  Any visited technique will work.
  - [Game on Leaves](https://codeforces.com/contest/1363/problem/C): Can be solved by removing each leaf one by one. Or checking a general condidition to determine the winner in O(1).

# Search:boom:

---

* [Connected Cells in a Grid](https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem): Recursion with Flood Fill.

* [Hackerland Radio Transmitters](https://www.hackerrank.com/challenges/hackerland-radio-transmitters): Greedy Search 

* [Non-Divisible Subset](https://www.hackerrank.com/challenges/non-divisible-subset/problem): Requires math insight about what about what being evenly divisible means.

* [Pairs](https://www.hackerrank.com/challenges/pairs/problem): Search for pairing values according to criteria.  Hashmap is useful. 

* [Red Knight's Shortest Path](https://www.hackerrank.com/challenges/red-knights-shortest-path/problem): BFS problem.

* [New Year Chaos](https://www.hackerrank.com/challenges/new-year-chaos/submissions/code/149588080)

* [Dreamoon and Ranking Collection](https://codeforces.com/contest/1330/problem/A):  Search in array by counting gaps.

* [Pão a Metro](https://www.urionlinejudge.com.br/judge/en/problems/view/2329): Pure Binary Search Problem

* [The Monkey and the Oiled Bamboo](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3183): Binary search problem. Maximum is the sum of all heights.

* [Onde esta o marmore?](https://www.urionlinejudge.com.br/judge/pt/problems/view/1025): Binary Search. Requires optimization on the sort.  Quicksort is recommended.

* [Ajude seu Madruga](https://www.urionlinejudge.com.br/judge/pt/problems/view/1912):Binary search. Requires 1e-5 precision. Using double is recommended.

* [Imposto Real](https://www.urionlinejudge.com.br/judge/pt/problems/view/2666): BFS search. Try to take advantage that it is a MST.

* [https://codeforces.com/contest/1358/problem/B](https://codeforces.com/contest/1358/problem/B): It is possible to search in a linear search, think greedy.

* [Solve the Maze](https://codeforces.com/contest/1365/problem/D): By surrounding all bad people, and checking if all good person can reach the exit is a good way of thinking. BFS can be used.

# Adhoc:boom:

---

- [Queen's Attack II](https://www.hackerrank.com/challenges/queens-attack-2/problem) : Interesting Problem.

- [Sherlock and Anagrams](https://www.hackerrank.com/challenges/sherlock-and-anagrams/) : Search for anagrams in a string.

- [Array Manipulation](https://www.hackerrank.com/challenges/crush): Cummulative Sum.

- [3D Surface Area](https://www.hackerrank.com/challenges/3d-surface-area/) :  Awesome Insight.

- [Forming a Magic Square](https://www.hackerrank.com/challenges/magic-square-forming) : Generate combinations and compare them.

- [Sherlock and Valid String](https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem): By sorting the frequency array and examining the boundaries, it is possible to get to the answer.

- [Bigger is greater](https://www.hackerrank.com/challenges/bigger-is-greater/problem): Really simple to do by using the std. 

- [Bitmap](https://www.thehuxley.com/problem/821): Divide and Conquer problem. Treat as a string

- [Seasonal War](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=288): Flood and Fill problem. 

- [Park Lighting](https://codeforces.com/contest/1358/problem/A): Quick Math Problem. Odd and Even can be summarized in the same formula.

- [Odd Selection](https://codeforces.com/contest/1363/problem/A): The number of odd numbers needs to be odd.  Can be solved with brute force. 

- [Celex Update](https://codeforces.com/contest/1358/problem/C): Math problem. There are x_diff * *y_diff + the first paths.

- [The Best Vacation](https://codeforces.com/contest/1358/problem/D): Tricky cummulative sum problem.

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
* [Tree Shufling](https://codeforces.com/contest/1363/problem/E): Greedy Problem.  Children nodes can have their parent's cost if it's smaller than theirs.  Then solving bottom to top can be done in a greedy way.
* [Road to Zero](https://codeforces.com/contest/1342/problem/A): If 2a > b, we can use both operations.

# Constructive:boom:

---

* [Binary Period](https://codeforces.com/contest/1342/problem/B):  Problem to find a string containing the specified substring. There is a pattern.
* [Phoenix and Beauty](https://codeforces.com/contest/1348/problem/B): Problem to make an array have all subarrays of size k with an equal sum. Making it periodic is the way.
* [Phoenix and Distribution](https://codeforces.com/contest/1348/problem/C): Problem to find the minimum string of maximum lexicography. 
* [Trouble Sort](https://codeforces.com/contest/1365/problem/B): If there's both 1 and 0 it can be sorted.
* [Rotation Matching](https://codeforces.com/contest/1365/problem/C): By only shifting to a direction and a single array, it`s possible to store the results in an array.

# Math

* [Yet Another Couting Problem](https://codeforces.com/contest/1342/problem/C): The answers for module operation are periodic with a period of a times b. So we only need to calculate up to this point and use these results for the given question.
* [Phoenix and Balance](https://codeforces.com/contest/1348/problem/A): Since summation of 2^i = 2^n, then we need to put the last element with the first half. 
* [Puzzle Pieces](https://codeforces.com/contest/1345/problem/A): Quick problem. Any other solution then (1,x) or (2,2) would be a solution composed of 2x3 and that is impossible.
* [Card Constructions](https://codeforces.com/contest/1345/problem/B): Number of trianglesis given by  summation of n. That is, n*(n+1).  3 by triangle and excluding the floor. 
* [Hilbert's Hotel](https://codeforces.com/contest/1345/problem/C): Remember remainder and module are different operations when the number is negative. 
* [Matrix Game](https://codeforces.com/contest/1365/problem/A): Number of reamining moves is min(col, row). So depending if is even or odd we can determine the winner.


