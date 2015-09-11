#############
Prerequisites
#############

Task 1:

Virtual machine with fedora 22 installed.

Here is the link : https://getfedora.org/en/workstation/

Make sure you use a VM for this - this will save a lot of hassles of Rebooting.
 
 Run the following commands to configure the system

 systemctl set-default multi-user.target # This stops the machine to boot into
 graphical mode saving important time
 systemctl enable sshd.service # Enables ssh in system start

 References to understand the above

 https://fedoraproject.org/wiki/Systemd
 https://ask.fedoraproject.org/en/question/42485/runlevel-3-in-fedora-20/
 http://fedoraproject.org/wiki/Systemd#How_do_I_change_the_default_target

 http://docs.fedoraproject.org/en-US/Fedora/14/html/Deployment_Guide/s2-ssh-configuration-sshd.html
 http://linuxconfig.org/how-to-install-start-and-connect-to-ssh-server-on-fedora-linux

 Install gcc, vim, and git

  dnf install gcc vim git # Yum is now dnf - use this to install softwares.

  Install 4.2.0-rc7 kernel on it. Get the kernel from kernel.org

  You need to be root or use sudo

  tar -xf tarball
  make
  make modules
  make modules_install
  make install

  Download the attached files and


  make
  insmod hello.ko
  dmesg | grep hello -i

  This will help you setup the machine for development.


  2. Install python-docutils package. We will use Sphinx tool for writing our
  documentation. Here is the link http://sphinx-doc.org/

  Try writing some hello world document in that.


  3. Checkout the code from git@github.com:abrrba/bfs.git  -- you will need a
  github account. Upload your ssh keys for passwordless authentication.

  How to upload the key?

  do "ssh-keygen" keep pressing enter

  At the end of the command do "cat .ssh/id_rsa.pub" and copy the text from
  "ssh-rsa" to end.

  Then in https://github.com/settings/profile page go to SSH Keys (direct link
  is https://github.com/settings/ssh") and upload your keys.

  Read about it if required.


  The second tasks are as follows - read the following chapters of the following
  attached books.

  This is important so that we get connected to the fundamentals of operating
  systems. You are free to read the whole books as well !!

  Linux Kernel Development - Chapter 1, 2, 5, 12 and 13

  Understanding The Unix Kernel - Chapter 12 and Chapter 18

  The Design Of Unix Operating System - Chapters 1, 2, 3, 4, 5

  For those who are already comfortable with the chapters should also skim the
  chapters once just to revise them.

  The ETA for this task is 4th September. 



  Third task - I might be out of email communication while traveling hence
  giving the next task list.

  Attached is a document which you all should go through and complete.

  ETA is 9th September.

  This will end all the foundational work we need to do for this book.

  A lot of part of the documents I shared will be put in the book as well.

  Incase you need any help and have questions - ask me - I will be happy to
  answer those.
