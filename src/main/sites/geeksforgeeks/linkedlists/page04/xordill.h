/****************************************************************************************************************************************************
 *  File Name   		: xordill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page04\xordill.h
 *  Created on			: May 1, 2014 :: 7:31:23 PM
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

#ifndef XORDILL_H_
#define XORDILL_H_

struct xordill{
	int value;
	uint32_t xorValue;
};

class xordillutil {
private:
	xordill *head;

public:
	xordillutil(){
		head = null;
	}

	void insertNodeIntoValue(int value){
		if(head == null){
			xordill *newNode = (xordill *)malloc(sizeof(xordill));
			newNode->value = value;
			head = newNode;
		}else{
			xordill *traversalNode = head,*prevPtr = null,*nextPtr;
			while(traversalNode != null){
				nextPtr = (xordill *)(traversalNode->xorValue ^ (uint32_t)prevPtr);
				if(nextPtr == null){
					xordill *newNode = (xordill *)malloc(sizeof(xordill));
					newNode->value = value;
					newNode->xorValue = (uint32_t)traversalNode;
					traversalNode->xorValue = traversalNode->xorValue ^ newNode;
					break;
				}
				traversalNode = nextPtr;
			}
		}
		return;
	}

	void createXorDill(vector<int> userInput){
		if(userInput.size() == 0){
			return;
		}
		for(unsigned int counter = 0;counter < userInput.size();counter++){
			insertNodeIntoValue(userInput[counter]);
		}
	}

	bool searchForNode(int value){
		xordill *traversalNode = head;
		xordill *prevNode = null,*temp;
		while(traversalNode != null){
			if(traversalNode->value == value){
				return true;
			}
			temp = traversalNode;
			traversalNode =(xordill *)(traversalNode->xorValue ^ (uint32_t)prevNode);
			prevNode = temp;
		}
		return false;
	}

	void printxordill(){
		xordill *traversalNode = head;
		xordill *prevNode = null,*temp;
		while(traversalNode != null){
			printf("%d\t",traversalNode->value);
			temp = traversalNode;
			traversalNode = (xordill *)((traversalNode->xorValue) ^ (uint32_t)prevNode);
			prevNode = temp;
		}
	}

	virtual ~xordill();
};

#endif /* XORDILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
