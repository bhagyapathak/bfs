#! /bin/bash

#
# File to compile and open the pdf version of the document.
#

make latexpdf
evince _build/latex/BasicFilesystem.pdf

