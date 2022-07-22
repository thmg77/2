#include<stdio.h> 
#include<iostream.h> 
#include<fstream.h> 
#include<conio.h> 
#include<string.h> 
#include<stdlib.h> 
class student 
{ 
public: 
char name[20], usn[10], sem[10], branch[20], buffer[50]; 
public: 
void writerec( ); 
void displayrec( ); 
void searchrec( ); 
void modifyrec( ); 
}; 
void student :: writerec( ) 
{ 
fstream 
fp; 
student 
s; 
fp.open("stu1.txt", ios :: app); 
cout<<"\nEnter name"; 
cin>>s.name; 
cout<<"\nEnter usn"; 
cin>>s.usn; 
cout<<"\nEnter sem"; 
cin>>s.sem; 
cout<<"\nEnter branch"; 
cin>>s.branch; 
strcpy(s.buffer, s.name); 
strcat(s.buffer, "|"); 
strcat(s.buffer, s.usn); 
strcat(s.buffer,"|"); 
strcat(s.buffer, s.sem); 
strcat(s.buffer, "|"); 
strcat(s.buffer, s.branch); 
int 
c = strlen(s.buffer);
for(int i=0; i<50-c; i++) 
{ 
strcat(s.buffer,"$"); 
} 
strcat(s.buffer, "\n"); 
fp<<s.buffer; 
fp.close( ); 
} 
void student :: displayrec( ) 
{ 
int 
i; 
char buff[50]; 
student s; 
fstream fp; 
fp.open("stu1.txt", ios::in); 
i = 0; 
cout<<"Name\t\tUSN\t\tSem\t\tBranch\n"; 
while(!fp.eof( )) 
{ 
fp.getline(s.name, 20, '|'); 
fp.getline(s.usn, 10, '|'); 
fp.getline(s.sem, 10, '|'); 
fp.getline(s.branch, 20, '$'); 
fp.getline(buff, 50, '\n'); 
cout<<s.name<<"\t\t"<<s.usn<<"\t\t"<<s.sem<<"\t\t"<<s.branch; 
cout<<"\n"; 
i++; 
} 
fp.close( ); 
getch( ); 
} 
void student :: searchrec( ) 
{ 
fstream 
fp; 
student 
s; 
char reg[10], buff[50]; 
fp.open("stu1.txt", ios::in); 
cout<<"\n Enter the USN of the record which is to be searched"; 
cin>>reg; 
while(!fp.eof( )) 
{ 
fp.getline(s.name, 20, '|'); 
fp.getline(s.usn, 10, '|'); 
fp.getline(s.sem, 10, '|'); 
fp.getline(s.branch, 20, '$'); 
fp.getline(buff, 50, '\n'); 
if(strcmp(s.usn,reg) = = 0) 
{ 
cout<<"\n Record Found"; 
cout<<"\n"<<s.name<<"\t\t"<<s.usn<<"\t\t"<<s.sem<<"\t\t"; 
cout<<s.branch; 
//cout<<"\n"; 
getch( ); 
return; 
} 
} 
cout<<"\n Record not Found"; 
getch( ); 
return; 
} 
void student :: modifyrec( ) 
{ 
fstream 
fp; 
student 
s[20]; 
char reg[10], buff[50], buff1[50]; 
int 
i, j; 
fp.open("stu1.txt", ios :: in); 
cout<<"\nEnter the usn"; 
cin>>reg; 
i = 0; 
while(!fp.eof( )) 
{ 
fp.getline(s[i].name, 20, '|'); 
fp.getline(s[i].usn, 10, '|'); 
fp.getline(s[i].sem, 10, '|'); 
fp.getline(s[i].branch, 20, '$'); 
fp.getline(buff, 50, '\n'); 
i++; 
} 
i - -;
for(j=0;j<i;j++) 
{ 
if(strcmp(reg,s[j].usn) = = 0) 
{ 
cout<<"\n The old values of the record with usn"<<reg<<"are\n"; 
cout<<"\n Name="<<s[j].name; 
cout<<"\n USN="<<s[j].usn; 
cout<<"\n sem="<<s[j].sem; 
cout<<"\n Branch="<<s[j].branch; 
cout<<"\n Enter new values\n"; 
cout<<"\n Name="; cin>>s[j].name; 
cout<<"\n USN="; cin>>s[j].usn; 
cout<<"\n sem="; cin>>s[j].sem; 
cout<<"\n Branch="; cin>>s[j].branch; 
break; 
} 
} 
if(j = = i) 
{ 
cout<<"\n The record with usn"<<reg<<"is not present"; 
getch( ); 
return; 
} 
fp.close( ); 
fstream fp1; 
fp1.open("stu1.txt", ios :: out); 
for(j=0; j<i; j++) 
{ 
strcpy(buff1, s[j].name); 
strcat(buff1, "|"); 
strcat(buff1, s[j].usn); 
strcat(buff1, "|"); 
strcat(buff1, s[j].sem); 
strcat(buff1, "|"); 
strcat(buff1, s[j].branch); 
int 
c = strlen(buff1); 
for(int k=0; k<50-c; k++) 
strcat(buff1, "$"); 
strcat(buff1, "\n");
fp1<<buff1; 
} 
fp1.close( ); 
} 
void main( ) 
{ 
fstream 
fp; 
int 
ch; 
student 
s; 
fp.open("stu1.txt", ios :: out); 
//fp.close( ); 
for(;;) 
{ 
clrscr( ); 
cout<<"\n 1. write record"; 
cout<<"\n 2. display record"; 
cout<<"\n 3. search record"; 
cout<<"\n 4. modify record"; 
cout<<"\n 5. exit"; 
cout<<"\n Enter your choice"; 
cin>>ch; 
switch(ch) 
{ 
case 1:s.writerec( ); 
break; 
case 2: s.displayrec( ); 
break; 
case 3: s.searchrec( ); 
break; 
case 4: s.modifyrec( ); 
break; 
case 5:exit(0); 
break; 
} 
} 
} 

