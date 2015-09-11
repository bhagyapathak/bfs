==============
Kernel Project
==============

Problem Statement
-----------------

* We want to track the last user who modified the file for ext2 file system. Currently ``ext2`` file system does not maintain such information.

Implementation Plan
-------------------

* Find the function which is called when any ext2 file is opened.
* Change the code so that your written function is called rather than the existing function. Your function in-turn calls the existing functions. In short add a hook to the existing code.
* Add a new field in the inode, generally these kind of information are kept in the extended attributes but for the sake of simplicity we will add a inode field. The field needs to be added to the disk inode version as well as the in memory copy of the inode. The readers should try implementing the extended attribute version of the project.
* Check if the file system is getting mounted, after adding the new field.
* In the function my_open() update the field when the file is opened in the write mode. You need to mark the inode dirty and sync the inode.
* Add a proc interface which will help me access the ``muid`` field.


Step 0
------

* Make changes to the ``ext2_fsync`` function. Just add a ``printk`` to understand how to modify the code, compile and install them.

.. literalinclude:: code/kernel/project01/add_printk/add_printk.diff
    :language: c
    :linenos: 

* Compile the code with 
   ``make SUBDIRS=fs/ext2``
* Replace the modules so that you modules gets loaded.
   ``cp fs/ext2/ext2.ko /lib/modules/3.4.6/kernel/fs/ext2/ext2.ko``
* Set up a loop device to work with.
   ``dd if=/dev/zero of=ext2_fs bs=1M count=100;``
   ``losetup /dev/loop0 ext2_fs``
* Mount a loop device
   ``mke2fs /dev/loop0;``
   ``mount /dev/loop0 /mnt``
* Write small scripts which will do petty jobs for you.

Step 1
------

* Write a function my_open() which calls the function ``dquot_file_open``. Make changes to the ext2 code in ``ext2_file_operations`` structure's open function. Make it call ``my_open()`` written by you in the file ext2/file.c. Your function should just be a wrapper and not alter the functionality.
* Also change the ext2.h file to add your function's declaration.

.. literalinclude:: code/kernel/project01/my_open/my_open.diff
    :language: c
    :linenos: 

* Compile - install - umount - rmmod ext2 - mount - check in dmesg

Step 2
------

* Make changes to the ext2 inode and add a ``muid`` field of type. 
* You will need to make changes in the incore data structures as well.
* ``mke2fs`` command should be called with -I 256 to ensure that the new field is accomodated. ``-I`` option changes the inode size.
* ``mkfs -I 256 /dev/loop0``

.. literalinclude:: code/kernel/project01/added_muid/added_muid.diff
    :language: c
    :linenos: 

* Compile - install - umount - rmmod ext2 - mount - check in dmesg

Step 3
------

* Add code to update the ``muid`` field whenever the file is opened for write. Also mark the inode dirty and sync it to the disk.

.. literalinclude:: code/kernel/project01/ext2_update_muid_field_on_modification/update_muid.diff
    :language: c    
    :linenos:   

.. literalinclude:: code/kernel/project01/ext2_update_muid_field_on_modification/inode.diff
    :language: c    
    :linenos:   

* Compile - install - umount - rmmod ext2 - mount - check in dmesg

Step 4
------

* Add proc interface to the file system for managment of new features. The proc interface will provide the functionality to print the ``muid`` field if the filename is provided..

* Add a file proc.c to the modules directory.   

.. literalinclude:: code/kernel/project01/ext2_proc_interface/proc.c
    :language: c 
    :linenos: 

* Make changes to super.c

.. literalinclude:: code/kernel/project01/ext2_proc_interface/super.diff
    :language: c 
    :linenos: 

* Make changes to the Makefile as well

.. literalinclude:: code/kernel/project01/ext2_proc_interface/makefile.diff
    :language: c 
    :linenos: 

* ``echo "PFD /mnt/filename" > /proc/driver/linuxKernel101``


* Compile - install - umount - rmmod ext2 - mount - check in dmesg
* Make another user in your system and make changes to file system using that user.
* Check if the correct muid is printing or not.
 
Enhancements
------------

* Write a user space tool to interact with the feature and generate reports.
* Find out the synchronization issues in the enhancement, solve them.
* Write code so that the admin can enable and disable the feature.
* Write code so that the feature can be enabled on specific mountpoints.
* Port the code to the ext2/ext4 file systems, take care of journalling.
