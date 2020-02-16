#include <stdint.h>

struct CPUIDResult {
  uint32_t eax, ebx, ecx, edx;
};

struct CPUIDResult ReadCPUID(uint32_t eax, uint32_t ecx) {
  struct CPUIDResult r;
  __asm__("cpuid" : "=a"(r.eax), "=b"(r.ebx), "=c"(r.ecx), "=d"(r.edx) : "0"(eax), "2"(ecx));
  return r;
}
