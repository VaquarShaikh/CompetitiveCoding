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
	string s;
	cin>>s;
	int n = s.length();
	polygon p(n);
	p.points[0].x = 0;
	p.points[0].y = 0;

	for(int i = 1;i < n;i++){
		int temp;
		cin>>temp;
		if(s[i-1] == 'N'){
			p.points[i].y = p.points[i-1].y + temp;
			p.points[i].x = p.points[i-1].x;
		}else if(s[i-1] == 'E'){
			p.points[i].x = p.points[i-1].x + temp;
			p.points[i].y = p.points[i-1].y;
		}else if(s[i-1] == 'S'){
			p.points[i].y = p.points[i-1].y - temp;
			p.points[i].x = p.points[i-1].x;
		}else{
			p.points[i].x = p.points[i-1].x - temp;
			p.points[i].y = p.points[i-1].y;
		}
	}
	cout<<area(p,n)<<endl;
}