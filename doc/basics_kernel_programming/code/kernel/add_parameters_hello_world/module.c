/*
 * <PD> Program to add the passed parameters to a kernel module </PD>
 */
#include <linux/module.h>
#include <linux/init.h>

#define DEFAULT_PARAM1 100
#define DEFAULT_PARAM2 200

/*
 * Variable for integer parameter
 */
int param1 = DEFAULT_PARAM1;
module_param(param1, int, 0);

int param2 = DEFAULT_PARAM2 module_param(param2, int, 0);

static int __init my_init(void)
{
   int i = 0;
   printk(KERN_INFO "\nHello from Hello Module\n");
   printk(KERN_INFO "\nPassed Parameters\n");

   /*
    * Print the parameters passed
    */
   if (param1 == DEFAULT_PARAM1) {
      printk(KERN_INFO
             "\nNothing Passed or Default Value %d for param1 passed\n",
             DEFAULT_PARAM1);
   } else {
      printk(KERN_INFO "\nParam1 passed is %d", param1);
   }

   if (param1 == DEFAULT_PARAM2) {
      printk(KERN_INFO
             "\nNothing Passed or Default Value %d for param1 passed\n",
             DEFAULT_PARAM2);
   } else {
      printk(KERN_INFO "\nParam2 passed is %d", param2);
   }

   printk(KERN_INFO "The sum of the parameters are %d",
          param1 + param2);
   return 0;
}

static void __exit my_exit(void)
{
   printk(KERN_INFO "Bye from Hello Module");
}

module_init(my_init);
module_exit(my_exit);

MODULE_DESCRIPTION("module to demonstrate module parameters");
MODULE_AUTHOR("abr");
MODULE_LICENSE("GPL v2");
MODULE_VERSION("1.0");
