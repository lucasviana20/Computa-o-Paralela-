#include <gmp.h>
#include <stdio.h>
#include <assert.h>

int main(){

  /* The basic operation is to initialize the number */
  /* 1. Initialize the number r */
  mpf_t r;
  mpf_init2 (r, 256);
  mpf_set_d(r,0.123456789123456789);   /*r = 15 now */

  //mpf_mul_ui(r,r,10); /* r = r * 10 */

  printf (" r = ");
  mpf_out_str(stdout,10,20,r);
  printf ("\n");

}
