# Dynamic Programming :boom:

---

## Longest Commom Sequence (LCS)

- [Compromise](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=472) : Requires retrieval of the optimum solution's path.

## Coin Change

* [The Coin Change Problem](https://www.hackerrank.com/challenges/coin-change): Pure

## Pure DP

* [Superman Celebrates Diwali](https://www.hackerrank.com/challenges/superman-celebrates-diwali/problem) Amazing problem. Requires iterative answer and some way to avoid computing problems that won't be useful.
* [Max Array Sum](https://www.hackerrank.com/challenges/max-array-sum/problem): Classic Problem. Pure.
* [Tournament](https://codeforces.com/contest/1260/problem/E): Really hard to see it as a DP.  Hard to model the data. Really hard question but it is simple once the concept is grasped.
* 

# Backtracking :boom:

---

* [Count Luck](https://www.hackerrank.com/challenges/count-luck/problem): Pure

# Graph:boom:

---

* [Mania de Par](https://www.urionlinejudge.com.br/judge/pt/problems/view/1931): Interesting Dijkstra problem with DP.  Keeping separate values for even and odd is helpful. 
* [Bomba](https://olimpiada.ic.unicamp.br/pratique/p2/2012/f2/bomba/): Djikstra-like problem where there is an extra state that is time.
* [Zak Galou](https://www.urionlinejudge.com.br/judge/pt/problems/view/1409): DP Coin Change + Dijkstra. (DOING) :fire: 

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
