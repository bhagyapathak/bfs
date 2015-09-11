
#define SUCCESS 0
#define DEVICE_NAME "mychardev" /* Dev name as it appears in the /proc */ 
struct param {
   int number;
   char *ptr[];
};
int init_module(void);
void cleanup_module(void);
int device_open(struct inode *, struct file *);
int device_release(struct inode *, struct file *);
ssize_t device_read(struct file *, char *, size_t, loff_t *);
ssize_t device_write(struct file *, const char *, size_t,\
 					loff_t *);
long device_ioctl(struct file *, unsigned int,
         unsigned long);

long unlocked_device_ioctl(struct file *, unsigned int,
         unsigned long);

