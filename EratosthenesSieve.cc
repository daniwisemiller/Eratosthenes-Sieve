/********************************
Danielle Wisemiller     CS 3610
Prof Liu                Project 1
*********************************/
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
	//file variables
	ifstream ins;
	string filename;
	cout<<"Enter the name of the input file: "<<endl;
	cin>>filename;
	//open file
	int n;
	ins.open(filename.c_str());
	//read file and run sieve
	int test;
	ins>>test;
	cout<<"Number of test cases: "<<test<<endl;
	while(ins>>n)
	{	
    	bool prime[n+1];
      	memset(prime, true, sizeof(prime));
      	for (int p=2; p*p<=n; p++)
      		{
          	  //if prime[p] is not changed --then it is a prime number
          		if (prime[p] == true)
          		{
              	  	//update all multiples of p in prime
              	  	for (int i=p*2; i<=n; i += p)
                  	  	prime[i] = false;
          	  	}
      	  	}
 
     	//print all prime numbers
      	for (int p=2; p<=n; p++)
        	 if (prime[p])
            	 cout << p << " ";
		//reset line for next input number
		cout<<endl;
 	}
  //close input file
  ins.close();
}