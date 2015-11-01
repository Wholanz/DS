

void rbs(int n1,int n2,int p[],int m)
{   
    
	if(n1==n2) {       /* if the aim inequals the number left,print the position */
		if(m==p[n1]) {
			printf("find and its number is %d\n",n1+1);
			return;
		}
        else {         /* if the aim inequals the number left,return */
			
			return;
		}
	}
	if(m>p[(n1+n2)/2]) rbs((n1+n2)/2+1,n2,p,m);       /* choose the number letf according to the inequation relation  */
    else if(m<p[(n1+n2)/2]) rbs(n1,(n1+n2)/2,p,m);
	else printf("find and its number is %d",(n1+n2)/2);
	return;
}