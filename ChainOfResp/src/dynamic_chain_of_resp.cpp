/*
 * dynamic_chain_of_resp.cpp
 *
 *  Created on: 2018. 1. 8.
 *      Author: daum
 * Description: dynamic_cast 이용
 */

#include <iostream>
using namespace std;

class Request{
public:
	virtual ~Request(){}
};
class HelpRequest : public Request{};
class PrintRequest : public Request{};
class PreviewRequest : public Request{};

class Handler{
public :
	Handler(Handler* pObj) : pSuccessor_(pObj){}
	virtual void HandleRequest(Request *pReq){
		if(dynamic_cast<HelpRequest*>(pReq)!=NULL){
			//HelpRequest 처리
			cout<<"HelpRequest Processing"<<endl;
		}else if(dynamic_cast<PrintRequest*>(pReq)!=NULL){
			//PrintRequest 처리
			cout<<"PrintRequest Processing"<<endl;
		}else{
			cout<<"Default Processing"<<endl;
		}
	}

private:
	Handler* pSuccessor_;
};

class ExtendHandler : public Handler{
public:
	ExtendHandler(Handler *pObj) : Handler(pObj){}

	virtual void HandleRequest(Request *pReq) {
		if (dynamic_cast<HelpRequest*>(pReq) != NULL) {
			//PreviewRequesst 처리
			cout << "PreviewRequesst Processing" << endl;
		}else { Handler:: HandleRequest(pReq); }
	}
};

int main(){
	ExtendHandler hdlr(0);
	Request *pReq=new PreviewRequest;

	hdlr.HandleRequest(pReq);
}


