#include <gmp.h>
#include <stdio.h>
#include <assert.h>

int main(){

  /* The basic operation is to initialize the number */
  /* 1. Initialize the number r */
  mpz_t r;
  mpz_init(r);
  mpz_set_ui(r,15);   /*r = 15 now */

  mpz_mul_ui(r,r,10); /* r = r * 10 */

  printf (" r = ");
  mpz_out_str(stdout,10,r);
  printf ("\n");

}
