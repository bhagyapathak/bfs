Ext3 File System
================

We will look into the ext3 file system which will help us understand a basic file system.

We will now print some of the file system specific data which will help us understand any file system better.

With any exercise we will discuss the details of that on disk data structure.

ext3 disk layout


Ex 1 - read the on disk inode fields of a file passed from ioctl

Ex 2 - print the superblock 

Ex 3 - Print the group descriptor

Ex -4 - print the data blocks of any inode, read the direct, indirect and double indirect blocks as well

Ex -5 - journalling, how to make a journal

Small project 1 

Let us try to add a functionality to the ext3 file system. It will be that of a file create time stamp. We will add an inode field to track this. Our own stat() system will read this and tell you.

Second we will do it via extended attributes.

truncate() system call.

Some Projects
==============

Print Usage Stats
-----------------

QUzint is a small project developped for UZINT lecture at Warsaw University of Technology. It's goal is to create a program which would analise and collect an ext2 usage statistics. QUzint uses Qt as a mean to provide nice user interface. 

Undelete a file in ext2
------------------------

let us find out how a file is deleted in ext2 file system, and then we will try to undelete a file

Recycle Bin for ext2
--------------------

- we will immplement a recycle bin for ext3 where any file when it is deleted will be moved to the ./lost+found directory - when the file system will be full 70% it will delete some files from the directory. The 70% can e managed

Ext2 with advanced features
----------------------------

Changing ext3's name to any other name and using the same code base, basicaly if a user has root file system of type ext3 and wants to use a feature rich ext3 file system then what does he do.

e2fsprogs
---------

http://en.wikipedia.org/wiki/E2fsprogs has a list of projects which are done on ext2 file system, we can open up the code of the projects for us.

Follwing projects can be implemented

resize2fs 
++++++++++
which can expand and shrink ext2, ext3 and ext4 file systems

tune2fs 
++++++++
used to modify file system parameters

dumpe2fs 
+++++++++
which prints superblock and block group information.


filefrag 
+++++++++
report on file fragmentation

findfs 
+++++++
find a filesystem by label or UUID

e2freefrag 
+++++++++++
report free space fragmentation information

chattr 
+++++++
change file attributes on a Linux file system

e2image 
++++++++
save critical ext2/ext3/ext4 filesystem metadata to a file

findsuper 
++++++++++
quick hacked up program to find ext2 superblocks

lsattr 
+++++++
list file attributes on a Linux second extended file system

Many of these utilities are based on the libext2fs library.

Writing a file system
---------------------

In a separate document we will write a full file system
