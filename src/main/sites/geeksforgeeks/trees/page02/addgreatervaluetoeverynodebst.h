/****************************************************************************************************************************************************
 *  File Name   		: addgreatervaluetoeverynodebst.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page02\addgreatervaluetoeverynodebst.h
 *  Created on			: Jun 30, 2014 :: 7:16:05 PM
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

#ifndef ADDGREATERVALUETOEVERYNODEBST_H_
#define ADDGREATERVALUETOEVERYNODEBST_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void addGreaterValuesToEveryNodeBST(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null;
	addGreaterValuesToEveryNodeBST(ptr->left);
	if(prevNode != null){
		ptr->value += prevNode->value;
	}
	prevNode = ptr;
	addGreaterValuesToEveryNodeBST(ptr->right);
}

//Not completed
void addGreaterValuesToEveryNodeDuplicateValBST(itNode *ptr){
	if(ptr == null){
		return;
	}
	static itNode *prevNode = null,*prevDistinctNode = null;
	if(prevNode != null){
		if(ptr->value == prevNode->value){
			if(prevDistinctNode != null){
				ptr->value += prevDistinctNode->value;
			}
		}
	}
	if(prevNode->value != ptr->value){

		}
	prevNode = ptr;

}

/****************************************************************************************************************************************************/
/* 																O(NLOGN) Algorithm 																    */
/****************************************************************************************************************************************************/

/****************************************************************************************************************************************************/
/* 																O(N^2) Algorithm 																    */
/****************************************************************************************************************************************************/


#endif /* ADDGREATERVALUETOEVERYNODEBST_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
