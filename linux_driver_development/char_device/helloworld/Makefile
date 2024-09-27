# Guide to create a local Makefile to build a basic driver 
# obj-<X> := <module_name>.o
# obj-<X> is a kbuild variable and 'X' takes one value below:
# X = n, y, m where n = Do not compile module, y = Compile module & link with kernel image (static module) 
# and m = Compile as dynamic loaded kernel module

obj-m := hello_world.o

# Section to automate the build process and eliminate to type the long command
KERN_DIR = /lib/modules/$(shell uname -r)/build
host:
		make -C $(KERN_DIR) M=$(PWD) modules