#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
typedef double dd;

int main(){
	dd x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	dd x3,y3,x4,y4;
	cin>>x3>>y3>>x4>>y4;
	dd a1 = (y2 - y1);
	dd b1 = (x1 - x2);
	dd c1 = a1*x1 + b1*y1;

	dd a2 = (y4 - y3);
	dd b2 = (x3 - x2);
	dd c2 = a2*x2 + b2*y2;

	dd dx = b2*c1 - b1*c2;
	dd dy = a2*c1 - a1*c2;

	dd d = a1*b2 - a2*b1;
	if(d == 0){
		cout<<"parallel lines\n";
	}



	double x = dx/d;
	double y = -1*dy/d;

	cout<<x<<" "<<y<<endl;
} 