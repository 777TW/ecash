#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "final.h"

using namespace std;

void Personal::login(){
	int j;
	cout << "=== �w��ϥ�eCash ===" << endl;
	cout << "�п�J�z���b��: ";
	cin >> ID;
	for(j=0;j<size;j++){
		if(data[j].id==ID){
			Money = data[j].money;
			aa=j;
			cout << "eCash: �b���}�ҧ���" << endl;
			break;
				
		}
	}
			
	if (j==size){
		cout << "eCash: �b�����s�b�A�Ĥ@���ϥ�" << endl;
		data[size].id = ID;
		data[size].money = 0;
		aa=size;
		size++;
	}
}
		
void Personal::logout(){
			
	cout << "eCash: �b���n�X�A�w�s��!" << endl;
	data[aa].money = Money;
	ID="";
	Money=0;
	outfile.open("data.txt", ios::out);
	for (int i=0;i<size; i++){
		outfile << data[i].id;
		outfile << " ";
		outfile << data[i].money;
		outfile << "\n";
	}
	outfile.close();
}
		
void Personal::store(){
	cout << "�п�J�x�s�����B:" << endl;
	cin >> Money2;
	if(Money2 <0){
		cout << "eCash: �п�J�@�Ӥj��0�����B" << endl; 
	}
	else{
		Money = Money + Money2;
		cout << "eCash: �A�s�F" << Money2 << "��" << endl; 
	}
			
}
		
void Personal::pay(){
	
	cout<< "�п�J���O���B:" << endl;
	cin >> Money2;
	if(Money2 < 0){
		cout << "eCash: �п�J�@�Ӥj��0�����B" << endl;
	}
	else if(Money2 > Money){
		cout << "eCash: �z��������" << endl;
	}
	else{
		Money = Money - Money2;
		cout << "eCash: �z��F" << Money2 << "��" << endl;
	}
}
		
void Personal::display(){
	cout << "eCash: �z�|��"<< Money << "��" << endl;
}
		


int main(){
	
	int i = 0;	
	Personal p1;
	infile.open("data.txt", ios::in);
	
	while( !infile.eof()) {
		infile >> data[i].id >> data[i].money;
		i++;
	}
	size = i-1;
	infile.close();
	
	p1.login();
	cout << data[aa].id << "�z�n�A�п�ܶ���" << endl;
	cout << "s: �x��" << endl;
	cout << "p: ���O" << endl;
	cout << "d: �d�߾l�B" << endl;
	cout << "q: ���}" << endl;
	cout << "> " ;

	string a;
	while(1){
		cin >> a;
		if(a=="s"){
			p1.store();
		}
		else if(a=="p"){
			p1.pay();
		}
		else if(a=="d"){
			p1.display();
		}
		else if(a=="q"){
			p1.logout();
			cout << "eCash: ����,ByeBye!" << endl;
			return 0;
		}
		cout << "> " ;	
	}
	
	return 0; 
}
