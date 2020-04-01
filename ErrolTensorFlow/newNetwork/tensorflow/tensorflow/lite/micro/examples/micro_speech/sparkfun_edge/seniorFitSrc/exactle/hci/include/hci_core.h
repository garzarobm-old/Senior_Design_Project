/*************************************************************************************************/
/*!
 *  \file   hci_core.h
 *
 *  \brief  HCI core interfaces.
 *
 *          $Date: 2017-03-10 14:08:37 -0600 (Fri, 10 Mar 2017) $
 *          $Revision: 11501 $
 *
 *  Copyright (c) 2009-2017 ARM Ltd., all rights reserved.
 *  ARM Ltd. confidential and proprietary.
 *
 *  IMPORTANT.  Your use of this file is governed by a Software License Agreement
 *  ("Agreement") that must be accepted in order to download or otherwise receive a
 *  copy of this file.  You may not use or copy this file for any purpose other than
 *  as described in the Agreement.  If you do not agree to all of the terms of the
 *  Agreement do not use this file and delete all copies in your possession or control;
 *  if you do not have a copy of the Agreement, you must contact ARM Ltd. prior
 *  to any use, copying or further distribution of this software.
 */
/*************************************************************************************************/
#ifndef HCI_CORE_H
#define HCI_CORE_H

#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/hci/include/hci_core_ps.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/wsf_queue.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/wsf_os.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/hci/include/hci_api.h"
#include "tensorflow/lite/micro/examples/micro_speech/sparkfun_edge/seniorFitSrc/exactle/include/cfg_stack.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************************************
  Callback Function Types
**************************************************************************************************/

typedef void(*hciResetSeq_t)(uint8_t *pMsg, uint16_t opcode);

/**************************************************************************************************
  Data Types
**************************************************************************************************/

/* Per-connection structure for ACL packet accounting */
typedef struct
{
  uint8_t         *pTxAclPkt;                   /* Fragmenting TX ACL packet pointer */
  uint8_t         *pNextTxFrag;                 /* Next TX ACL packet fragment */
  uint8_t         *pRxAclPkt;                   /* RX ACL packet pointer */
  uint8_t         *pNextRxFrag;                 /* Next RX ACL packet fragment */
  uint16_t        handle;                       /* Connection handle */
  uint16_t        txAclRemLen;                  /* Fragmenting TX ACL packet remaining length */
  uint16_t        rxAclRemLen;                  /* Fragmented RX ACL packet remaining length */
  bool_t          fragmenting;                  /* TRUE if fragmenting a TX ACL packet */
  bool_t          flowDisabled;                 /* TRUE if data flow disabled */
  uint8_t         queuedBufs;                   /* Queued ACL buffers on this connection */
  uint8_t         outBufs;                      /* Outstanding ACL buffers sent to controller */
} hciCoreConn_t;

/* Main control block for dual-chip implementation */
typedef struct
{
  hciCoreConn_t   conn[DM_CONN_MAX];            /* Connection structures */
  uint8_t         leStates[HCI_LE_STATES_LEN];  /* Controller LE supported states */
  bdAddr_t        bdAddr;                       /* Bluetooth device address */
  wsfQueue_t      aclQueue;                     /* HCI ACL TX queue */
  hciCoreConn_t   *pConnRx;                     /* Connection struct for current transport RX packet */
  uint16_t        maxRxAclLen;                  /* Maximum reassembled RX ACL packet length */
  uint16_t        bufSize;                      /* Controller ACL data buffer size */
  uint8_t         aclQueueHi;                   /* Disable flow when this many ACL buffers queued */
  uint8_t         aclQueueLo;                   /* Enable flow when this many ACL buffers queued */
  uint8_t         availBufs;                    /* Current avail ACL data buffers */
  uint8_t         numBufs;                      /* Controller number of ACL data buffers */
  uint8_t         whiteListSize;                /* Controller white list size */
  uint8_t         numCmdPkts;                   /* Controller command packed count */
  uint16_t        leSupFeat;                    /* Controller LE supported features */
  int8_t          advTxPwr;                     /* Controller advertising TX power */
  uint8_t         resListSize;                  /* Controller resolving list size */
  uint16_t        maxAdvDataLen;                /* Controller maximum advertisement (or scan response) data length */
  uint8_t         numSupAdvSets;                /* Controller maximum number of advertising sets */
  uint8_t         perAdvListSize;               /* Controller periodic advertising list size */
  hciResetSeq_t   extResetSeq;                  /* HCI extended reset sequence callback */
} hciCoreCb_t;

/**************************************************************************************************
  Global Variables
**************************************************************************************************/

/* Control block */
extern hciCoreCb_t hciCoreCb;

/* Event mask */
extern const uint8_t hciEventMask[HCI_EVT_MASK_LEN];

/* LE event mask */
extern const uint8_t hciLeEventMask[HCI_LE_EVT_MASK_LEN];

/* Event mask page 2 */
extern const uint8_t hciEventMaskPage2[HCI_EVT_MASK_LEN];

/* LE supported features configuration mask */
extern uint16_t hciLeSupFeatCfg;

/**************************************************************************************************
  Function Declarations
**************************************************************************************************/

void hciCoreInit(void);
void hciCoreResetStart(void);
void hciCoreConnOpen(uint16_t handle);
void hciCoreConnClose(uint16_t handle);
hciCoreConn_t *hciCoreConnByHandle(uint16_t handle);
void hciCoreSendAclData(hciCoreConn_t *pConn, uint8_t *pData);
void hciCoreTxReady(uint8_t bufs);
void hciCoreTxAclStart(hciCoreConn_t *pConn, uint16_t len, uint8_t *pData);
bool_t hciCoreTxAclContinue(hciCoreConn_t *pConn);
void hciCoreTxAclComplete(hciCoreConn_t *pConn, uint8_t *pData);
uint8_t *hciCoreAclReassembly(uint8_t *pData);
bool_t hciCoreTxAclDataFragmented(hciCoreConn_t *pConn);

#ifdef __cplusplus
};
#endif

#endif /* HCI_CORE_H */