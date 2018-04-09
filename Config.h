
#define TimeOut 9999


//----------------------------------------------------------Configuration UART--------------------------------------------------------------
#define Use_Port        Port_USB
#define Baudrate        57600
//----------------------------------------------------------Configuration for AS3993--------------------------------------------------------------

//------------LinkFrequency-------------------------
#define LinkFrequency_40kHz     0x00
#define LinkFrequency_160kHz    0x60
#define LinkFrequency_256kHz    0x90
#define LinkFrequency_320kHz    0xC0
#define LinkFrequency_640kHz    0xF0

#define UseLinkFrequency  LinkFrequency_40kHz

#if (UseLinkFrequency==LinkFrequency_640kHz)
#define useDR 1 // DR:= 64/3
#else
#define useDR 0 // DR:= 8
#endif
  
  
//------------Encode Mode---------------------------
#define FM_0            0x00
#define Miller_2        0x01
#define Miller_4        0x02
#define Miller_8        0x03

#define UseCodeMode     Miller_2

  
//------------Decode Mode---------------------------
#define V1      1
#define V2      2
#define Use_test_Miller V1




//------------Miller Preamble (TRext)----------------
#define TRext_0         0x00    // Only supported for Miller_4 and Miller_8     ( Maybe Miller_2 )
#define TRext_1         0x01
#define ShortPreamble   TRext_0 // Only supported for Miller_4 and Miller_8     ( Maybe Miller_2 )
#define LongPreamble    TRext_1

#define UsePreambleMode LongPreamble



//----------------------------------------------------------Configuration for ST-Chips and CLS---------------------------------------------------

#define Chip1_on        0x01
#define Chip1_off       0x02
#define Chip2_on        0x04
#define Chip2_off       0x08
#define Chip3_on        0x10
#define Chip3_off       0x20
#define CLS_on          0x40
#define CLS_off         0x00


#define Reader          0x00
#define Sender          0x01
#define CW              0x02
#define OOK             0x04
#define ASK             0x08
#define FSK             0x10
#define PN9             0x20 // Rx:GPIO
#define FIF0            0x40
#define Normal          0x80

#define CLS_1           0x01// Mismatch: 2 Caps
#define CLS_2           0x02// Mismatch: 2 Caps + 1 Res
#define CLS_3           0x04// PhaseShifter + Attenuator

#define FullSearch      0x00
#define HillClimbing    0x80
#define Hold            0x40
#define Once            0x20
#define Manuell         0x10

#define Stable          300