############
Introduction
############

Linux Kernel Programming is one of the most exciting thing for the beginners in
System Programming. With time a lot of excellent books were published on it but
the books were written to cover everything about the Linux Kernel and thus had a
widespread scope. These books enabled to take a lot of people to take kernel
programming as their career chocices or as a hobby. We have been trying to find
a book which specifically deals with the storage subsytem of the Linux kernel
and written in a way that it is actually a DIY type of project. 

We did not find them, hence we decided to write one our selves.

This book will enable the readers to understand the working of a file system
better. The book is actully a documented version of a file system which enables
the readers to walk through the code and understadnig the code through the
commentrary around the code.

The book is divided into three parts

1. Basics of Kernel Programming
        In this section we will deal with kernel module programming, proc
        interface, some data strucutues avaibalable in the kernel space,
        character device driver for communicatiing with the user space, and
        other good stuff.

2. Understanding the File System realted pieces of linux kernel
        Here we understand how the file system is orgranged in the kernel. This
        gives us a very good understanding on how and what are the critical
        components in a file sytem and how are things maintained in a running
        linux kernel.

3. Project on writing the file system.
        This one is interesting, we write a complete file system from scratch
        here. We do the release planning and we understand the feautres, we
        decide the disk layout and we start coding and testing the file system.
        We do the performance testing, we add some cool features and thus we
        have a very good file system ready in few days.




==========
Motivation
==========
Copied from another book of mine

While learning the nitty gritties of linux kernel I found that there is not document which tells the details in the way most of the people understand. I also saw a lot of requests on kernel new bies for tutorials and documents which can help programmers and learners in a hands-on way.

This document is just a small attempt for bridging the gap between the hands-on and theory.

While interacting with students related to Linux and Linux Kernel I found that they do not have a head start guide which gives a detailed view of the whle linux system. Moreover there is no such document which is hands-on based, exercise based. 

I see a lot of questions on mailing lists asking for help in starting with linux kernel and then getting lost in the wide amount of unstructed information present every where.
