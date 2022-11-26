#include<bits/stdc++.h>
using namespace std;

char arr[1000][1000];
bool visited[1000][1000];
int n;

bool is_valid(int x,int y){
	if(x<0||y<0||x>=n||y>=n) return false;
	if(visited[x][y]==1) return false;
	if(arr[x][y]=='T') return false;
	return true;
}
int BFS(int src_x,int src_y){
	stack<pair<int,int> > q;
	visited[src_x][src_y]=1;
	q.push(make_pair(src_x,src_y));
	int lv=0;
	
	while(!q.empty()){
		lv++;
		int q_size=q.size();
		while(q_size--){
			int x=q.top().first;
			int y=q.top().second;
			q.pop();
			int dx[]={-1,0,1,0};
			int dy[]={0,-1,0,1};
			for(int i=0;i<4;i++){
				if(is_valid(x+dx[i],y+dy[i])){
					if(arr[x+dx[i]][y+dy[i]]=='E') return lv;
					q.push(make_pair(x+dx[i],y+dy[i]));
					visited[x+dx[i]][y+dy[i]]=1;
				}
			}
		}
	}
}
int main(){
	cin>>n;
	int sx,sy;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			if(arr[i][j]=='S'){
				sx=i;
				sy=j;
			}
		}
	}
	cout<<BFS(sx,sy);
}
