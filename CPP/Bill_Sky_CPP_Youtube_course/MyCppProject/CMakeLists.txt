cmake_minimum_required(VERSION 3.10.0)
project(MyCppProject VERSION 0.1.0 LANGUAGES C CXX)

add_executable(${PROJECT_NAME} 
    # src/main.cpp
    # src/main2.cpp
    # src/numeric_variables.cpp
    # src/characters_and_strings.cpp
    # src/the_assignment_operator.cpp
    # src/constants_scope_and_globals.cpp
    # src/simple_arithmetic.cpp
    # src/pointers.cpp
    # src/pointers_and_arrays.cpp
    # src/more_math.cpp
    # src/program_interactivity.cpp
    # src/interactivity_with_formatted_output.cpp
    # src/pointers_and_dynamic_memory_allocation.cpp
    # src/conditional_processing_flowcharts.cpp
    # src/if_statements.cpp
    # src/dynamic_array_of_puppies.cpp
    # src/dynamic_puppies.cpp
    # src/intro_to_object_oriented_programming.cpp 
    # src/object_pointers.cpp 
    # src/Puppy.cpp
    # src/switch_statement.cpp
    # src/while_loops.cpp
    src/simple_files.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(CTest)
enable_testing()
