KVERS = $(shell uname -r)

# Kernel modules
obj-m += globalmem.o
obj-m += multi_globalmem.o

# Specify flags for the module compilation.
#EXTRA_CFLAGS=-g -O0

build: kernel_modules app_modules

kernel_modules:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) modules
app_modules:
	gcc ioctl.c -o ioctl

clean:
	make -C /lib/modules/$(KVERS)/build M=$(CURDIR) clean
	rm ioctl
