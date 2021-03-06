
/*
 * oor_pkt_miss.h - skeleton vpp engine plug-in header file 
 *
 * Copyright (c) <current-year> <your-organization>
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __included_oor_pkt_miss_h__
#define __included_oor_pkt_miss_h__

#include <vnet/vnet.h>
#include <vnet/ip/ip.h>
#include <vnet/ethernet/ethernet.h>

#include <vppinfra/hash.h>
#include <vppinfra/error.h>

typedef struct {
    /* API message ID base */
    u16 msg_id_base;
    u32 sw_if_index;
    ip46_address_t ipv4_gateway;
    u8 has_ipv4_gateway;
    ip46_address_t ipv6_gateway;
    u8 has_ipv6_gateway;

    /* convenience */
    vlib_main_t * vlib_main;
    vnet_main_t * vnet_main;
    ethernet_main_t * ethernet_main;
} oor_pkt_miss_main_t;

oor_pkt_miss_main_t oor_pkt_miss_main;

vlib_node_registration_t oor_pkt_miss_node;

#define OOR_PKT_MISS_PLUGIN_BUILD_VER "1.0"

#endif /* __included_oor_pkt_miss_h__ */
