Kernel Programming
==================

* This is simple C code :-)
* This is a **LARGE** C program :-)
* You have to be little more careful while coding.
* Small mistakes can compromise the whole system.


Kernel Modules
==============

* Pieces of code that can be loaded and unloaded into the kernel upon demand

* Extends the functionality of the kernel without the need to reboot the system

* Device drivers which allows the kernel to access hardware connected to the system


Kernel Module Advantages
------------------------

* Without modules, we would have to build monolithic kernels 

* Adding new functionality would require adding the code in the kernel image which will need recompilation.

* Monolithic kernel leads to  larger kernel images resulting in loading code which is not required

* Rebooting machine whenever new functionality is added

* Example: till the time you don't have to mount a ext2 file system why will you load code for reading ext2 file system


Compiling a Kernel
==================

* We may need to compile our own kernel to add/remove some features present in the system.
* The kernel distributed with **general settings** setting which should run on all the possible instalaltions.
* Thus they need to support a wide range of hardware
* Some of the features may e built in while some of them may be built as modules
* Its alright if they are built as module as they don't increase the size of the kernel.
* Built-in features will increase the size of kernel, thus effecting the system's performance.
* Making our own kernel will ensure the kernel is having appropriate set of features.
* Double check before you **remove** any feature, your freshly compiled kernel may not boot :-).
* Read ``Linux Kernel In A Nutshell`` for further understanding.

Compiling a Kernel - steps
---------------------------
* ``www.kernel.org`` - download the new kernel from this website.
* ``tar -xzf/xjf downloaded kernel``
* ``make oldconfig`` - makes the old configuration present in the system, if new features are present asks about them.
* ``make defconfig`` - makes the default configuration for your architecture, the configuration file is present in ``arch/ARCHITECTURE/configs/``.
* ``make gconfig`` - gives a GTK based configuration menu.
* ``make qconfig`` - gives a QT based configuration menu.
* ``make menuconfig`` - gives a ncurses based configuration menu.
* ``make modules`` - makes the modules.
* ``make modules_install`` - installs the modules to the required loaction usually ``/lib/modules/KERNEL-VERSION/kernel``.
* ``make install`` - installs the kernel in the required location usually ``/boot/``, makes the initial ramfs sets up the boot loader, you are now ready to reboot your system.
* ``Kernel Newbies`` - mailing list for newbies in kernel.

Hands-on make menunconfig - tweak settings
------------------------------------------
* goto - File systems -> 
   mark ``Ext2`` as module i.e. ``M``  use spacebar to toggle between the possible values
   mark ``Ext3`` as a built into images i.e. ``*``
* goto - File Systems -> DOS/NT Filesystem 
      remove VFAT support i.e. ``BLANK``
      add NTFS module support i.e. ``M``
*  go back using <esc><esc>
* Save the configuration, you will get a ``.config`` file in your directory.
* Use ``diff`` or ``vimdiff`` to see the changes between the default configuration file of your architecture and freshly generated ``.config`` file.
* Use ``diff`` or ``vimdiff`` to see the changes between the systems configuration file in your ``/boot/`` directory and the freshly generated ``.config`` file.
* Compile the kernel using the steps provided in the slide above.

Making Changes to Kernel Code - Steps
=====================================
* Make the changes in the required file, re-check it.
* ``make SUBDIRS="path"`` - to compile the particular module.
* ``make modules_install`` - to install the module, you can manually copy the module to the ``/lib/`` directory.
* ``make install`` - update the whole system if required, not required generally.
* Check the working of the code.

Hands On - Making changes to Kernel Code
----------------------------------------

* Make changes to the ext2 code. In the ``ext2_fsync`` function, add a ``printk`` and compile the code. Copy the modules to the ``/lib/XX`` directory and test by mounting a ext2 file system. Check ``dmesg`` for the printed message. Open/Write a file using ``vim`` to see the effects.

* The diff is based of ``linux-3.4.6 Kernel`` - use the same kernel version to avoid unneccessary problems at this stage.

.. code-block:: c
    :include: code/kernel/ext2_changed_code/file.c.diff
    :linenos: 

Kernel Module Examples
======================

Tools for kernel modules
------------------------

* ``insmod`` - insert module.
* ``modprobe`` - insert module.
* ``modprobe -r`` - remove the module present in the kernel.
* ``rmmod`` - remove the module present in the kernel.
* ``lsmod`` - list the modules inserted in the kernel.
* ``modinfo`` - prints the information of the module.
* ``init_module(), query_module(), create_module(), delete_module()`` - system calls called by the various commands to insert/delete module to the kernel space.

Hello World Kernel Module
-------------------------

file module.c 
~~~~~~~~~~~~~

.. code-block:: c
    :include: code/kernel/hello_world/module.c
    :linenos:


file Makefile
~~~~~~~~~~~~~

.. code-block:: make
    :include: code/kernel/hello_world/Makefile
    :linenos:

Module with parameter passing
-----------------------------

file module.c 
~~~~~~~~~~~~~

.. code-block:: c
    :include: code/kernel/parameters_hello_world/module.c
    :linenos:

file Makefile
~~~~~~~~~~~~~

.. code-block:: make 
    :include: code/kernel/parameters_hello_world/Makefile
    :linenos:

file ii.sh
~~~~~~~~~~

.. code-block:: sh
    :include: code/kernel/parameters_hello_world/ii.sh
    :linenos:

Module with paramter passing which adds two numbers
---------------------------------------------------

file module.c 
~~~~~~~~~~~~~

.. code-block:: c
    :include: code/kernel/add_parameters_hello_world/module.c
    :linenos:

file Makefile
~~~~~~~~~~~~~

.. code-block:: make
    :include: code/kernel/add_parameters_hello_world/Makefile
    :linenos:

EXPORT_SYMBOL()
---------------

* EXPORT_SYMBOL helps you provide APIs to other modules/code.
* The functions which you EXPORT are available to the other modules/code.
* Your module will not load if the its expecting a symbol(variable/function) and its not present in the kernel.
* ``modprobe`` helps here and loads the modules which is needed by your module.
* What if there is circular dependancy between the modules?

Show example of kernel modules exporting symbols.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

* Module2 fails to load as it could not find the symbols
    ``insmod module2.ko``
    ``dmesg``

* Module1 exports the symbols 
    ``cat /proc/kallsyms > /tmp/1``
    ``insmod module1.ko``
    ``cat /proc/kallsyms > /tmp/2``
    ``vimdiff /tmp/1 /tmp/2``

* **DONT RUN IT** Depmod is smart enough to find the dependancies and write to a file - don't run it as it will overwrite the original file. First take backup of the file.
    ``depmod ABSOLUTE_PATH_OF_THE_MODULE1 ABSOLUTE_PATH_OF_THE_MODULE2`` 
    see the file ``/modules/3.2.0-23-generic/modules.dep``

* Modprobe understands in which order the modules are to be loaded
    ``modprobe module2`` loads both the module

file module1.c 
~~~~~~~~~~~~~~
.. code-block:: c
    :include: code/kernel/exporting_symbols/module1.c
    :linenos:

file module2.c 
~~~~~~~~~~~~~~
.. code-block:: c
    :include: code/kernel/exporting_symbols/module2.c
    :linenos:

file Makefile
~~~~~~~~~~~~~

.. code-block:: make
    :include: code/kernel/exporting_symbols/Makefile
    :linenos:


Device Drivers
===============

* A device driver or software driver is a computer program allowing higher- level computer programs to interact with a hardware device.
* Translator between a hardware device and the applications or operating systems
* Drivers are hardware-dependent and operating-system-specific.
* They usually provide the interrupt handling required for any necessary asynchronous time-dependent

Device Drivers Types
--------------------
* Character Device Drivers
* Operate on characters as basic unit of input and output
* Accessed in sequential and non-random manner
* Block Device Driver
* Serves blocks of data
* Random access as required by file systems

copy_to_user(), copy_from_user()
--------------------------------
* Macros to copy data from user space and copy data to kernel space.

Character Device driver and ioctls
----------------------------------

file chardev.c
~~~~~~~~~~~~~~
.. code-block:: c
    :include: code/kernel/chardev/kernel/chardev.c
    :linenos:

file Makefile
~~~~~~~~~~~~~
.. code-block:: c
    :include: code/kernel/chardev/kernel/Makefile
    :linenos:

file ioctl.c
~~~~~~~~~~~~
.. code-block:: c
    :include: code/kernel/chardev/user/ioctl.c
    :linenos:

Steps:
~~~~~~

insmod chardev.ko
cat /proc/devices | grep sav_dev
mknod  /dev/mydev c 250 0
ls -l /dev/mydev


Proc Interface
==============

Make a proc entry for your module and write some value to it.
-------------------------------------------------------------

.. code-block:: c
    :include: code/kernel/proc1/proc.c
    :linenos:

kmalloc()
~~~~~~~~~
* kmalloc() is the kernel space version of malloc()
* call it  **kmalloc(bytes, GFP_KERNEL)**        
* Read more about it in ``Linux Kernel Develpement, Robert Love``


Make a proc directory and have multiple values to it.
-----------------------------------------------------

.. code-block:: c
    :include: code/kernel/proc2/proc.c
    :linenos:

file Makefile
~~~~~~~~~~~~~
.. code-block:: c
    :include: code/kernel/proc2/Makefile
    :linenos:

Make a proc entry and based on value written to the file call differenct functions.
-----------------------------------------------------------------------------------

.. code-block:: c
    :include: code/kernel/proc3/proc.c
    :linenos:

file Makefile
~~~~~~~~~~~~~
.. code-block:: c
    :include: code/kernel/proc3/Makefile
    :linenos:

Kernel Data Structures
======================

* You need not code your own linked list for your code.
* Kernel gives you linked list and red black tree implementations.
* The linked list is extensively used by the kernel.
* Red Black tree is used in the Completely Fair Schedular.

Using Kernel's linked list for your data structure
--------------------------------------------------

.. code-block:: c
    :include: code/kernel/ll1/ll.c
    :linenos:

.. code-block:: c
    :include: code/kernel/ll1/module.c
    :linenos:

.. code-block:: c
    :include: code/kernel/ll1/proc.c
    :linenos:


file Makefile
~~~~~~~~~~~~~
.. code-block:: c
    :include: code/kernel/ll1/Makefile
    :linenos:

Kernel's Bug Reporting
======================

* Kernel has built-in functions/macros for BUGS
* BUG(), BUG_ON(), dump_stack() and panic() can be used in your code to report error conditions.

BUG(), BUG_ON(), dump_stack(), panic() example
----------------------------------------------

.. code-block:: c
    :include: code/kernel/bug_on/proc.c
    :linenos:

file Makefile
~~~~~~~~~~~~~
.. code-block:: c
    :include: code/kernel/bug_on/Makefile
    :linenos:

Assignments
===========

#. Calculator in kernel space using parameters passed
#. Pass the file name, print the inode details
#. Use proc interface to call different functions.
#. Use proc interface to modify the behaviour of module.
#. Make a linked list in kernel space -- pass the values using ioctls
#. Using kernel's red-black tree for your data structures
#. Using proc interface pass the name of the mount point and print the details.
#. Print the superblock information if the mount point is passed
#. Print the super block information of the "/" mounted file system


Project Track Last User who modified the file
==============================================

#. Make changes to the ext2 code. Make changes to the ``ext2_file_operations`` structure's open function. Make it call function written by you in the file ext2/file.c. Keep your function's name as my_open(). Call the function ``dquot_file_open`` from your function. Your function should just be a wrapper and not alter the functionality.

.. code-block:: c
    :include: code/kernel/ext2_open_wrapper/file.c.diff
    :linenos: 


#. Make changes to the ext2 inode and add a ``muid`` field of type. You will need to make changes in the incore data structures as well as the mke2fs command should be called with -I 256 to ensure that the new field is accomodated.

``mkfs -I 128 /dev/loop0``


#. Add code to update the ``muid`` field whenever the file is opened for write.

.. code-block:: c    
    :include: code/kernel/ext2_update_muid_field_on_modification/diff.diff
    :linenos:   

#. Add proc interface to the file system for managment of new features.

.. code-block:: c 
    :include: code/kernel/ext2_proc_interface/diff.diff
    :linenos: 

Going Furhter
=============
