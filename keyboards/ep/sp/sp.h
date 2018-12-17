#ifndef SP_H
#define SP_H
#include "quantum.h"

#define xxx KC_NO

/* ---------LEFT HAND---------   ---------RIGHT HAND--------- */
#define LAYOUT(                                                \
  L00,L01,L02,L03,L04,L05,           R01,R02,R03,R04,R05,R06,  \
  L10,L11,L12,L13,L14,L15,           R11,R12,R13,R14,R15,R16,  \
  L20,L21,L22,L23,L24,L25,           R21,R22,R23,R24,R25,R26,  \
  L30,L31,L32,L33,L34,L35,           R31,R32,R33,R34,R35,R36,  \
  L40,L41,L42,L43,L44,L45,           R41,R42,R43,R44,R45,R46,  \
  L50,L51,L52,L53,L54,L55,L56,   R50,R51,R52,R53,R54,R55,R56)  \
  /* Matrix Definitions */                                     \
  { /* Left Hand */                \
    {L00,L01,L02,L03,L04,L05,xxx}, \
    {L10,L11,L12,L13,L14,L05,xxx}, \
    {L20,L21,L22,L23,L24,L05,xxx}, \
    {L30,L31,L32,L33,L34,L35,xxx}, \
    {L40,L41,L42,L43,L44,L45,xxx}, \
    {L50,L51,L52,L53,L54,L55,L56}, \
    /* Right Hand */               \
    {R06,R05,R04,R03,R02,R01,xxx}, \
    {R16,R15,R14,R13,R12,R11,xxx}, \
    {R26,R25,R24,R23,R22,R21,xxx}, \
    {R36,R35,R34,R33,R32,R31,xxx}, \
    {R46,R45,R44,R43,R42,R41,xxx}, \
    {R56,R55,R54,R53,R52,R51,R50}  \
  }

#endif
