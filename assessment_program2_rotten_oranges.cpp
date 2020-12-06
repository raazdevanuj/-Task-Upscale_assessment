#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int valid(int x,int y,int r,int c){
        if(x<0||x>=r||y<0||y>=c) return false;
        return true;
}
void orangesRotting(vector<vector<int>>& arr) {
        if(arr.size()==0) {
        	cout<<"time frames: 0"<<endl;
			cout<<"fresh oranges: 0"<<endl;
			cout<<"Rotten oranges: 0"<<endl;
				return;
		}	
        queue<pair<int,pair<int,int>>>q;
        int r=arr.size(),c=arr[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]==2)
                {
                    q.push(make_pair(0,make_pair(i,j)));
                }
            }
        }
        int d_x[]={-1,1,0,0};
        int d_y[]={0,0,-1,1};
        int ans=0;
        while(!q.empty()){
            pair<int,pair<int,int>>p=q.front();q.pop();
            int depth=p.first;
            int i=p.second.first;
            int j=p.second.second;
            ans=max(ans,depth);
            for(int k=0;k<4;k++){
                int x=i+d_x[k];
                int y=j+d_y[k];
                if(valid(x,y,r,c)&& arr[x][y]==1){
                    q.push(make_pair(depth+1,make_pair(x,y)));
                    arr[x][y]=2;
                }
            }   
        }
        int fresh_oranges=0,empty_cell=0;
         for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]==1)
                {
                 fresh_oranges++;
                }
                if(arr[i][j]==0){
                	empty_cell++;
				}
            }
        }
        	cout<<"time frames: "<<ans<<endl;
			cout<<"fresh oranges: "<<fresh_oranges<<endl;
			cout<<"Rotten oranges: "<<(r*c)-fresh_oranges-empty_cell<<endl;
    }
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> arr;
	for(int i=0;i<n;i++)
	{
		vector<int>vec;
		for(int j=0;j<m;j++){
			int x; cin>>x;
			vec.push_back(x);
		}
		arr.push_back(vec);
	}
	orangesRotting(arr);
	return 0;
}
