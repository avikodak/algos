/****************************************************************************************************************************************************
 *  File Name   		: segregateevenodd.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page02\segregateevenodd.h
 *  Created on			: May 10, 2014 :: 1:25:54 AM
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

#ifndef SEGREGATEEVENODD_H_
#define SEGREGATEEVENODD_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void segregateEvenOddNodeQuickDivide(sillNode **ptr){
	if(ptr == null){
		return null;
	}
	sillutils *utils = new sillutils();
	sillNode *tailOfSill = utils->getTailOfSill(ptr),*crawler = *ptr,*tailCrawler = tailOfSill,*prevNode = null;
	while(crawler != tailOfSill && crawler->value%2){
		tailCrawler->next = crawler;
		crawler = crawler->next;
		(*ptr) = crawler;
		tailCrawler = tailCrawler->next;
		tailCrawler->next = null;
	}
	if(crawler->value%2 == 0){
		prevNode = crawler;
		crawler = crawler->next;
		while(crawler != tailOfSill && crawler != null){
			if(crawler->value & 1){
				prevNode->next = crawler->next;
				tailCrawler->next = crawler;
				crawler = crawler->next;
				tailCrawler = tailCrawler->next;
			}else{
				crawler = crawler->next;
			}
		}
	}
}

void segregateEvenOddNodeBuckets(sillNode **ptr){
	if(ptr == null){
		return;
	}
	queue<sillNode *> evenBucket,oddBucket;
	sillNode *traversalNode = ptr;
	while(traversalNode != null){
		if(traversalNode->value & 1){
			oddBucket.push(traversalNode);
		}else{
			evenBucket.push(traversalNode);
		}
		traversalNode = traversalNode->next;
	}
	*ptr = null;
	traversalNode = null;
	while(!evenBucket.empty()){
		if(*ptr == null){
			*ptr = evenBucket.front();
			traversalNode = *ptr;
		}else{
			traversalNode->next = evenBucket.front();
			traversalNode = traversalNode->next;
		}
		traversalNode->next = null;
		evenBucket.pop();
	}
	while(!oddBucket.empty()){
		if(*ptr == null){
			*ptr = oddBucket.front();
			traversalNode = *ptr;
		}else{
			traversalNode->next = oddBucket.front();
			traversalNode = traversalNode->next;
		}
		traversalNode->next = null;
		oddBucket.pop();
	}
}

sillNode *segregateEvenOddNodes(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillNode *evenHead = null,*oddHead = null,*evenCrawler,*oddCrawler;
	sillNode *crawler = ptr;
	while(crawler != null){
		if(crawler->value & 1){
			if(oddHead == null){
				oddHead = crawler;
				oddCrawler = oddHead;
			}else{
				oddCrawler->next = crawler;
				oddCrawler = oddCrawler->next;
			}
			crawler = crawler->next;
			oddCrawler->next = null;
		}else{
			if(evenHead == null){
				evenHead = crawler;
				evenCrawler = evenHead;
			}else{
				evenCrawler->next = crawler;
				evenCrawler = evenCrawler->next;
			}
			crawler = crawler->next;
			evenCrawler->next = null;
		}
	}
	sillNode *evenOddList = (sillNode *)malloc(2*sizeof(sillNode));
	evenOddList[0] = evenCrawler;
	evenOddList[1] = oddCrawler;
	return evenOddList;
}

sillNode *segregateEvenOddNodesNewLists(sillNode *ptr){
	if(ptr == null){
		return null;
	}
	sillNode *evenHead = null,*oddHead = null,*evenCrawler,*oddCrawler;
	sillNode *crawler = ptr;
	while(crawler != null){
		if(crawler->value&1){
			if(evenHead == null){
				evenHead = new sillNode(crawler->value);
				evenCrawler = evenHead;
			}else{
				evenCrawler->next = new sillNode(crawler->value);
				evenCrawler = evenCrawler->next;
			}
		}else{
			if(oddHead == null){
				oddHead = new sillNode(crawler->value);
				oddCrawler = oddHead;
			}else{
				oddCrawler->next = new sillNode(crawler->value);
				oddCrawler = oddCrawler->next;
			}
		}
		crawler = crawler->next;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/

#endif /* SEGREGATEEVENODD_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
