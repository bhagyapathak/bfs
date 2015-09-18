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



System Calls
=============

System calls are the APIs provided by the kernel to the user space applications to get work done by the kernel. There are few things involved in a system call.

The system call is called by the application
The arguements are copied to the registers 
The user space application changes the mode of the system to the priviledge mode by calling either int 80h, sysenter, or syscall interface.


We will try to see how a system call is called by looking at the assembly code of the following C program.

::

	int main() {
	int fd=open("Hello_world", RO);
	if (fd) {
		if (write(fd, "hello", strlen("hello"))) {
			printf("Write success");
			}
		}
	return 0;
	}

If you look at the dis assembly of the above code you will find two system calls open and write and how the parameters are passed. 

Implementing the system call
----------------------------

As an example we willl take the fsstat system call to implement by our selves. The kernel level code has already been discussed in the chaper of VFS, you just need to implement a system call to understand the how can you imeplement a system call for fun or profit.



System calls for file system
============================

The idea here is to open up every system call for the readers by the means of some exercises.

open - see the data structures created by the system call, like the entry of the file desciptor in the files array of the task struct.

read - 

write - 

close - see the effect of it in the task struct

dup - see the effect in the task struct

ioctl - 

lseek - see the effect in the file object

fstat - extract the information from the fd

stat - extract the information from the path name provided

lstat - extract the information of the link

chmod - change the mode in the file

chown - change the owner of the file

unlink - unlink the file 

link - link the file

symlink - create the symbolic link

getcwd - get the current working directory

opendir - not required

readdir - not required

telldir - not required

seekdir - not required

closedir - not required

fcntl - not required

mmap - not required

mkdir - not required 

rmdir - not required

chdir - not required
