# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/veins/artery

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/veins/artery/build

# Include any dependencies generated for this target.
include src/traci/CMakeFiles/traci.dir/depend.make

# Include the progress variables for this target.
include src/traci/CMakeFiles/traci.dir/progress.make

# Include the compile flags for this target's objects.
include src/traci/CMakeFiles/traci.dir/flags.make

src/traci/CMakeFiles/traci.dir/API.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/API.cc.o: ../src/traci/API.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/traci/CMakeFiles/traci.dir/API.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/API.cc.o -c /home/veins/artery/src/traci/API.cc

src/traci/CMakeFiles/traci.dir/API.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/API.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/API.cc > CMakeFiles/traci.dir/API.cc.i

src/traci/CMakeFiles/traci.dir/API.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/API.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/API.cc -o CMakeFiles/traci.dir/API.cc.s

src/traci/CMakeFiles/traci.dir/BasicModuleMapper.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/BasicModuleMapper.cc.o: ../src/traci/BasicModuleMapper.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/traci/CMakeFiles/traci.dir/BasicModuleMapper.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/BasicModuleMapper.cc.o -c /home/veins/artery/src/traci/BasicModuleMapper.cc

src/traci/CMakeFiles/traci.dir/BasicModuleMapper.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/BasicModuleMapper.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/BasicModuleMapper.cc > CMakeFiles/traci.dir/BasicModuleMapper.cc.i

src/traci/CMakeFiles/traci.dir/BasicModuleMapper.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/BasicModuleMapper.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/BasicModuleMapper.cc -o CMakeFiles/traci.dir/BasicModuleMapper.cc.s

src/traci/CMakeFiles/traci.dir/BasicNodeManager.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/BasicNodeManager.cc.o: ../src/traci/BasicNodeManager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/traci/CMakeFiles/traci.dir/BasicNodeManager.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/BasicNodeManager.cc.o -c /home/veins/artery/src/traci/BasicNodeManager.cc

src/traci/CMakeFiles/traci.dir/BasicNodeManager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/BasicNodeManager.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/BasicNodeManager.cc > CMakeFiles/traci.dir/BasicNodeManager.cc.i

src/traci/CMakeFiles/traci.dir/BasicNodeManager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/BasicNodeManager.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/BasicNodeManager.cc -o CMakeFiles/traci.dir/BasicNodeManager.cc.s

src/traci/CMakeFiles/traci.dir/BasicSubscriptionManager.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/BasicSubscriptionManager.cc.o: ../src/traci/BasicSubscriptionManager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/traci/CMakeFiles/traci.dir/BasicSubscriptionManager.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/BasicSubscriptionManager.cc.o -c /home/veins/artery/src/traci/BasicSubscriptionManager.cc

src/traci/CMakeFiles/traci.dir/BasicSubscriptionManager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/BasicSubscriptionManager.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/BasicSubscriptionManager.cc > CMakeFiles/traci.dir/BasicSubscriptionManager.cc.i

src/traci/CMakeFiles/traci.dir/BasicSubscriptionManager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/BasicSubscriptionManager.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/BasicSubscriptionManager.cc -o CMakeFiles/traci.dir/BasicSubscriptionManager.cc.s

src/traci/CMakeFiles/traci.dir/CheckTimeSync.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/CheckTimeSync.cc.o: ../src/traci/CheckTimeSync.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/traci/CMakeFiles/traci.dir/CheckTimeSync.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/CheckTimeSync.cc.o -c /home/veins/artery/src/traci/CheckTimeSync.cc

src/traci/CMakeFiles/traci.dir/CheckTimeSync.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/CheckTimeSync.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/CheckTimeSync.cc > CMakeFiles/traci.dir/CheckTimeSync.cc.i

src/traci/CMakeFiles/traci.dir/CheckTimeSync.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/CheckTimeSync.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/CheckTimeSync.cc -o CMakeFiles/traci.dir/CheckTimeSync.cc.s

src/traci/CMakeFiles/traci.dir/Core.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/Core.cc.o: ../src/traci/Core.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/traci/CMakeFiles/traci.dir/Core.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/Core.cc.o -c /home/veins/artery/src/traci/Core.cc

src/traci/CMakeFiles/traci.dir/Core.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/Core.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/Core.cc > CMakeFiles/traci.dir/Core.cc.i

src/traci/CMakeFiles/traci.dir/Core.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/Core.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/Core.cc -o CMakeFiles/traci.dir/Core.cc.s

src/traci/CMakeFiles/traci.dir/ConnectLauncher.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/ConnectLauncher.cc.o: ../src/traci/ConnectLauncher.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/traci/CMakeFiles/traci.dir/ConnectLauncher.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/ConnectLauncher.cc.o -c /home/veins/artery/src/traci/ConnectLauncher.cc

src/traci/CMakeFiles/traci.dir/ConnectLauncher.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/ConnectLauncher.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/ConnectLauncher.cc > CMakeFiles/traci.dir/ConnectLauncher.cc.i

src/traci/CMakeFiles/traci.dir/ConnectLauncher.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/ConnectLauncher.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/ConnectLauncher.cc -o CMakeFiles/traci.dir/ConnectLauncher.cc.s

src/traci/CMakeFiles/traci.dir/ExtensibleNodeManager.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/ExtensibleNodeManager.cc.o: ../src/traci/ExtensibleNodeManager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/traci/CMakeFiles/traci.dir/ExtensibleNodeManager.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/ExtensibleNodeManager.cc.o -c /home/veins/artery/src/traci/ExtensibleNodeManager.cc

src/traci/CMakeFiles/traci.dir/ExtensibleNodeManager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/ExtensibleNodeManager.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/ExtensibleNodeManager.cc > CMakeFiles/traci.dir/ExtensibleNodeManager.cc.i

src/traci/CMakeFiles/traci.dir/ExtensibleNodeManager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/ExtensibleNodeManager.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/ExtensibleNodeManager.cc -o CMakeFiles/traci.dir/ExtensibleNodeManager.cc.s

src/traci/CMakeFiles/traci.dir/InsertionDelayVehiclePolicy.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/InsertionDelayVehiclePolicy.cc.o: ../src/traci/InsertionDelayVehiclePolicy.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/traci/CMakeFiles/traci.dir/InsertionDelayVehiclePolicy.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/InsertionDelayVehiclePolicy.cc.o -c /home/veins/artery/src/traci/InsertionDelayVehiclePolicy.cc

src/traci/CMakeFiles/traci.dir/InsertionDelayVehiclePolicy.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/InsertionDelayVehiclePolicy.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/InsertionDelayVehiclePolicy.cc > CMakeFiles/traci.dir/InsertionDelayVehiclePolicy.cc.i

src/traci/CMakeFiles/traci.dir/InsertionDelayVehiclePolicy.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/InsertionDelayVehiclePolicy.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/InsertionDelayVehiclePolicy.cc -o CMakeFiles/traci.dir/InsertionDelayVehiclePolicy.cc.s

src/traci/CMakeFiles/traci.dir/Listener.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/Listener.cc.o: ../src/traci/Listener.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/traci/CMakeFiles/traci.dir/Listener.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/Listener.cc.o -c /home/veins/artery/src/traci/Listener.cc

src/traci/CMakeFiles/traci.dir/Listener.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/Listener.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/Listener.cc > CMakeFiles/traci.dir/Listener.cc.i

src/traci/CMakeFiles/traci.dir/Listener.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/Listener.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/Listener.cc -o CMakeFiles/traci.dir/Listener.cc.s

src/traci/CMakeFiles/traci.dir/MultiTypeModuleMapper.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/MultiTypeModuleMapper.cc.o: ../src/traci/MultiTypeModuleMapper.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/traci/CMakeFiles/traci.dir/MultiTypeModuleMapper.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/MultiTypeModuleMapper.cc.o -c /home/veins/artery/src/traci/MultiTypeModuleMapper.cc

src/traci/CMakeFiles/traci.dir/MultiTypeModuleMapper.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/MultiTypeModuleMapper.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/MultiTypeModuleMapper.cc > CMakeFiles/traci.dir/MultiTypeModuleMapper.cc.i

src/traci/CMakeFiles/traci.dir/MultiTypeModuleMapper.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/MultiTypeModuleMapper.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/MultiTypeModuleMapper.cc -o CMakeFiles/traci.dir/MultiTypeModuleMapper.cc.s

src/traci/CMakeFiles/traci.dir/PosixLauncher.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/PosixLauncher.cc.o: ../src/traci/PosixLauncher.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/traci/CMakeFiles/traci.dir/PosixLauncher.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/PosixLauncher.cc.o -c /home/veins/artery/src/traci/PosixLauncher.cc

src/traci/CMakeFiles/traci.dir/PosixLauncher.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/PosixLauncher.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/PosixLauncher.cc > CMakeFiles/traci.dir/PosixLauncher.cc.i

src/traci/CMakeFiles/traci.dir/PosixLauncher.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/PosixLauncher.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/PosixLauncher.cc -o CMakeFiles/traci.dir/PosixLauncher.cc.s

src/traci/CMakeFiles/traci.dir/RegionsOfInterest.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/RegionsOfInterest.cc.o: ../src/traci/RegionsOfInterest.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object src/traci/CMakeFiles/traci.dir/RegionsOfInterest.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/RegionsOfInterest.cc.o -c /home/veins/artery/src/traci/RegionsOfInterest.cc

src/traci/CMakeFiles/traci.dir/RegionsOfInterest.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/RegionsOfInterest.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/RegionsOfInterest.cc > CMakeFiles/traci.dir/RegionsOfInterest.cc.i

src/traci/CMakeFiles/traci.dir/RegionsOfInterest.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/RegionsOfInterest.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/RegionsOfInterest.cc -o CMakeFiles/traci.dir/RegionsOfInterest.cc.s

src/traci/CMakeFiles/traci.dir/RegionOfInterestVehiclePolicy.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/RegionOfInterestVehiclePolicy.cc.o: ../src/traci/RegionOfInterestVehiclePolicy.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object src/traci/CMakeFiles/traci.dir/RegionOfInterestVehiclePolicy.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/RegionOfInterestVehiclePolicy.cc.o -c /home/veins/artery/src/traci/RegionOfInterestVehiclePolicy.cc

src/traci/CMakeFiles/traci.dir/RegionOfInterestVehiclePolicy.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/RegionOfInterestVehiclePolicy.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/RegionOfInterestVehiclePolicy.cc > CMakeFiles/traci.dir/RegionOfInterestVehiclePolicy.cc.i

src/traci/CMakeFiles/traci.dir/RegionOfInterestVehiclePolicy.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/RegionOfInterestVehiclePolicy.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/RegionOfInterestVehiclePolicy.cc -o CMakeFiles/traci.dir/RegionOfInterestVehiclePolicy.cc.s

src/traci/CMakeFiles/traci.dir/TestbedModuleMapper.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/TestbedModuleMapper.cc.o: ../src/traci/TestbedModuleMapper.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object src/traci/CMakeFiles/traci.dir/TestbedModuleMapper.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/TestbedModuleMapper.cc.o -c /home/veins/artery/src/traci/TestbedModuleMapper.cc

src/traci/CMakeFiles/traci.dir/TestbedModuleMapper.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/TestbedModuleMapper.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/TestbedModuleMapper.cc > CMakeFiles/traci.dir/TestbedModuleMapper.cc.i

src/traci/CMakeFiles/traci.dir/TestbedModuleMapper.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/TestbedModuleMapper.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/TestbedModuleMapper.cc -o CMakeFiles/traci.dir/TestbedModuleMapper.cc.s

src/traci/CMakeFiles/traci.dir/TestbedNodeManager.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/TestbedNodeManager.cc.o: ../src/traci/TestbedNodeManager.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object src/traci/CMakeFiles/traci.dir/TestbedNodeManager.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/TestbedNodeManager.cc.o -c /home/veins/artery/src/traci/TestbedNodeManager.cc

src/traci/CMakeFiles/traci.dir/TestbedNodeManager.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/TestbedNodeManager.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/TestbedNodeManager.cc > CMakeFiles/traci.dir/TestbedNodeManager.cc.i

src/traci/CMakeFiles/traci.dir/TestbedNodeManager.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/TestbedNodeManager.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/TestbedNodeManager.cc -o CMakeFiles/traci.dir/TestbedNodeManager.cc.s

src/traci/CMakeFiles/traci.dir/ValueUtils.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/ValueUtils.cc.o: ../src/traci/ValueUtils.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object src/traci/CMakeFiles/traci.dir/ValueUtils.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/ValueUtils.cc.o -c /home/veins/artery/src/traci/ValueUtils.cc

src/traci/CMakeFiles/traci.dir/ValueUtils.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/ValueUtils.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/ValueUtils.cc > CMakeFiles/traci.dir/ValueUtils.cc.i

src/traci/CMakeFiles/traci.dir/ValueUtils.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/ValueUtils.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/ValueUtils.cc -o CMakeFiles/traci.dir/ValueUtils.cc.s

src/traci/CMakeFiles/traci.dir/VariableCache.cc.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/VariableCache.cc.o: ../src/traci/VariableCache.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object src/traci/CMakeFiles/traci.dir/VariableCache.cc.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/VariableCache.cc.o -c /home/veins/artery/src/traci/VariableCache.cc

src/traci/CMakeFiles/traci.dir/VariableCache.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/VariableCache.cc.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/VariableCache.cc > CMakeFiles/traci.dir/VariableCache.cc.i

src/traci/CMakeFiles/traci.dir/VariableCache.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/VariableCache.cc.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/VariableCache.cc -o CMakeFiles/traci.dir/VariableCache.cc.s

src/traci/CMakeFiles/traci.dir/sumo/foreign/tcpip/socket.cpp.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/sumo/foreign/tcpip/socket.cpp.o: ../src/traci/sumo/foreign/tcpip/socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object src/traci/CMakeFiles/traci.dir/sumo/foreign/tcpip/socket.cpp.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/sumo/foreign/tcpip/socket.cpp.o -c /home/veins/artery/src/traci/sumo/foreign/tcpip/socket.cpp

src/traci/CMakeFiles/traci.dir/sumo/foreign/tcpip/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/sumo/foreign/tcpip/socket.cpp.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/sumo/foreign/tcpip/socket.cpp > CMakeFiles/traci.dir/sumo/foreign/tcpip/socket.cpp.i

src/traci/CMakeFiles/traci.dir/sumo/foreign/tcpip/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/sumo/foreign/tcpip/socket.cpp.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/sumo/foreign/tcpip/socket.cpp -o CMakeFiles/traci.dir/sumo/foreign/tcpip/socket.cpp.s

src/traci/CMakeFiles/traci.dir/sumo/foreign/tcpip/storage.cpp.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/sumo/foreign/tcpip/storage.cpp.o: ../src/traci/sumo/foreign/tcpip/storage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object src/traci/CMakeFiles/traci.dir/sumo/foreign/tcpip/storage.cpp.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/sumo/foreign/tcpip/storage.cpp.o -c /home/veins/artery/src/traci/sumo/foreign/tcpip/storage.cpp

src/traci/CMakeFiles/traci.dir/sumo/foreign/tcpip/storage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/sumo/foreign/tcpip/storage.cpp.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/sumo/foreign/tcpip/storage.cpp > CMakeFiles/traci.dir/sumo/foreign/tcpip/storage.cpp.i

src/traci/CMakeFiles/traci.dir/sumo/foreign/tcpip/storage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/sumo/foreign/tcpip/storage.cpp.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/sumo/foreign/tcpip/storage.cpp -o CMakeFiles/traci.dir/sumo/foreign/tcpip/storage.cpp.s

src/traci/CMakeFiles/traci.dir/sumo/utils/traci/TraCIAPI.cpp.o: src/traci/CMakeFiles/traci.dir/flags.make
src/traci/CMakeFiles/traci.dir/sumo/utils/traci/TraCIAPI.cpp.o: ../src/traci/sumo/utils/traci/TraCIAPI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Building CXX object src/traci/CMakeFiles/traci.dir/sumo/utils/traci/TraCIAPI.cpp.o"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/traci.dir/sumo/utils/traci/TraCIAPI.cpp.o -c /home/veins/artery/src/traci/sumo/utils/traci/TraCIAPI.cpp

src/traci/CMakeFiles/traci.dir/sumo/utils/traci/TraCIAPI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/traci.dir/sumo/utils/traci/TraCIAPI.cpp.i"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/veins/artery/src/traci/sumo/utils/traci/TraCIAPI.cpp > CMakeFiles/traci.dir/sumo/utils/traci/TraCIAPI.cpp.i

src/traci/CMakeFiles/traci.dir/sumo/utils/traci/TraCIAPI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/traci.dir/sumo/utils/traci/TraCIAPI.cpp.s"
	cd /home/veins/artery/build/src/traci && /usr/lib/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/veins/artery/src/traci/sumo/utils/traci/TraCIAPI.cpp -o CMakeFiles/traci.dir/sumo/utils/traci/TraCIAPI.cpp.s

# Object files for target traci
traci_OBJECTS = \
"CMakeFiles/traci.dir/API.cc.o" \
"CMakeFiles/traci.dir/BasicModuleMapper.cc.o" \
"CMakeFiles/traci.dir/BasicNodeManager.cc.o" \
"CMakeFiles/traci.dir/BasicSubscriptionManager.cc.o" \
"CMakeFiles/traci.dir/CheckTimeSync.cc.o" \
"CMakeFiles/traci.dir/Core.cc.o" \
"CMakeFiles/traci.dir/ConnectLauncher.cc.o" \
"CMakeFiles/traci.dir/ExtensibleNodeManager.cc.o" \
"CMakeFiles/traci.dir/InsertionDelayVehiclePolicy.cc.o" \
"CMakeFiles/traci.dir/Listener.cc.o" \
"CMakeFiles/traci.dir/MultiTypeModuleMapper.cc.o" \
"CMakeFiles/traci.dir/PosixLauncher.cc.o" \
"CMakeFiles/traci.dir/RegionsOfInterest.cc.o" \
"CMakeFiles/traci.dir/RegionOfInterestVehiclePolicy.cc.o" \
"CMakeFiles/traci.dir/TestbedModuleMapper.cc.o" \
"CMakeFiles/traci.dir/TestbedNodeManager.cc.o" \
"CMakeFiles/traci.dir/ValueUtils.cc.o" \
"CMakeFiles/traci.dir/VariableCache.cc.o" \
"CMakeFiles/traci.dir/sumo/foreign/tcpip/socket.cpp.o" \
"CMakeFiles/traci.dir/sumo/foreign/tcpip/storage.cpp.o" \
"CMakeFiles/traci.dir/sumo/utils/traci/TraCIAPI.cpp.o"

# External object files for target traci
traci_EXTERNAL_OBJECTS =

src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/API.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/BasicModuleMapper.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/BasicNodeManager.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/BasicSubscriptionManager.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/CheckTimeSync.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/Core.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/ConnectLauncher.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/ExtensibleNodeManager.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/InsertionDelayVehiclePolicy.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/Listener.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/MultiTypeModuleMapper.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/PosixLauncher.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/RegionsOfInterest.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/RegionOfInterestVehiclePolicy.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/TestbedModuleMapper.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/TestbedNodeManager.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/ValueUtils.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/VariableCache.cc.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/sumo/foreign/tcpip/socket.cpp.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/sumo/foreign/tcpip/storage.cpp.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/sumo/utils/traci/TraCIAPI.cpp.o
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/build.make
src/traci/libtraci.so: src/traci/CMakeFiles/traci.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/veins/artery/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_22) "Linking CXX shared library libtraci.so"
	cd /home/veins/artery/build/src/traci && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/traci.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/traci/CMakeFiles/traci.dir/build: src/traci/libtraci.so

.PHONY : src/traci/CMakeFiles/traci.dir/build

src/traci/CMakeFiles/traci.dir/clean:
	cd /home/veins/artery/build/src/traci && $(CMAKE_COMMAND) -P CMakeFiles/traci.dir/cmake_clean.cmake
.PHONY : src/traci/CMakeFiles/traci.dir/clean

src/traci/CMakeFiles/traci.dir/depend:
	cd /home/veins/artery/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/veins/artery /home/veins/artery/src/traci /home/veins/artery/build /home/veins/artery/build/src/traci /home/veins/artery/build/src/traci/CMakeFiles/traci.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/traci/CMakeFiles/traci.dir/depend

