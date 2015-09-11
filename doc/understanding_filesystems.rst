
Understanding FileSystems
=========================

Implementing some system calls by yourself

Let us start by fsstat() system call which prints the file system information in the user space. Our approach is to first print
it using a chardev and ioctl, then print it using a proc interface and then print it by implementing our own system call. This will give 
us a pretty good idea about how to write a proc interface, write a character device driver and ioctl and also how to implement a system call.

The reason you can't find it is because, for the most part, it's not in the kernel -- it's in the userspace mount utility, which is in the util-linux package. If you don't give it a filesystem type, or if you give it a type of "any", mount merely goes through the list of all of the filesystems the kernel knows about, and tries each one in order until one of them mounts successfully (or returns an error if none of them do).

How does it find out what filesystem types the kernel knows about? It reads the /proc/filesystems file, which walks the file_systems linked list in fs/filesystems.c. When a filesystem driver is loaded, it calls register_filesystem in that same file to add itself to that list. For example, there's a call to register_filesystem in init_ext2_fs in fs/ext2/super.c — init_ext2_fs is the module-init function for the ext2 module.

Some filesystems are noisy and print errors to the kernel debug log when someone tries to mount a device with the wrong filesystem, which is why, for instance, you might see errors about "invalid XFS filesystem" when successfully mounting an ext4 filesystem, if mount happened to try xfs first.
