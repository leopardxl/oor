/*
 *
 * Copyright (C) 2011, 2015 Cisco Systems, Inc.
 * Copyright (C) 2015 CBA research group, Technical University of Catalonia.
 *
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
 *
 */

#ifndef IFACE_LIST_H_
#define IFACE_LIST_H_

#include "liblisp/lisp_mapping.h"
#include "defs.h"
#include "lib/timers.h"

# define IN6_IS_ADDR_GLOBAL(a) \
        (__extension__                                  \
                ({ const uint32_t *__a = (const uint32_t *) (a);         \
                (__a[0] & htonl (0xE0000000)) == htonl (0x20000000); }))

# define IN6_IS_ADDR_SITE_LOCAL(a) \
        (__extension__                                  \
                ({ const uint32_t *__a = (const uint32_t *) (a);         \
                ((__a[0] & htonl (0xffc00000)) == htonl (0xfec00000)) ||  \
                ((__a[0] & htonl (0xfe000000)) == htonl (0xfc000000)); }))


/* Interface structure
 * ===================
 * Locator address (rloc) is linked to the interface address. If the address
 * of the interface changes, the locator address changes automatically */
typedef struct iface {
    char *iface_name;
    uint32_t iface_index;
    uint8_t status;
    lisp_addr_t *ipv4_address;
    lisp_addr_t *ipv6_address;
    lisp_addr_t *ipv4_gateway;
    lisp_addr_t *ipv6_gateway;

    int out_socket_v4;
    int out_socket_v6;
} iface_t;




extern glist_t *interface_list;  //<iface_t *>
extern shash_t *iface_addr_ht; // <char * address, char * iface_name>
extern ipv6_scope_e ipv6_scope;



int ifaces_init();
void iface_destroy(iface_t *iface);
void ifaces_destroy();
int iface_configure (iface_t *iface, int afi);
char *iface_to_char(iface_t *iface);

iface_t *add_interface(char *iface_name);
iface_t *get_interface(char *iface_name);
iface_t *get_interface_from_index(int iface_index);
iface_t *get_interface_with_address(lisp_addr_t *address);
int *get_out_socket_ptr_from_address(lisp_addr_t *address);

/* Print the interfaces and locators of the lisp node */
void iface_list_to_char(int log_level);

iface_t *get_any_output_iface(int);

lisp_addr_t *iface_address(iface_t *iface, int afi);
lisp_addr_t *iface_gateway(iface_t *iface, int afi);
int iface_socket(iface_t *iface, int afi);
int *iface_socket_pointer(iface_t *iface, int afi);
static uint8_t iface_status(iface_t *iface);
char *get_interface_name_from_address(lisp_addr_t *addr);

static inline uint8_t iface_status(iface_t *iface)
{
    return (iface->status);
}



#endif /*IFACE_LIST_H_*/
