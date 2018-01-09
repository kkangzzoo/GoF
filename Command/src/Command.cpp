//============================================================================
// Name        : Command.cpp
// Author      : kkangzzoo
// Version     :
// Copyright   : Your copyright notice
// Description : non Command  >  Client는 요청 처리에 필요한 클래스를 모두 알아야 함.
//============================================================================


#include <iostream>
#include <string>
#include <map>
using namespace std;

static const int NA_POS=-1;

#define CMD_NAME "cmd"
#define LOGIN_VAL "login"
#define BBSLIST_VAL "bbslist"
#define BBSREAD_VAL "bbsread"

class Request{
public:
	string GetValue(string name){
		return nvList_[name];
	}

	void SetNameValue(string name, string value){
		nvList_[name]=value;
	}

private:
	map<string, string> nvList_;
};

class RequesParser{
public:
	bool GetRequest(string input, Request& req){
		string key, value, str;
		int start=0, pos=0;

		while(pos!=NA_POS){
			pos=input.find("=",start);
			if(pos==NA_POS) continue;

			key=input.substr(start, pos-start);
			start=pos+1;

			pos=input.find("&",start);
			if(pos==NA_POS)	value=input.substr(start, input.length()-start);
			else value = input.substr(start, pos-start);
			start=pos+1;

			if(!key.empty()){
				req.SetNameValue(DecodeString(key), DecodeString(value));
				key="";
			}
		}
		return true;
	}

protected:
	string DecodeString(string s){
		string output;
		int len=s.length();

		for(int i=0; i<len; i++){
			if(s[i]=='+') output +=' ';
			else if(s[i]=='%'){
				const char *pStr=s.data()+i+1;
				char ch=Hex2Digit(pStr);
				output+=ch;
				i+=2;
			}else output +=s[i];
		}
		return output;
	}

	unsigned int Hex2Digit(const char* hex){
		register char digit;
		digit=(hex[0]>='A'?((hex[0]&0x4F)-'A')+10 : (hex[0]-'0'));
		digit<<=4;
		digit +=(hex[1]>='A'?((hex[1]&0x4F)-'A')+10 : (hex[1]-'0'));

		return digit;
	}
private:
};

class UserManager{
public:
	bool CheckPasswd(Request& req){
		cout<<"Password OK" <<endl;
		return true;
	}
};

class BBS{
public:
	void DisplayList(Request& req){
		cout<<"Display BBS List"<<endl;
	}
	void DisplayItem(Request& req){
		cout<<"Display BBS Item"<<endl;
	}
};

BBS _bbs;
UserManager _userMan;

int main() {
	string input;
	RequesParser parser;

	while(1){
		cin>>input;

		Request req;
		parser.GetRequest(input, req);

		string cmd=req.GetValue(CMD_NAME);
		if(cmd==LOGIN_VAL)
			_userMan.CheckPasswd(req);
		else if (cmd==BBSLIST_VAL)
			_bbs.DisplayList(req);
		else if (cmd==LOGIN_VAL)
			_bbs.DisplayItem(req);
		else
			cout<<"Not Available Command : " <<cmd << endl;
	}
	return 0;
}
