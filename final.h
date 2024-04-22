#ifndef FINAL_H
#define FINAL_H

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

	int aa;
	
	struct account{
		string id;
		int money;
	};
	
	account data[100];
	FILE *in;
	ifstream infile;
	ofstream outfile;
	
	int size;
	
class Personal{
	private:
		int Money;
		string ID;
	public:
		Personal() : Money(0), ID("") {};
		Personal(int M, string idd) : Money(M), ID(idd) {};
		int Money2;
		void login();
		void logout();
		void store();
		void pay();
		void display();
};	

#endif
