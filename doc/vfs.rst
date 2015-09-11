
Super_block Object
==================

The first thing we want to deal with is the super_block object. Super_block objects are used to keep track of the whole file system and the super_block operations are related to the whole file system. We will not go into the details of each operations and fields as they are already explained very well in a lot of other refereces present on Linux Kernel, but we will focus on how to extract information of the filesystem.

fsstat() system call - fsstat system call gives you information related to a mounted file system.

Let us write a code for it. Our char dev will help us here as well, as an exercise try to impleent a proc interface and system call for it.

Inode Object
============

Inode is the metadata structure for any file in the file system. Inodes thus keep all the information related to file in the file system. We can extract information related to file using the inode object. We have three system calls related to this activity 
stat
fstat
lstat.

We will try to implement all three using our chardev, as always try to implement the system call for it.

File Object
===========

We will now deal with File Object to understand what all can be done with it. 

We will try to rewrite the lseek and seek system calls for it. We will write a small application which will open the file, read some bytes and then using an ioctl we will move the file pointer a bit. We will again read and see from where the data is being read.


Dentry Object
=============

Using our code we will try to read the dentry cache and see what all files and thus inodes are present in the cache.

Dentry Cache - When ever we path lookup any path an entry in the dentry cache gets created which is actually a hash table, when the same path name component is looked for we get a small performance gain. 
