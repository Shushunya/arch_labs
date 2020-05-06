#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

MODULE_AUTHOR("Serhii Popovych <serhii.popovych@globallogic.com>");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

/* MY EDIT */
EXPORT_SYMBOL(print_hello);

static int __init hello_init(void)
{
	return 0;
}

int print_hello(uint par)
{
	int i = 0; //because C cannot declare counter inside "for"

	if(par==0 || (par>=5 && par<=10))
	{
		pr_warn("Warning, continuing..");
	}
	else if(par>10) 
	{
		pr_err("Error, exiting..");
		return -EINVAL;
	}
	else
	{
		for(i = 0; i < par; i++)
			pr_info("Hello, world!\n");
	}
	return 0;
}
/* END OF MY EDIT */

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

module_init(hello_init);
module_exit(hello_exit);
