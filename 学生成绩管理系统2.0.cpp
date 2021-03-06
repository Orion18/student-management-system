#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define N 10
#define Mi 3                  //方便后期改程序
int LZC=0;                    //定义全局变量并赋以初值,用来存放后来输入的数据的个数，最重要的作用是防伪作用
struct Student
{
	int number;
	char name[20];
	int cla;
	float score[3];
	float Average;
	float Sum;
}stu[N];
void printHello()  //输出欢迎界面，主要用来设置界面
{
	system("color f0");//设置前景色和背景色
	system("mode con cols=60 lines=25");//设置框体面积
	printf("**********************************\n");
	printf("*         欢迎进入               *\n*      学生成绩管理系统!         *\n");
	printf("**********************************\n");
	system("pause");//冻结屏幕
	system("CLS");//清屏
}
void inputRecord()//用来输入数据
{
	int i;
	for (i = 0; i<3; i++)
	{
		printf("学号:");scanf("%d", &stu[i].number);
		printf("班级:"); scanf("%d", &stu[i].cla);
		printf("姓名:");scanf("%s", &stu[i].name);
		printf("高数:");scanf("%f", &stu[i].score[0]);
		printf("英语:");scanf("%f", &stu[i].score[1]);
		printf("C语言:");scanf("%f", &stu[i].score[2]);
		stu[i].Sum = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]);        //计算总成绩
		printf("总成绩:%.2f", stu[i].Sum);
		stu[i].Average = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3;     //计算平均成绩
		printf("平均成绩:%.2f\n", stu[i].Average);
	}
}
void inputDate()  //后期输入数据
{
	int p,lzc; printf("需要输入几个数据？\n");scanf("%d", &LZC);
	lzc = LZC + 2;//计数器，后来输入的数据需从3开始计数
	printf("请输入数据!\n");
	for (p = 0; p < LZC; p++)
	{
		printf("学号:"); scanf("%d", &stu[lzc].number);
		printf("班级:"); scanf("%d", &stu[lzc].cla);
		printf("姓名:"); scanf("%s", &stu[lzc].name);
		printf("高数:"); scanf("%f", &stu[lzc].score[0]);
		printf("英语:"); scanf("%f", &stu[lzc].score[1]);
		printf("C语言:"); scanf("%f", &stu[lzc].score[2]);
	}
	printf("输入完成!\n");
}
void queryNum()//在query函数中按照学号查询
{
	void OutputOneDate(int i);
	int i, j, k, x;//j为计数器
	char c = '1';//定义循环的开关
	while (c == '1')//如果c为1，则继续循环
	{
		k = -1;
		printf("\n请输入学生学号:");
		scanf("%d", &x);
		for (i = 0, j = 1; i<Mi; i++)//将数据一一比对
			if (stu[i].number == x)//如果相等
			{
				k = i;//找到要查询的同学学号,并用k记下其下标
				printf("学生%d的信息:\n", j++);
				OutputOneDate(k);//输出数据
				printf("\n按任意键继续!\n");
				getchar();
			}
		printf("继续查询其他学生信息吗?");
		printf("\n继续查询请按1；不继续请按2\n");
		c = getchar();//如果c的值仍为1则继续循环
		getchar();
	}
	system("pause");
}
void queryName()//在query函数中按照姓名查询
{
	void OutputOneDate(int i);
	int i, j, k;
	char xname[20], c = '1';
	while (c == '1')
	{
		k = -1;
		printf("\n请输入学生姓名:");
		gets_s(xname);
		for (i = 0, j = 1; i<Mi; i++)//精确查询
			if (strcmp(stu[i].name, xname) == 0)
			{
				k = i;//找到要查询的同学姓名,并用k记下其下标
				printf("学生%d的信息:\n", j++);
				OutputOneDate(k);
				system("pause");
			}
		if (k == -1)//k表示没有精确查询结果
		{
			printf("\n模糊查询结果如下:\n");
			for (i = 0, j = 1; i<Mi; i++)//精确查询
				if (strstr(stu[i].name, xname) != NULL)//模糊查询
				{
					k = 1;
					printf("学生%d的信息:\n", j++);
					OutputOneDate(k);//输出数据
					printf("\n按任意键继续!\n");
					getchar();
				}
			if (j == 1)
				printf("\n抱歉!没有该学生信息!\n");//警告
		}
		printf("继续查询其他学生信息吗?");
		printf("\n继续查询请按1；不继续请按2\n");
		c = getchar();//如果c的值为1则继续循环
		getchar();
	}//结束while
	system("pause");
}
void query()                                                     //getRecord函数中查询学生信息
{
	printf("请选择查询方式:\n1.按照学号\n2.按照姓名\n");
	int i;
	scanf("%d", &i);//输入选择
	if (i == 1)queryNum();//按照学号查找
	else queryName();//按照姓名查找
}
int compareMax(float x, float y, float z)  //用来比较三个分数中的不及格的最大值
{
	float Z;
	if (x >= 60)x = 0; if (y >= 60)y = 0; if (z >= 60)z = 0;//如果该科及格,就让该科的值等于0
	if (x > y) Z = x;                                       //又因为实参形参的单项传递原来的值并不会改变
	else  Z = y;
	if (z > Z)Z = z;
	return Z;
}
int compareMaxS(float x, float y, float z)//比较三个分数的最大值
{
	float Z;//定义Z用来储存最大值
	if (x > y) Z = x;//如果x>y,Z=x
	else  Z = y;//否则Z=y
	if (z > Z)Z = z;//如果z>Z，Z=z，否则Z仍等于Z
	return Z;//返回Z
}
int compareDate(float x, float y,float z,float n)//分析浮点数n为哪一个数据
{
	int P;
	if (n == x)P = 0;//与第一个相等返回0
	else if (n == y)P = 1;//与第二个相等返回1
	else if(n==z)P = 2;//与第三个相等返回2
	else P = 3;//n与三个数都不相等则返回3
	return P;
}
int compareDateS(int x, int y, int z, int n)//分析整型n为哪一个数据
{
	int P;
	if (n == x)P = 0;//与第一个相等返回0
	else if (n == y)P = 1;//与第二个相等返回1
	else if(n==z) P = 2;//与第三个相等返回2
	else P = 3;//n与三个数都不相等则返回3
	return P;
}
int compareDateSS(char x[20], char y[20], char z[20],char n[20])//分析数组n为哪一个数组
{
	int P;
	if (n == x)P = 0;//与第一个相等返回0
	else if (n == y)P = 1;//与第二个相等返回1
	else if(n==z) P = 2;//与第三个相等返回2
	else P = 3;    //n与三个数都不相等则返回3
	return P;
}
void maxFlulk()                                                 //getRecord函数中查询最高分的不及格学生
{
	void OutputOneDate(int i);//声明输出函数
	printf("请选择学科:\n1.高数\n2.英语\n3.C语言\n");
	int i,M,P;
	scanf("%d", &i);//选择学科
	switch (i)
	{
	case 1:M = compareMax(stu[0].score[0], stu[1].score[0], stu[2].score[0]);//M为0都为及格
		if (M == 0) { printf("此科目没有不及格的"); break; }//M为0都为及格
		else P = compareDate(stu[0].score[0], stu[1].score[0], stu[2].score[0], M);//若M不等于0，将其与其他三个数比较
		OutputOneDate(P); break;//如果是第一个返回值为0
	case 2:M = compareMax(stu[0].score[1], stu[1].score[1], stu[2].score[1]);
		if (M == 0) { printf("此科目没有不及格的"); break; }//M为0都为及格
		else P = compareDate(stu[0].score[1], stu[1].score[1], stu[2].score[1], M);//若M不等于0，将其与其他三个数比较
		OutputOneDate(P); break;//如果是第一个返回值为0
	case 3:M = compareMax(stu[0].score[2], stu[1].score[2], stu[2].score[2]);
		if (M == 0) { printf("此科目没有不及格的"); break; }//M为0都为及格
		else P = compareDate(stu[0].score[2], stu[1].score[2], stu[2].score[2], M);//若M不等于0，将其与其他三个数比较
		OutputOneDate(P); break;//如果是第一个返回值为0
	default:printf("enter date error!!!");
	}
}
void getRecord()
{
	int i;
	printf("请选择功能:\n1.查询学生信息\n2.查找最高分的不及格学生\n");
	scanf("%d", &i);//选择
	if (i == 1)query();                                         //用来查询信息
	else maxFlulk();                                            //用来查找最高分的不及格学生
}
void changeNum()
{
    flag1:int Num1,Num2,i;
	printf("请输入要更改的学号:");
	scanf("%d", &Num1);
	printf("请输入更改后的学号:");
	scanf("%d", &Num2);
	i=compareDate(stu[0].number, stu[1].number, stu[2].number,Num1);//将输入的学号与存在的学号对比
	if (i == 0)stu[0].number=Num2;//将原来的数据更改为后来输入的数据
	else if(i==1)stu[1].number = Num2;//如果i为1，则需要修改第2个
	else if (i==2)stu[2].number = Num2;//如果i为2，则需要修改第3个
	else //否则返回三，表示未查找到该数据
	{ 
		printf("未查找到该学号！是否继续？\n1.继续 2.退出\n"); //没有查找到该数据则会警告
		int i; scanf("%d", &i); //选择
		if (i == 1) goto flag1;//重新运行
		else goto flag2; //退出
	}
	printf("修改完成！\n");
    flag2:system("pause");
}
void changeCls()
{
flag1:int Cla1,Cla2,i;
	printf("请输入要更改的班级:");
	scanf("%d", &Cla1);
	printf("请输入要更改的班级:");
	scanf("%d", &Cla2);
	i = compareDate(stu[0].cla, stu[1].cla, stu[2].cla, Cla1);
	if (i == 0)stu[0].cla = Cla2;//将原来的数据更改为后来输入的数据
	else if (i == 1)stu[1].cla = Cla2;//如果i为1，则需要修改第2个
	else if(i==2)stu[2].cla = Cla2;//如果i为2，则需要修改第3个
	else //否则返回三，表示未查找到该数据
	{ 
		printf("未查找到该班级！是否继续？\n1.继续 2.退出\n"); //没有查找到该数据则会警告
		int i; scanf("%d", &i); //选择
		if (i == 1) goto flag1;//重新运行
		else goto flag2; //退出
	}
	printf("修改完成！\n");
flag2:system("pause");
}
void changeName()
{
flag1:char Name1[20], Name2[20]; int i;
	printf("请输入要改变的名字:"); scanf("%s", Name1);
	printf("请输入改变后的名字:"); scanf("%s", Name2);
	i = compareDateSS(stu[0].name, stu[1].name, stu[2].name, Name1);//将三个成绩与输入的数据比对
	if (i == 0)strcpy(stu[0].name, Name2);//将原来的数据更改为后来输入的数据
	else if(i==1)strcpy(stu[1].name, Name2);//如果i为2，则需要修改第3个
	else if(i==2)strcpy(stu[2].name, Name2);//如果i为2，则需要修改第3个
	else//否则返回三，表示未查找到该数据
	{ 
		printf("未查找到该姓名！是否继续？\n1.继续 2.退出\n");//没有查找到该数据则会警告
		int i; scanf("%d", &i); //选择
		if (i == 1) goto flag1; //重新运行
		else goto flag2; //退出
	}
	printf("修改完成！\n");
flag2:system("pause");
}
void changeScore(int x)
{
flag1:int i; float score1, score2;
	printf("请输入要更改的成绩:");
	scanf("%f", &score1);//输入要更改的成绩
	printf("请输入更改后的成绩");
	scanf("%f", &score2);//输入更改后的成绩
	i = compareDate(stu[0].score[x], stu[1].score[x], stu[2].score[x], score1);//将三个成绩与输入的数据比对
	if (i == 0)stu[0].score[x] = score2;//将原来的数据更改为后来输入的数据
	else if (i == 1)stu[1].score[x] = score2;//如果i为2，则需要修改第3个
	else if (i == 2)stu[2].score[x] = score2;//如果i为2，则需要修改第3个
	else//否则返回三，表示未查找到该数据
	{ 
		printf("未查找到该姓名!是否继续？\n1.继续 2.退出\n"); //没有查找到该数据则会警告
		int i; scanf("%d", &i);//选择
		if (i == 1) goto flag1;//重新运行
		else goto flag2; //退出
	}
	printf("修改完成！\n");
flag2:system("pause");
}
void changeDate()            //用来修改已经输入的数据,不过只能修改第一批输入的数据
{
	int i;
	void exportRecord();
	exportRecord();
	printf("请选择需要修改的数据\n1.学号\n2.班级\n3.姓名\n4.高数成绩\n5.英语成绩\n6.C语言成绩\n");
	scanf("%d", &i);
	switch (i)
	{
	case 1:changeNum(); break;//更改学号
	case 2:changeCls(); break;//更改班级
	case 3:changeName(); break;//更改姓名
	case 4:changeScore(0); break;//"0"即为高数（在结构体中定义过）
	case 5:changeScore(1); break;//"1"即为英语（在结构体中定义过）
	case 6:changeScore(2); break;//"2"即为C语言（在结构体中定义过）
	default:printf("enter date error!\n");//报错
	}
}
void getAverage()//得到平均值
{
	float score1, score2, score3, score4;
	score1 = (stu[0].score[0] + stu[1].score[0] + stu[2].score[0]) / 3;//高数的平均值
	score2= (stu[0].score[1] + stu[1].score[1] + stu[2].score[1]) / 3;//英语的平均值
	score3= (stu[0].score[2] + stu[1].score[2] + stu[2].score[2]) / 3;//C语言的平均值
	score4 = (stu[0].score[0] + stu[1].score[0] + stu[2].score[0] + stu[0].score[1] + stu[1].score[1] + stu[2].score[1] + stu[0].score[2] + stu[1].score[2] + stu[2].score[2]) / 3;
	//总分的平均值
	printf("高数平均分:%.2f\n英语平均分:%.2f\nC语言平均分:%.2f\n总分平均分:%.2f\n",score1, score2, score3, score4);
}
void getOrder()//用来排序
{
	void OutputOneDate(int i);
	int i, j;//计数变量
	struct Student temp;//中间变量 类型为结构体
	if(stu[0].number>stu[1].number){temp=stu[0];stu[0]=stu[1];stu[1]=temp;}//交换数据
	if(stu[0].number>stu[2].number){temp=stu[0];stu[0]=stu[2];stu[2]=temp;}//交换数据
	if(stu[1].number>stu[2].number){temp=stu[1];stu[1]=stu[2];stu[2]=temp;}//交换数据
	printf("\n排序后的学生信息:\n");
	for (i = 0; i<Mi; i++)
	{
		OutputOneDate(i);
	}//输出排序后的学生信息
}
void deleteOnedate()//删除数据
{
flag1:int i,o;
	printf("请输入要删除信息的学生学号:"); scanf("%d", &i);
	o = compareDateS(stu[0].number, stu[1].number, stu[2].number, i);//用来比较输入的数据与已知的数据
	if (o == 0)
	{
		stu[0].number = stu[0].cla  = 0;//删除即将其值变为0
		stu[0].name[20] = ' ';//删除即将其值变为空
		stu[0].score[0] = stu[0].score[1] = stu[0].score[2] = stu[0].Sum = stu[0].Average = 0;//删除即将其值变为0
	}
	else if (o == 1)
	{
		stu[1].number = stu[1].cla = 0;//删除即将其值变为0
		stu[1].name[20] = ' ';//删除即将其值变为空
		stu[1].score[0] = stu[1].score[1] = stu[1].score[2] = stu[1].Sum = stu[1].Average = 0;//删除即将其值变为0
	}
	else if(o==2)
	{
		stu[2].number = stu[2].cla = 0;//删除即将其值变为0
		stu[2].name[20] = ' ';//删除即将其值变为空
		stu[2].score[0] = stu[2].score[1] = stu[2].score[2] = stu[2].Sum = stu[2].Average = 0;//删除即将其值变为0
	}
	else 
	{ 
		printf("未查找到该姓名！是否继续？\n1.继续 2.退出\n");//如果输入的数据没有查询到
		int i; scanf("%d", &i); //则可以选择
		if (i == 1) goto flag1; //继续运行
		else goto flag2; //或者退出
	}
	printf("修改完成！\n");//提醒
flag2:system("pause");//冻结屏幕
}
void updateRecord()//更新数据
{
	int i;
	printf("请选择功能:\n1.修改学生信息\n2.求学生的平均分\n3.按照学号排序\n4.插入学生成绩\n5.删除1个学生成绩\n");//提醒
	scanf("%d", &i);//输入选择的功能
	switch (i)
	{
	case 1:changeDate(); break;//修改数据
	case 2:getAverage(); break;//求平均值
	case 3:getOrder(); break;//排序
	case 4:inputDate(); break;//添加数据
	case 5:deleteOnedate(); break;//删除数据
	default:printf("enter date error!\n");//报错
	}
}
void printCount(float x,float y,float z)
{
	int i = compareMaxS(x, y, z),j=0; float max;//i,j为计数器
	if (i == 0)max = x;//如果i等于0，则说明最大值为x
	else if (i == 1)max = y;//或者为y
	else max = z;//否则为z
	if (x < 60)j++;if (y < 60)j++;if (z < 60)j++;//j负责计数
	printf("该科的最高分为%.2f,不及格人数为%d\n", max, j);//输出数据
}
void countRecord()
{
	printf("请选择要统计的科目:\n1.高数\n2.英语\n3.C语言\n");
	int i; scanf("%d", &i);i -= 1;//减一以对应结构体中中的数据
	switch (i)
	{
	case 0:printCount(stu[0].score[i], stu[1].score[i], stu[2].score[i]); break;//计算高数的最高分，不及格人数
	case 1:printCount(stu[0].score[i], stu[1].score[i], stu[2].score[i]); break;//计算英语的最高分，不及格人数
	case 2:printCount(stu[0].score[i], stu[1].score[i], stu[2].score[i]); break;//计算C语言的最高分，不及格人数
	default:printf("enter date error!!!\n");//警告
	}
}
void OutputOneDate(int i)//输出一个数据，需要传入一个整型
{
	printf("学号:%d  班级:%d  姓名:%s\n", stu[i].number, stu[i].cla, stu[i].name);
	printf("高数:%.2f  英语:%.2f  C语言:%.2f  总分:%.2f  平均分:%.2f\n", stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].Sum, stu[i].Average);
}
void exportRecord()//输出一系列数据，并将最终数据导入到"学生管理系统数据.txt"中
{
	int i;//计数器
	printf("**********************************\n");
	for (i = 0; i < 3+LZC; i++)OutputOneDate(i);//LZC为之前增加的数据个数
	printf("**********************************\n");
}
void exportRecord_s()//输出一系列数据，并将最终数据导入到"学生管理系统数据.txt"中
{
	int i;
	FILE *p;//定义指针指向文件
	p = fopen("学生管理系统数据.txt", "a");//用写入方式打开学生管理系统数据.txt
	printf("**********************************\n");
	for (i = 0; i < 3 + LZC; i++) 
	{
		OutputOneDate(i); 
		fprintf(p, "学号%d 班级%d 姓名%s 高数成绩%.2f 英语成绩%.2f C语言成绩%.2f 总分%.2f 平均分%.2f\n", stu[i].number, stu[i].cla, stu[i].name, stu[i].score[0], stu[i].score[1], stu[i].score[2], stu[i].Sum, stu[i].Average); 
	}//输出数据，并将数据导出到学生管理系统数据.txt
	printf("数据导出成功！可在【学生管理系统数据.txt】中查看数据!\n");//提醒
	printf("**********************************\n");
}
void choose()//选择菜单
{
	printf("**********************************\n");
	printf("*   请输入数字选择功能：         *\n");
	printf("*   1.运行输入记录模块           *\n*   2.运行查询记录模块           *\n*   3.运行更新记录模块           *\n*   4.运行统计记录模块           *\n*   5.运行输出记录模块           *\n*   6.清屏                       *\n*   7.注意事项                   *\n");
	printf("**********************************\n");
	int i;
	scanf("%d", &i);//输入选择
	switch (i)
	{
	case 1:inputRecord(); break;//输入记录模块
	case 2:getRecord(); break;//查询记录模块
	case 3:updateRecord(); break;//更新记录模块
	case 4:countRecord(); break;//统计记录模块
	case 5:exportRecord_s(); break;//输出记录模块
	case 6:system("CLS"); break;//清屏
	case 7:printf("\n\n1.后续输入的数据暂不可查询，如需更改需要重新输入。\n2.只有运行输出模块才能将数据导出。\n3.李宗宸版权所有，切勿抄袭！！！！\n\n"); break;//注意事项
	default:printf("There were some errors!\n");
	}
}
int main()//函数的主体
{
	printHello();//调用欢迎页面，调整版式
	int ON;char OFF;//定义开关
	while(true)
	{
		choose();//菜单函数
		printf("***************************\n*    是否继续？           *\n*    1.继续运行           *\n*    2.退出系统           *\n***************************\n");
		getchar();//输入字符
		OFF=getchar();//回车
		if(OFF=='1'||OFF=='2'){if(OFF=='2')break;}//如果输入的值为1或2，将进入第二层选择，如果OFF是2则退出死循环
		else printf("输入数据错误!!!将继续运行！！！\n");//如果输入其他则会提醒错误
		//如果只用scanf如果输入字符而不是数字则会崩溃😩
	}
}
