/*
 *  * Make a entry  /proc/driver/my_mod1 and write something to it.
 *   */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>


#define NODE_ENTRY "driver/ext2_linuxKernel101"

static struct proc_dir_entry *ext2_proc_entry, *ext2_proc_dir;

static int ext2_proc_read(char *page, char **start, off_t off, int count,
            int *eof, void *data)
{
    
	return -EINVAL;
}


void ext2_proc_print_inode_details(unsigned int inum) {
	printk(KERN_INFO "Print inode details of %u\n", inum);
}

void ext2_proc_print_file_details(char *filename) {
	printk(KERN_INFO "Print file details of %s\n", filename);
}

void ext2_proc_print_all_inodes(void) {
	printk(KERN_INFO "Print all the inodes in the file system\n");
}



/*
 * This should be based per file system and error checkings hould be present, locking too, but as it
 * just for demostrtation, we skip those
 */

static int ext2_proc_write(struct file *file, const char __user * buffer,
		unsigned long count, void *data)
{
	char *str;
	unsigned int inum=0;
	char filename[40], command[40];
	str = kmalloc((size_t) count, GFP_KERNEL);
	if (copy_from_user(str, buffer, count)) {
		kfree(str);
		return -EFAULT;
	}

	sscanf(str, "%s", command);
	printk("First Arguement %s\n", command);

	if (!strcmp(command, "print_inode_details")) {
		sscanf(str, "%s %u", command, &inum);
		printk(KERN_INFO "Printing data of inode number%u\n", inum);
		ext2_proc_print_inode_details(inum);
	}   

	if (!strcmp(command, "print_file_details")) {
		sscanf(str, "%s %s", command, filename);
		printk(KERN_INFO "Printing details of file  %s\n", filename);
		ext2_proc_print_file_details(filename);
	}   


	if (!strcmp(command, "print_all_inodes")) {
		printk(KERN_INFO "Printing the linked list\n");
		ext2_proc_print_all_inodes();
	}   
	return count;
}


int ext2_init_proc_interface(void)
{
	printk(KERN_INFO "Hello from Proc Interface of ext2 module");


	/*
	 * Make the entry
	 */

	ext2_proc_entry = create_proc_entry(NODE_ENTRY, S_IRUGO | S_IWUSR, NULL);
	if (ext2_proc_entry == NULL) {
		printk(KERN_INFO "Failed to make the required proc entry");
		return -1;
	} else {
		pr_info("I created the entry");
	}
	/*
	 * Set the procedures for the proc_file
	 */
    ext2_proc_entry->read_proc = ext2_proc_read;
    ext2_proc_entry->write_proc = ext2_proc_write;
    // ext2_proc_entry->data = ext2_proc_entry;
    return 0;
}

void ext2_proc_remove(void)
{
    if (ext2_proc_dir) {
        remove_proc_entry(NODE_ENTRY, NULL);
        pr_info("Removed the entry");
    }
    printk(KERN_INFO "Bye from Hello Module");
}
