#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cmath>
int conv(char [],char);
using namespace std;

int main (int argc, char *argv[]){
	fstream archivo;
	char num1[10],num2[10],b1,b2;
	int n1,n2;
	archivo.open(argv[1],ios::in|ios::out);
	archivo.clear();
	archivo.seekg(0);
	while(archivo>>num1>>b1>>num2>>b2){
		n1=conv(num1,b1);
		n2=conv(num2,b2);
		cout<<num1<<" "<<b1<<" "<<num2<<" "<<b2;
		if(n1==n2)
			cout<<right<<setw(5)<<"="<<endl;
		else if(n1>n2)
				cout<<right<<setw(5)<<">"<<endl;
			 else
			 	cout<<right<<setw(5)<<"<"<<endl;
	}
	system("PAUSE");
}

int conv(char num[],char b){
	int base,tem,r=0,con;
	int lon=strlen(num)-1,x=lon;
	base=(int)b-48;
	while(x>=0){
		tem=(int)num[x]-48;
		con=pow(base,lon-x)*tem;
		r+=con;
		x--;
	}
	return r;
}
