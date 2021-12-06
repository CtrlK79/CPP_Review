/*
 * File Name : BankingCommonDecl.h
 * Author : Jaewoo Kim
 * File Ver : 0.8
 */

#ifndef __BANKING_COMMON_DECL_H__
#define __BANKING_COMMON_DECL_H__

#include <iostream>
#include <cstring>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::strlen;
using std::strcpy;
using std::strcmp;
using std::exit;
using std::ostream;
using std::istream;
const int NAME_LEN = 20;

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
enum {RANK_A=1, RANK_B, RANK_C};
enum {NORMAL=1, CREDIT};
#endif