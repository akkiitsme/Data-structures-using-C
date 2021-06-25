#include <bits/stdc++.h>
using namespace std;
int bitcount(long int x){
	int d=(log2(x)+1);
	int i;
	int count=0;
	int v=1;
	for (i=0;i<d;i++){
	if(i!=0){
	v=v<<1;
	}
	if((v&x)>0){ 
	count+=1;
	}
 }
 return count;
}

int main(){
	int k,x,y,i,a,b,m,n;
	int count=0,count2=0,count3=0;
	cin>>k;
	for(i=0;i<k;i++){
	cin>>x>>y;
	cin>>a>>b;
	cin>>m>>n;
		for(i=x;i<=y;i++){
		count+=bitcount(i);
		}
		for(i=a;i<=b;i++){
		count2+=bitcount(i);
		}
		for(i=m;i<=n;i++){
		count3+=bitcount(i);
		}		
	cout<<count<<endl;
	cout<<count2<<endl;
	cout<<count3<<endl;
	}
}
