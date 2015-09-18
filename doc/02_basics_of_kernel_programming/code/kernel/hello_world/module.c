/*
 * <PD> Hello World Module </PD>
 */
#include <linux/module.h>
#include <linux/init.h>

static int __init my_init(void)
{
	printk(KERN_INFO "Hello from Hello Module");
	return 0;
}

static void __exit my_exit(void)
{
	printk(KERN_INFO "Bye from Hello Module");
}

module_init(my_init);
module_exit(my_exit);

MODULE_DESCRIPTION("Sample Hello World Module");
MODULE_AUTHOR("abr");
MODULE_LICENSE("GPL v2");
