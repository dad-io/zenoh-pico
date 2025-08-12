// Stub implementations for disabled transport features
#include "zenoh-pico/utils/result.h"
#include "zenoh-pico/transport/transport.h"
#include "zenoh-pico/link/endpoint.h"
#include "zenoh-pico/net/session.h"
#include "zenoh-pico/protocol/definitions/network.h"

// Multicast transport stubs
z_result_t _z_multicast_open_client(const _z_locator_t *locator, _z_link_t *zl, uint32_t timeout) {
    (void)locator; (void)zl; (void)timeout;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _z_multicast_open_peer(const _z_locator_t *locator, _z_link_t *zl, uint32_t timeout) {
    (void)locator; (void)zl; (void)timeout;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _z_multicast_transport_create(_z_transport_t *zt, _z_link_t *zl, const _z_transport_common_t *tc, uint32_t *ts, uint32_t *ls) {
    (void)zt; (void)zl; (void)tc; (void)ts; (void)ls;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _z_multicast_send_close(_z_transport_t *zt, uint8_t reason, bool link_only) {
    (void)zt; (void)reason; (void)link_only;
    return _Z_RES_OK;
}

void _z_multicast_transport_clear(_z_transport_t *zt) {
    (void)zt;
}

z_result_t _z_multicast_send_n_msg(const _z_session_t *zn, const _z_network_message_t *n_msg, z_reliability_t reliability, z_congestion_control_t cong_ctrl) {
    (void)zn; (void)n_msg; (void)reliability; (void)cong_ctrl;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

// RawEth transport stubs  
z_result_t _z_raweth_open_client(const _z_locator_t *locator, _z_link_t *zl, uint32_t timeout) {
    (void)locator; (void)zl; (void)timeout;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _z_raweth_open_peer(const _z_locator_t *locator, _z_link_t *zl, uint32_t timeout) {
    (void)locator; (void)zl; (void)timeout;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _z_raweth_send_n_msg(const _z_session_t *zn, const _z_network_message_t *n_msg, z_reliability_t reliability, z_congestion_control_t cong_ctrl) {
    (void)zn; (void)n_msg; (void)reliability; (void)cong_ctrl;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _z_raweth_config_from_strn(_z_str_intmap_t *config, const char *strn, size_t len) {
    (void)config; (void)strn; (void)len;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

// Session task stubs for multicast
z_result_t _zp_multicast_start_read_task(_z_transport_t *zt, z_task_attr_t *attr, _z_task_t *task) {
    (void)zt; (void)attr; (void)task;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _zp_multicast_stop_read_task(_z_transport_t *zt) {
    (void)zt;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _zp_multicast_start_lease_task(_z_transport_multicast_t *ztm, z_task_attr_t *attr, _z_task_t *task) {
    (void)ztm; (void)attr; (void)task;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _zp_multicast_stop_lease_task(_z_transport_multicast_t *ztm) {
    (void)ztm;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

// Session task stubs for raweth
z_result_t _zp_raweth_start_read_task(_z_transport_t *zt, z_task_attr_t *attr, _z_task_t *task) {
    (void)zt; (void)attr; (void)task;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _zp_raweth_stop_read_task(_z_transport_t *zt) {
    (void)zt;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

// Link management stubs
z_result_t _z_endpoint_udp_multicast_valid(_z_endpoint_t *ep) {
    (void)ep;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _z_new_link_udp_multicast(_z_link_t *zl, _z_endpoint_t ep) {
    (void)zl; (void)ep;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _z_endpoint_raweth_valid(_z_endpoint_t *endpoint) {
    (void)endpoint;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _z_new_link_raweth(_z_link_t *zl, _z_endpoint_t endpoint) {
    (void)zl; (void)endpoint;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}

z_result_t _zp_multicast_send_join(_z_transport_multicast_t *ztm) {
    (void)ztm;
    return _Z_ERR_TRANSPORT_NOT_AVAILABLE;
}