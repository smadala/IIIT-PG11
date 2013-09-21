/*
   Bracket Stabling

   No fancy story for this one.
   You would be given a string of curly braces i.e either an opening brace '{' or a closing bracket '}'.
    Which may or may not be stable. The definition of a stable string is:
    	
    	a. A NULL string is stable.
		b. If a string str is stable so would be {str}
			c. If two strings are stable than their concatenation would also be stable
			i.e. if str1 and str2 is stable then str1str2 is also stable.
				
			Some examples of Stable strings: {{}}, {}{} and {}
			Some examples of Un-Stable strings: {{ , }{ and {{}{

			You have to tell minimum number of actions needed to make a string stable.
			An action is to either replace an opening brace with a closing or vice-versa.

			Input Specification:

			There would be multiple test cases. Each line would be containing one input string.
			Each line/string would be a non-empty string
			and would be composed of only opening and closing braces '{' and '}' only.
			Any string can contain atmost 2000 braces and would be even in length.
			Last line would be containg one or more minus sign(-)
			your program should not process beyond that.
			Output Specification:

			For every input line you have to print the following line :

			n.(space)A

			where 'n' is the test case no (starting from 1) followed by a dot(.) then a single space 
			and the number of actions needed to make input string stable.
			Print a new-line character (\n) after each line.


			Sample Input:

			 

			{{}{
			{{
			{}
			----
			Sample Output:

			 

			1. 1
			2. 1
			3. 0

			Timelimit: 1s
   */
#include<iostream>
#include<string>
#include<stack>
using namespace::std;
int test=1;
void process(string in){
	//int left=0,right=0;
	stack<char> s;
	char t;

	for(string::iterator it=in.begin(); it!=in.end(); it++){
		if(*it == '{')
			s.push(*it);
		else{
			if(s.size() == 0) { s.push(*it); continue;}
			t=s.top();
			if( t == '{')
				s.pop();
			else
				s.push(*it);
	
		}
	}
	char f,n;
	int c=0;
	while(s.size() >0){ 
		f=s.top();
		s.pop();
		n=s.top();
		s.pop();
		if(f == n) c++;
		else c=c+2;
	}
     
		cout<< test <<". "<<c<<endl;
	test++;
}
int main(){
        string in;
	while(1){
		cin>>in;
		if( in.find('-',0) != string::npos)
			return 0;
		process(in);
	}
	return 0;
}
