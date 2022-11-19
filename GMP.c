#include <gmp.h>
#include <stdio.h>
#include <assert.h>

int main(){

  /* The basic operation is to initialize the number */
  /* 1. Initialize the number r */
  mpf_t r;
  mpf_init(r);
  mpf_set_d(r,15);   /*r = 15 now */

  //mpf_mul_ui(r,r,10); /* r = r * 10 */

  printf (" r = ");
  mpf_out_str(stdout,10,r);
  printf ("\n");

}
