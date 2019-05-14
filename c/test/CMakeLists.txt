add_executable (rtcm_test rtcm_decoder_tests.c)

target_link_libraries(rtcm_test LINK_PUBLIC rtcm)

add_test(NAME rtcm_test COMMAND rtcm_test)
