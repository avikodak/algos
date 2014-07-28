/****************************************************************************************************************************************************
 *  File Name   		: morrispreorder.h 
 *	File Location		: C:\Users\AVINASH\Desktop\CC++\algorithms\src\main\sites\geeksforgeeks\trees\page04\morrispreorder.h
 *  Created on			: May 25, 2014 :: 2:02:30 PM
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

#ifndef MORRISPREORDER_H_
#define MORRISPREORDER_H_

/****************************************************************************************************************************************************/
/* 																	O(N) Algorithm 																    */
/****************************************************************************************************************************************************/
void morrisPreOrder(itNode *ptr){
	if(ptr == null){
		return;
	}
	itNode *traversingNode = ptr,*temp;
	while(traversingNode != null){
		if(traversingNode->left != null){
			temp = traversingNode->left;
			while(temp->right != null && temp->right != traversingNode){
				temp = temp->right;
			}
			if(temp->right == null){
				printf("%d\t",traversingNode->value);
				temp->right = traversingNode;
				traversingNode = traversingNode->left;
			}else{
				temp->right = null;
				traversingNode = traversingNode->right;
			}
		}else{
			printf("%d\t",traversingNode->value);
			traversingNode = traversingNode->right;
		}
	}

}

#endif /* MORRISPREORDER_H_ */

/****************************************************************************************************************************************************/
/* 																MAIN CODE END 																	    */
/****************************************************************************************************************************************************/
