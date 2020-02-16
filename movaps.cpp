#include <iostream>

struct SomeLarge {
  unsigned long x, y;
};

void print(const SomeLarge& a) {
  std::cout << a.x << ", " << a.y << std::endl;
}

int main() {
#ifdef NOALIGN
  __asm__("push %rdi");
#endif

  print({1, 2});

#ifdef NOALIGN
  __asm__("pop %rdi");
#endif
}
