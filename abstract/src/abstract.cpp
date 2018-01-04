//============================================================================
// Name        : abstract.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <sys/utsname.h>

using namespace std;

#define HPUX "HPUX"
#define SUNOS "SunOS"

class Scanner{};
class Parser{};
class CodeGenerator{};
class Optimizer{};

class HPScanner :public Scanner{};
class HPParser : public Parser{};
class HPCodeGenerator :public CodeGenerator{};
class HPOptimizer : public Optimizer{};

class SunScanner :public Scanner{};
class SunParser : public Parser{};
class SunCodeGenerator:public CodeGenerator{};
class SunOptimizer : public Optimizer{};

struct utsname sysInfo;

void ScanParse(){
	if(strncasecmp(sysInfo.sysname, HPUX, strlen(HPUX))==0){
		HPScanner scanner;
		HPParser parser;
	}else if(strncasecmp(sysInfo.sysname, SUNOS, strlen(SUNOS))==0){
		SunScanner scanner;
		SunParser parser;
	}else{
		cout<<sysInfo.sysname<<"does not supported"<<endl;
	}
}

void CodeGenOptimize(){
	if(strncasecmp(sysInfo.sysname, HPUX, strlen(HPUX))==0){
			HPCodeGenerator codeGenerator;
			HPOptimizer optimizer;
		}else if(strncasecmp(sysInfo.sysname, SUNOS, strlen(SUNOS))==0){
			SunCodeGenerator codeGenerator;
			SunOptimizer optimizer;
		}else{
			cout<<sysInfo.sysname<<"does not supported"<<endl;
		}
}


int main() {
	if(uname(&sysInfo)<0){
		cout<<"Error Ocurred"<<endl;
		return (-1);
	}
	ScanParse();
	CodeGenOptimize();
	return 0;
}
