# Reverse Polish Notation Library

This library provides functions for converting infix notation to reverse Polish notation (RPN), which is a postfix notation used in calculators.

## Build

To build the library, run the following commands:

```
cmake -S . -B ./build
cmake --build ./build
```

## Usage

To use the library, include the header file `rpn.h` and link against the library file `RPN.a`. The library provides the function `convert_to_rpn`, which takes an infix expression as a string and converts it to RPN. The RPN expression is stored in a `Deque` data structure provided by the library.

Here's an example of using the library to convert the infix expression `"2 + 3 * (4 - 1)"` to RPN:

```c
#include <stdio.h>
#include "rpn.h"

int main() {
  Deque* rpn = init_deque();
  convert_to_rpn(rpn, "2 + 3 * (4 - 1)");
  while (!d_is_empty(rpn)) {
    Lexem lex = d_pop_lexem_b(rpn);
    if (lex.type == NUMBER) {
      printf("%f ", lex.value);
    } else {
      printf("%c ", lex.value);
    }
    free(lex.str);
  }
  d_free(rpn);
  free(rpn);
  return 0;
}
```

This will output the RPN expression `"2 3 4 1 - * +"`.

## Dependencies

This library depends on the `Deque` library, which provides a data structure for storing the RPN expression.

## Development

To contribute to the development of this library, you can use the following commands:

- `make cppcheck` - run cppcheck for code analysis
- `make clang-format` - run clang-format for code formatting
- `make clean` - clean the build directory
- `make rebuild` - clean the build directory and rebuild the library

## License

This library is licensed under the MIT License. See the `LICENSE` file for details.