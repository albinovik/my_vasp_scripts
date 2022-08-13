#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#define MAX 200

double etha(double a, double c, double betha)
           {
           double res1;
           double del=a/c;
           double del2=del*cos(betha);
           double del3=1+del2;
           double del4=sin(betha);
           double del5=pow(del4,2);
           double del6=2*del5;
           res1 = del3/del6;
           return(res1);
           }

double niu(double a, double c, double x, double betha)
           {
           double res2;
           double it1=cos(betha);
           double it2=x*c*it1;
           double it3 = it2/a;
           res2 = it3 + 0.5;
           return(res2);
           }


int main(int argc, char *argv[])
{

double a=0, b=0, c=0, alpha=0, betha=0, gamma=0;

double Pic=3.141592653589793;

a=atof(argv[1]);
b=atof(argv[2]);
c=atof(argv[3]);
printf("a = %lf\n",a);
printf("b = %lf\n",b);
printf("c = %lf\n",c);

alpha=atof(argv[4]);
alpha=alpha*(Pic/180.);
betha=atof(argv[5]);
betha=betha*(Pic/180.);
gamma=atof(argv[6]);
gamma=gamma*(Pic/180.);
printf("alpha = %lf\n",alpha);
printf("betha = %lf\n",betha);
printf("gamma = %lf\n",gamma);

double out1=0, out2=0;

out1=etha(a,c,betha);
printf("etha = %lf\n", out1);

out2=niu(a,c,out1,betha);
printf("niu = %lf\n", out2);


//calculation of sepatate K-points in monoclinic primitive cell
// formula from Computational Materials Science 128 (2017) 140–184 (Table 87)

double x1=-out1;
double temp=0;
double x2=1-out2;
double x3=-1+out1;
double x4=-out2;
double temp2=0.5;
double temp3=-0.5;

printf("G    %lf   %lf   %lf\n",temp,temp,temp);
printf("Z    %lf   %lf   %lf\n",temp,temp2,temp);
printf("B    %lf   %lf   %lf\n",temp,temp,temp2);
printf("B2   %lf   %lf   %lf\n",temp,temp,temp3);
printf("Y    %lf   %lf   %lf\n",temp2,temp,temp);
printf("Y2   %lf   %lf   %lf\n",temp3,temp,temp);
printf("C    %lf   %lf   %lf\n",temp2,temp2,temp);
printf("C2   %lf   %lf   %lf\n",temp3,temp2,temp);
printf("D    %lf   %lf   %lf\n",temp,temp2,temp2);
printf("D2   %lf   %lf   %lf\n",temp,temp2,temp3);
printf("A    %lf   %lf   %lf\n",temp3,temp,temp2);
printf("E    %lf   %lf   %lf\n",temp3,temp2,temp2);
printf("H    %lf   %lf   %lf\n", x1, temp, x2);
printf("H2   %lf   %lf   %lf\n", x3, temp, out2);
printf("H4   %lf   %lf   %lf\n", x1, temp, x4);
printf("M    %lf   %lf   %lf\n", x1, temp2, x2);
printf("M2   %lf   %lf   %lf\n", x3, temp2, out2);
printf("M4   %lf   %lf   %lf\n", x1, temp2, x4);

printf("Recommended path: G-Z-D-B-G-A-E-Z-C2-Y2-G\n");

return 0;
}
