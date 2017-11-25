#include <cstdio>
#include <iostream>

#define mod_value 1000000007

using namespace std;


void multiply(long long int F[2][2], long long int M[2][2])
{
  long long int x =  ((F[0][0]*M[0][0])%mod_value + (F[0][1]*M[1][0])%mod_value)%mod_value;
  long long int y =  ((F[0][0]*M[0][1])%mod_value + (F[0][1]*M[1][1])%mod_value)%mod_value;
  long long int z =  ((F[1][0]*M[0][0])%mod_value + (F[1][1]*M[1][0])%mod_value)%mod_value;
  long long int w =  ((F[1][0]*M[0][1])%mod_value + (F[1][1]*M[1][1])%mod_value)%mod_value;
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

void power(long long int F[2][2], long long int n)
{
  if( n == 0 || n == 1)
      return;
  long long int M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}


long long int modfib(long long int n)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  if (n == 1)
    return 2;
  if (n == 2)
    return 3;
  power(F, n-2);
  return (F[0][0]*3+F[0][1]*2)%mod_value;
}

int main()
{
	long long int T;
	cin >> T;
	for(int k=0;k<T;k++)
	{
		long long int num;
		cin >> num;
		cout << modfib(num) << endl;
	}
	return 0;
}
