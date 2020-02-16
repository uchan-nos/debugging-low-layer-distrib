#include <cstdint>

uint64_t tick;

__attribute__((interrupt))
void IntHandlerLAPICTimer(void*) {
  ++tick;
  *reinterpret_cast<volatile uint32_t*>(0xfee000b0) = 0;
}

void WaitTick(uint64_t until) {
  while (tick < until);
}
