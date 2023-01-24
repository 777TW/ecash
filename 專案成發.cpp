#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "final.h"

using namespace std;

void Personal::login(){
	int j;
	cout << "=== 歡迎使用eCash ===" << endl;
	cout << "請輸入您的帳號: ";
	cin >> ID;
	for(j=0;j<size;j++){
		if(data[j].id==ID){
			Money = data[j].money;
			aa=j;
			cout << "eCash: 帳號開啟完成" << endl;
			break;
				
		}
	}
			
	if (j==size){
		cout << "eCash: 帳號不存在，第一次使用" << endl;
		data[size].id = ID;
		data[size].money = 0;
		aa=size;
		size++;
	}
}
		
void Personal::logout(){
			
	cout << "eCash: 帳號登出，已存檔!" << endl;
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
	cout << "請輸入儲存的金額:" << endl;
	cin >> Money2;
	if(Money2 <0){
		cout << "eCash: 請輸入一個大於0的金額" << endl; 
	}
	else{
		Money = Money + Money2;
		cout << "eCash: 你存了" << Money2 << "元" << endl; 
	}
			
}
		
void Personal::pay(){
	
	cout<< "請輸入消費金額:" << endl;
	cin >> Money2;
	if(Money2 < 0){
		cout << "eCash: 請輸入一個大於0的金額" << endl;
	}
	else if(Money2 > Money){
		cout << "eCash: 您的錢不夠" << endl;
	}
	else{
		Money = Money - Money2;
		cout << "eCash: 您花了" << Money2 << "元" << endl;
	}
}
		
void Personal::display(){
	cout << "eCash: 您尚有"<< Money << "元" << endl;
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
	cout << data[aa].id << "您好，請選擇項目" << endl;
	cout << "s: 儲值" << endl;
	cout << "p: 消費" << endl;
	cout << "d: 查詢餘額" << endl;
	cout << "q: 離開" << endl;
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
			cout << "eCash: 謝謝,ByeBye!" << endl;
			return 0;
		}
		cout << "> " ;	
	}
	
	return 0; 
}
