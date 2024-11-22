#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include "ft_printf.h"

void print_separator(void) {
    printf("\n%s\n", "----------------------------------------");
}

void test_char(char c) {
    int len1, len2;
    printf("\nTesting char: '%c'\n", c);
    len1 = printf("Main printf: %c\n", c);  // Adjusted label
    len2 = ft_printf("Your printf: %c\n", c); // Adjusted label
    printf("Lengths -> Expected: %d | Yours: %d | %s\n", len1, len2, (len1 == len2) ? "✓" : "✗");
}

void test_string(char *str) {
    int len1, len2;
    printf("\nTesting string: \"%s\"\n", str ? str : "NULL");
    len1 = printf("Main printf: %s\n", str ? str : "(null)"); // Adjusted label
    len2 = ft_printf("Your printf: %s\n", str ? str : "(null)"); // Adjusted label
    printf("Lengths -> Expected: %d | Yours: %d | %s\n", len1, len2, (len1 == len2) ? "✓" : "✗");
}

void test_number(int n) {
    int len1, len2;
    printf("\nTesting number: %d\n", n);
    len1 = printf("Main printf: %d\n", n); // Adjusted label
    len2 = ft_printf("Your printf: %d\n", n); // Adjusted label
    printf("Lengths -> Expected: %d | Yours: %d | %s\n", len1, len2, (len1 == len2) ? "✓" : "✗");
}

void test_unsigned(unsigned int n) {
    int len1, len2;
    printf("\nTesting unsigned: %u\n", n);
    len1 = printf("Main printf: %u\n", n); // Adjusted label
    len2 = ft_printf("Your printf: %u\n", n); // Adjusted label
    printf("Lengths -> Expected: %d | Yours: %d | %s\n", len1, len2, (len1 == len2) ? "✓" : "✗");
}

void test_hex(unsigned int n) {
    int len1, len2;
    printf("\nTesting hex: %x\n", n); // Remove #
    len1 = printf("Main printf: %x\n", n); // Adjusted label
    len2 = ft_printf("Your printf: %x\n", n); // Adjusted label
    printf("Lengths -> Expected: %d | Yours: %d | %s\n", len1, len2, (len1 == len2) ? "✓" : "✗");
}

void test_pointer(void *ptr) {
    int len1, len2;
    printf("\nTesting pointer: %p\n", ptr);
    len1 = printf("Main printf: %p\n", ptr); // Adjusted label
    len2 = ft_printf("Your printf: %p\n", ptr); // Adjusted label
    printf("Lengths -> Expected: %d | Yours: %d | %s\n", len1, len2, (len1 == len2) ? "✓" : "✗");
}

int main(void) {
    int num;
    char *str;
    void *ptr1;
    void *ptr2;

    // Test Characters
    printf("\n=== CHARACTER TESTS ===");
    print_separator();
    test_char('A');
    test_char('0');
    test_char(' ');
    test_char('\t');
    test_char(127); // DEL character

    // Test Strings
    printf("\n=== STRING TESTS ===");
    print_separator();
    test_string("Hello, World!");
    test_string("");   // Empty string
    test_string(NULL); // NULL string
    test_string("Testing\nNew\tLine\rand\ttabs");
    test_string("@#$%^&*()_+"); // Special characters

    // Test Numbers
    printf("\n=== NUMBER TESTS ===");
    print_separator();
    test_number(0);
    test_number(-42);
    test_number(42);
    test_number(INT_MAX);
    test_number(INT_MIN);
    test_number(-0);
    test_number(2147483647);
    test_number(-2147483648);

    // Test Unsigned Numbers
    printf("\n=== UNSIGNED NUMBER TESTS ===");
    print_separator();
    test_unsigned(0);
    test_unsigned(42);
    test_unsigned(UINT_MAX);
    test_unsigned(2147483648);
    test_unsigned(4294967295);
    test_unsigned(1000000000);

    // Test Hexadecimal (lowercase)
    printf("\n=== HEXADECIMAL TESTS (lowercase) ===");
    print_separator();
    test_hex(0);
    test_hex(255);
    test_hex(4096);
    test_hex(UINT_MAX);
    test_hex(0xabcdef);
    test_hex(0x123456);

    // Test Hexadecimal (uppercase)
    printf("\n=== HEXADECIMAL TESTS (uppercase) ===");
    print_separator();
    test_hex(0);
    test_hex(255);
    test_hex(4096);
    test_hex(UINT_MAX);
    test_hex(0xABCDEF);
    test_hex(0x123456);

    // Test Pointers
    printf("\n=== POINTER TESTS ===");
    print_separator();
    num = 42;
    str = "test";
    ptr1 = &num;
    ptr2 = &str;
    test_pointer(ptr1);
    test_pointer(ptr2);
    test_pointer(NULL);
    test_pointer((void *)0xABCDEF);

	printf("\n=== ERROR TESTS ===\n");
    print_separator();

    // 1. NULL Format String
    int len1 = printf(NULL, num);
    int len2 = ft_printf(NULL, num);
    printf("NULL format string: true len = %d | My len = %d --> %s\n", len1, len2, (len1 == len2) ? "OK :)" : "KO :(");

    // 3. Invalid Memory Access (Dereferencing NULL pointer)
    char* invalid_pointer = NULL;
    len1 = printf("Dereferencing pointer: %s", invalid_pointer);
    len2 = ft_printf("Dereferencing pointer: %s", invalid_pointer);
	printf("Dereferencing NULL pointer: Truelen = %d | Mylen = %d --> %s\n", len1, len2, (len1 == len2)?"OK :)":"KO :(");
	
	printf("\n========= Testat Lmla7 =========\n");
	
	len1 = printf(" %u %u %lu %lu %lu %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	len2 = ft_printf(" %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("Lengths -> Expected: %d | Yours: %d | %s\n", len1, len2, (len1 == len2) ? "✓" : "✗");

	len1 = printf(" %x %x %lx %lx %lx %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	len2 = ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("Lengths -> Expected: %d | Yours: %d | %s\n", len1, len2, (len1 == len2) ? "✓" : "✗");

	len1 = printf(" %X %X %lX %lX %lX %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	len2 = ft_printf(" %X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("Lengths -> Expected: %d | Yours: %d | %s\n", len1, len2, (len1 == len2) ? "✓" : "✗");

	len1 = printf(" %p %p %p %p %p %p %p\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	len2 = ft_printf(" %p %p %p %p %p %p %p\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("Lengths -> Expected: %d | Yours: %d | %s\n", len1, len2, (len1 == len2) ? "✓" : "✗");

	len1 = printf(" %i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	len2 = ft_printf(" %i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("Lengths -> Expected: %d | Yours: %d | %s\n", len1, len2, (len1 == len2) ? "✓" : "✗");

	printf("\n=== TESTS COMPLETED ===\n");
	return (0);
}
