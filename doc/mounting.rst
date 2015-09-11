
Mounting
========
When ever you have to access a block device which has a file system on it, you will have to mount that block device. The kernel needs to know the tyoe of the file system present on the block device so that it can use appropriate functions, specific functions to access the file system. Whenever you mount any file system you need to specify the device you want to mount, the location where you want to mount, the file system type on the block device and the parameters you want to use when you mount the file system. The parameters can be used to specify the file system will be READ-ONLY or READ-WRITE

When a file system is mounted then the kernel makes the file system available under the mounted-on directory. A specific data structure vfsmount is used to keep the information about the mounted file systems. We here will see some concepts about mounting the file system.

Let us see some concepts related to mounting the file system.
