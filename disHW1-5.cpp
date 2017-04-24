#include <iostream>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;



int main()
{
	
	int a[8]={0};
	a[6]=0;
	a[7]=22;
	for(int i=0; i<6; i++)
	  cin >> a[i];
	  
	bool flag=false;
	int b[28]={0};
	
	
	
	int count=0;
		for(int i=0; i<28; i++)
		  b[i]={0};
	
		for(int i=0; i<8; i++)
		{
			for(int j=0; j<8; j++)
			{
				if(i==j)
			  	  continue;
				b[count]=abs(a[i]-a[j]);
				  count++;	
			}
		}
	
	
		sort(b, b+28);
		for(int i=0; i<28; i++)
	  	  cout << i << " " << b[i] << "\n";
		cout << "\n";
	
	
	return 0;


	
}
