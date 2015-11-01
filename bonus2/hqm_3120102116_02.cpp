/* Author: Hu Liangze;  ID:3120102116;  No.02 */

#include <stdio.h>
#include <stdlib.h>

struct heap;
struct graph;
typedef struct graph *node;
typedef struct heap *heapnode;
struct heap{
	   int key;
	   int position;
	   int indegree;
};
struct graph{
	int key;
	int indegree;
};

int heapsize=0 , tablesize=0;



void insert(int i,node p,heapnode h){
	int now;
	if (p[i].key<0) return ;
	heapsize++;
	if(heapsize==1) {
		h[1].key=p[i].key;
		h[1].position=i;
		p[i].key=-1;

		return;
	}
	now=heapsize;
	while(h[now/2].key>p[i].key){
		h[now]=h[now/2];
		now/=2;
	}
	h[now].key=p[i].key;
	h[now].position=i;
    p[i].key=-1;
    return ;
}
int Delete(heapnode h){
	int temp,small,now=1,last=heapsize;
	temp=h[1].key;
	while(now*2<=heapsize){
	if(now*2+1>heapsize) small=now*2;
	else if((h[now*2]).key>(h[now*2+1]).key) small=now*2+1;
	else small=now*2;
	if(h[last].key<h[small].key) {
		h[now]=h[last];
		break;
	}
	else {
		h[now]=h[small];
			now=small;
	}
    }
	h[now]=h[last];
    heapsize--;
	return temp;
}
void reversehash(int n , node p){
    int i,temp;
    heapnode h;
	h=(heapnode) malloc(sizeof(struct heap)*(n+1));

    heapsize=0;
    for(i=0;i<n;i++){
		p[i].indegree=(i-(p[i].key)%n+n)%n;
		if(p[i].indegree==0) {
			insert(i,p,h);
		}
	}
    
		while(heapsize>0){
			temp=h[1].position;
			if(tablesize==1) printf("%d\n",Delete(h));
			else printf("%d ",Delete(h));
			tablesize--;
            for(i=0;i<n;i++){
				if (p[i].key>=0&&(i-(p[i].key)%n+n)%n>(temp-(p[i].key)%n+n)%n){
					if(--(p[i].indegree)==0)
						insert(i,p,h);
				}
			}
		}
            
   return ;		
}


int
main (){

        node p=NULL;
        int n=0 ,  tem=0 , i ;

	
        scanf("%d",&n);
        
		while(n>0){
			tablesize=0;
			p=(node)malloc(sizeof(struct graph)*n);
			for(i=0;i<n;i++){
              scanf("%d",&tem);
			  if(tem>=0){ 
				  tablesize++;			  
			  }
            p[i].key=tem;
			}
			reversehash(n,p);
			free(p);
			scanf("%d",&n);
		}
		return 0;
}

