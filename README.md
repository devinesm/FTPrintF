*This project has been created as part of the 42 curriculum by ipinto-m.*

## Description

**ft_printf** is a custom implementation of the standard C library function `printf`. This project aims to recreate the functionality of the original `printf` function, handling variable argument lists and formatting output according to specified format specifiers.

The goal of this project is to deepen understanding of:
- Variadic functions and variable argument lists in C
- String parsing and manipulation
- Format specifier handling
- Output formatting and type conversion

This implementation supports the most common format specifiers:
- `%c` - Character
- `%s` - String
- `%p` - Pointer (in hexadecimal format)
- `%d` / `%i` - Signed integer
- `%u` - Unsigned integer
- `%x` / `%X` - Hexadecimal (lowercase and uppercase)
- `%%` - Literal percent sign

## Instructions

### Compilation

To compile the project, simply run:

```bash
make
```

This will generate the `libftprintf.a` static library.

To clean object files:

```bash
make clean
```

To clean everything including the library:

```bash
make fclean
```

To recompile from scratch:

```bash
make re
```

### Installation

The library is compiled into `libftprintf.a`. To use it in your project:

1. Include the header file in your C code:
```c
#include "ft_printf.h"
```

2. Link the library during compilation:
```bash
gcc your_program.c -L. -lftprintf -o your_program
```

### Usage Examples

```c
#include "ft_printf.h"

int main(void)
{
    // Character
    ft_printf("%c\n", 'A');  // Output: A
    
    // String
    ft_printf("%s\n", "Hello");  // Output: Hello
    
    // Integer
    ft_printf("%d\n", 42);  // Output: 42
    
    // Hexadecimal
    ft_printf("%x\n", 255);  // Output: ff
    ft_printf("%X\n", 255);  // Output: FF
    
    // Unsigned integer
    ft_printf("%u\n", 4294967295);  // Output: 4294967295
    
    // Pointer
    int x = 10;
    ft_printf("%p\n", (void *)&x);  // Output: 0x7ffee...
    
    // Multiple arguments
    ft_printf("Number: %d, String: %s, Hex: %x\n", 42, "test", 255);
    
    return (0);
}
```

## Algorithm and Data Structure

### Variadic Functions (`stdarg.h`)

The core of this implementation relies on variadic functions, which allow a function to accept a variable number of arguments. The standard library provides three macros in `<stdarg.h>`:

1. **`va_list`**: A type to hold information about variable arguments
2. **`va_start(ap, last_fixed_arg)`**: Initializes the `va_list` to point to the first variable argument
3. **`va_arg(ap, type)`**: Retrieves the next argument of the specified type
4. **`va_end(ap)`**: Cleans up the `va_list`

### Implementation Strategy

The implementation uses a two-phase approach:

**Phase 1: Format String Parsing**
- The main `ft_printf()` function iterates through the format string character by character
- When a `%` is encountered, the next character is treated as a format specifier
- The corresponding `va_arg()` macro is used to extract the argument from the variable argument list
- Non-format characters are directly written to output

**Phase 2: Format Specifier Processing**
- A static helper function `get_format()` handles each format specifier
- Each specifier has a dedicated printing function:
  - `ft_print_char()` - outputs a single character
  - `ft_print_str()` - outputs a null-terminated string
  - `ft_print_numbers()` - handles signed integers with conversion to decimal
  - `ft_print_unsigned()` - handles unsigned integers
  - `ft_print_hex()` - converts integers to hexadecimal (base 16)
  - `ft_print_pointer()` - formats pointers with `0x` prefix

### Data Structure: Character Array Buffer

The implementation writes output directly to file descriptor 1 (standard output) using `write()` syscall. Each printing function:
- Converts the input value to its string representation
- Writes the result to the output
- Returns the count of characters written

### Type Conversion Logic

**For Integers:**
- Signed integers are processed digit by digit through repeated division by 10
- Negative numbers are handled by printing a `-` sign and processing the absolute value

**For Hexadecimal:**
- Unsigned integers are converted to base 16 using repeated division by 16
- Results are mapped to characters `0-9` and `a-f` (or `A-F` for uppercase)
- Pointers are printed with the `0x` prefix

**For Strings and Characters:**
- Strings are iterated and each character is written individually
- Characters are written directly with proper type casting

### Error Handling

The implementation returns:
- The total number of characters written on success
- `-1` on error (e.g., if `write()` fails)

## Resources

### Documentation and References

1. **GNU C Library Manual - stdarg.h**
   - Official documentation on variadic functions: https://man7.org/linux/man-pages/man3/stdarg.3.html

2. **Medium - Variadic Functions in C**
   - Comprehensive guide on using `stdarg.h`: https://medium.com/@scarletskynned/variadic-functions-in-c-stdarg-h-f466101f1d47

3. **Medium - va_list in C: Exploring ft_printf**
   - Detailed exploration of `va_list` implementation: https://medium.com/@turman1701/va-list-in-c-exploring-ft-printf-bb2a19fcd128

### AI Usage

AI was utilized in the following aspects of this project:

1. **Code Structure and Best Practices**
   - Guidance on organizing variadic function implementations
   - Recommendations for error handling patterns
   - Code formatting and style optimization

2. **Algorithm Explanation**
   - Clarification of how `va_list`, `va_start()`, `va_arg()`, and `va_end()` work internally
   - Understanding of the calling convention for variadic functions
   - Type casting and conversion logic for different format specifiers

3. **Debugging and Testing**
   - Assistance in identifying edge cases (null pointers, maximum values, etc.)
   - Validation of implementation correctness
   - Performance considerations for the conversion algorithms

4. **Documentation**
   - Structuring README with clear examples and explanations
   - Writing comprehensive algorithm descriptions
   - Creating usage examples for different format specifiers

## Project Structure

```
.
├── ft_printf.c           # Main printf implementation
├── ft_printf.h           # Header file with function declarations
├── ft_print_chars.c      # Character and string printing functions
├── ft_print_numbers.c    # Integer and unsigned printing functions
├── ft_print_hex.c        # Hexadecimal and pointer printing functions
├── Makefile              # Build configuration
├── README.md             # This file
└── libft/                # Libft dependency (standard utilities)
    └── [libft source files]
```

## Notes

- The implementation depends on the **libft** library, which provides standard utility functions like `ft_strlen()`
- The project uses only standard C library functions (no external dependencies beyond libft)
- Memory safety is maintained throughout; all functions validate inputs appropriately
- The implementation prioritizes correctness over performance, making it educational and easy to understand
