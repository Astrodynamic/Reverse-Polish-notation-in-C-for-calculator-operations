#include "rpn.h"

void convert_to_rpn(Deque *rpn, const char *infix) {
  int op = 0;
  char *p_str = (char *)infix;
  Deque *stack = init_deque();
  while (*p_str != '\n' && *p_str != '\0') {
    if (*p_str == 'x') {
      d_push_b(rpn, VARIABLE);
      p_str++;
    } else if (isdigit(*p_str)) {
      d_push_b(rpn, NUMBER, strtod(p_str, &p_str));
    } else if (is_function(*p_str)) {
      d_push_f(stack, OPERATION, *p_str++);
    } else if (is_operation(*p_str)) {
      while (d_get_operation_f(stack, &op) && is_less_eq_p(*p_str, op))
        d_push_lexem_b(rpn, d_pop_lexem_f(stack));
      d_push_f(stack, OPERATION, *p_str++);
    } else if (*p_str == '(') {
      d_push_f(stack, OPERATION, *p_str++);
    } else if (*p_str++ == ')') {
      while (d_get_operation_f(stack, &op) && op != '(')
        d_push_lexem_b(rpn, d_pop_lexem_f(stack));
      free(d_pop_lexem_f(stack));
      if (d_get_operation_f(stack, &op) && is_function(op))
        d_push_lexem_b(rpn, d_pop_lexem_f(stack));
    }
  }
  while (stack->head) d_push_lexem_b(rpn, d_pop_lexem_f(stack));
  d_free(stack);
  free(stack);
}

int get_priority(int op) {
  int result = 6;
  const char *s_op = "(+-*/A^BC";
  const int p_op[9] = {0, 1, 1, 2, 2, 2, 3, 4, 4};
  if (strchr(s_op, op)) result = p_op[strchr(s_op, op) - s_op];
  return result;
}

int is_less_eq_p(int op1, int op2) {
  return get_priority(op1) <= get_priority(op2);
}

bool is_operation(int op) { return strchr("+-*/^ABC", op); }

bool is_function(int op) { return (op >= 'D' && op <= 'L'); }
