#include <stdlib.h>
#include <assert.h>
#include "sudokuHelpers.h"
#include <stdio.h>


// check if a 9-item group in a Sudoku puzzle is complete
// a group could be a row, a column, or a cube
int check(int * ra) {
  int counts[SIZE+1] = {0};  
  for (int i = 0; i < SIZE; i++)
    counts[ra[i]]++;
  for (int i = 1; i <= SIZE; i++)
    if (counts[i] != 1) return 0;  // incomplete or wrong
  return 1;  // must be correct if all counts were 1
}

// make a 1D array from a column of a 2D array (SIZE x SIZE)
int* makeCol(int *table) {
  // TODO: declare the unit variable (array of 9 integers, to be returned)
  int* unit = (int *) malloc(sizeof(int) * SIZE);
  for (int i = 0; i < SIZE; i++) {
    unit[i] = *table;  // first value of column
    table += SIZE;   // skip over next 9 values
  }
  /* DEBUGGING
  for (int i = 0; i < SIZE; i++)
    printf("%d ", unit[i]);
  printf("\n");
  */
  return unit;
}

// make a 1D array from a cube of a 2D array (SIZE x SIZE )
int* makeCube(int *table) {
  //  assert(row >= 0 && row < SIZE && row % 3 == 0);
  //  assert(col >= 0 && col < SIZE && col % 3 == 0);

  // TODO: declare the unit variable (array of 9 integers, to be returned)
  int* unit = (int *) malloc(sizeof(int) * SIZE);
  int idx = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      unit[idx++] = table[j];
    }
    table += SIZE; // skip over next 9 values to next row down
  }
  /* DEBUGGING
  for (int i = 0; i < SIZE; i++)
    printf("%d ", unit[i]);
  printf("\n");
  */
  return unit;
}

// check each row
int checkRows(int table[][SIZE]) {
  int good = 0;
  for (int r = 0; r < SIZE; r++) {
    good += check(table[r]);     // TODO: call check on current row
  }
  return (good == SIZE);
}

// check each column
int checkCols(int table[][SIZE]) {
  int good = 0;
  int * column;
  for (int c = 0; c < SIZE; c++) {
    column = makeCol(&table[0][c]);  // TODO: call makeCol on current column
    good += check(column);
    free(column);  // clean up when we're done
  }
  return (good == SIZE);
}

// check each cube
int checkCubes(int table[][SIZE]) {
  int good = 0;
  int * cube;
  for (int r = 0; r < SIZE; r += 3) 
    for (int c = 0; c < SIZE; c += 3) {
      cube = makeCube(&table[r][c]); // TODO: call makeCube on current cube
      good += check(cube);
      free(cube);  // clean up when we're done
    }
  return (good == SIZE);
}
