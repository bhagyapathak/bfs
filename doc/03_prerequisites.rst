#############
Prerequisites
#############


**********************************
The coding and testing enviornment
**********************************

#. Virtual Machine with Linux Installed on it.
#. Install gcc, vim, and git
#. Install 4.2.0-rc7 kernel on it. Get the kernel from kernel.org. See  :ref:`install_linux_kernel-label`.
#. Write and test a sample kernel module. See :ref:`test_kernel_module-label`.


::
  
  make
  insmod hello.ko
  dmesg | grep hello -i

#. Install python-docutils package. We will use Sphinx tool for writing our documentation. Here is the link http://sphinx-doc.org/ 
  Try writing some hello world document in that. Use the following convention.

  ::

    Normally, there are no heading levels assigned to certain characters as the
    structure is determined from the succession of headings. However, for the Python
    documentation, this convention is used which you may follow:
    
    # with overline, for parts
    
    * with overline, for chapters
    
    =, for sections
    
    -, for subsections
    
    ^, for subsubsections
    
    ", for paragraphs

#. Checkout the code from git@github.com:abrrba/bfs.git  -- you will need a github account. Upload your ssh keys for passwordless authentication.

  How to upload the key?

  do "ssh-keygen" keep pressing enter

  At the end of the command do "cat .ssh/id_rsa.pub" and copy the text from
  "ssh-rsa" to end.

  Then in https://github.com/settings/profile page go to SSH Keys (direct link
  is https://github.com/settings/ssh") and upload your keys.

  Read about it if required.

*******
Reading
*******


This is important so that we get connected to the fundamentals of operating
systems. You are free to read the whole books as well !!

.. note:: For those who are already comfortable with the chapters should also skim the chapters once just to revise them.

#. Linux Kernel Development
    Chapter 01 - Introduction to the Linux Kernel 
    Chapter 02 - Getting startted with the kernel
    Chapter 05 - System Calls
    Chapter 12 - Memory Management
    Chapter 13 - The Virtual File System

#. Understanding The Unix Kernel
    Chapter 12 - The Virtual File System
    Chapter 18 - The Ext2 File System

#. The Design Of Unix Operating System
    Chapter 01 - General Overview of the system
    Chapter 02 - Introduction to the kernel
    Chapter 03 - The Buffer Cache
    Chapter 04 - Internal Representation Of Files
    Chapter 05 - System Calls For The File System


.. _install_linux_kernel-label:

***********************
Installing Linux Kernel
***********************


You need to be root or use sudo

  
#. :command:`tar -xf tarball`
#. :command:`make`
#. :command:`make modules`
#. :command:`make modules_install`
#. :command:`make install`

.. _test_kernel_module-label:

******************
Test Kernel Module
******************


