/****************************************************************************************************************************************************
 *  File Name   		: rotatesill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page02\rotatesill.h
 *  Created on			: May 10, 2014 :: 11:05:32 AM
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

#ifndef ROTATESILL_H_
#define ROTATESILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void rotateSill(sillNode **ptr,unsigned int rotateBy){
	if(*ptr == null){
		return;
	}
	sillutils *utils = new sillutils();
	unsigned int length = utils->lengthOfSILL(ptr);
	rotateBy %= length;
	if(rotateBy == length){
		return;
	}
	sillNode *crawler = ptr,*head = ptr;
	while(rotateBy-- && crawler != null){
		crawler = crawler->next;
	}
	(*ptr) = crawler->next;
	crawler->next = null;
	crawler = *ptr;
	while(crawler->next != null){
		crawler = crawler->next;
	}
	crawler->next = head;
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

void moveTailToHead(sillNode **ptr){
	if(*ptr == null || (*ptr)->next == null){
		return;
	}
	sillNode *crawler = *ptr;
	while(crawler->next->next != null){
		crawler = crawler->next;
	}
	crawler->next->next = *ptr;
	(*ptr) = crawler->next;
	crawler->next = null;
}

void rotateSillOneByOne(sillNode **ptr,unsigned int rotateBy){
	if(*ptr == null){
		return;
	}
	sillutils *utils = new sillutils();
	unsigned int length = utils->lengthOfSILL(*ptr);
	rotateBy %= length;
	while(rotateBy--){
		moveTailToHead(ptr);
	}
}

#endif /* ROTATESILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
