using namespace std;
#include<iostream>
#include<stack>
#define MAX 20
#define endl '\n'
/*
测试数据：
输入n和m的值：10 10
输入一个n*m大小的迷宫：
##########
#+##+++#E#
#++++++#+#
#++++#+++#
####+##+##
#++++++++#
#+##+++#+#
#++#+++#+#
#S+#++#++#
##########
*/
struct node {
	char sign;//足迹和标志 
	bool flag;//鉴别是否到达过 
	int x;//坐标 
	int y;
};
class Maze {
	public:
		node maze[MAX][MAX];
		int m, n;
		Maze();//初始化迷宫
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
			maze[i][j].flag = false;//初始化为所有位置都没有到达过 
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
	//判断北南西东四个方向有无可走方块即方块标志为+号且没有到达过 
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
	stack<node> s;//本例子使用栈，采用深度搜索不讨论最短路径，到达终点即可 
	s.push(m.findingStart());
	while (s.top().sign!= 'E') {
		//当发现方块没有下一个可走方块时进行回溯即弹栈 
		if (m.moving(s.top()).sign == '*') {
			m.maze[s.top().x][s.top().y].sign = '+';
			s.pop();
		}
		//有可走方块入栈 
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
