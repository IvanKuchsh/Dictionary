cmake_minimum_required (VERSION 3.8)

project ("Dictionary")

add_executable (dictionary "main.cpp")

set_target_properties(
	dictionary PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED ON
)