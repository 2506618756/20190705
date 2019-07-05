#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define STUDENTNUMBER 5
#define REFEREENUMBER 7
using namespace std;
struct Referees
{
    string name;
    string telephone;
    string address;
    double grades[STUDENTNUMBER];
}Referee[REFEREENUMBER];
struct Students
{
	string name;
	string college;
	string ID;
	double sum=0;
	double grades[REFEREENUMBER];
}student[STUDENTNUMBER];
bool compare(Students &first,Students &second)
{
	if( first.sum > second.sum )
	{
		return 1;
	}
	else 
	{
		return 0;
	}	
}
int main()
{
    int n = 0,k = 0;
    ifstream refereeinput,studentinput;
    ofstream Match("E:\Competition results.xlsx");
    refereeinput.open("E:\Refereeinformation.txt");
    if(!refereeinput.is_open())
    {
        cout << "Error: opening file fail" << endl;
        exit(1);
    }
    while(!refereeinput.eof() && n < REFEREENUMBER )
    {
        refereeinput >> Referee[n].name;
        refereeinput >> Referee[n].telephone;
        refereeinput >> Referee[n].address;
		while( k<STUDENTNUMBER )
		{
			refereeinput >> Referee[n].grades[k];
			k++;
		}
        n++;
        k = 0;
    }
    refereeinput.close();
	studentinput.open("E:\studentinformation.txt");
    if(!studentinput.is_open())
    {
        cout << "Error: opening file fail" << endl;
        exit(1);
    }
    while(!studentinput.eof() && k < STUDENTNUMBER )
    {
    	studentinput >> student[k].ID >> student[k].college >> student[k].name;
    	k++;
	}
    studentinput.close();
    cout << "下面是各裁判人员的个人信息："  << endl << endl; 
	for( int i=0; i<REFEREENUMBER; i++ )
	{
		cout << "姓名："       << Referee[i].name;
		cout << "  联系方式：" << Referee[i].telephone;
		cout << "  家庭地址：" << Referee[i].address;
		cout << endl;	
	}
	cout << endl << endl; 
	cout << "下面是各裁判人员的评分信息："  << endl << endl; 
	for( int i=0; i<REFEREENUMBER; i++ )
	{
		cout << Referee[i].name << endl;
		cout << "评分：";
		for( int k=0; k<STUDENTNUMBER; k++ )
		{
			cout << setw(8) << student[k].name;
			cout << setw(4) << Referee[i].grades[k];
		}
		cout << endl; 
	}
	cout << endl << endl;	
	for( int i=0; i<REFEREENUMBER; i++ )
	{
		for( int j=0; j<STUDENTNUMBER; j++ )
		{
			student[j].grades[i] = Referee[i].grades[j];
		}
	}
	for( int i=0; i<STUDENTNUMBER; i++ )
	{
		sort( student[i].grades , student[i].grades + REFEREENUMBER );
		for( int j=1; j<REFEREENUMBER-1; j++ )
		student[i].sum += student[i].grades[j];
		student[i].sum /= (REFEREENUMBER-2);
	}	
	sort( student , student + STUDENTNUMBER , compare );
	cout << "下面是各参赛选手的竞赛信息："  << endl << endl;
	cout << setw(4)  << "排名";
	cout << setw(8)  << "学号";
	cout << setw(12) << "学院";
	cout << setw(7)  << "姓名";
	cout << setw(8)  << "成绩" << endl;	
	for( int i=0; i<STUDENTNUMBER; i++ )
	{
		cout << setw(1)  << i+1;;
		cout << setw(14) << student[i].ID;
		cout << setw(10) << student[i].college;
		cout << setw(8)  << student[i].name;
		cout << setw(4)  << floor(student[i].sum) << endl;
	}
	cout  << endl << endl;
	cout  << "本次比赛的全场最高分是：" << student[0].sum  << "   分" << endl; 
	cout  << "恭喜本次比赛的冠军得主：" << student[0].name << " 同学" << endl;
	cout  << "下面让请为我们的冠军送上热烈的掌声！" << endl;
	cout  << "啪啪啪啪啪啪啪啪啪啪啪啪-----------"; 
	Match << setw(4)  << "排名";
	Match << setw(8)  << "学号";
	Match << setw(12) << "学院";
	Match << setw(7)  << "姓名";
	Match << setw(8)  << "成绩" << endl;
	for( int i=0; i<STUDENTNUMBER; i++ )
	{
		Match << setw(1)  << i+1;
		Match << setw(13) << student[i].ID;
		Match << setw(10) << student[i].college;
		Match << setw(8)  << student[i].name;
		Match << setw(4)  << floor(student[i].sum) << endl;
	}
    return 0;
}
