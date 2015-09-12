#############
Prerequisites
#############


**********************************
The coding and testing enviornment
**********************************

#. Virtual Machine with Linux Installed on it.
#. Install gcc, vim, and git
#. Install 4.2.0-rc7 kernel on it. Get the kernel from kernel.org

::
  
  You need to be root or use sudo
  tar -xf tarball
  make
  make modules
  make modules_install
  make install

#. Test if you are able to insert a module or no. Save the following code with the given filenames and test the following steps.

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

*************
Reading Stuff
*************

The second tasks are as follows - read the following chapters of the following
attached books.

This is important so that we get connected to the fundamentals of operating
systems. You are free to read the whole books as well !!

Linux Kernel Development - Chapter 1, 2, 5, 12 and 13

Understanding The Unix Kernel - Chapter 12 and Chapter 18

The Design Of Unix Operating System - Chapters 1, 2, 3, 4, 5

For those who are already comfortable with the chapters should also skim the chapters once just to revise them.
