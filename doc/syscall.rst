##########################
Implementing a System Call
##########################


On a 32 bit machine 
===================

/home/rishi/linux-3.9.3/arch/x86/syscalls - file syscall_32.tbl 

Make an entry in the file with the system call name 

_64 file for 64 bit machineas




How to add a new Linux kernel API in 3.3 version? -- for 64 bits OS

get kernel codes from www.kernel.org.

wget http://www.kernel.org/pub/linux/kernel/v3.0/linux-3.3.1.tar.bz2

Upzip it with command ‘tar xvfj XXX” to a folder For example : /root/kernel tar xvfj linux-3.3.1.tar.bz2

Edit file “/root/kernel/linux-3.3.1/arch/x86/syscalls/syscall_64.tbl” Add new line

312 64 husky1 sys_husky1

Eidt file “/root/kernel/linux-3.3.1/include/linux/syscalls.h” Add new function declaration

asmlinkage long sys_husky1(int fd);

before the line “#endif”

Add a new c file under “/root/kernel/linux-3.3.1/arch/x86/kernel” (I am using x86 CPU) Example :

Edit “/root/kernel/linux-3.3.1/arch/x86/kernel/Makefile” Add a new line “obj-y += husky.o”

goto /root/kernel/linux-3.3.1 folder and run command “make –j8”


