#include <gmp.h>
#include <stdio.h>
#include <assert.h>

int main()
{
  mpf_t r;
  mpf_init2 (r, 256);
  mpf_set_str(r, "0.1111111111111111111111111111111111111111", 10); 
  mpf_add(r,r,r);
  mpf_add(r,r,r);

  printf (" r = ");
  gmp_printf("%.40Ff\n", r);
  printf ("\n");

}
