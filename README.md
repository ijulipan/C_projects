# C_projects

**Repo of My C_projects and learning materials**
 
  **Pointers**

  Pointers are variables that stores the memory address of another variable as its value. Pointers must point to the same data type and are initialised using the '*' operator.
  
   Refer the example at [pointers](https://github.com/ijulipan/C_projects/blob/main/learn/c_concepts/pointer.c)

  **Signed & Unsigned Integer**
  
  A signed integer is an integer that ranges from [-2147483648 to 2147483647]. An unsigned integer ranges a nonnegative integer from [0 to 4294967295]

  **Stack**
  
  Stack is a linear data structure and a basic algorithm involving _Last In First Out_ (LIFO) rule. Element insertion and deletion always occur at the top. 

  Common terms associated with stack is **push** (adding elements) and **pop** (removing elements) from the stack.

  An example of a stack is placed in [stack](https://github.com/ijulipan/C_projects/blob/main/learn/c_concepts/stack.c).

**How to build a kernel module**

1. Create the C program containing the init, exit and operations of the driver
2. Create a local Makefile (refer to hello world Makefile)
3. Run the following command:-
_make -C <path_to_linux_kernel_tree> M=<path_to_module> [target]_

**NOTE**: path_to_linux_kernel_tree can be found in the terminal by going to /lib/modules/<kernel_version>
      path_to_module can also be replaced with $PWD if the current working directory is in the targeted kernel module
      Target has a list of commands that can be run such as:-
        1. modules: The default command to build targets. (It has the same functionality if no target was specified)
        2. modules_install: Use this command if installation is needed instead of building. (It will be placed in /lib/modules/<kernel_release>/extra)
        3. clean: Remove all built modules
        4. help: Show the list of commands available

Automated build process has been made, please refer to Makefile in [helloworld](https://github.com/ijulipan/C_projects/blob/main/linux_driver_development/char_device/helloworld/Makefile)
