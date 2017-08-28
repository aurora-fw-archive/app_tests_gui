message(STATUS "Loading tests-gui app...")

if (NOT CONFIGURED_ONCE)
	set(APP_TESTS_GUI_SOURCE_DIR ${APP_TESTS_GUI_DIR}/src)
endif()

add_executable(aurorafw_app_tests_gui ${APP_TESTS_GUI_SOURCE_DIR}/test_gui.cpp)

target_link_libraries(aurorafw_app_tests_gui aurorafw-core aurorafw-gui)

set_target_properties(aurorafw_app_tests_gui PROPERTIES OUTPUT_NAME test_gui.out)
