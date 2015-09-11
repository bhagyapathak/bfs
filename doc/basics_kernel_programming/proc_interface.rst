==============
Proc Interface
==============

Make a proc entry for your module and write some value to it.
-------------------------------------------------------------

``file``: proc.c
~~~~~~~~~~~~~~~~
.. literalinclude:: code/kernel/proc1/proc.c
    :language: c
    :linenos:

``file``: Makefile
~~~~~~~~~~~~~~~~~~
.. literalinclude:: code/kernel/proc1/Makefile
    :language: c
    :linenos:

kmalloc()
~~~~~~~~~
* kmalloc() is the kernel space version of malloc()
* call it  **kmalloc(bytes, GFP_KERNEL)**        
* Read more about it in ``Linux Kernel Develpement, Robert Love``


Make a proc directory and have multiple values to it.
-----------------------------------------------------

``file``: proc.c
~~~~~~~~~~~~~~~~
.. literalinclude:: code/kernel/proc2/proc.c
    :language: c
    :linenos:

``file``: Makefile
~~~~~~~~~~~~~~~~~~
.. literalinclude:: code/kernel/proc2/Makefile
    :language: c
    :linenos:

Make a proc entry and based on value written to the file call differenct functions.
-----------------------------------------------------------------------------------

``file``: proc.c
~~~~~~~~~~~~~~~~
.. literalinclude:: code/kernel/proc3/proc.c
    :language: c
    :linenos:

``file``: Makefile
~~~~~~~~~~~~~~~~~~
.. literalinclude:: code/kernel/proc3/Makefile
    :language: c
    :linenos:
