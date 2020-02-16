CFLAGS = -O3
CXXFLAGS = $(CFLAGS)
CC = clang
CXX = clang++

all: elf.out retf.bin cpuid.o movaps wait_value_change.o wait_value_change_no_volatile.o zero.o formatint.o

elf.out: elf.o
	$(CXX) -o $@ $<

%.bin: %.asm
	nasm -f bin -o $@ $<

%.o: %.asm
	nasm -f elf64 -o $@ $<

movaps: movaps.cpp
	$(CXX) -DNOALIGN $(CPPFLAGS) $(CXXFLAGS) -o $@ $^

.PHONY: run_mikanos
run_mikanos:
	qemu-system-x86_64 -m 1G \
	-drive if=pflash,format=raw,readonly,file=./OVMF_CODE.fd \
	-drive if=pflash,format=raw,file=./OVMF_VARS.fd \
	-drive if=ide,index=0,media=disk,format=raw,file=./mikanos.img \
	-device nec-usb-xhci,id=xhci -device usb-mouse -device usb-kbd \
	-monitor stdio -gdb tcp::1234
