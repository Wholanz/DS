
void rss(int i,int n,int p[],int m)
{   
    
	if(m==p[i]) {
         		printf("find and its number is %d\n",i+1);   /* if the aim is found,print its position */
                return;	
	}
	if(i+1>=n) {
             
                return;            /* return after all numbers has been searched */
	}
	rss(i+1,n,p,m);                /* recursion */
	return;
}