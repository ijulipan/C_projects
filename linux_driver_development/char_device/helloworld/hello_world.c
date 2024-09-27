/* This is the header section, need to mention the correct kernel headers*/
/* We do not use userspace headers i.e stdio.h as we need to run these files in kernel*/
#include <linux/module.h>


/* Function to initialise the module */
static int __init hello_world_init(void)
{
    /* Kernel's printf */
    pr_info("Hello world!\n")
    return 0;
}

/* Function to exit/remove the module */
static int __exit hello_world_exit(void)
{
    pr_info("Good-bye!")
}

/* Module entry/exit points registration */
module_init(hello_world_init);
module_exit(hello_world_exit);

/* Module Description */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("WWW.FASTBITLAB.COM")
MODULE_DESCRIPTION("A kernel module to print some messages")
