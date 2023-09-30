# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.17)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget Vanetza::access Vanetza::asn1_support Vanetza::asn1_its Vanetza::asn1_security Vanetza::asn1_pki Vanetza::asn1 Vanetza::btp Vanetza::common Vanetza::dcc Vanetza::facilities Vanetza::geonet Vanetza::gnss Vanetza::net Vanetza::security Vanetza::vanetza)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target Vanetza::access
add_library(Vanetza::access SHARED IMPORTED)

set_target_properties(Vanetza::access PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Vanetza::net"
)

# Create imported target Vanetza::asn1_support
add_library(Vanetza::asn1_support SHARED IMPORTED)

set_target_properties(Vanetza::asn1_support PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include;${_IMPORT_PREFIX}/include/vanetza/asn1/support"
)

# Create imported target Vanetza::asn1_its
add_library(Vanetza::asn1_its SHARED IMPORTED)

set_target_properties(Vanetza::asn1_its PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Vanetza::asn1_support"
)

# Create imported target Vanetza::asn1_security
add_library(Vanetza::asn1_security SHARED IMPORTED)

set_target_properties(Vanetza::asn1_security PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Vanetza::asn1_support"
)

# Create imported target Vanetza::asn1_pki
add_library(Vanetza::asn1_pki SHARED IMPORTED)

set_target_properties(Vanetza::asn1_pki PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Vanetza::asn1_support"
)

# Create imported target Vanetza::asn1
add_library(Vanetza::asn1 SHARED IMPORTED)

set_target_properties(Vanetza::asn1 PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Vanetza::asn1_its;Boost::boost"
)

# Create imported target Vanetza::btp
add_library(Vanetza::btp SHARED IMPORTED)

set_target_properties(Vanetza::btp PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Boost::boost;Vanetza::geonet"
)

# Create imported target Vanetza::common
add_library(Vanetza::common SHARED IMPORTED)

set_target_properties(Vanetza::common PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Boost::date_time;Threads::Threads"
)

# Create imported target Vanetza::dcc
add_library(Vanetza::dcc SHARED IMPORTED)

set_target_properties(Vanetza::dcc PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Vanetza::access;Vanetza::net"
)

# Create imported target Vanetza::facilities
add_library(Vanetza::facilities SHARED IMPORTED)

set_target_properties(Vanetza::facilities PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Boost::date_time;Vanetza::asn1;Vanetza::security"
)

# Create imported target Vanetza::geonet
add_library(Vanetza::geonet SHARED IMPORTED)

set_target_properties(Vanetza::geonet PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Boost::date_time;Vanetza::dcc;Vanetza::net;Vanetza::security"
)

# Create imported target Vanetza::gnss
add_library(Vanetza::gnss SHARED IMPORTED)

set_target_properties(Vanetza::gnss PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Boost::date_time"
)

# Create imported target Vanetza::net
add_library(Vanetza::net SHARED IMPORTED)

set_target_properties(Vanetza::net PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Vanetza::common"
)

# Create imported target Vanetza::security
add_library(Vanetza::security SHARED IMPORTED)

set_target_properties(Vanetza::security PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "VANETZA_WITH_CRYPTOPP"
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include"
  INTERFACE_LINK_LIBRARIES "Vanetza::common;Vanetza::net;CryptoPP::CryptoPP"
)

# Create imported target Vanetza::vanetza
add_library(Vanetza::vanetza INTERFACE IMPORTED)

set_target_properties(Vanetza::vanetza PROPERTIES
  INTERFACE_LINK_LIBRARIES "Vanetza::access;Vanetza::asn1_support;Vanetza::asn1_its;Vanetza::asn1_security;Vanetza::asn1_pki;Vanetza::asn1;Vanetza::btp;Vanetza::common;Vanetza::dcc;Vanetza::facilities;Vanetza::geonet;Vanetza::gnss;Vanetza::net;Vanetza::security"
)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
  message(FATAL_ERROR "This file relies on consumers using CMake 3.0.0 or greater.")
endif()

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/VanetzaTargets-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
