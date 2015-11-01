# include <stdio.h>
# include <time.h>
# include <stdlib.h>
# include <string.h>
# include "ibs.cpp"
# include "rbs.cpp"
# include "iss.cpp"
# include "rss.cpp"


clock_t start,stop;
double duration;

int main()  {
	         int n ,  *p , i , k ;
			 char s[10];                               /* used to store the name of the function typed in */
             printf("Input a total number :\n");       
			 scanf("%d",&n);                           /* input the scale of numbers tested */
			 p=(int *)malloc(n*sizeof(int));
			 for(i=0;i<n;i++) {
			                 p[i]=i+1;                 /* input numbers automatically from 0 to n-1 */
			 
			 }
			 printf("type in the repetition times you want:\n");
			 scanf("%d",&k);                           /* input the times of the function runs */
			 printf("type in the function:\n");
			 gets(s);
			 gets(s);                                  /* choose the function tested */
			 if(strcmp(s,"iss")==0){                   /* test iterative sequential search */
             start=clock();
			 for (i=0;i<k;i++)
             iss (n,p,n+1); 
             stop=clock();
             duration=((double)(stop-start))/CLK_TCK;
             }
			 else if(strcmp(s,"rss")==0){              /* test recursive sequential search */
             start=clock();   
			 for (i=0;i<k;i++)
             rss (0,n,p,n+1); 
             stop=clock();
             duration=((double)(stop-start))/CLK_TCK;
             }
			 else if(strcmp(s,"ibs")==0){              /* test iterative binary search */
             start=clock(); 
			 for (i=0;i<k;i++)
             ibs (n,p,n+1); 
             stop=clock();
             duration=((double)(stop-start))/CLK_TCK;
             }
			 else if(strcmp(s,"rbs")==0){              /* test recursive binary search */
             start=clock();    
			 for (i=0;i<k;i++)
             rbs (0,n-1,p,n+1); 
             stop=clock();
             duration=((double)(stop-start))/CLK_TCK;
             }
			 else printf("wrong input!");
			 printf("%d\n",stop-start);                /* print tick */
			 printf("duration= %lf\n",duration);       /* print total running time */
			 getchar();
   return 0;

}