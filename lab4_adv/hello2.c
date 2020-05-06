#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

extern int print_hello(uint par);

MODULE_AUTHOR("Serhii Popovych <serhii.popovych@globallogic.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

static uint p = 1; //by default
module_param(p, uint, S_IRUGO); 
MODULE_PARM_DESC(p, "Num of times for helloworld.");

static int __init hello_init(void)
{
	return print_hello(p);
}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
