find_package(Git REQUIRED)
file(GLOB PATCH_FILES ${PATCH_DIRECTORY}/*.patch)
foreach(PATCH_FILE IN LISTS PATCH_FILES)
    get_filename_component(PATCH_NAME "${PATCH_FILE}" NAME_WE)
    message(STATUS "Applying patch ${PATCH_NAME}")
    execute_process(COMMAND "${GIT_EXECUTABLE}" apply "${PATCH_FILE}" RESULT_VARIABLE PATCH_RESULT)
    if(NOT PATCH_RESULT EQUAL 0)
        message(SEND_ERROR "Applying patch ${PATCH_FILE} failed!")
    endif()
endforeach()
