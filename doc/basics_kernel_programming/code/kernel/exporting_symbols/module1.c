/*
 * <PD> Module 1 for demonstration of circular dependancy </PD>
 */
#include <linux/module.h>
#include <linux/init.h>

int GLOBAL_VARIABLE = 1000;

EXPORT_SYMBOL(GLOBAL_VARIABLE);

void print_hello(int num)
{
	while (num--) {
		printk(KERN_INFO "Hello Friend!!!\n");
	}
}

EXPORT_SYMBOL(print_hello);

void add_two_numbers(int a, int b)
{
	printk(KERN_INFO "Sum of the numebrs %d", a + b);
}

EXPORT_SYMBOL(add_two_numbers);

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

MODULE_AUTHOR("abr");
MODULE_LICENSE("GPL v2");
