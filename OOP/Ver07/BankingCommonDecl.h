/*
 * File Name : BankingCommonDecl.h
 * Author : Jaewoo Kim
 * File Ver : 0.7
 */

#ifndef __BANKING_COMMON_DECL_H__
#define __BANKING_COMMON_DECL_H__

#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::strlen;
using std::strcpy;
const int NAME_LEN = 20;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
enum {RANK_A=1, RANK_B, RANK_C};
enum {NORMAL=1, CREDIT};
#endif