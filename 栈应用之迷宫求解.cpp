using namespace std;
#include<iostream>
#include<stack>
#define MAX 20
#define endl '\n'
struct node {
	char sign;
	bool flag;
	int x;
	int y;
};
class Maze {
	public:
		node maze[MAX][MAX];
		int m, n;
		Maze();//初始化迷宫
		void footPrint();//留下足迹
		void print();//输出迷宫
		node moving(node nd);//移动
		node findingStart();//寻找起点
};
Maze::Maze() {
	cout << "请输入分别输入两个正整数n和m分别代表代表迷宫的长和宽：" << endl;
	cin >> n >> m;
	cout << "请输入一个"<<n<<"*"<<m<<"大小的迷宫(其中用#表示墙体，用+表示可行走的位置，用S表示起点，用E表示终点)：" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j].sign;
			maze[i][j].flag = false;
			maze[i][j].x = i;
			maze[i][j].y = j;
		}
	}
}
node Maze::findingStart() {
	 for(int i = 0; i < n; i++) {
		 for (int j = 0; j < m; j++) {
			 if (maze[i][j].sign == 'S')
				 return maze[i][j];
		 }
	 }
	 return maze[0][0];
}
node Maze::moving(node nd) {
	if (nd.x - 1 >=0&&maze[nd.x - 1][nd.y].flag == 0 && (maze[nd.x - 1][nd.y].sign == '+'||maze[nd.x - 1][nd.y].sign == 'E')) {
		return maze[nd.x - 1][nd.y];
	}
	if (nd.x+1<10&&maze[nd.x + 1][nd.y].flag == 0 && (maze[nd.x+1][nd.y].sign == '+'||maze[nd.x + 1][nd.y].sign == 'E')) {
		return maze[nd.x + 1][nd.y];
	}
	if (nd.y - 1 >= 0 && maze[nd.x][nd.y-1].flag == 0 && (maze[nd.x ][nd.y-1].sign == '+'||maze[nd.x ][nd.y-1].sign =='E')) {
		return maze[nd.x][nd.y-1];
	}
	if (nd.y + 1 < 10 && maze[nd.x][nd.y + 1].flag == 0 && (maze[nd.x][nd.y + 1].sign == '+'||maze[nd.x][nd.y + 1].sign == 'E')) {
		return maze[nd.x][nd.y + 1];
	}
	node a;
	a.sign = '*';
	return a;
}
void Maze::print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
				cout << maze[i][j].sign;
		}
		cout << endl;
	}
}
int main() {
	Maze m;
	m.findingStart();
	stack<node> s;
	s.push(m.findingStart());
	while (s.top().sign!= 'E') {
		if (m.moving(s.top()).sign == '*') {
			m.maze[s.top().x][s.top().y].sign = '+';
			s.pop();
		}
		else {
			if (s.top().sign == 'S') {
				s.push(m.moving(s.top()));
				m.maze[s.top().x][s.top().y].sign= '0';
			}
			else {
				char a = m.maze[s.top().x][s.top().y].sign;
				s.push(m.moving(s.top()));
				if(m.maze[s.top().x][s.top().y].sign!='E')
					m.maze[s.top().x][s.top().y].sign = '0'+(a-'0'+1)%10;
			}
			m.maze[s.top().x][s.top().y].flag=true;
		}
	}
	cout<<"从起点到达终点的路径如下："<<endl; 
	m.print();
	return 0;
}
