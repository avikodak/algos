/****************************************************************************************************************************************************
 *  File Name   		: linkedlist.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\utils\ds\linkedlist\linkedlist.h
 *  Created on			: Apr 10, 2014 :: 3:36:48 AM
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

/****************************************************************************************************************************************************/
/* 															USER DEFINED CONSTANTS 																    */
/****************************************************************************************************************************************************/

#define null NULL

/****************************************************************************************************************************************************/
/* 														LINKED LIST DATA STRUCTURES START 															*/
/****************************************************************************************************************************************************/

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct sillNode{
	int value;
	sillNode *next;

	sillNode(){

	}

	sillNode(int userInput){
		value = userInput;
		next = null;
	}
};

struct dillNode{
	int value;
	dillNode *prev;
	dillNode *next;

	dillNode(){

	}

	dillNode(int userInput){
		value = userInput;
		prev = null;
		next = null;
	}
};

struct xordillNode{
	int value;
	uint32_t xorValue;

	xordillNode(){

	}

	xordillNode(int userInput){
		value = userInput;
		xorValue = 0;
	}
};

struct sillfNode{
	int value;
	bool flag;
	sillfNode *next;

	sillfNode(){

	}

	sillfNode(int userInput){
		value = userInput;
		flag = false;
		next = null;
	}
};

struct sillArbitPtrNode{
	int value;
	sillArbitPtrNode *next;
	sillArbitPtrNode *arbitrary;

	sillArbitPtrNode(){

	}

	sillArbitPtrNode(int userInput){
		value = userInput;
		next = null;
		arbitrary = null;
	}
};

struct sillHashmap{
	hash_map<unsigned int,sillNode *> indexNodeMap;
	hash_map<uint32_t,unsigned int> nodeIndexMap;
};

#endif /* LINKEDLIST_H_ */

/****************************************************************************************************************************************************/
/* 														LINKED LIST DATA STRUCTURES END																*/
/****************************************************************************************************************************************************/
