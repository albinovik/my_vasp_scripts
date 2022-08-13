#include <stdio.h>
#include <stdlib.h>
void ithPermutation(const int n, int c, int i, double g, double h)
{
   int j, k = 0;
   int *fact = (int *)calloc(n, sizeof(int));
   int *perm = (int *)calloc(n, sizeof(int));
   double *magn = (double *)calloc(n, sizeof(int));

   // massiv of magnetic momentums
   for (j = 0; j < n; ++j)
   {
      //m=n/2;
      if(j<n/2){
      magn[j]=g;//printf("%0.1lf ", g);
      }
      else{ 
      magn[j]=h;//printf("%0.1lf ", h);
      }
   }

   // compute factorial numbers
   fact[k] = 1;
   while (++k < n)
      fact[k] = fact[k - 1] * k;

   // compute factorial code
   for (k = 0; k < c; ++k)
   {
      perm[k] = (i / fact[c - 1 - k]) % (n-k);
   //   i = i % fact[n - c - 1 - k];
   }

   // readjust values to obtain the permutation
   // start from the end and check if preceding values are lower
   for (k = n - 1; k > 0; --k)
      for (j = k - 1; j >= 0; --j)
         if (perm[j] <= perm[k])
            perm[k]++;

   // print permutation
   for (k = 0; k < n; ++k){
       int temp=perm[k];
       //j=magn[temp];
       //printf("temp = %d and magn[%d]=%d\n", temp, temp, magn[temp]);
       printf("%0.1lf ", magn[temp]);
                          }
      //printf("%d ", perm[k]);
   printf("\n");

   free(fact);
   free(perm);
//   free(magn);
}

int main(int argc, char *argv[]){
int a,b,c;
a=atoi(argv[1]);
b=atoi(argv[2]);
c=atoi(argv[3]);
double d,e;
d=atof(argv[4]);
e=atof(argv[5]);
//printf("%d ", c);

int x=c-1;
//for (c=0; c<=x; c++){
ithPermutation(a, b, x, d, e);
//                    }
//printf("Permutation(10, 3628799)=%d\n",b);
return 0;
}
