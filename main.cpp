#include<iostream>
#include<vector>
#include<string>
using namespace std;
int num;	//������
vector<string>pro;


struct PCB{
	string name;	//������
	PCB* ptr;	//����ָ��
	int time;	//Ҫ������ʱ��
	int priority;	//������
	string statue;	//״̬
}tem,pcb[20];


//�����ȼ��Ŷ�
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
//���ÿһ�����к�Ķ���
void print(PCB*p)
{
	printf("|-������-|-Ҫ������ʱ��-|-������-|-״̬-|\n");
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
	cout << "������̸�����";
	cin >> num;
	cout << "�����������������Ϣ(������ Ҫ������ʱ�� ������)��" << endl;
	PCB* head=new PCB;//ͷ�ڵ�
	PCB HEAD;
	head = &HEAD;
	for (int i = 0; i < num; ++i) {
		cin >> pcb[i].name;
		cin >> pcb[i].time;
		cin >> pcb[i].priority;
		pcb[i].statue = "R";
	}
	head = pcb;
	//��ʼ��
	cout << "\n		���̳�ʼ��״̬\n";
	queue(pcb);
	print(pcb);
	//����
	int index = 1;
	int fi = 0;
	while (fi != num) {
		while (head->time == 0)
			head = head + 1;
		printf("\nʱ�䣺��%dʱ�̡�|��ǰ���н���Ϊ��",index);
		cout << head->name << endl;
		print(pcb);//�����ǰ���̶�����Ϣ
		index++;
		pro.push_back(head->name);//�������м�¼
		head->priority -= 1;//��������
		head->time -= 1;
		if (head->time == 0) {
			head->statue = "E";
			fi++;
		}
		queue(pcb);//��������������
	}
	cout << "------------------------------------------------------------\n";
	cout << "���̵���˳��";
	for(int i=0;i<pro.size();++i){
		cout << pro[i] << " ";
	}
	cout << "\n------------------------------------------------------------\n";
	system("pause");
	return 0;
}
