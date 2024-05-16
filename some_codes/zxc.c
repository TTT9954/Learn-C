#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define MAX_INT	2147483647
// int odd_even(int num)
// {
// 	if(num % 2) return 1;
// 	else return 0;
// }

// int sum_ex1(int num)
// {
// 	int sum = 0;
// 	sum+=num;
// 	return sum;
// }

// float sum_ex2(float num)
// {
// 	float sum = 0;
// 	if(num == 0) return -1;
// 	sum += (float)(1/num);
// 	return (float)sum;
// }

int factorial(int num)
{
	int result = 1;
	for(int i = 1; i <= num; i++)
	{
		result *= i;
	}
	return result;
}

// int NumbPrime(int num)
// {
// 	int count = 0;
// 	for(int i = 1; i <= num; i++)
// 	{
// 		if(!(num % i)) count++;
// 	}
// 	if(count == 2) return 1;
// 	else return 0;
// }

// int num_inverse(int num)
// {
// 	int num_temp = num;
// 	int temp = 0;
// 	int inverse = 0;
// 	while(num_temp != 0)
// 	{
// 	   temp = (num_temp % 10);
// 	   inverse = inverse * 10 + temp;
// 	   num_temp /= 10;
// 	}
// 	if(num == inverse) return 1;
// 	else return 0;
// }

// int Fibonacci(int num)
// {
// 	if(num == 0) return 0;
// 	else if(num == 1) return 1;
// 	else return Fibonacci(num-1)+Fibonacci(num-2);
// }

// int factorial1(int num)
// {
// 	if(num == 0) return 1;
// 	else return 0;
// }

// int sum_digits(int num)
// {
// 	int sum = 0;
// 	uint8_t digit = 0;
// 	while(num != 0)
// 	{
// 		digit = num%10;
// 		sum += digit;
// 		num /= 10;
// 	}
// 	return sum;
// }

// int square_number(int num)
// {
// 	return num*num;
// }

// int armstrong_num(int num)
// {
// 	int temp_num = num;
// 	int digit = 0;
// 	int sum = 0;
// 	while(temp_num != 0)
// 	{
// 		digit++;
// 		temp_num/= 10;
// 	}
// 	temp_num = num;
// 	while(temp_num != 0)
// 	{
// 		sum+= pow(temp_num%10, digit);
// 		temp_num /= 10;
// 	}
// 	if(sum == num) return 1;
// 	else return 0;
// }

// int GCF(int a, int b)
// {
// 	int max = 0;
// 	if(a > b) return -1;
// 	for(int i = 1; i <= b; i++)
// 	{
// 		if((a%i == 0) && (b%i == 0))
// 		{
// 			if(i > max)
// 			{
// 				max = i;
// 			}

// 			else return 1;
// 		}
// 	}
// 	return max;
// }

// int LCF(int a, int b)
// {
// 	for(int i = 1; i <= MAX_INT; i++)
// 	{
// 		if((i % a == 0) && (i % b == 0))
// 		{
// 			return i;
// 		}
// 	}
// }


// pi = 4 * sigma(k, n)((-1)^k*(1/(2*k+1)))
float Pi_caculation(int k, int n, float a)
{
	float condition = (float)1/((float)(2*n+1));
	float sigma = 0;
	float pi = 0;
	while(condition >= a)
	{
		condition = (float)1/((float)(2*k+1));
		sigma += (float)pow(-1,k)*(float)(1/(float)(2*k+1));	
		k++;
	}
	pi = (float)(4 * sigma);
	return pi;
}
/// @brief 
/// @return pi = 4 * sigma(k, n)((-1)^k*(1/(2*k+1)))

// e^x = sigma(0, n)(x^k/k!), stop condition |x^n/n!| <= a
float e_caculation(int k, double x, double a)
{
	double condition = (float)abs(pow(x,k)/(float)factorial(k));
	double sigma = 0;
	double result = 0;
	double xMuk = 0;
	double kGiaiThua = 0;
	while(condition >= a)
	{
		xMuk = (double)pow(x,k);
	    condition = (double)(xMuk/(double)factorial(k));
		sigma += (double)xMuk/(double)factorial(k);
		k++;
	}
	return sigma;
}

int main()
{
	// double a, x;
	// printf("Nhap x, a: ");
	// scanf("%lf%lf", &x, &a);
	
	// long long kGiaiThua = 1;
	// int k = 0;
	// double xMuK = 1;
	// double kq = 0;
	// double tam = xMuK / kGiaiThua;
	
	// while(tam >= a) {
	// 	kq += tam;
	// 	k++;
	// 	xMuK *= x;
	// 	kGiaiThua *= k;
	// 	tam = xMuK / kGiaiThua;
	// }
	
	//printf("e^%0.2lf = %lf", x, kq);
	printf("%0.2lf",  e_caculation(0, 2, 0.1));
    return 0;
}



