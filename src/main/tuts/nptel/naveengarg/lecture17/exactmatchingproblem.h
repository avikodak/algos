/****************************************************************************************************************************************************
 *  File Name   		: exactmatchingproblem.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\tuts\nptel\naveengarg\lecture17\exactmatchingproblem.h
 *  Created on			: Jun 22, 2014 :: 7:31:37 PM
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

#ifndef EXACTMATCHINGPROBLEM_H_
#define EXACTMATCHINGPROBLEM_H_

/****************************************************************************************************************************************************/
/* 																O(M*N) Algorithm 																    */
/****************************************************************************************************************************************************/
vector<unsigned int> getMatchingIndex(char *text,char *pattern){
	vector<unsigned int> indexes;
	if(text == null || pattern == null){
		return indexes;
	}
	char *outerCrawler,*innerCrawler,*patternCrawler;
	unsigned int runningIndex = 0;
	while(outerCrawler != null){
		innerCrawler = outerCrawler;
		patternCrawler = pattern;
		while(innerCrawler != null && patternCrawler != null && *innerCrawler == *patternCrawler){
			innerCrawler++;
			patternCrawler++;
		}
		if(innerCrawler == null){
			break;
		}
		if(patternCrawler == null){
			indexes.push_back(runningIndex);
		}
		outerCrawler++;
		runningIndex++;
	}
	return indexes;
}

#endif /* EXACTMATCHINGPROBLEM_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
