==================
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

.. literalinclude:: code/kernel/project01/ext2_changed_code/file.c.diff
    :language: c
    :linenos: 
