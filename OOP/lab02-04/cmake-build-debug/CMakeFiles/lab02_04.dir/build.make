# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/astan/Desktop/OOP/lab02-04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/astan/Desktop/OOP/lab02-04/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab02_04.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab02_04.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab02_04.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab02_04.dir/flags.make

CMakeFiles/lab02_04.dir/main.c.o: CMakeFiles/lab02_04.dir/flags.make
CMakeFiles/lab02_04.dir/main.c.o: ../main.c
CMakeFiles/lab02_04.dir/main.c.o: CMakeFiles/lab02_04.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/astan/Desktop/OOP/lab02-04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab02_04.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lab02_04.dir/main.c.o -MF CMakeFiles/lab02_04.dir/main.c.o.d -o CMakeFiles/lab02_04.dir/main.c.o -c /mnt/c/Users/astan/Desktop/OOP/lab02-04/main.c

CMakeFiles/lab02_04.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab02_04.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/astan/Desktop/OOP/lab02-04/main.c > CMakeFiles/lab02_04.dir/main.c.i

CMakeFiles/lab02_04.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab02_04.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/astan/Desktop/OOP/lab02-04/main.c -o CMakeFiles/lab02_04.dir/main.c.s

CMakeFiles/lab02_04.dir/domain/RawMaterial.c.o: CMakeFiles/lab02_04.dir/flags.make
CMakeFiles/lab02_04.dir/domain/RawMaterial.c.o: ../domain/RawMaterial.c
CMakeFiles/lab02_04.dir/domain/RawMaterial.c.o: CMakeFiles/lab02_04.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/astan/Desktop/OOP/lab02-04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lab02_04.dir/domain/RawMaterial.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lab02_04.dir/domain/RawMaterial.c.o -MF CMakeFiles/lab02_04.dir/domain/RawMaterial.c.o.d -o CMakeFiles/lab02_04.dir/domain/RawMaterial.c.o -c /mnt/c/Users/astan/Desktop/OOP/lab02-04/domain/RawMaterial.c

CMakeFiles/lab02_04.dir/domain/RawMaterial.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab02_04.dir/domain/RawMaterial.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/astan/Desktop/OOP/lab02-04/domain/RawMaterial.c > CMakeFiles/lab02_04.dir/domain/RawMaterial.c.i

CMakeFiles/lab02_04.dir/domain/RawMaterial.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab02_04.dir/domain/RawMaterial.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/astan/Desktop/OOP/lab02-04/domain/RawMaterial.c -o CMakeFiles/lab02_04.dir/domain/RawMaterial.c.s

CMakeFiles/lab02_04.dir/repo/repo.c.o: CMakeFiles/lab02_04.dir/flags.make
CMakeFiles/lab02_04.dir/repo/repo.c.o: ../repo/repo.c
CMakeFiles/lab02_04.dir/repo/repo.c.o: CMakeFiles/lab02_04.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/astan/Desktop/OOP/lab02-04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lab02_04.dir/repo/repo.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lab02_04.dir/repo/repo.c.o -MF CMakeFiles/lab02_04.dir/repo/repo.c.o.d -o CMakeFiles/lab02_04.dir/repo/repo.c.o -c /mnt/c/Users/astan/Desktop/OOP/lab02-04/repo/repo.c

CMakeFiles/lab02_04.dir/repo/repo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab02_04.dir/repo/repo.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/astan/Desktop/OOP/lab02-04/repo/repo.c > CMakeFiles/lab02_04.dir/repo/repo.c.i

CMakeFiles/lab02_04.dir/repo/repo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab02_04.dir/repo/repo.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/astan/Desktop/OOP/lab02-04/repo/repo.c -o CMakeFiles/lab02_04.dir/repo/repo.c.s

CMakeFiles/lab02_04.dir/service/service.c.o: CMakeFiles/lab02_04.dir/flags.make
CMakeFiles/lab02_04.dir/service/service.c.o: ../service/service.c
CMakeFiles/lab02_04.dir/service/service.c.o: CMakeFiles/lab02_04.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/astan/Desktop/OOP/lab02-04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lab02_04.dir/service/service.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lab02_04.dir/service/service.c.o -MF CMakeFiles/lab02_04.dir/service/service.c.o.d -o CMakeFiles/lab02_04.dir/service/service.c.o -c /mnt/c/Users/astan/Desktop/OOP/lab02-04/service/service.c

CMakeFiles/lab02_04.dir/service/service.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab02_04.dir/service/service.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/astan/Desktop/OOP/lab02-04/service/service.c > CMakeFiles/lab02_04.dir/service/service.c.i

CMakeFiles/lab02_04.dir/service/service.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab02_04.dir/service/service.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/astan/Desktop/OOP/lab02-04/service/service.c -o CMakeFiles/lab02_04.dir/service/service.c.s

CMakeFiles/lab02_04.dir/UI/ui.c.o: CMakeFiles/lab02_04.dir/flags.make
CMakeFiles/lab02_04.dir/UI/ui.c.o: ../UI/ui.c
CMakeFiles/lab02_04.dir/UI/ui.c.o: CMakeFiles/lab02_04.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/astan/Desktop/OOP/lab02-04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/lab02_04.dir/UI/ui.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lab02_04.dir/UI/ui.c.o -MF CMakeFiles/lab02_04.dir/UI/ui.c.o.d -o CMakeFiles/lab02_04.dir/UI/ui.c.o -c /mnt/c/Users/astan/Desktop/OOP/lab02-04/UI/ui.c

CMakeFiles/lab02_04.dir/UI/ui.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab02_04.dir/UI/ui.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/astan/Desktop/OOP/lab02-04/UI/ui.c > CMakeFiles/lab02_04.dir/UI/ui.c.i

CMakeFiles/lab02_04.dir/UI/ui.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab02_04.dir/UI/ui.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/astan/Desktop/OOP/lab02-04/UI/ui.c -o CMakeFiles/lab02_04.dir/UI/ui.c.s

CMakeFiles/lab02_04.dir/teste/teste.c.o: CMakeFiles/lab02_04.dir/flags.make
CMakeFiles/lab02_04.dir/teste/teste.c.o: ../teste/teste.c
CMakeFiles/lab02_04.dir/teste/teste.c.o: CMakeFiles/lab02_04.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/astan/Desktop/OOP/lab02-04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/lab02_04.dir/teste/teste.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lab02_04.dir/teste/teste.c.o -MF CMakeFiles/lab02_04.dir/teste/teste.c.o.d -o CMakeFiles/lab02_04.dir/teste/teste.c.o -c /mnt/c/Users/astan/Desktop/OOP/lab02-04/teste/teste.c

CMakeFiles/lab02_04.dir/teste/teste.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab02_04.dir/teste/teste.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/astan/Desktop/OOP/lab02-04/teste/teste.c > CMakeFiles/lab02_04.dir/teste/teste.c.i

CMakeFiles/lab02_04.dir/teste/teste.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab02_04.dir/teste/teste.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/astan/Desktop/OOP/lab02-04/teste/teste.c -o CMakeFiles/lab02_04.dir/teste/teste.c.s

CMakeFiles/lab02_04.dir/validator.c.o: CMakeFiles/lab02_04.dir/flags.make
CMakeFiles/lab02_04.dir/validator.c.o: ../validator.c
CMakeFiles/lab02_04.dir/validator.c.o: CMakeFiles/lab02_04.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/astan/Desktop/OOP/lab02-04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/lab02_04.dir/validator.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lab02_04.dir/validator.c.o -MF CMakeFiles/lab02_04.dir/validator.c.o.d -o CMakeFiles/lab02_04.dir/validator.c.o -c /mnt/c/Users/astan/Desktop/OOP/lab02-04/validator.c

CMakeFiles/lab02_04.dir/validator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab02_04.dir/validator.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/astan/Desktop/OOP/lab02-04/validator.c > CMakeFiles/lab02_04.dir/validator.c.i

CMakeFiles/lab02_04.dir/validator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab02_04.dir/validator.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/astan/Desktop/OOP/lab02-04/validator.c -o CMakeFiles/lab02_04.dir/validator.c.s

# Object files for target lab02_04
lab02_04_OBJECTS = \
"CMakeFiles/lab02_04.dir/main.c.o" \
"CMakeFiles/lab02_04.dir/domain/RawMaterial.c.o" \
"CMakeFiles/lab02_04.dir/repo/repo.c.o" \
"CMakeFiles/lab02_04.dir/service/service.c.o" \
"CMakeFiles/lab02_04.dir/UI/ui.c.o" \
"CMakeFiles/lab02_04.dir/teste/teste.c.o" \
"CMakeFiles/lab02_04.dir/validator.c.o"

# External object files for target lab02_04
lab02_04_EXTERNAL_OBJECTS =

lab02_04: CMakeFiles/lab02_04.dir/main.c.o
lab02_04: CMakeFiles/lab02_04.dir/domain/RawMaterial.c.o
lab02_04: CMakeFiles/lab02_04.dir/repo/repo.c.o
lab02_04: CMakeFiles/lab02_04.dir/service/service.c.o
lab02_04: CMakeFiles/lab02_04.dir/UI/ui.c.o
lab02_04: CMakeFiles/lab02_04.dir/teste/teste.c.o
lab02_04: CMakeFiles/lab02_04.dir/validator.c.o
lab02_04: CMakeFiles/lab02_04.dir/build.make
lab02_04: CMakeFiles/lab02_04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/astan/Desktop/OOP/lab02-04/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable lab02_04"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab02_04.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab02_04.dir/build: lab02_04
.PHONY : CMakeFiles/lab02_04.dir/build

CMakeFiles/lab02_04.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab02_04.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab02_04.dir/clean

CMakeFiles/lab02_04.dir/depend:
	cd /mnt/c/Users/astan/Desktop/OOP/lab02-04/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/astan/Desktop/OOP/lab02-04 /mnt/c/Users/astan/Desktop/OOP/lab02-04 /mnt/c/Users/astan/Desktop/OOP/lab02-04/cmake-build-debug /mnt/c/Users/astan/Desktop/OOP/lab02-04/cmake-build-debug /mnt/c/Users/astan/Desktop/OOP/lab02-04/cmake-build-debug/CMakeFiles/lab02_04.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab02_04.dir/depend

