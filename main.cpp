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
    cout << "�����Ǹ�������Ա�ĸ�����Ϣ��"  << endl << endl; 
	for( int i=0; i<REFEREENUMBER; i++ )
	{
		cout << "������"       << Referee[i].name;
		cout << "  ��ϵ��ʽ��" << Referee[i].telephone;
		cout << "  ��ͥ��ַ��" << Referee[i].address;
		cout << endl;	
	}
	cout << endl << endl; 
	cout << "�����Ǹ�������Ա��������Ϣ��"  << endl << endl; 
	for( int i=0; i<REFEREENUMBER; i++ )
	{
		cout << Referee[i].name << endl;
		cout << "���֣�";
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
	cout << "�����Ǹ�����ѡ�ֵľ�����Ϣ��"  << endl << endl;
	cout << setw(4)  << "����";
	cout << setw(8)  << "ѧ��";
	cout << setw(12) << "ѧԺ";
	cout << setw(7)  << "����";
	cout << setw(8)  << "�ɼ�" << endl;	
	for( int i=0; i<STUDENTNUMBER; i++ )
	{
		cout << setw(1)  << i+1;;
		cout << setw(14) << student[i].ID;
		cout << setw(10) << student[i].college;
		cout << setw(8)  << student[i].name;
		cout << setw(4)  << floor(student[i].sum) << endl;
	}
	cout  << endl << endl;
	cout  << "���α�����ȫ����߷��ǣ�" << student[0].sum  << "   ��" << endl; 
	cout  << "��ϲ���α����Ĺھ�������" << student[0].name << " ͬѧ" << endl;
	cout  << "��������Ϊ���ǵĹھ��������ҵ�������" << endl;
	cout  << "žžžžžžžžžžžž-----------"; 
	Match << setw(4)  << "����";
	Match << setw(8)  << "ѧ��";
	Match << setw(12) << "ѧԺ";
	Match << setw(7)  << "����";
	Match << setw(8)  << "�ɼ�" << endl;
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
