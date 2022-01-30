#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

class Point{
public:
	double x,y;
};

class polygon{
public:
	Point* points;
	polygon(int npoints){
		points = new Point[npoints];
	} 
};


double area(polygon p,int n){
	double farea = 0;
	for(int i = 1;i < n- 1;i++){
		double x1 = p.points[i].x - p.points[0].x;
		double y1 = p.points[i].y - p.points[0].y;
		double x2 = p.points[i+1].x - p.points[0].x;
		double y2 = p.points[i+1].y - p.points[0].y;

		double cross_p = x1*y2 - y1*x2;
		farea += cross_p;
	}
	return abs(farea/2);
}

int main(){
	int n;
	cin>>n;
	polygon p(n);
	for(int i = 0;i < n;i++){
		cin>>p.points[i].x;
		cin>>p.points[i].y;
	}
	cout<<area(p,n)<<endl;
}
/*
4
1 1
1 5
5 5
5 1
op
16
*/