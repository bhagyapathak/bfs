#################
Basic File System
#################

.. contents::

************
Introduction
************

This is a book on how to write a file system in Linux Kernel. The purpose of the
file system is to demonstrate how easy it is to code a file system.

********************
Reading the document
********************

#. Checkout the Repo.
#. Install sphinx using the command ``pip install -U Sphinx``.
#. Install ``rst2pdf`` for reading this document in pdf. Run ``rst2pdf README.rst``. Read the pdf as ``README.pdf``
#. Make html ``make html``. Open the document ``_build/html/index.html``.
#. Make pdf ``make latexpdf``. Open the document ``_build/latex/BasicFilesystem.pdf``

*****************
Checkout The Repo
*****************

#. Make a github account.
#. Upload your ssh keys for passwordless authentication. Read the document for understanding how to upload ssh keys.
#. Checkout the code from git@github.com:abrrba/bfs.git.

How to upload the key?
======================

#. Do "ssh-keygen" keep pressing enter
#. At the end of the command do "cat .ssh/id_rsa.pub" and copy the text from "ssh-rsa" to end.
#. Then in https://github.com/settings/profile page go to SSH Keys (direct link is https://github.com/settings/ssh") and upload your keys.
