/* Copyright (c) 2016-2017, Rafael Almeida <rlca at dcc dot ufmg dot br>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of mtraceroute nor the names of its contributors may
 *     be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __PDU_IPV6_H__
#define __PDU_IPV6_H__

#include <stdint.h>
#include "packet.h"

#define IPV6_H_SIZE       40
#define IPV6_HOP_LIMIT    64
#define IPV6_HOP_LIMIT_ND 255
#define IPV6_FL_MASK      0xfffff

// IPv6 header
struct ipv6_hdr {
    uint32_t version_tc_fl;
    uint16_t length;
    uint8_t  next_header;
    uint8_t  hop_limit;
    uint32_t src_addr[4];
    uint32_t dst_addr[4];
};

#define IPV6_PH_SIZE 40

struct ipv6_ph {
    uint32_t src_addr[4];
    uint32_t dst_addr[4];
    uint32_t length;
    uint8_t zeroes[3];
    uint8_t next_header;
};

int pdu_ipv6(struct packet *p, uint8_t traffic_class,
             uint32_t flow_label, uint16_t length,
             uint8_t next_header, uint8_t hop_limit,
             const uint8_t *src_addr, const uint8_t *dst_addr);

int pdu_ipv6_length(struct packet *p, int tag);

int pdu_ipv6_next_header(struct packet *p, int tag);

struct ipv6_ph *pdu_ipv6_ph(const uint32_t *src_addr, const uint32_t *dst_addr,
                            uint16_t length, uint8_t next_header);

#endif // __PDU_IPV6_H__
