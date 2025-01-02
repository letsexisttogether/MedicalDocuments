# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MedicalDocuments_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MedicalDocuments_autogen.dir\\ParseCache.txt"
  "MedicalDocuments_autogen"
  )
endif()
