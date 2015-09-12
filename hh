#! /bin/bash

#
# File to compile and open the html version of the document.
#

make html
firefox _build/html/index.html
