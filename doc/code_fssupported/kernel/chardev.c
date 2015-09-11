/*
 *  <PD> Creates a read-only char device that says how many times
 *  you've read from the dev file </PD>
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kallsyms.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <asm/uaccess.h>   /* for put_user */
#include "../ukheader.h"

struct param {
   int number;
   char *ptr[];
};
/*  
 *  Prototypes - this would normally go in a .h file
 */
int init_module(void);
void cleanup_module(void);
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t,\
						loff_t *);
static long device_ioctl(struct file *, unsigned int,
         unsigned long);

static long unlocked_device_ioctl(struct file *, unsigned int,
         unsigned long);
#define SUCCESS 0
#define DEVICE_NAME "sav_dev" /* Dev name as it appears in 
                                 /proc/devices*/
#define BUF_LEN 80   /* Max length of the message from the device */

/* 
 * Global variables are declared as static, 
 * so are global within the file. 
 */

static int Major;    /* Major number assigned to our device driver */
static int Device_Open = 0;   /* Is device open?  
             * Used to prevent multiple access to device */
static char msg[BUF_LEN]; /* The msg the device will give when asked*/
static char *msg_Ptr;

static struct file_operations fops = {
   .read = device_read,
   .write = device_write,
   .open = device_open,
   .release = device_release,
   .compat_ioctl = device_ioctl,
   .unlocked_ioctl = unlocked_device_ioctl

};


/*
 * http://onebitbug.me/2011/03/04/introducing-linux-kernel-symbols/
 */

unsigned long get_symbol_address(char *sym_name) {
	return kallsyms_lookup_name(sym_name);
}

int print_file_systems(void) {

	/*
	 * Get the address of the file_systems variable 
	 */
	struct file_system_type *fs=NULL, **fs1=NULL, **p;
	unsigned long addr_file_systems=get_symbol_address("file_systems");
	printk(KERN_INFO "[%s]: Address of file_systems is %lx", __this_module.name, addr_file_systems);

	if (!addr_file_systems) {
		printk(KERN_INFO "[%s]: Could not find the address",__this_module.name);
		return -1;
	}

	fs1=(struct file_system_type **) (addr_file_systems);
	fs=(struct file_system_type *)(*fs1);

	p=addr_file_systems;
	printk(KERN_INFO "[%s]: File System Name XXX is %s", __this_module.name, addr_file_systems);
	printk(KERN_INFO "[%s]: File System Name is %s", __this_module.name, (fs)->name);
	printk(KERN_INFO "[%s]: File System Name is %c", __this_module.name, (fs)->name[0]);
	printk(KERN_INFO "[%s]: File System Name is %c", __this_module.name, fs->name[1]);
	printk(KERN_INFO "[%s]: File System Name is %c", __this_module.name, fs->name[2]);
/*	fs=fs->next;
	printk(KERN_INFO "[%s]: File System Name is %s", __this_module.name, fs->name);
	fs=fs->next;
	printk(KERN_INFO "[%s]: File System Name is %s", __this_module.name, fs->name);
	fs=fs->next;
	printk(KERN_INFO "[%s]: File System Name is %s", __this_module.name, fs->name);
*/

	for (p=addr_file_systems; *p; p=&(*p)->next) {
/*		if (strlen((*p)->name) == len &&
				strncmp((*p)->name, name, len) == 0)
			break;
*/

		printk(KERN_INFO "[%s] Fs Name is %s", (*p)->name);

	}

	return 0;

}

/*
 * Device ioctl
 */

static long unlocked_device_ioctl( struct file *file, unsigned int cmd, unsigned long arg)
{
   int numbers, i;
   printk(KERN_INFO "Command Passed is %d", cmd);

   switch (cmd) {
   case 1:
      printk(KERN_INFO "I AM IN COMMAND NUMBER 1");
      numbers = ((struct param *)arg)->number;
      printk(KERN_INFO "Number Passed %d", ((struct param *)arg)->number);
      for (i = 0; i < numbers; i++) {
         printk(KERN_INFO "ARG 1 %s", ((struct param *)arg)->ptr[i]);
      }
      printk(KERN_INFO "I will try to print the values passed to me");
      return 0;

   case 2:
      printk(KERN_INFO "I AM IN COMMAND NUMBER 1");
      printk(KERN_INFO " HEY ITS DONE");
      return 0;

case PRINT_FILE_SYSTEMS:
	printk(KERN_INFO "[%s]: Printing the file system types in the system", __this_module.name);
	if (print_file_systems()) {
		printk(KERN_INFO "Error executing the function");
		return 1;
	}
	return 0;

   default:
      printk(KERN_INFO
             "I do not know what to do, you have passed such value, %d is the value",
             cmd);
      return -1;
   }
   return 0;
}
/*
 * This function is called when the module is loaded
 */
int init_module(void)
{
   Major = register_chrdev(0, DEVICE_NAME, &fops);

   if (Major < 0) {
      printk(KERN_ALERT "Registering char device failed with %d\n",\
             Major);
      return Major;
   }

   printk(KERN_INFO "I got major number %d. To talk to\n", Major);
   printk(KERN_INFO "the driver, create a dev file with\n");
   printk(KERN_INFO "'mknod /dev/%s c %d 0'.\n", DEVICE_NAME, Major);
   printk(KERN_INFO "Try various minor numbers, Try to cat and \
			echo to the device file\n");
   printk(KERN_INFO "Remove the device file and module when done.\n");

   return SUCCESS;
}

/*
 * This function is called when the module is unloaded
 */
void cleanup_module(void)
{
   /* 
    * Unregister the device 
    */

   printk(KERN_INFO "\n\nUnregistering the device file.\n");
   unregister_chrdev(Major, DEVICE_NAME);
}

/*
 * Methods
 */

/* 
 * Called when a process tries to open the device file, like
 * "cat /dev/mycharfile"
 */
static int device_open(struct inode *inode, struct file *file)
{
   static int counter = 0;

   if (Device_Open)
      return -EBUSY;

   Device_Open++;
   sprintf(msg, "I already told you %d times Hello world!\n", 
                                    counter++);
   msg_Ptr = msg;
   try_module_get(THIS_MODULE);

   return SUCCESS;
}

/* 
 * Called when a process closes the device file.
 */
static int device_release(struct inode *inode, struct file *file)
{
   Device_Open--;    /* We're now ready for our next caller */

   /* 
    * Decrement the usage count, or else once you opened the file, 
    * you'll
    * never get get rid of the module. 
    */
   module_put(THIS_MODULE);

   return 0;
}

/* 
 * Called when a process, which already opened the dev file, attempts 
   to read from it.  */
static ssize_t device_read(struct file *filp, /* see include/linux/fs.h   */
            char *buffer,  /* buffer to fill with data */
            size_t length, /* length of the buffer     */
            loff_t * offset)
{
   /*
    * Number of bytes actually written to the buffer 
    */
   int bytes_read = 0;

   /*
    * If we're at the end of the message, 
    * return 0 signifying end of file 
    */
   if (*msg_Ptr == 0)
      return 0;

   /* 
    * Actually put the data into the buffer 
    */
   while (length && *msg_Ptr) {

      /* 
       * The buffer is in the user data segment, not the kernel 
       * segment so "*" assignment won't work.  We have to use 
       * put_user which copies data from the kernel data segment to
       * the user data segment. 
       */
      put_user(*(msg_Ptr++), buffer++);

      length--;
      bytes_read++;
   }

   /* 
    * Most read functions return the number of bytes put into the buffer
    */
   return bytes_read;
}

/*  
 * Called when a process writes to dev file: echo "hi" > /dev/hello 
 */
static ssize_t
device_write(struct file *filp, const char *buff, size_t len, loff_t * off)
{
   printk(KERN_ALERT "Sorry, this operation isn't supported.\n");
   return -EINVAL;
}

static long device_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	printk(KERN_INFO "In unlocked ioctl\n");
        return 0;
}
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Character Device Driver for Entering Kernel Mode Using ioctl");
MODULE_AUTHOR("Rishi Bhushan Agrawal <rishi.b.agrawal@gmail.com>");
