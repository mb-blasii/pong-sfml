#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "atlas::atlas" for configuration "Debug"
set_property(TARGET atlas::atlas APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(atlas::atlas PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/libatlas.dll.a"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/libatlas.dll"
  )

list(APPEND _cmake_import_check_targets atlas::atlas )
list(APPEND _cmake_import_check_files_for_atlas::atlas "${_IMPORT_PREFIX}/lib/libatlas.dll.a" "${_IMPORT_PREFIX}/bin/libatlas.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
