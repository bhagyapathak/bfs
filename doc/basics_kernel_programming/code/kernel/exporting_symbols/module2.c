/*
 * <PD> Module 2 for exporting symbol demostration </PD>
 */
#include <linux/module.h>
#include <linux/init.h>

extern print_hello(int);
extern add_two_numbers(int, int);
extern GLOBAL_VARIABLE;

static int __init my_init(void)
{
	printk(KERN_INFO "Hello from Hello Module");
	print_hello(10);
	add_two_numbers(5, 6);
	printk(KERN_INFO "Value of GLOBAL_VARIABLE %d", GLOBAL_VARIABLE);
	return 0;
}

static void __exit my_exit(void)
{
	printk(KERN_INFO "Bye from Hello Module");
}

module_init(my_init);
module_exit(my_exit);

MODULE_AUTHOR("abr");
MODULE_LICENSE("GPL v2");
