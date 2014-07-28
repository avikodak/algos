/****************************************************************************************************************************************************
 *  File Name   		: sort0s1s2s.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page01\sort0s1s2s.h
 *  Created on			: May 15, 2014 :: 10:44:48 PM
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

#ifndef SORT0S1S2S_H_
#define SORT0S1S2S_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void sort0s1s2s(sillNode *ptr){
	if(ptr == null){
		return;
	}
	unsigned int frequency[3] = {0};
	sillNode *crawler = ptr;
	while(crawler != null){
		switch(crawler->value){
		case 0:
			frequency[0] += 1;
			break;
		case 1:
			frequency[1] += 1;
			break;
		case 2:
			frequency[2] += 1;
			break;
		default:
			throw "Invalid value";
		}
		crawler = crawler->next;
	}
	crawler = ptr;
	for(unsigned int counter = 0;counter < 3;counter++){
		while(frequency[counter]--){
			if(crawler == null){
				throw "Internal error";
			}
			crawler->value = counter;
			crawler = crawler->next;
		}
	}
}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

void sort0s1s2sONLOGN(sillNode *ptr){
	if(ptr == null){
		return;
	}
	vector<int> userInput;
	sillNode *crawler = ptr;
	while(crawler != null){
		userInput.push_back(crawler->value);
		crawler = crawler->next;
	}
	sort(userInput.begin(),userInput.end());
	crawler = ptr;
	for(unsigned int counter = 0;counter < userInput.size();counter++){
		crawler->value = userInput[counter];
		crawler = crawler->next;
	}
}

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/
void sort0s1s2sON2(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *outerCrawler = ptr,*innerCrawler,*ptrToMinKey;
	while(outerCrawler != null){
		innerCrawler = ptrToMinKey = outerCrawler;
		while(innerCrawler != null){
			if(ptrToMinKey->value > innerCrawler->value){
				ptrToMinKey = innerCrawler;
			}
			innerCrawler = innerCrawler->next;
		}
		if(ptrToMinKey != outerCrawler){

		}
		outerCrawler = outerCrawler->next;
	}
}

#endif /* SORT0S1S2S_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
