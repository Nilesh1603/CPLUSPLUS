// File: a1.cpp
// Nilesh
// Singh
#include<fstream>
#include<iostream>
#include<string>
#include<cmath>

int main(int argc,  char  *argv[]) {

int ss = std::stod(argv[2]);
std::fstream f(argv[1]);
std::string s1 ;
getline(f, s1);
int size = s1.size();
int  a ,c,g,t,n;
a=0;
c=0;
g=0;
t=0;
n=0;
std::string s2 ="";
std::string s3="";
for(int i =0; i < size ; i++)
{

  if(s1[i]=='A')
  { s2+='1';
  s3+='0';
   a++;
  }  if(s1[i]=='C')
  {
    s2+='2';
s3+='1';
    c++;

  }if(s1[i]=='G')
  {
    s2+='3';
s3+='2';
      g++;
  }if(s1[i]=='T')
  {s3+='3';
    s2+='4';
    t++;
  }if(s1[i]=='N')
  {
    s3+='4';
    s2+='0';
    n++;
  }

}

std::cout << 0 << " " << ss << " " << size <<  std::endl;
std::cout << 1 << " "<< a << " " << c << " " << g << " "<< t << " " << n << std::endl;
if(size < ss)
std::cout << "error" << std::endl;
else
{

long long int* types = new  long long int [size-ss+1];
  std::string* type = new std::string [size-ss+1];
  int c=0;



for(int i=0; i < size-ss+1 ; i++)
{

    type[i]="";
    types[i]=0;

    std::string s ="";
    std::string x="";


    for(int j = i;j<i+ss;j++)
      {
         s = s+s2[j];
         x = x+s3[j];
    }
    if((s.find('0') != std::string::npos)&&(x.find('4') != std::string::npos))
    ;
   else
{
    type[c] = x;
    types[c]= std::stoll(s);
    c++;
}
}

int m = std::pow(4,ss);

int* count= new int [m];

for (int i = 0; i <m ; ++i) {
  count[i]=0;
}

int* b10 = new int [c];



for(int i =0; i<c; i++)
{ b10[i]=0;

  std::string z = type[i];
  int x =0;
  int p =0;
  for(int j=ss-1; j>=0;j--)
  {
    if(z[j]=='0')
    x+=(0)*(std::pow(4,p));
    if(z[j]=='1')
    x+=(1)*(std::pow(4,p));
    if(z[j]=='2')
    x+=(2)*(std::pow(4,p));
    if(z[j]=='3')
    x+=(3)*(std::pow(4,p));
    p++;
    }
  b10[i]=x;

}
std::string* d= new std::string [c];

for (int i = 0; i < c; ++i)
{
  if(types[i]!=0){

  if (count[b10[i]]>0) {
count[b10[i]] ++;
  types[i]=0;
  }
  else
  count[b10[i]] ++;
}
d[i]="";
  if(types[i]!=0&&types[i]!=9){

long long  int a= types[i];
while (a!=0) {
  int r = a%10;
  if(r==1){
    d[i]="A"+d[i];
  }
  if(r==2){
    d[i]="C"+d[i];
  }
  if(r==3){
    d[i]="G"+d[i];
  }
  if(r==4){
    d[i]="T"+d[i];
  }
a=a/10;
}
}
}


for (int i = 0; i < c; i++) {
if(types[i]!=9&&types[i]!=0)
std::cout << d[i] << " " << count[b10[i]]<< std::endl;
}
delete []type;
delete [] d;
delete [] b10;
delete [] count;
delete [] types;
}


f.close();

return 0;

}
