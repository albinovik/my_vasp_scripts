#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2000

double bulk(double x, double y)
       {
       double ba;
       ba = (x + 2*y)/3.;
       return(ba);
        }

double modGV(double x, double y, double z)
       {
       double g;
       g = (x - y + 3*z)/5.;
       return(g);
       }

double modGR(double x, double y, double z)
       {
       double gr;
       gr = (5*z*(x - y))/(4*z + 3*(x - y));
       return(gr);
       }

double Sredn(double x, double y)
       {
       double z;
       z = (x + y)/2.;
       return(z);
       }

double Young(double x, double y)
       {
       double Yo;
       Yo = (9*x*y)/(3*x + y);
       return Yo;
       }

double AnisFac123(double x, double y, double z, double a)
       {
       double An;
       An = 4*a/(x + y - 2*z);
       return An; 
       }

double AnisUniv(double x, double y, double z, double a)
       {
       double Uni;
       Uni = 5*x/y + z/a - 6;
       return(Uni);
       }

double AZen(double x, double y, double z)
       {
       double A;
       A = 2*z/(x + y);
       return A;
       }

double AC(double x, double y)
       {
       double Acb;
       Acb = (x - y)/(x + y);
       return Acb;
       }

double Puas(double x, double y)
       {
       double pp;
       pp = (3*x - 2*y)/(2*(3*x + y));
       return pp;
       }

int main(int argc, char *argv[]){

	char file_name[]="OUTCAR";
	FILE *fp;
	char words[MAX] ;
	int line=0;
        int mark=0;
        double temp = 1.0, temp2 = 0.;
        double CIY[10][10];
        char stro[10];
        double p1, p2, p3, p4, p5;

	if( ( fp = fopen(file_name,"r") ) == NULL ){
		fprintf(stderr, "can not open file '%s'\n", file_name);
		exit(1);
	}
	char start[]= " TOTAL ELASTIC MODULI (kBar)";
        char finish[]=" ---";


        printf("   \n"); printf("   \n"); printf("   \n");


	while( fgets(words, MAX, fp) !=NULL && (line != 10)){
               if(strstr(words, start) != NULL) mark=1;
               if(mark == 1) {fprintf(stdout, "%s", words);
                              line++;
                             }
               if(line == 4) sscanf(words,"%s %lf %lf %lf %lf %lf %lf",&stro[0],&CIY[0][0],&CIY[0][1],&CIY[0][2],&CIY[0][3],&CIY[0][4],&CIY[0][5]);
               if(line == 5) sscanf(words,"%s %lf %lf %lf %lf %lf %lf",&stro[1],&CIY[1][0],&CIY[1][1],&CIY[1][2],&CIY[1][3],&CIY[1][4],&CIY[1][5]);
               if(line == 6) sscanf(words,"%s %lf %lf %lf %lf %lf %lf",&stro[2],&CIY[2][0],&CIY[2][1],&CIY[2][2],&CIY[2][3],&CIY[2][4],&CIY[2][5]);
               if(line == 7) sscanf(words,"%s %lf %lf %lf %lf %lf %lf",&stro[3],&CIY[3][0],&CIY[3][1],&CIY[3][2],&CIY[3][3],&CIY[3][4],&CIY[3][5]);
               if(line == 8) sscanf(words,"%s %lf %lf %lf %lf %lf %lf",&stro[4],&CIY[4][0],&CIY[4][1],&CIY[4][2],&CIY[4][3],&CIY[4][4],&CIY[4][5]);
               if(line == 9) sscanf(words,"%s %lf %lf %lf %lf %lf %lf",&stro[5],&CIY[5][0],&CIY[5][1],&CIY[5][2],&CIY[5][3],&CIY[5][4],&CIY[5][5]);
	}
//	fprintf(stdout, "%d line | %s\n",line++,  words);



      //we are print values of CIY[i][j] on screen
      //int i,j;
      //for(i=0;i<6;i++){
      //         for(j=0;j<6;j++){
      //                  printf("CIY[%d][%d] = %lf \n",i,j,CIY[i][j]);
      //                         }
      //                 }


       p1 = bulk(CIY[0][0],CIY[0][1])*0.1;
       printf("BV = %lf GPa      |     ",p1);
       p4 = bulk(CIY[0][0],CIY[0][1])*0.1;
       printf("BR = %lf GPa      |     ",p4);
       temp = Sredn(p1,p4); printf("B = %lf GPa\n",temp);
       p2 = modGV(CIY[0][0],CIY[0][1],CIY[3][3])*0.1;
       printf("GV = %lf GPa      |     ",p2);
       p3 = modGR(CIY[0][0],CIY[0][1],CIY[3][3])*0.1;
       printf("GR = %lf GPa      |     ",p3);
       p5 = AC(p2, p2); // calculation AC
       temp2 = Sredn(p2,p3); printf("G = %lf GPa\n",temp2);
       printf(" --------------------------------------------------------------------------------\n");

       p3 = Young(temp,temp2);
       printf("Young's modulus: E = %lf GPa\n",p3);
       printf(" --------------------------------------------------------------------------------\n");
       p3 = Puas(temp, temp2);
       printf("Poisson's ratio: v = %lf \n",p3);
       printf(" --------------------------------------------------------------------------------\n");


       p1 = AnisFac123(CIY[0][0],CIY[2][2],CIY[0][2],CIY[3][3])*0.1;
       p2 = AnisFac123(CIY[1][1],CIY[2][2],CIY[1][2],CIY[4][4])*0.1;
       p3 = AnisFac123(CIY[0][0],CIY[1][1],CIY[0][1],CIY[5][5])*0.1;
       printf("The shear anisotropic factor:\n");
       printf("A1 = %lf           |     A2 = %lf           |     A3 = %lf    \n",p1,p2,p3);
       printf(" --------------------------------------------------------------------------------\n");
       //printf("A2 = %lf GPa\n",p2);
       //printf("A3 = %lf GPa\n",p3);
       temp = AnisUniv(p2,p3,p1,p1)*0.1;
       printf("Universal undex:        |     Zener index:            |     Chung-Buessem index: \n");
       printf("AU = %lf           |     ",temp);
       temp2 = AZen(CIY[0][0],CIY[0][1],CIY[3][3])*0.1;
      // printf(" --------------------------------------------------------------------------------\n");
      // printf("The Zener anisotropic index:\n");
       printf("A = %lf            |     AC = %lf    \n",temp2, p5);
       printf(" --------------------------------------------------------------------------------\n");
      // printf("Percentage of elastic anisotropy:\n");


	if(fclose(fp) != 0){
		fprintf(stderr, "can not open file '%s'\n", file_name);
		exit(2);
	}

       printf("   \n");


	return 0;
}
