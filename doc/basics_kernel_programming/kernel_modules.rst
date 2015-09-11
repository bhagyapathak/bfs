======================
Kernel Module Hands-on
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

``file``: module.c 
~~~~~~~~~~~~~~~~~~

.. literalinclude:: code/kernel/hello_world/module.c
    :language: c
    :linenos:


``file``: Makefile
~~~~~~~~~~~~~~~~~~

.. literalinclude:: code/kernel/hello_world/Makefile
    :language: make
    :linenos:

Module with parameter passing
-----------------------------

``file``: module.c 
~~~~~~~~~~~~~~~~~~

.. literalinclude:: code/kernel/parameters_hello_world/module.c
    :language: c
    :linenos:

``file``: Makefile
~~~~~~~~~~~~~~~~~~

.. literalinclude:: code/kernel/parameters_hello_world/Makefile
    :language: make 
    :linenos:

Module with paramter passing which adds two numbers
---------------------------------------------------

``file``: module.c 
~~~~~~~~~~~~~~~~~~

.. literalinclude:: code/kernel/add_parameters_hello_world/module.c
    :language: c
    :linenos:

``file``: Makefile
~~~~~~~~~~~~~~~~~~

.. literalinclude:: code/kernel/add_parameters_hello_world/Makefile
    :language: make
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

``file``: module1.c 
~~~~~~~~~~~~~~~~~~~~
.. literalinclude:: code/kernel/exporting_symbols/module1.c
    :language: c
    :linenos:

``file``: module2.c 
~~~~~~~~~~~~~~~~~~~
.. literalinclude:: code/kernel/exporting_symbols/module2.c
    :language: c
    :linenos:

``file``: Makefile
~~~~~~~~~~~~~~~~~~

.. literalinclude:: code/kernel/exporting_symbols/Makefile
    :language: make
    :linenos:



