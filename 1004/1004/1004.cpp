#include <stdio.h>
#include <stdlib.h>
#define mxn 1000;
#define mxm 10;
#define mxk 10000;
int i,j,k,m,n;
int v[1012];
int e[22000][3];
int dis;
int x,y,z;
int l;
char s[4];
int ans;
float min,mindis;
int mind,sum,flag;

int main(){
	void spfa(int t);
	scanf("%d%d%d%d",&n,&m,&k,&dis);
	l=0;
	for (i=0;i<k;i++){
		scanf("%s",s);
		if (s[0]!='G') x=atoi(s);else x=n+atoi(s+1);
		scanf("%s",s);
		if (s[0]!='G') y=atoi(s);else y=n+atoi(s+1);
		scanf("%d",&z);
		l++;
		e[l][0]=y;
		e[l][2]=v[x];
		e[l][1]=z;
		v[x]=l;
		l++;
		e[l][0]=x;
		e[l][2]=v[y];
		e[l][1]=z;
		v[y]=l;
	}
	min=1000*dis;mindis=0;
	ans=0;
	for (i=n+1;i<=n+m;i++) spfa(i);
	if (ans) printf("G%d\n%0.1f %0.1f",ans-n,mindis,min/n);else 
		printf("No Solution");
	scanf("%d");
	return 0;
}

void spfa(int t){

	int q[1013];
	int q_f[1013];
	int dist[1013];
	int rt,lt;
	int x,y,z;
	int i,j,k;
	
	for (i=1;i<=n+m;i++) dist[i]=dis+1;
	for (i=1;i<=n+m;i++) q_f[i]=1;
	q[0]=t;q_f[t]=0;dist[t]=0;
	lt=0;rt=1;
	while (lt<rt){
		x=v[q[lt]];
		while (x>0){
			y=e[x][0];
			if (e[x][1]+dist[q[lt]]<dist[y]){
				dist[y]=e[x][1]+dist[q[lt]];
				if (q_f[y]) {
					q[rt]=y;
					rt++;
					q_f[y]=0;
				}
			}
			x=e[x][2];
		}
		q_f[q[lt]]=1;
		lt++;
	}
	flag=1;sum=0;mind=dis;
	for (i=1;i<=n;i++){
		if (dist[i]<dis) sum+=dist[i];else { flag=0;break;}
		if (dist[i]<mind) mind=dist[i];
	}
	if (flag){
		if (mindis<mind||mindis==mind&&sum<min) {
			min=sum;
			ans=t;
			mindis=mind;
		}
	}
}
