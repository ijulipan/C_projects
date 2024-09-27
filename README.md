# C_projects

How to build a kernel module

1. Create the C program containing the init, exit and operations of the driver
2. Create a local Makefile (refer to hello world Makefile)
3. Run the following command:-
make -C <path_to_linux_kernel_tree> M=<path_to_module> [target]

NOTE: path_to_linux_kernel_tree can be found in the terminal by going to /lib/modules/<kernel_version>
      path_to_module can also be replaced with $PWD if the current working directory is in the targeted kernel module
      Target has a list of commands that can be run such as:-
        1. modules: The default command to build targets. (It has the same functionality if no target was specified)
        2. modules_install: Use this command if installation is needed instead of building. (It will be placed in /lib/modules/<kernel_release>/extra)
        3. clean: Remove all built modules
        4. help: Show the list of commands available

Automated build process has been made, please refer to Makefile in hellworld directory
