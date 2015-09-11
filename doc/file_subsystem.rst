
File Subsystem
===============

Linux File Susbsystem completely depends on the Virtual File System Layer.  If you see it diagramitically the VFS layer sits just below the user space and kernel space divison where it is responsible for all the file system related system calls. The system calls like open() read() write() etc are implemented as sys_read sys_open functions in the kernel space.  You can read the chapter on system calls to understand this detail as this chapter mainly deals with Linux File Susbsystem.  
VFS layer can be thought of a protocol which the file systems should abide to if they want to get supported by the Linux Kernel. It is the responsiblity of the FS developer to write functions so that the file system behaves the way VFS wants it to behave.

VFS layer comprises of 4 types of object and associated functions with it. The objects are super_block object, inode object, dentry object and file object. Out of these four only File object does not have a corresponding on disk data struture and is generated on the fly. Here in this chaper we will try to write exercises and code to understand each object properly.
