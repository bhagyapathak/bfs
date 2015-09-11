======================
Kernel Data Structures
======================

* You need not code your own linked list for your code.
* Kernel gives you linked list and red black tree implementations.
* The linked list is extensively used by the kernel.
* Red Black tree is used in the Completely Fair Schedular.

Using Kernel's linked list for your data structure
--------------------------------------------------

``file``: ll.c
~~~~~~~~~~~~~~
.. literalinclude:: code/kernel/ll1/ll.c
    :language: c
    :linenos:

``file``: module.c
~~~~~~~~~~~~~~~~~~

.. literalinclude:: code/kernel/ll1/module.c
    :language: c
    :linenos:

``file``: proc.c
~~~~~~~~~~~~~~~~
.. literalinclude:: code/kernel/ll1/proc.c
    :language: c
    :linenos:


``file``: Makefile
~~~~~~~~~~~~~~~~~~
.. literalinclude:: code/kernel/ll1/Makefile
    :language: c
    :linenos:
