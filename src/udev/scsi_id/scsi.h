/* SPDX-License-Identifier: GPL-2.0-or-later */
#pragma once

/* Copyright (C) IBM Corp. 2003 */

#include <scsi/scsi.h>
#include <sys/types.h>

struct scsi_ioctl_command {
        unsigned inlen;        /* excluding scsi command length */
        unsigned outlen;
        unsigned char data[1];
        /* on input, scsi command starts here then opt. data */
};

/*
 * Default 5 second timeout
 */
#define DEF_TIMEOUT 5000

#define SENSE_BUFF_LEN 32

/*
 * The request buffer size passed to the SCSI INQUIRY commands, use 254,
 * as this is a nice value for some devices, especially some of the usb
 * mass storage devices.
 */
#define SCSI_INQ_BUFF_LEN 254

/*
 * SCSI INQUIRY vendor and model (really product) lengths.
 */
#define VENDOR_LENGTH 8
#define MODEL_LENGTH 16

#define INQUIRY_CMD 0x12
#define INQUIRY_CMDLEN 6

/*
 * INQUIRY VPD page 0x83 identifier descriptor related values. Reference the
 * SCSI Primary Commands specification for details.
 */

/*
 * id type values of id descriptors. These are assumed to fit in 4 bits.
 */
#define SCSI_ID_VENDOR_SPECIFIC 0
#define SCSI_ID_T10_VENDOR      1
#define SCSI_ID_EUI_64          2
#define SCSI_ID_NAA             3
#define SCSI_ID_RELPORT         4
#define SCSI_ID_TGTGROUP        5
#define SCSI_ID_LUNGROUP        6
#define SCSI_ID_MD5             7
#define SCSI_ID_NAME            8

/*
 * Supported NAA values. These fit in 4 bits, so the "don't care" value
 * cannot conflict with real values.
 */
#define SCSI_ID_NAA_DONT_CARE         0xff
#define SCSI_ID_NAA_IEEE_REG          0x05
#define SCSI_ID_NAA_IEEE_REG_EXTENDED 0x06

/*
 * Supported Code Set values.
 */
#define SCSI_ID_BINARY 1
#define SCSI_ID_ASCII  2

struct scsi_id_search_values {
        u_char id_type;
        u_char naa_type;
        u_char code_set;
};

/*
 * Following are the "true" SCSI status codes. Linux has traditionally
 * used a 1 bit right and masked version of these. So now CHECK_CONDITION
 * and friends (in <scsi/scsi.h>) are deprecated.
 */
#define SCSI_CHECK_CONDITION         0x02
#define SCSI_CONDITION_MET           0x04
#define SCSI_BUSY                    0x08
#define SCSI_IMMEDIATE               0x10
#define SCSI_IMMEDIATE_CONDITION_MET 0x14
#define SCSI_RESERVATION_CONFLICT    0x18
#define SCSI_COMMAND_TERMINATED      0x22
#define SCSI_TASK_SET_FULL           0x28
#define SCSI_ACA_ACTIVE              0x30
#define SCSI_TASK_ABORTED            0x40
