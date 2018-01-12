/*
 * coinbox.h
 *
 *  Created on: 2018. 1. 12.
 *      Author: daum
 */


#ifndef COINBOX_H_
#define COINBOX_H_

class Mediator;

class CoinBox{
#define MAX_COIN_CNT 500
#define MIN_COIN_CNT 10

#define COIN_ACCEPT_MODE 1
#define COIN_REJECT_MODE 0

public:
	CoinBox();
	void SetMediator(Mediator* pMediator);

	void InsertCoin();
	void RejectCoin();
	void PayOutCoin(int payOutCnt);
	void SetCoinBoxMode(int mode);

protected:
	bool IsValid();

private:
	Mediator* pMediator_;
	int coinCnt_;
	int mode_;
};



#endif /* COINBOX_H_ */
