/****************************************************************************************************************************************************
 *  File Name   		: deque.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture03\deque.h
 *  Created on			: May 31, 2014 :: 1:07:32 PM
 *  Author				: AVINASH
 *  Testing Status 		: TODO
 *  URL 				: TODO
 ****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 														NAMESPACE DECLARATION AND IMPORTS 														    */
/****************************************************************************************************************************************************/

using namespace std;
using namespace __gnu_cxx;

/****************************************************************************************************************************************************/
/* 																INCLUDES		 																    */
/****************************************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <hash_map>
#include <stack>
#include <queue>
#include <limits.h>
#include <algos/utils/ds/tree/treeds.h>
#include <algos/utils/common/tree/tree.h>

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef DEQUE_H_
#define DEQUE_H_

class pdeque{
private:
	dillNode *front;
	dillNode *rear;
	unsigned int size;
public:
	void push_front(int value){
		if(this->front == null){
			this->front = new dillNode(value);
			this->rear = this->front;

		}else{
			dillNode *newNode = new dillNode(value);
			newNode->next = this->front;
			this->front = newNode;
		}
		this->size += 1;
	}

	void push_back(int value){
		if(this->rear == null){
			this->rear = new dillNode(value);
			this->front = this->rear;
		}else{
			dillNode *newNode = new dillNode(value);
			this->rear->next = newNode;
			this->rear = newNode;
		}
		this->size += 1;
	}

	void pop_front(){
		if(front == null){
			throw "Deque is empty";
		}
		dillNode *nodeToBeDeleted = this->front;
		if(this->front == this->rear){
			this->rear = null;
		}
		this->front = this->front->next;
		free(nodeToBeDeleted);
	}

	void pop_rear(){
		if(rear  == null){
			throw "Deque is empty";
		}
		dillNode *nodeToBeDeleted = this->rear;
		if(this->front == this->rear){
			this->front = null;
		}
		this->rear = this->rear->prev;
		free(nodeToBeDeleted);
	}

	unsigned int size(){
		return size;
	}

	bool isEmpty(){
		return size == 0?true:false;
	}

	int getFront(){
		if(isEmpty()){
			throw "Deque is empty";
		}
		return front->value;
	}

	int getRear(){
		if(isEmpty()){
			throw "Deque is empty";
		}
		return rear->value;
	}
};

#endif /* DEQUE_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
