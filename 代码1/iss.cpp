
void iss(int n,int p[],int m){
	
	int i;
	for (i=0;i<n;i++){
		if(m==p[i]) {
			printf("find and its number is %d\n",i+1); /* if the aim is found,print its position */
			return;
		}
	}
	
	return;

}
