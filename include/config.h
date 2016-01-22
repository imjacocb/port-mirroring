/* 
 * Copyright (c) 2015 Mike Maraya <mike[dot]maraya[at]gmail[dot]com>
 * All rights reserved.
 *
 * This file is subject to the terms and conditions defined in
 * https://github.com/mmaraya/port-mirroring/blob/master/LICENSE,
 * which is part of this software package.
 *
 */

#ifndef PORT_MIRRORING_UTIL_H_
#define PORT_MIRRORING_UTIL_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/limits.h>
#include "net.h"

#define OPTION_MAX  254     /* max value for program options                */
#define TIMEBUF     32      /* max timestamp length RFC3339                 */
#define SRC_MAX     4       /* maxium number of source network interfaces   */
#define PFE_MAX     80      /* maximum length of packet filter expression   */

// port-mirroring configuration bit flags
#define PM_DAEMON   0x01    /* run as background process                    */
#define PM_DEBUG    0x02    /* display debugging messages to console        */
#define PM_TZSP     0x04    /* send packets using TaZmen Sniffer Protocol   */
#define PM_IFACE    0x08    /* destination is a network interface           */
#define PM_IPADDR   0x0F    /* destination is an internet protocol address  */
#define PM_PROMISC  0x10    /* place source interface in promiscuous mode   */
#define PM_SYSLOG   0x20    /* log messages to syslog facility              */

// if no configuration file is specified, look through these in order
#define CFG_PATH_1  "/etc/config/port-mirroring"
#define CFG_PATH_2  "/etc/port-mirroring"
#define CFG_PATH_3  "port-mirroring.conf"

// default program id file
#define PID_PATH    "/var/run/port-mirroring.pid"

// program-wide configuration settings and variables
struct pm_cfg
{
    char        *cfg_file;      /* path to configuration file       */
    uint8_t     flags;          /* boolean setting bitmask          */
    char        *src[SRC_MAX];  /* source network interfaces        */
    char        *dst_if;        /* destination network interface    */
    in_addr_t   dst_ip;         /* destination IP address           */
    char        *pf;            /* tcpdump packet filter expression */
    char        *pid_file;      /* path to process id file          */
    int         src_count;      /* number of source ports           */ 
    int         packet_count;   /* number of packets processed      */
};

void find_cfg(struct pm_cfg *cfg);
char * printMACStr(const char *mac);
char * getUCIItem(char *buf, char *item);
int getUCIConf(char *buf, char *option, char *value);

#endif  // PORT_MIRRORING_UTIL_H_
