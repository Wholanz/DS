


void ibs(int n,int p[],int m)
{   
	int n1=0,n2=n-1;
    while(n2>n1){                     /* loop before n2=n1 */
		         if(m>p[(n1+n2)/2]) n1=(n1+n2)/2+1;          
				 else if(m<p[n1+n2]/2) n2=(n1+n2)/2;
				 else {
					 printf("find and its number is %d\n",(n1+n2)/2+1);    /* if the aim is found,print its position and return */
					 return;
				 }

	}
   if(m==p[n1]) printf("find and its number is %d\n",n1+1);   /* if the aim is found,print its position */
   
	return;
}