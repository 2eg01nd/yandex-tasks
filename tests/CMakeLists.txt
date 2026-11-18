include(GoogleTest)

function(add_cpp_task TASK_NAME)
  set(TASK_HEADER "${CMAKE_SOURCE_DIR}/include/${TASK_NAME}.h")
  set(TASK_SOURCE "${CMAKE_SOURCE_DIR}/src/${TASK_NAME}.cpp")
  set(TASK_TEST "${CMAKE_CURRENT_SOURCE_DIR}/${TASK_NAME}_test.cpp")

  if(NOT EXISTS "${TASK_HEADER}")
    message(FATAL_ERROR "Missing header file: ${TASK_HEADER}")
  endif()

  if(NOT EXISTS "${TASK_SOURCE}")
    message(FATAL_ERROR "Missing source file: ${TASK_SOURCE}")
  endif()

  if(NOT EXISTS "${TASK_TEST}")
    message(FATAL_ERROR "Missing test file: ${TASK_TEST}")
  endif()

  add_library(${TASK_NAME} STATIC "${TASK_SOURCE}")

  target_include_directories(${TASK_NAME}
        PUBLIC
            "${CMAKE_SOURCE_DIR}/include"
    )

  target_compile_features(${TASK_NAME}
        PUBLIC
            cxx_std_20
    )

  if(MSVC)
    target_compile_options(${TASK_NAME} PRIVATE /W4 /permissive-)
  else()
    target_compile_options(${TASK_NAME} PRIVATE -Wall -Wextra -Wpedantic)
  endif()

  add_executable(${TASK_NAME}_test "${TASK_TEST}")

  target_link_libraries(${TASK_NAME}_test
        PRIVATE
            ${TASK_NAME}
            GTest::gmock_main
    )

  if(MSVC)
    target_compile_options(${TASK_NAME}_test PRIVATE /W4 /permissive-
        )
  else()
    target_compile_options(${TASK_NAME}_test PRIVATE -Wall -Wextra -Wpedantic)
  endif()

  if(CPP_TASKS_WARNINGS_AS_ERRORS)
    if(MSVC)
      target_compile_options(${TASK_NAME} PRIVATE /WX)
      target_compile_options(${TASK_NAME}_test PRIVATE /WX)
    else()
      target_compile_options(${TASK_NAME} PRIVATE -Werror)
      target_compile_options(${TASK_NAME}_test PRIVATE -Werror)
    endif()
  endif()

  gtest_discover_tests(${TASK_NAME}_test)
endfunction()

add_cpp_task(two_sum)
