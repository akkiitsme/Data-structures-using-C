#include<stdio.h>
void getarr(int[2][2]);
void putarr(int[2][2]);
int main(){
	int a[2][2],b[2][2],c[2][2];
	int r1,r2,c1,c2;
	int p1,p2,p3,p4,p5,p6,p7;
	printf("Enter 2x2 first matrix\n");
	getarr(a);
	printf("Enter 2x2 second matrix\n");
	getarr(b);
	
	p1= a[0][0] * (b[0][1] - b[1][1]);
	p2= (a[0][0] + a[0][1]) * b[1][1];
	p3= (a[1][0] + a[1][1] * b[0][0]);
	p4= a[1][1] * (b[1][0] - b[0][0]);
	p5= (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
	p6= (a[0][1] - a[1][1]) * (b[1][0]+b[1][1]);
	p7= (a[0][0] - a[1][0]) * (b[0][0]+b[1][1]);
	
	c[0][0] = p5 + p4 - p2 +p6;
	c[0][1] = p1 + p2;
	c[1][0] = p3 + p4;
	c[1][1] = p1 + p5 - p3 - p7;
	printf("......After Strassen multiplication.......\n");
	putarr(c);
	return 0;	
}
void getarr(int x[2][2]){
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
		printf("enter the value %d,%d :",i,j);	
		scanf("%d",&x[i][j]);
		}
	}	
}
void putarr(int x[2][2]){
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){	
		printf("%d ",x[i][j]);
		}
		printf("\n");
	}	
}
