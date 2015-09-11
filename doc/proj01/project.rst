##########
Project 01
##########

============
Introduction
============
    
================
Why this project
================

===================
What will you learn
===================

==============================
Concepts and Keywords involved
==============================

=============
Prerequisites
=============

====================
Requirement Analysis
====================

======
Design
======

==============
Implementation
==============

#. Make changes to the ext2 code. Make changes to the ``ext2_file_operations`` structure's open function. Make it call function written by you in the file ext2/file.c. Keep your function's name as my_open(). Call the function ``dquot_file_open`` from your function. Your function should just be a wrapper and not alter the functionality.


.. literalinclude:: code/ext2_open_wrapper/file.c.diff
    :language: c
    :linenos: 


#. Make changes to the ext2 inode and add a ``muid`` field of type. You will need to make changes in the incore data structures as well as the mke2fs command should be called with -I 256 to ensure that the new field is accomodated.

``mkfs -I 128 /dev/loop0``


#. Add code to update the ``muid`` field whenever the file is opened for write.

    
.. literalinclude:: code/ext2_update_muid_field_on_modification/diff.diff
    :language: c
    :linenos:   

#. Add proc interface to the file system for managment of new features.

 
.. literalinclude:: code/ext2_proc_interface/diff.diff
    :language: c
    :linenos: 

=======
Testing
=======

============
Enhancements
============

=========
Exercises
=========

==========
References
==========
