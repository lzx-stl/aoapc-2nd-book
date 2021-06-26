#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<int> v[30], temp;
int pos[30];

//将x上方的木块归位 
void turn(int x){
	int u = pos[x];
	int len = v[u].size();
	for(int i = len - 1; ~i; i--){
		if(v[u][i] == x){
		    for(int j = i + 1; j < len; j++){
		        int k = v[u][j];
			    v[k].push_back(k);
			    pos[k] = k;
			}
			for(int j = i + 1; j < len; j++)	v[u].pop_back();
			break;
		}
	}
}

//把a放到b上 
void move(int a, int b){
	int x = pos[a], y = pos[b];
	int len = v[x].size();
	int k = v[x][len - 1];
	v[x].pop_back();
	v[y].push_back(k);
	pos[k] = y;
}

//把 a 及以上的木块坨到 b 上面 
void moveall(int a, int b){
	int x = pos[a], y = pos[b];
	int len = v[x].size();
	for(int i = len - 1; ~i; i--)
	{
		if(v[x][i] == a)
		{
			for(int j = i; j < len; j++){
				int t = v[x][j];		
				v[y].push_back(t), pos[t] = y;
			}
			for(int j = i; j < len; j++)	v[x].pop_back();
			break;
		}
	}
}


int main(){
	cin >> n;
	for(int i = 0; i < n; i++)	v[i].push_back(i), pos[i] = i;
	string op1, op2;
	while(cin >> op1 && op1 != "quit")
	{
		cin >> a >> op2 >> b;
		if(pos[a] == pos[b])    continue;
		if(op1 == "move")
		{
			if(op2 == "onto")
			{
				turn(a), turn(b);
				move(a, b);	 
			}
			else
			{
				turn(a);
				move(a, b);	
			} 
		}
		else
		{
			if(op2 == "onto")
			{
				turn(b);
				moveall(a, b);
			}
			else    moveall(a, b);	

		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << i << ":";
		for(int j = 0; j < v[i].size(); j++)
		{
			cout << " " << v[i][j];
		}
		cout << endl;
	}
    return 0;
}

