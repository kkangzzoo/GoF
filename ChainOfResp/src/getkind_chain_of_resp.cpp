/*
 * getkind_chain_of_resp.cpp
 *
 *  Created on: 2018. 1. 8.
 *      Author: daum
 * Description: 별도 정의된 멤버 함수 활용
 */

#include <iostream>
using namespace std;

#define DEFAULT_REQUEST 0
#define HELP_REQUEST 1
#define PRINT_REQUEST 2
#define PREVIEW_REQUEST 3

class Request{
public:
	virtual int GetKint(){ return DEFAULT_REQUEST; }
};
class HelpRequest : public Request{
	virtual int GetKint(){ return HELP_REQUEST; }
};
class PrintRequest : public Request{
	virtual int GetKint(){ return PRINT_REQUEST; }
};
class PreviewRequest : public Request{
	virtual int GetKint(){ return PREVIEW_REQUEST; }
};

class Handler{
public :
	Handler(Handler* pObj) : pSuccessor_(pObj){}
	virtual void HandleRequest(Request *pReq){
		switch(pReq->GetKint()){
		case HELP_REQUEST:
			cout<<"HelpRequest Processing"<<endl;
			break;
		case PRINT_REQUEST:
			cout<<"PrintRequst Processing"<<endl;
			break;
		default:
			cout<<"Default Processing"<<endl;
		}
	}

private:
	Handler* pSuccessor_;
};

class ExtendedHandler : public Handler{
public :
	Handler(Handler* pObj) : pSuccessor_(pObj){}
	virtual void HandleRequest(Request *pReq){
		switch(pReq->GetKint()){
		case PREVIEW_REQUEST:
			cout<<"PreviewRequest Processing"<<endl;
			break;
		default:
			Handler::HandleRequest(pReq);
		}
	}

private:
	Handler* pSuccessor_;
};

int main(){
	Handler hdlr(0);
	Request *pReq=new PrintRequest;

	hdlr.HandleRequest(pReq);
}


