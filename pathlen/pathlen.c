#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
#include <sys/types.h>
#define MAX 200

double Masch(double x, double y, double z, double coef)
           {
           double res1;
           res1 = (sqrt(pow(x*coef,2) + pow(y*coef,2) + pow(z*coef,2)));
           return(res1);
           }

double distance(double x1, double y1, double z1, double x2, double y2, double z2)
           {
           double res2;
           res2 = sqrt(pow((x2-x1),2)+pow((y2-y1),2)+pow((z2-z1),2));
           return(res2);
           }

//function for writing array into file
void printArray(FILE *output, double (*arr)[3], unsigned size) {
    unsigned i, j;
    fprintf(output,"     x           y           z      \n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < 3; j++) {
            fprintf(output, " %lf   ", arr[i][j]);
        }
        fprintf(output,"\n");
    }
    fprintf(output,"\n");
}

//function for writing array on screen
void printArrSc(double (*arr)[3], unsigned size) {
    unsigned i, j;
    printf("     x           y           z      \n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %lf   ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void prHeader(FILE *output, char *x, double y, double (*arr)[3], unsigned size, char *z, char *w) {
    unsigned i, j;    
    fprintf(output,"%s\n",x);
    fprintf(output,"%.1lf\n",y);
    //printArray(CIY, 3);
    for (i = 0; i < size; i++) {
        for (j = 0; j < 3; j++) {
            fprintf(output, " %lf   ", arr[i][j]);
        }
        fprintf(output,"\n");
    }
   // fprintf(output,"\n");
    fprintf(output,"  %s\n",z);
    fprintf(output,"  %s\n",w);
    fprintf(output,"Cartesian\n");
}

//we replace word 'iter' by number of iteration
const char replace(FILE *output, char *a, char *b, char *c){
  memcpy(strstr(a, b), c, strlen(b));
  fprintf(output,"   %s",a);
}

//we count sum of element's values in int-massiv
int sumArr(int (*arr), int init, int nelem){
  int i,sum=0;
  for(i=init;i<nelem;i++){  
           sum+=arr[i];
                      }
  return sum;
                               }



int main(int argc, char *argv[])
{

  register int q;
  //printf("%d files match specified name\n", argc-1);
  //printf("They are: ");
  //for(q=1; q<argc; q++)
  //printf("%s ", argv[q]);
  //printf("\n");
  //return 0;

   char filename[MAX];

   int status;
   status=mkdir("pathways", ACCESSPERMS);

   FILE *fp; // for reading 
   FILE *nmf; // for writing
   char words[MAX]; // massiv for cash-string saving 
   int line=1; // amount of strings
   int mark=1; // if mark == 1, else we read the text only
               // if mark == 2, else we scan initial table
               // if mark == 3, else we analize other tables
   int number = 0; //it is a number of each step in each table
   double CIY[MAX][3];// massiv for data saving from first table
   double POSCARd[3][3];// vector data from POSCAR 
   double coef;//scale
   double TEMP[MAX][3];//massiv for temporary data
   double R[MAX];//massiv for distance data
   double LA[MAX];//massiv for distance data
   char name[MAX];
   char elem[MAX];
   char amoel[MAX];

   //parameters for 6 and 7 string in POSCAR
   char *istr;
   char elements[MAX];
   char *elemch[MAX];
   int amount[MAX];
   char sep[10]=" ";
   int i=0;
char vreme;


   //we create new file for calculation result
   nmf = fopen("result.txt","w");


   //we read POSCAR
   fprintf(nmf,"_______________________________________\n");
   fprintf(nmf,"|          DATA FROM POSCAR:          |\n");
   fprintf(nmf,"|                                     |\n");
   if(( fp = fopen("POSCAR","r") ) == NULL ){
		printf("can not open file POSCAR\n");
		exit(1);
                                            }

	while( fgets(words, MAX, fp) !=NULL && (line != 8)){
               if(line == 1) sscanf(words,"%s",&name[0]);//system
               if(line == 2) sscanf(words,"%lf",&coef);// scale
               if(line == 3) sscanf(words,"%lf %lf %lf",&POSCARd[0][0],&POSCARd[0][1],&POSCARd[0][2]);// first vector
               if(line == 4) sscanf(words,"%lf %lf %lf",&POSCARd[1][0],&POSCARd[1][1],&POSCARd[1][2]);// second vector
               if(line == 5) sscanf(words,"%lf %lf %lf",&POSCARd[2][0],&POSCARd[2][1],&POSCARd[2][2]);// third vector
               if(line == 6) memcpy (elem,words,MAX);
               if(line == 7) memcpy (amoel,words,MAX);
               line++;
	                                                   }
   //printf("elem[0]= %s\n",&elem[0]);


   // work with 7 string in POSCAR
   istr = strtok(amoel,sep);
   // Выделение последующих частей
   i=0;
   while(istr != NULL)
   {
      sscanf(istr,"%d",&amount[i]);
      //printf("%d | %d\n",i,amount[i]);
      istr = strtok(NULL,sep);
      i++;
   }
   int nelem = i;

   //char *vremenno=argv[3];
   //printf("Perenaznqachenije = %s\n",vremenno);
   


      //we are print values of POSCARd[i][j] in file
      fprintf(nmf,"| scale:   %.1lf                        |\n",coef);
      fprintf(nmf,"|                                     |\n");
      fprintf(nmf,"| lattice vectors:                    |\n");
      int j;
      for(i=0;i<3;i++){
               for(j=0;j<3;j++){
                        fprintf(nmf,"  %lf  ",POSCARd[i][j]);
                               }
                       fprintf(nmf,"\n");
                       }
 //     fprintf(nmf,"|_____________________________________|\n");
      fprintf(nmf,"\n");

    

    //close the POSCAR-file
    fclose(fp);

    //new lattice parameters

    double Acell = Masch(POSCARd[0][0],POSCARd[0][1],POSCARd[0][2],coef);
    double Bcell = Masch(POSCARd[1][0],POSCARd[1][1],POSCARd[1][2],coef);
    double Ccell = Masch(POSCARd[2][0],POSCARd[2][1],POSCARd[2][2],coef);

    //printf("_______________________________________\n");
    fprintf(nmf,"|                                     |\n");
    fprintf(nmf,"| lattice parameters:                 |\n");
    //printf("|                                     |\n");
    fprintf(nmf,"| a = %.4lf  b = %.4lf  c = %.4lf |\n",Acell,Bcell,Ccell);
    //fprintf(nmf,"|_____________________________________|\n");
      fprintf(nmf,"\n");

   fclose(nmf);



   char *chemelem = "Fe";
   line = 1;

   //we read OUTCAR
   if(( fp = fopen("OUTCAR","r") ) == NULL ){
		printf("can not open file OUTCAR\n");
		exit(1);
                                            }

   char steps[]="   NSW    =";
   char initial[]= " position of ions in cartesian coordinates  (Angst):";
   char probel[]=" \n";

   char start[]= "TOTAL-FORCE";
   char finish[]="total drift";

   int natoms=0;
   int addition=0;
   int item=0;//amount of iteration
   double dis=0;
   char simb[MAX];
   char sign[MAX];
   int pe=0;
   //char *chemelem;
   int begi,endi;
   char NSWVASP[MAX];
   int nakopitel[MAX];
   char *istr2;
   char allelem[MAX]; 

   while( fgets(words, MAX, fp) != 0){//while there no the end of the file
          if(strstr(words, steps) != NULL){ 
                                           sscanf(words,"%s %s %s",&NSWVASP[0],&NSWVASP[1],&NSWVASP[2]);
                                            }
          if(strstr(words, initial) != NULL){ 
                                            mark=2;
                                            }
          if(mark == 2 && strstr(words, probel) != NULL && (argc>1)){number=0;
                                            mark=1;
                                            nmf = fopen("result.txt","a");
                                            fprintf(nmf,"          amount of atoms = %d \n",natoms);
                                            fprintf(nmf,"|_____________________________________|\n");
                                            fprintf(nmf,"\n");
                                            fclose(nmf);

                                            // work with 6 string in POSCAR
                                            istr = strtok(elem,sep);
                                            q=0;
                                            while(istr != NULL){
                                            sscanf(istr,"%s",&elements[q]);
                                            
                                            for(i=1;i<argc;i++){  
                                            if(strcmp(argv[i], &elements[q])==0){
                                                  //printf("YES! %s\n",&elements[q]);
                                                  nakopitel[i]=q;
                                                  begi=sumArr(amount,0,nelem)-sumArr(amount,q,nelem);
                                                  begi=begi+1;
                                                  endi=sumArr(amount,0,q+1);

                                                   for(i=begi;i<endi;i++){
                                                   sprintf(&simb[0],"%d", i);
                                                   sprintf(&sign[0],"%s", "pathways/");
                                                   char *temp=strcat(&sign[0],&simb[0]);
                                                   temp=strcat(temp,".vasp");
                                                   nmf = fopen(temp,"w");
                                                   prHeader(nmf,&name[0],coef,POSCARd,3,&elements[q],&NSWVASP[2]);
                                                   fclose(nmf);
                                                                          }
                                                                                 }
                                     //else{pe=1;}
                                                                }


                                            //printf("%d | %s\n",q,&elements[q]);
                                            istr = strtok(NULL,sep);
                                            q++;
                                                                }
                                          //  if(pe==1){
                                          //            printf("p = %d \n There no such elements in POSCAR. Please try another word!\n",pe);
                                          //            }

                                                         }


          if(mark == 2 && strstr(words, probel) != NULL && (argc==1)){number=0;
                                            mark=1;
                                            nmf = fopen("result.txt","a");
                                            fprintf(nmf,"          amount of atoms = %d \n",natoms);
                                            fprintf(nmf,"|_____________________________________|\n");
                                            fprintf(nmf,"\n");
                                            fclose(nmf);

                                            // work with 6 string in POSCAR
                                            istr2 = strtok(elem,sep);
                                            printf("istr = %s\n",istr2);
                                            q=0;
                                               while(istr2 != NULL)
                                               {
                                                  sscanf(istr2,"%s",&allelem[q]);

                                                  begi=sumArr(amount,0,nelem)-sumArr(amount,q,nelem);
                                                  begi=begi+1;
                                                  endi=sumArr(amount,0,q+1);

                                                  for(i=begi;i<=endi;i++){
                                                  sprintf(&simb[0],"%d", i);
                                                  sprintf(&sign[0],"%s", "pathways/");
                                                  char *temp=strcat(&sign[0],&simb[0]);
                                                  temp=strcat(temp,".vasp");
                                                  nmf = fopen(temp,"w");
                                                  prHeader(nmf,&name[0],coef,POSCARd,3,&allelem[q],&NSWVASP[2]);
                                                  fclose(nmf);
                                                                 }

                                                  //printf("%d | %s\n",i,&allelem[q]);
                                                  istr2 = strtok(NULL,sep);
                                                  q++;
                                               }

                                     

                                                         }





          if(mark == 2){
                        if(number>0){
                                             sscanf(words,"%lf %lf %lf",&CIY[number-1][0],&CIY[number-1][1],&CIY[number-1][2]);
                             }
                                             natoms=number;
                                             addition=natoms+2;                                             
                                             number++;
                       }

          if(strstr(words, start) != NULL){ 
                                            mark=3;
                                            item++;
                                                        }
          if((strstr(words, finish) != NULL)){
                       //  nmf = fopen("result.txt","a");
                         //fprintf(nmf, "Iteration (%d)   \n", item);
                         //printArray(nmf,TEMP, natoms);
                         //fclose(nmf);
                         mark = 1;//include reading the text only
                         number=0;




                             //since first iteration and later: we will keep distance into R-massiv only
                             for(i=0;i<natoms;i++){
                                  R[i]=distance(CIY[i][0],CIY[i][1],CIY[i][2],TEMP[i][0],TEMP[i][1],TEMP[i][2]);
                                  LA[i]=LA[i]+R[i];
                                  //fprintf(nmf,"   d = %lf    length = %lf  \n",R[i],LA[i]);
                                                  }

                                  fprintf(nmf,"\n");

                       //  fclose(nmf);


                             //copy TEMP-data to CIY-massiv
                             for(i=0;i<natoms;i++){
                                          for(j=0;j<3;j++){
                                               CIY[i][j]=TEMP[i][j];  
                                                          }
                                                  }
                                            //printf("Iteration(%d) \n",item);
                                            //printArrSc(CIY, natoms);
                                            //printArrSc(CIY, natoms);

                         //             }  


                                              }



          if((mark == 3) && (number < addition)){
                                             if(number>1){
                                             sscanf(words,"%lf %lf %lf",&TEMP[number-2][0],&TEMP[number-2][1],&TEMP[number-2][2]);

                                             if(argc==1){
                                            sprintf(&simb[0],"%d", number-1);
                                            sprintf(&sign[0],"%s", "pathways/");
                                            char *temp=strcat(&sign[0],&simb[0]);
                                            temp=strcat(temp,".vasp");
                                            nmf = fopen(temp,"a");
                                            fprintf(nmf,"  %lf  %lf  %lf\n",TEMP[number-2][0],TEMP[number-2][1],TEMP[number-2][2]);
                                            fclose(nmf);
                                                        }


                                             if((argc>1) && (begi<=number-1) && (endi>=number-1)){
                                            //if(argc>1){
                                            //for(j=1;j<argc;j++){
                                            //q=nakopitel[j];
                                           //if(q>0){
                                            //begi=sumArr(amount,0,nelem)-sumArr(amount,q,nelem);
                                            //begi=begi+1;
                                            //endi=sumArr(amount,0,q+1);

                                            //for(i=begi;i<endi;i++){
                                            sprintf(&simb[0],"%d", number-1);
                                            sprintf(&sign[0],"%s", "pathways/");
                                            char *temp=strcat(&sign[0],&simb[0]);
                                            temp=strcat(temp,".vasp");
                                            nmf = fopen(temp,"a");
                                            fprintf(nmf,"  %lf  %lf  %lf\n",TEMP[number-2][0],TEMP[number-2][1],TEMP[number-2][2]);
                                            fclose(nmf);
                                            //                       }
                                            //       }
                                            //                   }
                                                        }



                                                         }

                                             number++;           
                                                 }


           line++;
          //printf("%d step | %d line\n",number, line);
                                     }



    //close the OUTCAR-file
    fclose(fp);

    nmf = fopen("result.txt","a");
    fprintf(nmf,"\n");
    fprintf(nmf,"        amount of iterations = %d \n",item);
    fprintf(nmf,"\n");
    fprintf(nmf,"  path length of each atoms (Angst): \n");
    fprintf(nmf,"\n");

         for(i=0;i<natoms;i++){
                 fprintf(nmf,"  %d  %lf \n",i+1,LA[i]);
                         }   

    fprintf(nmf,"\n");
    fclose(nmf);


    //for(i=1;i<natoms+1;i++){
    //sprintf(&simb[0],"%d", i);
    //sprintf(&sign[0],"%s", "pathways/");
    //char *temp=strcat(&sign[0],&simb[0]);
    //temp=strcat(temp,".vasp");
    //nmf = fopen(temp,"a");
    //prHeader(nmf,&name[0],coef,POSCARd,3);
    //fclose(nmf);
    //                       }

return 0;
}
