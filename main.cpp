#include<iostream>
#include<vector>
#include<string>
using namespace std;
int num;	//进程数
vector<string>pro;


struct PCB{
	string name;	//进程名
	PCB* ptr;	//进程指针
	int time;	//要求运行时间
	int priority;	//优先数
	string statue;	//状态
}tem,pcb[20];


//按优先级排队
void queue(PCB* p) {
	for (int i = 0; i < num - 1; ++i) {
		for (int j = i+1; j < num ; ++j) {
			if (pcb[i].priority < pcb[j].priority&&pcb[j].statue!="E") {
				tem = pcb[i];
				pcb[i] = pcb[j];
				pcb[j] = tem;
			}
		}
	}
}
//输出每一次运行后的队列
void print(PCB*p)
{
	printf("|-进程名-|-要求运行时间-|-优先数-|-状态-|\n");
	for (int i = 0; i < num;++i) {
		cout <<"|-- "<< pcb[i].name <<" --|------ "<< pcb[i].time<<" ------|-- " << pcb[i].priority
			<<" --|-- "<< pcb[i].statue<<"--|\n";
		
	}
	cout << endl;
}
void te(PCB *p) {
	PCB  pcb ;
	PCB *pp = p;
	cout<<(pp + 2)->name;
	*p = pcb;
	cout << p->name;
}
int main() {
	cout << "输入进程个数：";
	cin >> num;
	cout << "依次输入各个进程信息(进程名 要求运行时间 优先数)：" << endl;
	PCB* head=new PCB;//头节点
	PCB HEAD;
	head = &HEAD;
	for (int i = 0; i < num; ++i) {
		cin >> pcb[i].name;
		cin >> pcb[i].time;
		cin >> pcb[i].priority;
		pcb[i].statue = "R";
	}
	head = pcb;
	//初始化
	cout << "\n		进程初始化状态\n";
	queue(pcb);
	print(pcb);
	//运行
	int index = 1;
	int fi = 0;
	while (fi != num) {
		while (head->time == 0)
			head = head + 1;
		printf("\n时间：第%d时刻。|当前运行进程为：",index);
		cout << head->name << endl;
		print(pcb);//输出当前进程队列信息
		index++;
		pro.push_back(head->name);//进程运行记录
		head->priority -= 1;//进程运行
		head->time -= 1;
		if (head->time == 0) {
			head->statue = "E";
			fi++;
		}
		queue(pcb);//进行优先数排列
	}
	cout << "------------------------------------------------------------\n";
	cout << "进程调度顺序：";
	for(int i=0;i<pro.size();++i){
		cout << pro[i] << " ";
	}
	cout << "\n------------------------------------------------------------\n";
	system("pause");
	return 0;
}
