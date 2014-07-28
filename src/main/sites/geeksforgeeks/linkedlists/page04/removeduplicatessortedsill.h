/****************************************************************************************************************************************************
 *  File Name   		: removeduplicatessortedsill.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\linkedlists\page04\removeduplicatessortedsill.h
 *  Created on			: Apr 29, 2014 :: 10:11:12 PM
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

#ifndef REMOVEDUPLICATESSORTEDSILL_H_
#define REMOVEDUPLICATESSORTEDSILL_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/

void removeDuplicatesSortedSill(sillNode *ptr){
	if(ptr == null){
		return;
	}
	sillNode *outerCrawler,*innerCrawler,*temp;
	outerCrawler = ptr;
	while(outerCrawler != null){
		innerCrawler = outerCrawler->next;
		while(innerCrawler != null && innerCrawler->value == outerCrawler->value){
			temp = innerCrawler;
			outerCrawler->next = innerCrawler->next;
			innerCrawler = outerCrawler->next;
			free(temp);
		}
		outerCrawler = outerCrawler->next;
	}
}

#endif /* REMOVEDUPLICATESSORTEDSILL_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
