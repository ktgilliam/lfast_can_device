#pragma once

#include <cstdint>
#include <FlexCAN_T4.h>

///////////////// CAN FILTER MASKS
#define CAN_SNDR_ID_MASK    0xF00
#define CAN_MSG_ID_MASK     0x0FF

///////////////// SENDER ID MASKS /////////////////
#define CTRL_PC_ID_MASK             0x000
#define PFC_CTRL_ID_MASK            0x100
#define PEDESTAL_CTRL_ID_MASK       0x200
#define TEC_CTRL_ID_MASK            0x400

///////////////// CTRL PC MESSAGE ID's /////////////////
typedef enum
{
 CTRL_MSG_MIN,
 REQUEST_STATS,
 TIMESET_REQ_ACK,
 CMD_RA_POLY_A,
 CMD_RA_POLY_B,
 CMD_RA_POLY_C,
 CMD_DEC_POLY_A,
 CMD_DEC_POLY_B,
 CMD_DEC_POLY_C,
 AZ_POSN_REQ,
 EL_POSN_REQ,
 CTRL_MSG_MAX
} CTRL_PC_MSG_ID;

#define CAN_MAX_ID_MASK     0x7FF //only 11 bits available

///////////////// FILER MACROS /////////////////
#define CTRL_PC_FILT_BEGIN  (CTRL_PC_ID_MASK | CTRL_MSG_MIN)
#define CTRL_PC_FILT_END    (CTRL_PC_ID_MASK | CTRL_MSG_MAX)

///////////////// TYPES /////////////////
typedef void (*MsgHandler)(char *, int);

typedef enum
{
  CAN_TEST_MODE_TALKER,
  CAN_TEST_MODE_LISTENER
} CanTestMode;


///////////////// FUNCTIONS /////////////////
void initCanComms();

void registerCanMessageHandler(uint16_t canId, MsgHandler fn);
void initCanInterfaces();

// bool updateCanBusEvents(CAN_message_t &msg);
void canSendMessage(uint32_t id, char *mBuff, uint8_t len);
void sendMessageOnBus(CAN_message_t &msg, uint8_t busNo);
bool updateCanBusEvents(CAN_message_t &msg);



void registerCanRxCallback(_MB_ptr callbackFn);

void sendTestFrame();
void setCanTestMode(CanTestMode mode);

void updateCanBusEvents();