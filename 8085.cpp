#include<iostream>
#include<string.h>
#include "try2.h"


using namespace std;

string a="00";
string b="00";
string c="00";
string d="00";
string e="00";
string h="00";
string l="00";
string m ;
string pc ;
string carry="00";
string *str = new string[4000];
int zero=0;



string decToHexa1(int n);
string decToHexa2(int n);
string add2(string num1,string num2);
string sub2(string num1,string num2);
void fill_in_address(string address);
void list_data(string address1,string address2);
int hex_to_decimal(string hexVal);
string decToHexa(int n);

void LDA(string address);
void LDAX(char registre);
void STA(string address);
void STAX(char registre);
void LXI(char registre,string data);
void LHLD(string address);
void SHLD(string address);
void XCHG();


void addd(char registre);
void sub(char registre);
void MVI(char registre,string data);
void MOV(char registre1,char registre2);
void INR(char registre);
void DCR(char registre);
void ADI(string data);
void SUI(string data);
void DAD(char registre);

void CMP(char registre);

int main()
{
	ins_store obj;

	string st_add;
	cout<<"Enter starting address"<<"\n";
	cin>>st_add;
	pc = st_add;
while(1)
{
	m=str[hex_to_decimal(sub2(h+l,"4000"))];
	cout<<pc<<" ";

	string instruction;
	cin>>instruction;
	if( !instruction.compare("ADD") ) {
	char registre;
	cin>>registre;
	obj.add_node(pc,"ADD",registre,"0000");
	addd(registre);
	pc=add2(pc,"0001");
	}


	else if( !instruction.compare("SUB") ) {
	char registre;
	cin>>registre;
	obj.add_node(pc,"SUB",registre,"0000");
	sub(registre);
	pc=add2(pc,"0001");
	}

	else if( !instruction.compare("MVI") ) {
	string data;
	char registre;
	cin>>registre;
	cin>>data;
	obj.add_node(pc,"MVI",registre,data);
	MVI(registre,data);
	pc=add2(pc,"0002");
	}

	else if( !instruction.compare("MOV") ) {
	char registre1;
	char registre2;
	cin>>registre1;
	cin>>registre2;
	//obj.add_node(pc,"MOV",registre,"0000");
	MOV(registre1,registre2);
	pc=add2(pc,"0001");
	}

	else if( !instruction.compare("ADI") ) {
	string data;
	cin>>data;
	obj.add_node(pc,"ADI",'0',data);
	ADI(data);
	pc=add2(pc,"0002");
	}

	else if( !instruction.compare("SUI") ) {
	string data;
	cin>>data;
	obj.add_node(pc,"SUI",'0',data);
	SUI(data);
	pc=add2(pc,"0002");
	}

	else if( !instruction.compare("INR") ) {
	char registre;
	cin>>registre;
	obj.add_node(pc,"INR",registre,"0000");
	INR(registre);
	pc=add2(pc,"0001");
	}

	else if( !instruction.compare("DCR") ) {
	char registre;
	cin>>registre;
	obj.add_node(pc,"DCR",registre,"0000");
	DCR(registre);
	pc=add2(pc,"0001");
	}

	else if( !instruction.compare("ADC") ) {
	char registre;
	cin>>registre;
	obj.add_node(pc,"ADC",registre,"0000");
	addd(registre);
	a=add2(a,carry);
	pc=add2(pc,"0001");
	}

	else if( !instruction.compare("SBB") ) {
	char registre;
	cin>>registre;
	obj.add_node(pc,"SBB",registre,"0000");
	sub(registre);
	a=sub2(a,carry);
	pc=add2(pc,"0001");
	}

	else if( !instruction.compare("ACI") ) {
	string data;
	cin>>data;
	obj.add_node(pc,"ACI",'0',data);
	ADI(data);
	a=add2(a,carry);
	pc=add2(pc,"0002");
	}

	else if( !instruction.compare("SBI") ) {
	string data;
	cin>>data;
	obj.add_node(pc,"SBI",'0',data);
	ADI(data);
	a=sub2(a,carry);
	pc=add2(pc,"0002");
	}

	else if( !instruction.compare("LXI") ) {
	char registre;
	cin>>registre;
	string data;
	cin>>data;
	obj.add_node(pc,"LXI",registre,data);
	LXI(registre,data);
	pc=add2(pc,"0002");
	}

	else if( !instruction.compare("DAD") ) {
		char registre;
		cin>>registre;
		obj.add_node(pc,"DAD",registre,"0000");
		DAD(registre);
		pc=add2(pc,"0001");
	}

	else if( !instruction.compare("LDA") ) {
		string data;
		cin>>data;
		LDA(data);
		obj.add_node(pc,"LDA",'0',data);
		pc=add2(pc,"0003");
	}

	else if( !instruction.compare("STA") ) {
		string data;
		cin>>data;
		STA(data);
		obj.add_node(pc,"STA",'0',data);
		pc=add2(pc,"0003");
	}

	else if( !instruction.compare("LDAX") ) {
		char registre;
		cin>>registre;
		LDAX(registre);
		obj.add_node(pc,"LDAX",registre,"0000");
		pc=add2(pc,"0001");
	}

	else if( !instruction.compare("LHLD") ) {
		string data;
		cin>>data;
		LHLD(data);
		obj.add_node(pc,"LHLD",'0',data);
		pc=add2(pc,"0003");
	}

	else if( !instruction.compare("SHLD") ) {
		string data;
		cin>>data;
		SHLD(data);
		obj.add_node(pc,"SHLD",'0',data);
		pc=add2(pc,"0003");
	}

	else if( !instruction.compare("STAX") ) {
		char registre;
		cin>>registre;
			STAX(registre);
			obj.add_node(pc,"STAX",registre,"0000");
			pc=add2(pc,"0003");
		}

	else if( !instruction.compare("XCHG") ) {
			XCHG();
			obj.add_node(pc,"XCHG",'0',"0000");
			pc=add2(pc,"0001");
	}

	else if( !instruction.compare("CMP") ) {
		char registre;
		cin>>registre;
			//CMP(registre);
			obj.add_node(pc,"CMP",registre,"0000");
			pc=add2(pc,"0001");
	}


	else if( !instruction.compare("M") ) {
		string address;
		cin>>address;
		fill_in_address(address);
	}

	else if( !instruction.compare("L") ) {
		string data1;
		string data2;
		cin>>data1;
		cin>>data2;
		list_data(data1,data2);
	}


	else if( !instruction.compare("R") ) {
	cout<<"A-"<<a<<"-";cin>>a;
	cout<<"B-"<<b<<"-";cin>>b;
	cout<<"C-"<<c<<"-";cin>>c;
	cout<<"D-"<<d<<"-";cin>>d;
	cout<<"E-"<<e<<"-";cin>>e;
	cout<<"H-"<<h<<"-";cin>>h;
	cout<<"L-"<<l<<"-";cin>>l;
	cout<<"carry-"<<carry<<"\n";
	}




}

node* fetch_node=head;
while(fetch_node!=NULL)
{
		if(!fetch_node->address.compare(exe_address) )
		{
				string instruction=fetch_node->opcode;
				while(instruction!="g")
				{
						instruction=fetch_node->opcode;
						m=str[hex_to_decimal(sub2(h+l,"4000"))];

						if( !instruction.compare("ADD") ) {
						addd(fetch_node->operand1);
						}


					 	if( !instruction.compare("SUB") ) {
						char registre;
						cin>>registre;
						obj.add_node(pc,"SUB",registre,"0000");
						sub(registre);
						pc=add2(pc,"0001");
						}

						else if( !instruction.compare("MVI") ) {
						string data;
						char registre;
						cin>>registre;
						cin>>data;
						obj.add_node(pc,"MVI",registre,data);
						MVI(registre,data);
						pc=add2(pc,"0002");
						}

						else if( !instruction.compare("MOV") ) {
						char registre1;
						char registre2;
						cin>>registre1;
						cin>>registre2;
						//obj.add_node(pc,"MOV",registre,"0000");
						MOV(registre1,registre2);
						pc=add2(pc,"0001");
						}

						else if( !instruction.compare("ADI") ) {
						string data;
						cin>>data;
						obj.add_node(pc,"ADI",'0',data);
						ADI(data);
						pc=add2(pc,"0002");
						}

						else if( !instruction.compare("SUI") ) {
						string data;
						cin>>data;
						obj.add_node(pc,"SUI",'0',data);
						SUI(data);
						pc=add2(pc,"0002");
						}

						else if( !instruction.compare("INR") ) {
						char registre;
						cin>>registre;
						obj.add_node(pc,"INR",registre,"0000");
						INR(registre);
						pc=add2(pc,"0001");
						}

						else if( !instruction.compare("DCR") ) {
						char registre;
						cin>>registre;
						obj.add_node(pc,"DCR",registre,"0000");
						DCR(registre);
						pc=add2(pc,"0001");
						}

						else if( !instruction.compare("ADC") ) {
						char registre;
						cin>>registre;
						obj.add_node(pc,"ADC",registre,"0000");
						addd(registre);
						a=add2(a,carry);
						pc=add2(pc,"0001");
						}

						else if( !instruction.compare("SBB") ) {
						char registre;
						cin>>registre;
						obj.add_node(pc,"SBB",registre,"0000");
						sub(registre);
						a=sub2(a,carry);
						pc=add2(pc,"0001");
						}

						else if( !instruction.compare("ACI") ) {
						string data;
						cin>>data;
						obj.add_node(pc,"ACI",'0',data);
						ADI(data);
						a=add2(a,carry);
						pc=add2(pc,"0002");
						}

						else if( !instruction.compare("SBI") ) {
						string data;
						cin>>data;
						obj.add_node(pc,"SBI",'0',data);
						ADI(data);
						a=sub2(a,carry);
						pc=add2(pc,"0002");
						}

						else if( !instruction.compare("LXI") ) {
						char registre;
						cin>>registre;
						string data;
						cin>>data;
						obj.add_node(pc,"LXI",registre,data);
						LXI(registre,data);
						pc=add2(pc,"0002");
						}

						else if( !instruction.compare("DAD") ) {
							char registre;
							cin>>registre;
							obj.add_node(pc,"DAD",registre,"0000");
							DAD(registre);
							pc=add2(pc,"0001");
						}

						else if( !instruction.compare("LDA") ) {
							string data;
							cin>>data;
							LDA(data);
							obj.add_node(pc,"LDA",'0',data);
							pc=add2(pc,"0003");
						}

						else if( !instruction.compare("STA") ) {
							string data;
							cin>>data;
							STA(data);
							obj.add_node(pc,"STA",'0',data);
							pc=add2(pc,"0003");
						}

						else if( !instruction.compare("LDAX") ) {
							char registre;
							cin>>registre;
							LDAX(registre);
							obj.add_node(pc,"LDAX",registre,"0000");
							pc=add2(pc,"0001");
						}

						else if( !instruction.compare("LHLD") ) {
							string data;
							cin>>data;
							LHLD(data);
							obj.add_node(pc,"LHLD",'0',data);
							pc=add2(pc,"0003");
						}

						else if( !instruction.compare("SHLD") ) {
							string data;
							cin>>data;
							SHLD(data);
							obj.add_node(pc,"SHLD",'0',data);
							pc=add2(pc,"0003");
						}

						else if( !instruction.compare("STAX") ) {
							char registre;
							cin>>registre;
								STAX(registre);
								obj.add_node(pc,"STAX",registre,"0000");
								pc=add2(pc,"0003");
							}

						else if( !instruction.compare("XCHG") ) {
								XCHG();
								obj.add_node(pc,"XCHG",'0',"0000");
								pc=add2(pc,"0001");
						}

						else if( !instruction.compare("CMP") ) {
							char registre;
							cin>>registre;
								//CMP(registre);
								obj.add_node(pc,"CMP",registre,"0000");
								pc=add2(pc,"0001");
						}

						fetch_node=fetch_node->next;
				}

		}





}
}


string add2(string num1,string num2)
{
if(num1.length()==2 && num2.length()==2) {  int a=hex_to_decimal(num1);
int b=hex_to_decimal(num2);
int c=a+b;
if(c>255){c=c-256;carry="01";}
else(carry="00");
if(c==0){zero=1;}
else(zero=0);
return decToHexa1(c); }
if(num1.length()==4 && num2.length()==4) {  int a=hex_to_decimal(num1);
int b=hex_to_decimal(num2);
int c=a+b;
return decToHexa2(c); }
}

string sub2(string num1,string num2)
{
if(num1.length()==2 && num2.length()==2){int a=hex_to_decimal(num1);
int b=hex_to_decimal(num2);
int c=a-b;
if(c<0){c=c+256;carry="01";}
else(carry="00");
if(c==0){zero=1;}
else(zero=0);
return decToHexa1(c);}
if(num1.length()==4 && num2.length()==4){int a=hex_to_decimal(num1);
int b=hex_to_decimal(num2);
int c=a-b;
return decToHexa2(c);}
}


int hex_to_decimal(string hexVal)
{
int len =hexVal.length();
int base = 1;
int dec_val = 0;
    for (int i=len-1; i>=0; i--)
    {
        if (hexVal[i]>='0' && hexVal[i]<='9')
        {
            dec_val += (hexVal[i] - 48)*base;
 	   base = base * 16;
        }
        else if (hexVal[i]>='A' && hexVal[i]<='F')
        {
            dec_val += (hexVal[i] - 55)*base;
            base = base * 16;
        }
    }
    return dec_val;
}

//for 8 bit data
string decToHexa1(int n)
{
    char hexaDeciNum[2]={'0', '0'};
    int i = 1;
    while(n!=0)
    {
        int temp  = 0;
        temp = n % 16;
        if(temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i--;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i--;
        }
          n = n/16;
   }
return hexaDeciNum;
}

//for 16 bit data

string decToHexa2(int n)
{
    char hexaDeciNum[4]={'0', '0', '0', '0'};
    int i = 3;
    while(n!=0)
    {
        int temp  = 0;
        temp = n % 16;
        if(temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i--;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i--;
        }
          n = n/16;
   }
return hexaDeciNum;
}



void addd(char registre)
{
	if(registre=='A'){a=add2(a,a);}
	else if(registre=='B'){a=add2(a,b);}
	else if(registre=='C'){a=add2(a,c);}
	else if(registre=='D'){a=add2(a,d);}
	else if(registre=='E'){a=add2(a,e);}
	else if(registre=='H'){a=add2(a,h);}
	else if(registre=='L'){a=add2(a,l);}
	else if(registre=='M'){a=add2(a,m);}
}

void sub(char registre)
{
	if(registre=='A'){a=sub2(a,a);}
	else if(registre=='B'){a=sub2(a,b);}
	else if(registre=='C'){a=sub2(a,c);}
	else if(registre=='D'){a=sub2(a,d);}
	else if(registre=='E'){a=sub2(a,e);}
	else if(registre=='H'){a=sub2(a,h);}
	else if(registre=='L'){a=sub2(a,l);}
	else if(registre=='M'){a=sub2(a,m);}
}

void MVI(char registre,string data)
{
	if(registre=='A'){a=data;}
	else if(registre=='B'){b=data;}
	else if(registre=='C'){c=data;}
	else if(registre=='D'){d=data;}
	else if(registre=='E'){e=data;}
	else if(registre=='H'){h=data;}
	else if(registre=='L'){l=data;}
	else if(registre=='M'){m=data;}
}

void MOV(char registre1,char registre2)
{
	if(registre1=='A')
	{
			if(registre2=='B'){a=b;}
			else if(registre2=='C'){a=c;}
			else if(registre2=='D'){a=d;}
			else if(registre2=='E'){a=e;}
			else if(registre2=='H'){a=h;}
			else if(registre2=='L'){a=l;}
			else if(registre2=='M'){a=m;}
	}

	else if(registre1=='B')
	{
			if(registre2=='A'){b=a;}
			else if(registre2=='C'){b=c;}
			else if(registre2=='D'){b=d;}
			else if(registre2=='E'){b=e;}
			else if(registre2=='H'){b=h;}
			else if(registre2=='L'){b=l;}
			else if(registre2=='M'){b=m;}
	}

	else if(registre1=='C')
	{
			if(registre2=='A'){c=a;}
			else if(registre2=='B'){c=b;}
			else if(registre2=='D'){c=d;}
			else if(registre2=='E'){c=e;}
			else if(registre2=='H'){c=h;}
			else if(registre2=='L'){c=l;}
			else if(registre2=='M'){c=m;}
	}

	else if(registre1=='D')
	{
			if(registre2=='A'){d=a;}
			else if(registre2=='B'){d=b;}
			else if(registre2=='C'){d=c;}
			else if(registre2=='E'){d=e;}
			else if(registre2=='H'){d=h;}
			else if(registre2=='L'){d=l;}
			else if(registre2=='M'){d=m;}
	}

	if(registre1=='E')
	{
			if(registre2=='A'){e=a;}
			else if(registre2=='B'){e=b;}
			else if(registre2=='C'){e=c;}
			else if(registre2=='D'){e=d;}
			else if(registre2=='H'){e=h;}
			else if(registre2=='L'){e=l;}
			else if(registre2=='M'){e=m;}
	}

	else if(registre1=='H')
	{
			if(registre2=='A'){h=a;}
			else if(registre2=='B'){h=b;}
			else if(registre2=='C'){h=c;}
			else if(registre2=='D'){h=d;}
			else if(registre2=='E'){h=e;}
			else if(registre2=='L'){h=l;}
			else if(registre2=='M'){h=m;}
	}

	else if(registre1=='L')
	{
			if(registre2=='A'){l=a;}
			else if(registre2=='B'){l=b;}
			else if(registre2=='C'){l=c;}
			else if(registre2=='D'){l=d;}
			else if(registre2=='E'){l=e;}
			else if(registre2=='H'){l=h;}
			else if(registre2=='M'){l=m;}
	}

	else if(registre1=='M')
	{
			if(registre2=='A'){l=a;}
			else if(registre2=='B'){l=b;}
			else if(registre2=='C'){l=c;}
			else if(registre2=='D'){l=d;}
			else if(registre2=='E'){l=e;}
			else if(registre2=='H'){l=h;}
			str[hex_to_decimal(sub2(h+l,"4000"))]=m;
	}

}

void INR(char registre)
{
			if(registre=='A'){a=add2(a,"01");}
			else if(registre=='B'){b=add2(b,"01");}
			else if(registre=='C'){c=add2(c,"01");}
			else if(registre=='D'){d=add2(d,"01");}
			else if(registre=='E'){e=add2(e,"01");}
			else if(registre=='H'){h=add2(h,"01");}
			else if(registre=='L'){l=add2(l,"01");}
			else if(registre=='M'){m=add2(m,"01");}
}

void DCR(char registre)
{
			if(registre=='A'){a=sub2(a,"01");}
			else if(registre=='B'){b=sub2(b,"01");}
			else if(registre=='C'){c=sub2(c,"01");}
			else if(registre=='D'){d=sub2(d,"01");}
			else if(registre=='E'){e=sub2(e,"01");}
			else if(registre=='H'){h=sub2(h,"01");}
			else if(registre=='L'){l=sub2(l,"01");}
			else if(registre=='M'){m=sub2(m,"01");}
}

void ADI(string data)
{
a=add2(a,data);
}

void SUI(string data)
{
a=sub2(a,data);
}

void LXI(char registre,string data)
{
	int x=hex_to_decimal(data);
	int y=x/256;
	int z=x%256;
	if(registre=='B'){b=decToHexa1(y);c=decToHexa1(z);}
	else if(registre=='D'){d=decToHexa1(y);e=decToHexa1(z);}
	else if(registre=='H'){h=decToHexa1(y);l=decToHexa1(z);}
}

void DAD(char registre)
{
	if(registre=='B'){ l=add2(l,c);h=add2(h,carry);h=add2(h,b); }
	else if(registre=='D'){l=add2(l,e);h=add2(h,carry);h=add2(h,d);}
	else if(registre=='H'){l=add2(l,l);h=add2(h,carry);h=add2(h,h);}

}


void LDA(string address)
{
	a=str[hex_to_decimal(sub2(address,"4000"))];
}

void STA(string address)
{
	str[hex_to_decimal(sub2(address,"4000"))]=a;
}

void LDAX(char registre)
{
	if(registre=='B'){a=str[hex_to_decimal(sub2(b+c,"4000"))];}
	else if(registre=='D'){a=str[hex_to_decimal(sub2(d+e,"4000"))];}
}

void LHLD(string address)
{
	l=str[hex_to_decimal(sub2(address,"4000"))];
	h=str[hex_to_decimal(sub2(address,"3FFF"))];
}

void SHLD(string address)
{
	str[hex_to_decimal(sub2(address,"4000"))]=l;
	str[hex_to_decimal(sub2(address,"3FFF"))]=h;
}



void STAX(char registre)
{
	if(registre=='B'){str[hex_to_decimal(sub2(b+c,"4000"))]=a;}
	else if(registre=='D'){str[hex_to_decimal(sub2(d+e,"4000"))]=a;}
	else if(registre=='H'){str[hex_to_decimal(sub2(h+l,"4000"))]=a;}
}

void XCHG()
{
	string temp;
	temp=h; h=d; d=temp;
	temp=d; d=e; e=temp;
}
/*
void CMP(char registre)
{
	if(registre=='A'){carry="00";zero=1;}
	else if(registre=='B'){if(decToHexa(a)>decToHexa(b))  {carry="00";zero=0;}  else if((decToHexa(a)=decToHexa(b)) {zero=1;}  else {carry="01";}}
	else if(registre=='C'){if(decToHexa(a)>decToHexa(c))  {carry="00";zero=0;}  else if((decToHexa(a)=decToHexa(c)) {zero=1;}  else {carry="01";}}
	else if(registre=='D'){if(decToHexa(a)>decToHexa(d))  {carry="00";zero=0;}  else if((decToHexa(a)=decToHexa(d)) {zero=1;}  else {carry="01";}}
	else if(registre=='E'){if(decToHexa(a)>decToHexa(e))  {carry="00";zero=0;}  else if((decToHexa(a)=decToHexa(e)) {zero=1;}  else {carry="01";}}
	else if(registre=='H'){if(decToHexa(a)>decToHexa(h))  {carry="00";zero=0;}  else if((decToHexa(a)=decToHexa(h)) {zero=1;}  else {carry="01";}}
	else if(registre=='L'){if(decToHexa(a)>decToHexa(l))  {carry="00";zero=0;}  else if((decToHexa(a)=decToHexa(l)) {zero=1;}  else {carry="01";}}

} */

void fill_in_address(string address)
{
  cout<<"Press Z to exit"<<"\n";
  while(1)
  {
  string data;
  cout<<address<<"-";
  cin>>data;
	if(!data.compare("Z")){return;}
	str[hex_to_decimal(sub2(address,"4000"))]=data;
  address=add2(address,"0001");
  }
}


void list_data(string address1,string address2)
{
  int n = hex_to_decimal(sub2(address2,address1));
  while(n!=-1)
  {
    cout<<address1<<"-"<<str[hex_to_decimal(sub2(address1,"4000"))]<<"\t";
    address1=add2(address1,"0001");
    n--;
  }
	cout<<"\n";
}
