#include "life.h"
#include <iostream>
using namespace std;

void Life::initialize()
/*
Pre:  None.
Post: The Life object contains a configuration specified by the user.
*/

{  
   // Ask for the active grid size (1..maxrow, 1..maxcol)
   cout << "Enter desired number of rows(1.." << maxrow << "): ";
   cin >> rows;
   while (rows < 1 || rows > maxrow) {
      cout << "Row count " << rows << " is out of range. Enter 1.." << maxrow << ": ";
      cin >> rows;
   }
   cout << "Enter desired number of columns (1.." << maxcol << "): ";
   cin  >> cols;
   while (cols < 1 || cols > maxcol) {
      cout << "Column count " << cols << " is out of range. Enter 1.." << maxcol << ": ";
      cin >> cols;
   }
   cout << "List the coordinates for living cells (no hedge)." << endl;
   cout << "Terminate the list with the special pair -1 -1" << endl;

   // Zero the whole physical array (no hedge now)
   int row, col;
     for (row = 0; row < maxrow; ++row)
      for (col = 0; col < maxcol; ++col)
         grid[row][col] = 0;

   cin >> row >> col;
   while (row != -1 || col != -1) {
      if (row >= 1 && row <= rows)
         if (col >= 1 && col <= cols)
            grid[row][col] = 1;
         else
            cout << "Column " << col << " is out of range." << endl;
      else
         cout << "Row " << row << " is out of range." << endl;
      cin >> row >> col;
   }
}

void Life::print()
/*
Pre:  The Life object contains a configuration.
Post: The configuration is written for the user.
*/

{
   int row, col;
   cout << "\nThe current Life configuration is:" <<endl;
   for (row = 1; row <= rows; row++) {
      for (col = 1; col <= cols; col++)
         if (grid[row][col]) cout << '*';
         else cout << ' ';
      cout << endl;
   }
   cout << endl;
}

void Life::update()
/*
Pre:  The Life object contains a configuration.
Post: The Life object contains the next generation of configuration.
*/

{
   int row, col;
   int new_grid[maxrow][maxcol]; // no hedge

   for (row = 1; row <= rows; row++)
      for (col = 1; col <= cols; col++)
         switch (neighbor_count(row, col)) {
         case 2:
            new_grid[row][col] = grid[row][col];  //  Status stays the same.
            break;
         case 3:
            new_grid[row][col] = 1;                //  Cell is now alive.
            break;
         default:
            new_grid[row][col] = 0;                //  Cell is now dead.
         }

   for (row = 1; row <= rows; row++)
      for (col = 1; col <= cols; col++)
         grid[row][col] = new_grid[row][col];
}

int Life::neighbor_count(int row, int col)
/*
Pre:  The Life object contains a configuration, and the coordinates
      row and col define a cell inside its hedge.
Post: The number of living neighbors of the specified cell is returned.
*/

{
   // Loop bounds once (no hedges)
   const int rmin = (row == 0) ? 0 : row - 1;
   const int rmax = (row == rows - 1) ? rows - 1 : row + 1;
   const int cmin = (col == 0) ? 0 : col - 1;
   const int cmax = (col == cols -1) ? cols - 1 : col + 1;

   int r, c;
   int count = 0;
   for (r = rmin; r <= rmax; ++r)
      for (c = cmin; c <= cmax; ++c)
         count += grid[r][c];  //  Increase the count if neighbor is alive.

   count -= grid[row][col]; //  Reduce count, since cell is not its own neighbor.
   return count;
}