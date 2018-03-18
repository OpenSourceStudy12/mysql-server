#include <iostream>
#include <mysql/mysql.h>

using namespace std;

int main()
{
	MYSQL mysql;
	if(mysql_init(&mysql))
		cout << "init" << endl;
	if(mysql_real_connect(&mysql,"localhost","root","123456","studb1",0,NULL,0))
		cout << "connect" << endl;
		
	if(!mysql_query(&mysql,"select * from stuinfo"))
		cout << "select" << endl;
		
	MYSQL_RES *res=mysql_store_result(&mysql);
	if(res!=NULL)
		cout << "result" << endl;
	
	int rows=mysql_num_rows(res);
	int fields=mysql_num_fields(res);
	cout << rows << "  " << fields << endl;
	
	int i=0;
	int j=0;
	MYSQL_ROW row;
	for(i=0;i<rows;i++)
	{
		row=mysql_fetch_row(res);
		for(j=0;j<fields;j++)
		{
			cout << row[j] << "  ";
		}
		cout << endl;
	}
	
	mysql_close(&mysql);
	
	
	//if(!mysql_query(&mysql,"insert into stuinfo values(1004,'abc','1992-01-03','12345678')"))
		//cout << "insert" << endl;
	
	#if 0
	string id;
	string name;
	cout << "id:";
	cin >> id;
	cout <<  "name:";
	cin >> name;
	
	string str="update stuinfo set name='"+name+"' where id="+id;
	cout << str << endl;
	
	if(!mysql_query(&mysql,str.c_str()))
		cout << "update" << endl;
	#endif
}
