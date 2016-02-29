
#ifndef __COMB
#define __COMB

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN extern
#endif

#define __COMB_ID int
#define __COMB_BRANCH_ID int
#define __COMB_FUNCTION_ID unsigned int
#define __COMB_VALUE long long int
#define __COMB_ADDR unsigned long int
#define __COMB_OP int
#define __COMB_BOOL unsigned char
#include "stdint.h"
 struct buginfor{
	unsigned long int line;
	char * filename;
	char * dir;
};
enum {
  /* binary arithmetic */
  __COMB_ADD       =  0,
  __COMB_SUBTRACT  =  1,
  __COMB_MULTIPLY  =  2,
  __COMB_DIVIDE    =  3,
  __COMB_MOD       =  4,
  /* binary bitwise operators */
  __COMB_AND       =  5,
  __COMB_OR        =  6,
  __COMB_XOR       =  7,
  __COMB_SHIFT_L   =  8,
  __COMB_SHIFT_R   =  9,
  /* binary logical operators */
  __COMB_L_AND     = 10,
  __COMB_L_OR      = 11,
  /* binary comparison */
  __COMB_EQ        = 12,
  __COMB_NEQ       = 13,
  __COMB_GT        = 14,
  __COMB_LEQ       = 15,
  __COMB_LT        = 16,
  __COMB_GEQ       = 17,
  /* unhandled binary operators */
  __COMB_CONCRETE  = 18,
  /* unary operators */
  __COMB_NEGATE    = 19,
  __COMB_NOT       = 20,
  __COMB_L_NOT     = 21,
};
enum binary_op { ADD = 0, SUB, MUL, DIV, MOD, SHIFT_L, CONCRETE };
/*
 * Short-cut to indicate that a function should be skipped during
 * instrumentation.
 */

EXTERN void __Init();
//把整型变量强制转化之后再load
EXTERN void __LoadI(__COMB_ID, __COMB_ADDR,__COMB_VALUE);
EXTERN void __LoadF(__COMB_ID, __COMB_ADDR,double);

EXTERN void __LoadInt8(__COMB_ID, __COMB_ADDR, int8_t) ;
EXTERN void __LoadInt16(__COMB_ID, __COMB_ADDR, int16_t) ;
EXTERN void __LoadInt32(__COMB_ID, __COMB_ADDR, int32_t) ;
EXTERN void __LoadInt64(__COMB_ID, __COMB_ADDR, int64_t) ;
EXTERN void __LoadFloat(__COMB_ID, __COMB_ADDR, float) ;
EXTERN void __LoadDouble(__COMB_ID, __COMB_ADDR, double) ;

EXTERN void __StoreTo(__COMB_ID, __COMB_ADDR, __COMB_VALUE) ;
EXTERN void __ClearStack(__COMB_ID);

EXTERN void __ApplyInt8(__COMB_ID, __COMB_OP, int8_t);
EXTERN void __ApplyInt16(__COMB_ID, __COMB_OP, int16_t);
EXTERN void __ApplyInt32(__COMB_ID, __COMB_OP, int32_t);
EXTERN void __ApplyInt64(__COMB_ID, __COMB_OP, int64_t);
EXTERN void __ApplyFloat(__COMB_ID, __COMB_OP, float);
EXTERN void __ApplyDouble(__COMB_ID, __COMB_OP, double);
EXTERN void __ApplyCmp(__COMB_ID, __COMB_OP, __COMB_BOOL);

EXTERN void __Branch(__COMB_ID, __COMB_BRANCH_ID, __COMB_BOOL);
EXTERN void __FuncReturn(__COMB_ID);
EXTERN void __FuncCall(__COMB_ID, __COMB_FUNCTION_ID);
EXTERN void __HandleReturn(__COMB_ID, __COMB_VALUE);

#define mksymbol_uchar(x) __MkSymbolUChar(&x)
#define mksymbol_ushort(x) __MkSymbolUShort(&x)
#define mksymbol_uint(x) __MkSymbolUInt(&x)
#define mksymbol_char(x) __MkSymbolChar(&x)
#define mksymbol_short(x) __MkSymbolShort(&x)
#define mksymbol_int(x) __MkSymbolInt(&x)
#define mksymbol_float(x) __MkSymbolFloat(&x)
#define mksymbol_double(x) __MkSymbolsDouble(&x)

EXTERN void __MkSymbolUChar(unsigned char* x);
EXTERN void __MkSymbolUShort(unsigned short* x);
EXTERN void __MkSymbolUInt(unsigned int* x);
EXTERN void __MkSymbolChar(char* x);
EXTERN void __MkSymbolShort(short* x);
EXTERN void __MkSymbolInt(int* x);
EXTERN void __MkSymbolFloat(float* x);
EXTERN void __MkSymbolsDouble(double* x);

EXTERN void __HandleInt8(__COMB_ID id, __COMB_VALUE val) ;
EXTERN void __HandleInt16(__COMB_ID id, __COMB_VALUE val) ;
EXTERN void __HandleInt32(__COMB_ID id, __COMB_VALUE val) ;
EXTERN void __HandleInt64(__COMB_ID id, __COMB_VALUE val) ;
EXTERN void __HandleFloat(__COMB_ID id, __COMB_VALUE val);
EXTERN void __HandleDouble(__COMB_ID id, __COMB_VALUE val) ;

EXTERN void __array_check(__COMB_VALUE bound,__COMB_ADDR  index_addr,__COMB_VALUE index_value, __COMB_VALUE line);
EXTERN void __pointer_check(__COMB_ADDR index_addr,__COMB_VALUE  bound,__COMB_VALUE index_value,__COMB_VALUE each_size, __COMB_VALUE line);
EXTERN void __malloc_check(__COMB_ADDR addr,__COMB_VALUE size, __COMB_VALUE line);
EXTERN void __free_check(__COMB_ADDR addr,__COMB_VALUE line);
void check_memory_leak();
EXTERN void __array_init(__COMB_ADDR addr,__COMB_VALUE size);
EXTERN void __ptrtoarray_check(__COMB_ADDR ptr_start_addr,__COMB_ADDR  index_addr,__COMB_VALUE index_value, __COMB_VALUE line);
/*
//模板函数声明和定义需要都放在头文件中，不可分开
template<typename ty>
EXTERN void __array_assume(ty array_type,long long int array_size,long long int array_begin){
	return ;
	}*/
#endif
