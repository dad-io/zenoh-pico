# ESP-IDF Component CMakeLists.txt for zenoh-pico

# Define source files - exclude platform-specific files not needed for ESP-IDF
file(GLOB_RECURSE SOURCES 
    "${CMAKE_CURRENT_LIST_DIR}/src/*.c"
)

# Remove Arduino and other platform-specific files
list(FILTER SOURCES EXCLUDE REGEX ".*/arduino/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/mbed/.*") 
list(FILTER SOURCES EXCLUDE REGEX ".*/freertos/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/rpi_pico/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/threadx/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/unix/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/windows/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/zephyr/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/emscripten/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/flipper/.*")

# Remove raweth and multicast transport files since they're not needed for ESP32
list(FILTER SOURCES EXCLUDE REGEX ".*/raweth/.*")
list(FILTER SOURCES EXCLUDE REGEX ".*/multicast/.*")

# Add ESP-IDF specific sources
file(GLOB ESPIDF_SOURCES
    "${CMAKE_CURRENT_LIST_DIR}/src/system/espidf/*.c"
)
list(APPEND SOURCES ${ESPIDF_SOURCES})

# Add stub implementations for disabled transports
list(APPEND SOURCES "${CMAKE_CURRENT_LIST_DIR}/stubs.c")

# For ESP-IDF, we need to register the component
idf_component_register(
    SRCS ${SOURCES}
    INCLUDE_DIRS "include"
    REQUIRES lwip freertos esp_driver_uart
    PRIV_REQUIRES esp_netif esp_wifi esp_timer log
)

# Define configuration for ESP-IDF
target_compile_definitions(${COMPONENT_LIB} PUBLIC
    Z_FEATURE_PUBLICATION=1
    Z_FEATURE_SUBSCRIPTION=1
    Z_FEATURE_QUERY=1
    Z_FEATURE_QUERYABLE=1
    Z_FEATURE_INTEREST=0
    Z_FEATURE_LIVELINESS=0
    Z_FEATURE_MULTI_THREAD=1
    Z_FEATURE_UNICAST_TRANSPORT=1
    Z_FEATURE_MULTICAST_TRANSPORT=0
    Z_FEATURE_RAWETH_TRANSPORT=0
    Z_FEATURE_TCP_TRANSPORT=1
    Z_FEATURE_UDP_TRANSPORT=0
    Z_FEATURE_WS_TRANSPORT=0
    Z_FEATURE_RX_CACHE=0
    ZENOH_ESPIDF=1
    ZENOH_C_STANDARD=11
)

# Set C standard
set_property(TARGET ${COMPONENT_LIB} PROPERTY C_STANDARD 11)