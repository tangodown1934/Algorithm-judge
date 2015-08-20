
Algorithm Implementation/Miscellaneous/N-Queens
< Algorithm Implementation? | Miscellaneous
The eight queens puzzle is the problem of putting eight chess queens on an 8¡¿8 chessboard such that none of them is able to capture any other using the standard chess queen's moves. The queens must be placed in such a way that no two queens would be able to attack each other. Thus, a solution requires that no two queens share the same row, column, or diagonal. The eight queens puzzle is an example of the more general n queens puzzle of placing n queens on an n¡¿n chessboard, where solutions exist only for n = 1 or n ¡Ã 4.

Contents  [hide] 
1 C++
2 C
3 Haskell
4 Python
5 Mathematica
C++[edit]
A fully commented backtracking implementation in C++

#include <iostream>

using namespace std;

const int N = 5;
int position[N];

// Check if a position is safe
bool isSafe(int queen_number, int row_position)
{
	// Check each queen before this one
	for (int i = 0; i < queen_number; i++)
	{
		// Get another queen's row_position
		int other_row_pos = position[i];

		// Now check if they're in the same row or diagonals
		if (other_row_pos == row_position || // Same row
			other_row_pos == row_position - (queen_number - i) || // Same diagonal
			other_row_pos == row_position + (queen_number - i))   // Same diagonal
			return false;
	}
	return true;
}


// Recursively generate a tuple like [0 0 0 0], then [0 0 0 1] then etc...
void solve(int k)
{
	if (k == N) // We placed N-1 queens (0 included), problem solved!
	{
		// Solution found!
		cout << "Solution: ";
		for (int i = 0; i < N; i++)
			cout << position[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < N; i++) // Generate ALL combinations
		{
			// Before putting a queen (the k-th queen) into a row, test it for safeness
			if (isSafe(k, i))
			{
				position[k] = i;
				// Place another queen
				solve(k + 1);
			}
		}
	}
}

int main()
{
	solve(0);

	return 0;
}
C[edit]
A backtracking depth-first search (DFS) solution in C:

#include <stdio.h>

int
is_safe(int rows[8], int x, int y)  
{
    int i;
    
    if (y == 0)
            return 1;
    for (i=0; i < y; ++i) {
       if (rows[i] == x || rows[i] == x + y - i || rows[i] == x - y +i)
            return 0;
    }

    return 1;
}
 
void
putboard(int rows[8])  
{
    static int s = 0;
    int x, y;

    printf("\nSolution #%d:\n---------------------------------\n", ++s);
    for (y=0; y < 8; ++y) {
        for (x=0; x < 8; ++x)
            printf(x == rows[y] ? "| Q " : "|   ");
        printf("|\n---------------------------------\n");
    }
}
 
void
eight_queens_helper(int rows[8], int y)
{
    int x;

    for (x=0; x < 8; ++x) {
        if (is_safe(rows, x, y)) {
            rows[y] = x;
            if (y == 7)
              putboard(rows);
            else
              eight_queens_helper(rows, y+1);
        }
    }
}

int
main()
{
    int rows[8];

    eight_queens_helper(rows, 0);

    return 0;
}
Haskell[edit]
import Control.Monad

queens n = foldM (\y _ -> [ x : y | x <- [1..n], safe x y 1]) [] [1..n]
safe x [] n = True
safe x (c:y) n = and [ x /= c , x /= c + n , x /= c - n , safe x y (n+1)]

main = mapM_ print $ queens 8
Python[edit]
def queensproblem(rows, columns):
    solutions = [[]]
    for row in range(rows):
        solutions = add_one_queen(row, columns, solutions)
    return solutions

def add_one_queen(new_row, columns, prev_solutions):
    return [solution + [new_column]
            for solution in prev_solutions
            for new_column in range(columns)
            if no_conflict(new_row, new_column, solution)]

def no_conflict(new_row, new_column, solution):
    return all(solution[row]       != new_column           and
               solution[row] + row != new_column + new_row and
               solution[row] - row != new_column - new_row
               for row in range(new_row))

for solution in queensproblem(8, 8):
    print(solution)
Mathematica[edit]
dispSol[sol_] := sol /. {1 -> "Q" , 0 -> "-"} // Grid

solveNqueens[n_] := 
 Module[{c, m, b, vars}, c = cqueens[n]; m = mqueens[n]; 
  vars = mqueens2[n]; b = bqueens[Length[m]]; 
  Partition[LinearProgramming[c, m, b, vars, Integers], n]]

cqueens[n_] := Table[-1, {i, n^2}]

bqueens[l_] := Table[{1, -1}, {i, l}]

mqueens2[n_] := Table[{0, 1}, {i, n^2}]

mqueens[n_] := 
 Module[{t, t2, t3, t4}, t = mqueensh[n]; t2 = Append[t, mqueensv[n]];
   t3 = Append[t2, mqueensd[n]]; t4 = Append[t3, mqueensdm[n]]; 
  Partition[Flatten[t4], n^2]]

mqueensh[n_] := 
 Module[{t}, t = Table[0, {i, n}, {j, n^2}]; 
  For[i = 1, i <= n, i++, 
   For[j = 1, j <= n, j++, t[[i, ((i - 1)*n) + j]] = 1]]; t]

mqueensv[n_] := 
 Module[{t}, t = Table[0, {i, n}, {j, n^2}]; 
  For[i = 1, i <= n, i++, 
   For[j = 1, j <= n, j++, t[[j, ((i - 1)*n) + j]] = 1]]; t]

mqueensd[n_] := 
 Module[{t}, t = Table[0, {i, (2*n) - 1}, {j, n^2}]; 
  For[k = 2, k <= 2 n, k++, 
   For[i = 1, i <= n, i++, 
    For[j = 1, j <= n, j++, 
     If[i + j == k, t[[k - 1, ((i - 1)*n) + j]] = 1]]]]; t]

mqueensdm[n_] := 
 Module[{t}, t = Table[0, {i, Sum[1, {i, 1 - n, n - 1}]}, {j, n^2}]; 
  For[k = 1 - n, k <= n - 1, k++, 
   For[i = 1, i <= n, i++, 
    For[j = 1, j <= n, j++, 
     If[i == j - k, t[[k + n, ((i - 1)*n) + j]] = 1]]]]; t]
Category: Algorithm Implementation
Navigation menu
Create accountLog inBookDiscussionReadEditView history

Main Page
Help
Browse wiki
Cookbook
Wikijunior
Featured books
Recent changes
Donations
Random book
Using Wikibooks
Community
Reading room
Community portal
Bulletin Board
Help out!
Policies and guidelines
Contact us
Tools
What links here
Related changes
Upload file
Special pages
Permanent link
Page information
Cite this page
Languages
Add links
Sister projects
Wikipedia
Wikiversity
Wiktionary
Wikiquote
Wikisource
Wikinews
Wikivoyage
Commons
Wikidata
Print/export
Create a collection
Download as PDF
Printable version
This page was last modified on 24 May 2014, at 17:00.
Text is available under the Creative Commons Attribution-ShareAlike License.; additional terms may apply. By using this site, you agree to the Terms of Use and Privacy Policy.
Privacy policyAbout WikibooksDisclaimersDevelopersMobile viewWikimedia Foundation Powered by MediaWiki