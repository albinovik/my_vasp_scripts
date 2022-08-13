#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2000

double EnBound(double x, double y, double z, double w, double v)
       {
       double ba;
       ba = (x - 2*y*w - 2*z*v)/2/(w + v);
       return(ba);
       }

int main(int argc, char *argv[];){


	FILE *fp;

	char words[MAX];

        double temp1 = 1.0, temp2 = 0., encut = 0., EM = 0.;
        double PD[MAX][MAX];
        double PT[MAX][MAX];
        double SC[MAX][MAX];

        double p1, p2, p3;
        int i, j, k=0, num1 = 0, num2 = 0;

        char name[MAX];

        char mod1[]= "sc54pd17";
        char mod2[]= "sc54pt17";
        char mod3[]= "sc57pd13";
        char mod4[]= "sc57pt13";


if( ( fp = fopen("outpd.txt","r") ) == NULL ){
		fprintf(stderr, "can not open file '%s'\n", "outpd.txt");
		exit(1);
	}

    while( fgets(words, MAX, fp) !=NULL) {
    
    sscanf(words,"%s %lf %lf %lf", &name[k], &PD[k][0], &PD[k][1], &PD[k][2]);
    
//    printf("%s %lf %lf %lf \n", &name[k], PD[k][0], PD[k][1], PD[k][2]);

    k++;

                                         }

k = 0;

if( ( fp = fopen("outpt.txt","r") ) == NULL ){
		fprintf(stderr, "can not open file '%s'\n", "outpt.txt");
		exit(1);
	}

    while( fgets(words, MAX, fp) !=NULL) {
    
    sscanf(words,"%s %lf %lf %lf", &name[k], &PT[k][0], &PT[k][1], &PT[k][2]);
    
//    printf("%s %lf %lf %lf \n", &name[k], PT[k][0], PT[k][1], PT[k][2]);

    k++;

                                         }

k = 0;

if( ( fp = fopen("outsc.txt","r") ) == NULL ){
		fprintf(stderr, "can not open file '%s'\n", "outsc.txt");
		exit(1);
	}

    while( fgets(words, MAX, fp) !=NULL) {
    
    sscanf(words,"%s %lf %lf %lf", &name[k], &SC[k][0], &SC[k][1], &SC[k][2]);
    
//    printf("%s %lf %lf %lf \n", &name[k], SC[k][0], SC[k][1], SC[k][2]);

    k++;

                                         }

if( ( fp = fopen("outM.txt","r") ) == NULL ){
		fprintf(stderr, "can not open file '%s'\n", "outM.txt");
		exit(1);
	}

    

    double ra[MAX], rb[MAX], rc[MAX];



    while( fgets(words, MAX, fp) !=NULL) {

    if (strstr(words, mod1) != NULL){
    sscanf(words,"%s %lf %lf %lf", &name[0], &ra[0], &rb[0], &rc[0]);
    encut = rb[0];
    EM = rc[0];
    num1 = 54;
    num2 = 17;
    printf("------------------------------------------------------------------------\n");
    printf(" Energy/atom: Sc | Energy/atom: Pd |  Energy: Sc54Pd17  | Binding energy \n");
    printf("------------------------------------------------------------------------\n");


      for(i=0;i<MAX;i++){
          temp1 = SC[i][1];
              for(j=0;j<MAX;j++){
                  temp2 = PD[j][1];
                  if(encut == temp1 && encut == temp2){
                          p1 = SC[i][2]/2;
                          p2 = PD[j][2]/4;
                          p3 = EnBound(EM,p1,p1,num1,num2);
                         // printf(" Energy/atom: Sc | Energy/atom: Pd | Energy: Sc54Pd17 | Binding energy \n");
                         // printf("-----------------------------------------------------------------------\n");
                          printf("    %lf    |     %lf   |     %lf    |    %lf   \n",p1,p2,EM,p3);
                          //printf("%lf | %lf | %lf |  %lf %lf %lf \n",encut, temp1, temp2, p1, p2, p3);
                                                     } 
                               }  
 
                       }     


    
    //printf("%lf | %lf | %d | %d\n",encut, EM, num1, num2);
                                    }


                                         }


if( ( fp = fopen("outM.txt","r") ) == NULL ){
		fprintf(stderr, "can not open file '%s'\n", "outM.txt");
		exit(1);
	}

    

   // double ra[MAX], rb[MAX], rc[MAX];



    while( fgets(words, MAX, fp) !=NULL) {

    if (strstr(words, mod2) != NULL){
    sscanf(words,"%s %lf %lf %lf", &name[0], &ra[0], &rb[0], &rc[0]);
    encut = rb[0];
    EM = rc[0];
    num1 = 54;
    num2 = 17;
    printf("------------------------------------------------------------------------\n");
    printf(" Energy/atom: Sc | Energy/atom: Pt |  Energy: Sc54Pt17  | Binding energy \n");
    printf("------------------------------------------------------------------------\n");


      for(i=0;i<MAX;i++){
          temp1 = SC[i][1];
              for(j=0;j<MAX;j++){
                  temp2 = PT[j][1];
                  if(encut == temp1 && encut == temp2){
                          p1 = SC[i][2]/2;
                          p2 = PT[j][2]/4;
                          p3 = EnBound(EM,p1,p1,num1,num2);
                         // printf(" Energy/atom: Sc | Energy/atom: Pt | Energy: Sc54Pt17 | Binding energy \n");
                         // printf("-----------------------------------------------------------------------\n");
                          printf("    %lf    |     %lf   |     %lf    |    %lf   \n",p1,p2,EM,p3);
                          //printf("%lf | %lf | %lf |  %lf %lf %lf \n",encut, temp1, temp2, p1, p2, p3);
                                                     } 
                               }  
 
                       }     


    
    //printf("%lf | %lf | %d | %d\n",encut, EM, num1, num2);
                                    }


                                         }


if( ( fp = fopen("outM.txt","r") ) == NULL ){
		fprintf(stderr, "can not open file '%s'\n", "outM.txt");
		exit(1);
	}

    

   // double ra[MAX], rb[MAX], rc[MAX];



    while( fgets(words, MAX, fp) !=NULL) {

    if (strstr(words, mod3) != NULL){
    sscanf(words,"%s %lf %lf %lf", &name[0], &ra[0], &rb[0], &rc[0]);
    encut = rb[0];
    EM = rc[0];
    num1 = 57;
    num2 = 13;
    printf("------------------------------------------------------------------------\n");
    printf(" Energy/atom: Sc | Energy/atom: Pd |  Energy: Sc57Pd13  | Binding energy \n");
    printf("------------------------------------------------------------------------\n");


      for(i=0;i<MAX;i++){
          temp1 = SC[i][1];
              for(j=0;j<MAX;j++){
                  temp2 = PD[j][1];
                  if(encut == temp1 && encut == temp2){
                          p1 = SC[i][2]/2;
                          p2 = PD[j][2]/4;
                          p3 = EnBound(EM,p1,p1,num1,num2);
                         // printf(" Energy/atom: Sc | Energy/atom: Pt | Energy: Sc54Pt17 | Binding energy \n");
                         // printf("-----------------------------------------------------------------------\n");
                          printf("    %lf    |     %lf   |     %lf    |    %lf   \n",p1,p2,EM,p3);
                          //printf("%lf | %lf | %lf |  %lf %lf %lf \n",encut, temp1, temp2, p1, p2, p3);
                                                     } 
                               }  
 
                       }     


    
    //printf("%lf | %lf | %d | %d\n",encut, EM, num1, num2);
                                    }


                                         }


if( ( fp = fopen("outM.txt","r") ) == NULL ){
		fprintf(stderr, "can not open file '%s'\n", "outM.txt");
		exit(1);
	}

    

   // double ra[MAX], rb[MAX], rc[MAX];



    while( fgets(words, MAX, fp) !=NULL) {

    if (strstr(words, mod4) != NULL){
    sscanf(words,"%s %lf %lf %lf", &name[0], &ra[0], &rb[0], &rc[0]);
    encut = rb[0];
    EM = rc[0];
    num1 = 57;
    num2 = 13;
    printf("------------------------------------------------------------------------\n");
    printf(" Energy/atom: Sc | Energy/atom: Pt |  Energy: Sc57Pt13  | Binding energy \n");
    printf("------------------------------------------------------------------------\n");


      for(i=0;i<MAX;i++){
          temp1 = SC[i][1];
              for(j=0;j<MAX;j++){
                  temp2 = PT[j][1];
                  if(encut == temp1 && encut == temp2){
                          p1 = SC[i][2]/2;
                          p2 = PT[j][2]/4;
                          p3 = EnBound(EM,p1,p1,num1,num2);
                         // printf(" Energy/atom: Sc | Energy/atom: Pt | Energy: Sc54Pt17 | Binding energy \n");
                         // printf("-----------------------------------------------------------------------\n");
                          printf("    %lf    |     %lf   |     %lf    |    %lf   \n",p1,p2,EM,p3);
                          //printf("%lf | %lf | %lf |  %lf %lf %lf \n",encut, temp1, temp2, p1, p2, p3);
                                                     } 
                               }  
 
                       }     


    
    //printf("%lf | %lf | %d | %d\n",encut, EM, num1, num2);
                                    }


                                         }







	if(fclose(fp) != 0){
		fprintf(stderr, "can not open file '%s'\n", "outM.txt");
		exit(2);
	}

       printf("   \n");


	return 0;
}
