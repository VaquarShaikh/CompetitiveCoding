#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

struct Point{
	int x,y;
};

bool toChange(Point p,Point q,Point r){
	int x1 = p.x - q.x;
	int y1 = p.y - q.y;
	int x2 = r.x - q.x;
	int y2 = r.y - q.y;

	int value = x1*y2 - y1*x2;

	return value > 0;
}

void convexhull(Point points[],int n){
	vector<Point> hull;
	int left = 0;

	//leftmost
	for(int i = 1;i < n;i++){
		if(points[i].x < points[left].x){
			left = i;
		}
	}

	int p = left;
	do{
		hull.push_back(points[p]);
		int q = (p+1)%n;
		for(int i = 0;i < n;i++){
			if(toChange(points[p],points[q],points[i])){
				q = i;
			}
		}
		p = q;
	}while(p != left);
	for(int i = 0;i < hull.size();i++){
		cout<<hull[i].x<<" "<<hull[i].y<<endl;
	}
}

int main(){
	int n;
	cin>>n;
	Point points[n];
	for(int i = 0;i < n;i++){
		cin>>points[i].x;
	}
	for(int i = 0;i < n;i++){
		cin>>points[i].y;
	}
	convexhull(points,n);
}