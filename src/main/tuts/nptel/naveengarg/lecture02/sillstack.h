/****************************************************************************************************************************************************
 *  File Name   		: sillstack.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture02\sillstack.h
 *  Created on			: May 29, 2014 :: 2:26:03 AM
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

#ifndef SILLSTACK_H_
#define SILLSTACK_H_

class sillstack{
private:
	sillNode *head = null;
	unsigned int size = 0;
public:
	void push(int userInput){
		sillNode *newNode = new sillNode(userInput);
		newNode->next = this->head;
		this->head = newNode;
		size++;
	}

	bool empty(){
		return size == 0?true:false;
	}

	unsigned int size(){
		return size;
	}

	void top(){
		if(this->head == null){
			throw "Stack empty";
		}
		return this->head->value;
	}

	void pop(){
		sillNode *nodeToBeDeleted = this->head;
		this->head = this->head->next;
		free(nodeToBeDeleted);
		size--;
	}
};

#endif /* SILLSTACK_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
