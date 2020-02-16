#include <cstdarg>
#include <cstdio>

void print_console(const char*);
int counter;

int printk(const char* format, ...) {
  va_list ap;
  int result;
  char s[1024];

  ++counter;

  va_start(ap, format);
  result = vsprintf(s, format, ap);
  va_end(ap);

  print_console(s);
  return result;
}

void print_console(const char* s) {
  puts(s);
}

int main() {
  printk("hello%c world", ',');
  return 0;
}
