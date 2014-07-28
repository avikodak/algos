/****************************************************************************************************************************************************
 *  File Name   		: addnumberssill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page01\addnumberssill.h
 *  Created on			: May 15, 2014 :: 11:28:34 PM
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

#ifndef ADDNUMBERSSILL_H_
#define ADDNUMBERSSILL_H_


/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
sillNode *addNumbersSillReverseOrder(sillNode *firstPtr,sillNode *secondPtr){
	if(firstPtr == null && secondPtr == null){
		return null;
	}
	if(firstPtr == null || secondPtr == null){
		return firstPtr != null?firstPtr:secondPtr;
	}
	stack<sillNode *> firstSillNodes,secondSillNodes;
	sillNode *crawler = firstPtr;
	while(crawler != null){
		firstSillNodes.push(crawler);
		crawler = crawler->next;
	}
	crawler = secondPtr;
	while(crawler != null){
		secondSillNodes.push(crawler);
		crawler = crawler->next;
	}
	sillNode *head,*resultCrawler;
	int sum,carry = 0;
	while(!firstSillNodes.empty() && !secondSillNodes.empty()){
		sum = carry;
		if(firstSillNodes.top()->value < 0 || secondSillNodes.top()->value < 0){
			throw "Invalid value";
		}
		sum += firstSillNodes.top()->value + secondSillNodes.top()->value;
		if(head == null){
			head = new sillNode(sum%10);
			resultCrawler = head;
		}else{
			resultCrawler->next = new sillNode(sum%10);
			resultCrawler = resultCrawler->next;
		}
		carry = sum/10;
		firstSillNodes.pop();
		secondSillNodes.pop();
	}
	while(!firstSillNodes.empty()){
		sum = carry;
		if(firstSillNodes.top()->value < 0){
			throw "Invalid value";
		}
		sum += firstSillNodes.top()->value;
		resultCrawler->next = new sillNode(sum%10);
		resultCrawler = resultCrawler->next;
		carry = sum/10;
		firstSillNodes.pop();
	}
	while(!secondSillNodes.empty()){
		sum = carry;
		if(secondSillNodes.top()->value < 0){
			throw "Invalid value";
		}
		sum += secondSillNodes.top()->value;
		resultCrawler->next = new sillNode(sum%10);
		resultCrawler = resultCrawler->next;
		carry = sum/10;
		secondSillNodes.pop();
	}
	return head;
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* ADDNUMBERSSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
