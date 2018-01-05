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

class Scanner{
public:
	virtual ~Scanner()=0;
};

class Parser{
public:
	virtual ~Parser()=0;
};

class CodeGenerator{
public:
	virtual ~CodeGenerator()=0;
};

class Optimizer{
public:
	virtual ~Optimizer()=0;
};

Scanner::~Scanner(){}
Parser::~Parser(){}
CodeGenerator::~CodeGenerator(){}
Optimizer::~Optimizer(){}

class HPScanner :public Scanner{};
class HPParser : public Parser{};
class HPCodeGenerator :public CodeGenerator{};
class HPOptimizer : public Optimizer{};

class SunScanner :public Scanner{};
class SunParser : public Parser{};
class SunCodeGenerator:public CodeGenerator{};
class SunOptimizer : public Optimizer{};

class CompileFactory{
public:
	virtual Scanner* CreateScanner()=0;
	virtual Parser* CreateParser()=0;
	virtual CodeGenerator* CreateCodeGenerator()=0;
	virtual Optimizer* CreateOptimizer()=0;
};

class HPCompileFactory:public CompileFactory{
public:
	 Scanner* CreateScanner(){ new HPScanner; };
	 Parser* CreateParser(){ new HPParser; };
	 CodeGenerator* CreateCodeGenerator(){ new HPCodeGenerator; };
	 Optimizer* CreateOptimizer(){ new HPOptimizer; };
};

class SunCompileFactory:public CompileFactory{
public:
	 Scanner* CreateScanner(){ new SunScanner; };
	 Parser* CreateParser(){ new SunParser; };
	 CodeGenerator* CreateCodeGenerator(){ new SunCodeGenerator; };
	 Optimizer* CreateOptimizer(){ new SunOptimizer; };
};

CompileFactory *pFactory;


int main() {
	struct utsname sysInfo;

	if (uname(&sysInfo) < 0) {
		cout << "Error Ocurred" << endl;
		return (-1);
	}

	if (strncasecmp(sysInfo.sysname, HPUX, strlen(HPUX)) == 0) {
		pFactory = new HPCompileFactory;
	} else if (strncasecmp(sysInfo.sysname, SUNOS, strlen(SUNOS)) == 0) {
		pFactory = new SunCompileFactory;
	} else {
		cout << sysInfo.sysname << "does not supported" << endl;
		return 0;
	}

	Scanner *pScanner= pFactory->CreateScanner();
	Parser *pParser = pFactory->CreateParser();
	CodeGenerator *pCodeGenerator = pFactory ->CreateCodeGenerator();
	Optimizer *pOptimizer=pFactory->CreateOptimizer();

}
