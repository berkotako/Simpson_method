#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float fonk_calc(int,float,int A[100]);
float simpson (float ,float ,int ,int ,int A[100]);
int main(int argc, char *argv[]) {
	//We must create dynamically coef but now let's assume that 
	//many people dont know how to do this (Search Dynamic Memory Allocation)
	int up_val,down_val,power,division,i;
	int coef[100]={0};
	int *coef_p = &coef;
	
	float func_val;
	
	printf("Please enter the up_val ");
	scanf("%d",&up_val);
	printf("\nPlease enter the down_val ");
	scanf("%d",&down_val);
	printf("\nPlease enter the division(Recomended: 1000+) \n");
	scanf("%d",&division);
	printf("\nPlease enter the power \n ");
	scanf("%d",&power);
	float h = (fabs(up_val-down_val)/division);

	for(i=0;i<=power;i++){
		printf("\nEnter the value of coefficient x^(%d) :",i);
		scanf("%d",coef_p+i);
	}
	
	func_val = simpson(down_val,h,up_val,power,coef);
	printf("\nValue of Integral : %f",func_val);
	system("PAUSE");
	
	return 0;

}
//simpson formula 
float simpson(float x,float h,int up,int us,int A[100]){
	float sum_simp;
	int counter=0;
	//F0 adding
	sum_simp = sum_simp + fonk_calc(us,x,A);
	while(x<up){
	  x=x+h;
	  ++counter;
	  //single values multiply by 4 and double values multiply by 2
		if(counter%2==1 && (counter != 0 || floor((int)x) != up )){
			sum_simp = sum_simp + 4*fonk_calc(us,x,A);
		}
		if(counter%2==0 && (counter != 0 || floor((int)x) != up )){
			sum_simp = sum_simp + 2*fonk_calc(us,x,A);
		}
		
	}
	//The end of (Fn) function adding
	sum_simp = sum_simp + fonk_calc(us,x,A);
	
	return (h/3)*sum_simp;
	
}
//Ýts calculate the value of function
float fonk_calc(int us,float x_0,int A[100]){
    	float sum = 0;
    	int b;
 	for(b=0;b<=us;b++){
    	sum = sum + A[b]*pow(x_0,b);
 	}
return sum;
}
