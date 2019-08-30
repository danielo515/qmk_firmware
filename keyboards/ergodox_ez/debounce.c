/*
Port of debounce algorithm from cd544e10a

This would be classified as eager_pk_cycle.
*/

/*
  This constant define not debouncing time in msecs, but amount of matrix
  scan loops which should be made to get stable debounced results.
 
  On Ergodox matrix scan rate is relatively low, because of slow I2C.
  Now it's only 317 scans/second, or about 3.15 msec/scan.
  According to Cherry specs, debouncing time is 5 msec.
 
  However, some switches seem to have higher debouncing requirements, or
  something else might be wrong. (Also, the scan speed has improved since
  that comment was written.)
*/


#include "matrix.h"
#include "quantum.h"

#ifndef DEBOUNCE
  #define DEBOUNCE 5
#endif

#define debounce_counter_t uint8_t

// Debouncing: store for each key the number of scans until it's eligible to
// change.  When scanning the matrix, ignore any changes in keys that have
// already changed in the last DEBOUNCE scans.
static debounce_counter_t* debounce_matrix; //[MATRIX_ROWS * MATRIX_COLS];

void debounce_init(uint8_t num_rows) {
  debounce_matrix = (debounce_counter_t *)malloc(num_rows * MATRIX_COLS * sizeof(debounce_counter_t));
  int i = 0;
  for (uint8_t r = 0; r < num_rows; r++) {
    for (uint8_t c = 0; c < MATRIX_COLS; c++) {
      debounce_matrix[i++] = 0;
    }
  }
}

// Returns a matrix_row_t whose bits are set if the corresponding key should be
// eligible to change in this scan.
matrix_row_t debounce_mask(uint8_t row) {
  matrix_row_t result = 0;
  for (uint8_t j=0; j < MATRIX_COLS; ++j) {
    if (debounce_matrix[row * MATRIX_COLS + j]) {
      --debounce_matrix[row * MATRIX_COLS + j];
    } else {
      result |= (1 << j);
    }
  }
  return result;
}


// Report changed keys in the given row.  Resets the debounce countdowns
// corresponding to each set bit in 'change' to DEBOUNCE.
void debounce_report(matrix_row_t change, uint8_t row) {
  for (uint8_t i = 0; i < MATRIX_COLS; ++i) {
    if (change & (1 << i)) {
      debounce_matrix[row * MATRIX_COLS + i] = DEBOUNCE;
    }
  }
}

#if DEBOUNCE > 0
void debounce(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows, bool changed)
{
  for (uint8_t i = 0; i < num_rows; i++)
  {
	  matrix_row_t mask = debounce_mask(i);
	  matrix_row_t row = (raw[i] & mask) | (cooked[i] & ~mask);
	  debounce_report(row ^ cooked[i], i);
	  cooked[i] = row;	  
  }
}

#else //no debouncing.
void debounce(matrix_row_t raw[], matrix_row_t cooked[], uint8_t num_rows, bool changed)
{
  for (int i = 0; i < num_rows; i++) {
    cooked[i] = raw[i];
  }
}
#endif

//TODO: set this and unset this.
bool debounce_active(void) {
  return true;
}

