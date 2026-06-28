#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "controller::controller" for configuration ""
set_property(TARGET controller::controller APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(controller::controller PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcontroller.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS controller::controller )
list(APPEND _IMPORT_CHECK_FILES_FOR_controller::controller "${_IMPORT_PREFIX}/lib/libcontroller.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
