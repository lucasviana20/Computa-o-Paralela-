#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

void Trap(double a, double b, int n, double* global_result_p);

double f(double x)
{
    return exp(x);   
}

int main(int argc, char* argv[])
{
    double global_result = 0.0 , a = 15 , b = 2;
    
    int n = 100, thread_count;
    
    thread_count = strtol(argv[1], NULL, 10);
    
    #pragma omp parallel num_threads (thread_count)
    
    #pragma omp for reduction(+: *global_result_p)
    
        Trap(a, b, n, &global_result);
    
    printf("With n = %d trapezoids, our estimate\n", n); 
    
    printf("of the integral from %f to %f = %.14e\n", a, b, global_result);
    
    return 0;
}

void Trap(double a, double b, int n , double* global_result_p) 
{
    double h , x , my_result , local_a , local_b;
    
    int i , local_n , my_rank = omp_get_thread_num() , thread_count = omp_get_num_threads();
    
    h = (b-a) / n;
    
    local_n = n / thread_count;
    
    local_a = a + my_rank * local_n * h;
    
    local_b = local_a + local_n * h; 
    
    my_result = (f(local_a) + f(local_b)) / 2.0;
    
    for (i = 1; i <= local_n - 1 ; i++)
    {
        x = local_a + i * h;
        
        my_result += f(x);
    }
    
    my_result = my_result * h;
    
    *global_result_p += my_result;
}
