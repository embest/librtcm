add_executable (rtcm_test rtcm_decoder_tests.c)

target_link_libraries(rtcm_test LINK_PUBLIC rtcm)

add_custom_command(
    TARGET rtcm_test POST_BUILD
    COMMENT "Running unit tests"
    COMMAND rtcm_test
)
target_compile_options(rtcm_test PRIVATE "-std=gnu99")

