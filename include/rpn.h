#ifndef RPN_INCLUDE_RPN_H_
#define RPN_INCLUDE_RPN_H_

#include <ctype.h>

#include "deque.h"

void convert_to_rpn(Deque *rpn, const char *infix);
int get_priority(int op);
bool is_operation(int op);
int is_less_eq_p(int op1, int op2);
bool is_function(int op);

#endif  // RPN_INCLUDE_RPN_H_
