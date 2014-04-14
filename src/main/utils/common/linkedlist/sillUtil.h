/****************************************************************************************************************************************************
 *  File Name   		: sillUtil.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\utils\common\linkedlist\sillUtil.h
 *  Created on			: Apr 13, 2014 :: 10:07:06 PM
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
/* 																MAIN CODE START 																    */
/****************************************************************************************************************************************************/

#ifndef SILLUTIL_H_
#define SILLUTIL_H_

class sillutils {

private:
	//Tested
	sillNode *createSILLFromVectorMain(vector<int> userInput,unsigned int currentIndex){
		if(userInput.size() == 0 || currentIndex >= userInput.size()){
			return null;
		}
		sillNode *node = new sillNode(userInput[currentIndex]);
		node->next = createSILLFromVectorMain(userInput,currentIndex+1);
		return node;
	}

public:
	//Tested
	sillNode *createSILLFromVector(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		return createSILLFromVectorMain(userInput,0);
	}

	//Tested
	sillNode * createSILLFromVectorIterative(vector<int> userInput){
		if(userInput.size() == 0){
			return null;
		}
		sillNode *head = new sillNode(userInput[0]);
		sillNode *traversalNode = head;
		for(unsigned int counter = 1;counter < userInput.size();counter++){
			traversalNode->next = new sillNode(userInput[counter]);
			traversalNode = traversalNode->next;
		}
		traversalNode->next = null;
		return head;
	}

	//Tested
	void printSILL(sillNode *ptr){
		if(ptr == null){
			return;
		}
		printf("%d\t",ptr->value);
		printSILL(ptr->next);
	}
};

#endif /* SILLUTIL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
