/*************************************************************************************************/
/*!
 *  \file   plxps_db.c
 *
 *  \brief  Pulse Oximeter profile example record database and access functions.
 *
 *          $Date: 2016-04-19 13:50:01 -0700 (Tue, 19 Apr 2016) $
 *          $Revision: 6868 $
 *
 *  Copyright (c) 2012-2017 ARM Ltd., all rights reserved.
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

#include "wsf_types.h"
#include "wsf_assert.h"
#include "wsf_trace.h"
#include "bstream.h"
#include "att_api.h"
#include "svc_ch.h"
#include "svc_gls.h"
#include "app_api.h"
#include "plxps_api.h"
#include "plxps_main.h"

/**************************************************************************************************
  Macros
**************************************************************************************************/

/*! Number of records in example database */
#define PLXPS_DB_NUM_RECORDS     3

/**************************************************************************************************
  Local Variables
**************************************************************************************************/

/*! Control block */
static struct
{
  uint8_t     numRec;
} plxpsDbCb;

/*! Example record database */
static const plxpsRec_t plxpsDb[PLXPS_DB_NUM_RECORDS] =
{
  /* record 1 */
  {
    /* spotCheck */
    {
      0,                                                        /* Flags */
      SFLT_TO_UINT16(96, 1),                                    /* Pulse Oximeter Spo2 (SFLOAT) */
      SFLT_TO_UINT16(60, 1),                                    /* Pulse Oximeter Pulse (SFLOAT) */
      {2012, 6, 15, 20, 52, 36},                                /* timestamp */
      0,                                                        /* Measurement status */
      0,                                                        /* Sensor status */
      SFLT_TO_UINT16(96, 1),                                    /* Pulse Amplitude Index */
    }
  },
  
  /* record 2 */
  {
    /* spotCheck */
    {
      0,                                                        /* Flags */
      SFLT_TO_UINT16(96, 1),                                    /* Pulse Oximeter Spo2 (SFLOAT) */
      SFLT_TO_UINT16(60, 1),                                    /* Pulse Oximeter Pulse (SFLOAT) */
      {2012, 6, 15, 20, 52, 36},                                /* timestamp */
      0,                                                        /* Measurement status */
      0,                                                        /* Sensor status */
      SFLT_TO_UINT16(96, 1),                                    /* Pulse Amplitude Index */
    }
  },  
  /* record 3 */
  {
    /* spotCheck */
    {
      0,                                                        /* Flags */
      SFLT_TO_UINT16(96, 1),                                    /* Pulse Oximeter Spo2 (SFLOAT) */
      SFLT_TO_UINT16(60, 1),                                    /* Pulse Oximeter Pulse (SFLOAT) */
      {2012, 6, 15, 20, 52, 36},                                /* timestamp */
      0,                                                        /* Measurement status */
      0,                                                        /* Sensor status */
      SFLT_TO_UINT16(96, 1),                                    /* Pulse Amplitude Index */
    }
  }
};

/*************************************************************************************************/
/*!
 *  \fn     plxpsDbGetNext
 *        
 *  \brief  Get the next database record after the given current record.
 *
 *  \param  pCurrRec    Pointer to current record.
 *
 *  \return Pointer to record or NULL if no record.
 */
/*************************************************************************************************/
static const plxpsRec_t *plxpsDbGetEnd()
{
  return plxpsDb + plxpsDbCb.numRec;
}

/*************************************************************************************************/
/*!
 *  \fn     plxpsDbGetNext
 *        
 *  \brief  Get the next database record after the given current record.
 *
 *  \param  pCurrRec    Pointer to current record.
 *
 *  \return Pointer to record or NULL if no record.
 */
/*************************************************************************************************/
static plxpsRec_t *plxpsDbGetNext(plxpsRec_t *pCurrRec)
{
  if (plxpsDbCb.numRec == 0 || pCurrRec == plxpsDbGetEnd())
  {
    plxpsDbCb.numRec = 0;
    return NULL;
  }
  else if (pCurrRec == NULL)
  {
    return (plxpsRec_t *) plxpsDb;
  }
  else
  {
    return (pCurrRec + 1);
  }
}

/*************************************************************************************************/
/*!
 *  \fn     plxpsDbOpAll
 *        
 *  \brief  Get the next record filtered for "all".
 *
 *  \param  pCurrRec    Pointer to current record.
 *  \param  pRec        Return pointer to next record, if found.
 *
 *  \return CH_RACP_RSP_SUCCESS if a record is found, otherwise an error status is returned.
 */
/*************************************************************************************************/
static uint8_t plxpsDbOpAll(plxpsRec_t *pCurrRec,  plxpsRec_t **pRec)
{
  *pRec = plxpsDbGetNext(pCurrRec);
  return (*pRec != NULL) ? CH_RACP_RSP_SUCCESS : CH_RACP_RSP_NO_RECORDS;
}

/*************************************************************************************************/
/*!
 *  \fn     plxpsDbInit
 *        
 *  \brief  Initialize the pulse oximeter record database.
 *
 *  \return None.
 */
/*************************************************************************************************/
void plxpsDbInit(void)
{
  plxpsDbCb.numRec = PLXPS_DB_NUM_RECORDS;
}

/*************************************************************************************************/
/*!
 *  \fn     plxpsDbGetNextRecord
 *        
 *  \brief  Get the next record that matches the given filter parameters that follows
 *          the given current record.
 *
 *  \param  oper        Operator. 
 *  \param  pCurrRec    Pointer to current record.
 *  \param  pRec        Return pointer to next record, if found.
 *
 *  \return CH_RACP_RSP_SUCCESS if a record is found, otherwise an error status is returned.
 */
/*************************************************************************************************/
uint8_t plxpsDbGetNextRecord(uint8_t oper, plxpsRec_t *pCurrRec,  plxpsRec_t **pRec)
{
  uint8_t status;

  if (oper == CH_RACP_OPERATOR_ALL)
  {
    status = plxpsDbOpAll(pCurrRec, pRec);
  }
  else
  {
    status = CH_RACP_RSP_INV_OPERATOR;
  }
  
  return status;
}

/*************************************************************************************************/
/*!
 *  \fn     plxpsDbDeleteRecords
 *        
 *  \brief  Delete records that match the given filter parameters.
 *
 *  \param  oper        Operator. 
 *
 *  \return CH_RACP_RSP_SUCCESS if records deleted, otherwise an error status is returned.
 */
/*************************************************************************************************/
uint8_t plxpsDbDeleteRecords(uint8_t oper)
{
  /* only 'all records' is supported */
  if (oper == CH_RACP_OPERATOR_ALL)
  {
    plxpsDbCb.numRec = 0;
    
    return CH_RACP_RSP_SUCCESS;
  }
  else
  {
    return CH_RACP_RSP_INV_OPERATOR;
  }
}

/*************************************************************************************************/
/*!
 *  \fn     plxpsDbGetNumRecords
 *        
 *  \brief  Get the number of records matching the filter parameters.
 *
 *  \param  oper        Operator. 
 *  \param  pNumRec     Returns number of records which match filter parameters.

 *
 *  \return RACP status.
 */
/*************************************************************************************************/
uint8_t plxpsDbGetNumRecords(uint8_t oper, uint8_t *pNumRec)
{
  plxpsRec_t *pCurrRec = NULL;
  uint8_t   status;
   
  *pNumRec = 0;
  while ((status = plxpsDbGetNextRecord(oper, pCurrRec, &pCurrRec)) == CH_RACP_RSP_SUCCESS)
  {
    (*pNumRec)++;
  }
  
  if (status == CH_RACP_RSP_NO_RECORDS)
  {
    status = CH_RACP_RSP_SUCCESS;
  }
  
  return status;
}

/*************************************************************************************************/
/*!
*  \fn     plxpsDbGenerateRecord
*
*  \brief  Generate a new record.
*
*  \return None.
*/
/*************************************************************************************************/
void plxpsDbGenerateRecord(void)
{
  if (plxpsDbCb.numRec < PLXPS_DB_NUM_RECORDS)
  {
    plxpsDbCb.numRec++;
  }
}
