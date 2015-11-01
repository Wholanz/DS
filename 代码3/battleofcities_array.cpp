#include <stdio.h>
#include <string.h>

#define INF 99999

int city[1000][1000];
/*An array to store the highways'status.0 stands for nosuch a highway;
1 stands for it is connected and not destroyed;
n stands for a destroyed highway costing n-1 to rebuild*/
int N,M;

int getmincost(int n){//An algorithm based on prim algorithm, it returns the cost to rebuild the connection after losing city n.
	int i,j,mincost,minvertex,start;
	int lowcost[1000],know[1000];
	int result=0;

	start=(n==0)?1:0;//Set the first vertex of the minimum spanning tree
	memset(know,0,1000*sizeof(int));

	know[start]=1;
	know[n]=1;

	for(i=0;i<N;i++)//initialization of other vertice
		lowcost[i]=city[start][i];
	for(i=0;i<N-2;i++){
		mincost=INF;
		for(j=0;j<N;j++){//find the closest vertex to the tree
			if(lowcost[j] && lowcost[j]<mincost && !know[j]){
				mincost=lowcost[j];
				minvertex=j;
			}
		}
		if(mincost==INF)
			return INF;
		result+=mincost;//after finding,add its cost to theresult,and mark it known
		lowcost[minvertex]=0;
		know[minvertex]=1;
		for(j=0;j<N;j++){//update the information of remained vertice
			if(city[j][minvertex]<lowcost[j])
				lowcost[j]=city[j][minvertex];
			else if(!know[j] && !lowcost[j])
				lowcost[j]=city[j][minvertex];
		}
	}
	return result;
}



int main(){
	int i,j;
	int city1,city2,cost,status;
	int mincosts[1000];//these three variable are used to output
	int max;
	int same;

	while(scanf("%d",&N) && N){
		for(i=0;i<N;i++){
			for(j=0;j<N;j++)
				city[i][j]=INF;
		}
		scanf("%d",&M);

		for(i=0;i<M;i++){
			scanf("%d%d%d%d",&city1,&city2,&cost,&status);//read the graph.The rules are at the beginning of this file
			if(status)
				city[city1-1][city2-1]=city[city2-1][city1-1]=1;
			else
				city[city1-1][city2-1]=city[city2-1][city1-1]=cost+1;
		}

		max=0;
		same=1;
		for(i=0;i<N;i++){
			mincosts[i]=getmincost(i);//get the maxmun of the least cost if we lose a city
			if(mincosts[i]>max)
				max=mincosts[i];
		}

		if(max==N-2)
			printf("0\n");//if the mincosts are all the same,print "0"
		else{
			j=1;
			for(i=0;i<N;i++){//print the maxnum(if there are more than one ,print like this: city1 city2 city3...)
				if(mincosts[i]==max)
					if(j){
						printf("%d",i+1);
						j=0;
					}
					else
						printf(" %d",i+1);
			}
			printf("\n");
		}
	}
	return 0;
}