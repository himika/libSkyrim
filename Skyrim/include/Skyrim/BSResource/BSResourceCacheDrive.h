#pragma once

#include "../BSCore/BSFixedString.h"

/*==================================================================================
* TESV.exe
*==================================================================================
0110CD68  B0 4E A4 00 | 20 45 A4 00 | 20 4E A4 00 | B0 A3 A3 00 | ‹N?  E?  N? ‹??
0110CD78  D0 40 A4 00 | C0 4A A4 00 | 50 4B A4 00 | 10 4C A4 00 | ?@? ?J? PK? L?
0110CD88  70 3D A4 00 | A0 3E A4 00 | 70 40 A4 00 | F0 4D A4 00 | p = ? ?>? p@? ?M?
0110CD98  60 4A A4 00 | 40 25 A4 00 | 30 26 A4 00 | B0 A3 A3 00 | `J? @%? 0 & ? ‹??
0110CDA8  20 26 A4 00 | 40 2E A4 00 | 70 25 A4 00 | A0 25 A4 00 | &? @.? p%? ?%?
0110CDB8  D0 25 A4 00 | 00 26 A4 00 | 90 24 A4 00 | 00 53 A4 00 | ?%?  &? ?$?  S?
0110CDC8  43 61 63 68 | 65 50 61 75 | 73 65 00 00 | 43 61 63 68 | CachePause  Cach
0110CDD8  65 42 6C 6F | 63 6B 00 00 | 42 53 52 65 | 73 6F 75 72 | eBlock  BSResour
0110CDE8  63 65 3A 3A | 43 61 63 68 | 65 44 72 69 | 76 65 20 74 | ce::CacheDrive t
0110CDF8  68 72 65 61 | 64 00 00 00 | 3E 3E 3E 3E | 3E 3E 3E 2D | hread >> >> >> >-
0110CE08  20 4F 6E 43 | 6F 6D 70 6C | 65 74 65 3A | 20 27 25 73 | OnComplete: '%s
0110CE18  27 0D 0A 00 | 3E 3E 3E 3E | 3E 3E 3E 2D | 20 43 6F 70 | '  >>>>>>>- Cop
0110CE28  79 20 65 72 | 72 6F 72 3A | 20 27 25 73 | 27 0D 0A 00 | y error : '%s'
0110CE38  3E 3E 3E 3E | 3E 3E 3E 2D | 20 54 72 75 | 6E 63 61 74 | >> >> >> >-Truncat
0110CE48  69 6F 6E 20 | 6F 66 20 66 | 69 6C 65 20 | 25 73 20 66 | ion of file %s f
0110CE58  61 69 6C 65 | 64 21 20 0D | 0A 00 00 00 | 3E 3E 3E 3E | ailed!>> >>
0110CE68  3E 3E 3E 2D | 20 43 6F 70 | 79 20 65 72 | 72 6F 72 3A | >> >-Copy error :
0110CE78  20 53 74 61 | 72 74 57 72 | 69 74 65 20 | 66 61 69 6C | StartWrite fail
0110CE88  65 64 20 27 | 25 73 27 0D | 0A 00 00 00 | 00 00 00 00 | ed '%s'
0110CE98  3E 3E 3E 3E | 3E 3E 3E 2D | 20 77 61 69 | 74 69 6E 67 | >> >> >> >-waiting
0110CEA8  20 6F 6E 20 | 72 65 61 64 | 20 66 61 69 | 6C 65 64 20 | on read failed
0110CEB8  77 68 69 6C | 65 20 73 74 | 69 6C 6C 20 | 64 61 74 61 | while still data
0110CEC8  20 74 6F 20 | 72 65 61 64 | 3A 20 27 25 | 73 27 0D 0A | to read : '%s'
0110CED8  00 00 00 00 | 3E 3E 3E 3E | 3E 3E 3E 2D | 20 43 6F 70 | >> >> >> >-Cop
0110CEE8  79 20 65 72 | 72 6F 72 3A | 20 53 74 61 | 72 74 52 65 | y error : StartRe
0110CEF8  61 64 20 66 | 61 69 6C 65 | 64 21 20 27 | 25 73 27 0D | ad failed!'%s'
0110CF08  0A 00 00 00 | E0 78 A4 00 | D0 7B A4 00 | C0 79 A4 00 | ?x? ?{ ? ?y?


00A45AF8  PUSH OFFSET 0110CEDC    ASCII ">>>>>>>- Copy error: StartRead failed! '%s'"
00A45B23  PUSH OFFSET 0110CE98    ASCII ">>>>>>>- waiting on read failed while still data to read: '%s'"
00A45BA6  PUSH OFFSET 0110CE64    ASCII ">>>>>>>- Copy error: StartWrite failed '%s'"
00A45BBE  PUSH OFFSET 0110CE1C    ASCII ">>>>>>>- Copy error: '%s'"
00A45C67  PUSH OFFSET 0110CE38    ASCII ">>>>>>>- Truncation of file %s failed!"
00A45C8C  PUSH OFFSET 0110CE00    ASCII ">>>>>>>- OnComplete: '%s'"
00A45E2F  PUSH OFFSET 0110CDE0    ASCII "BSResource::CacheDrive thread"
00A46008  PUSH OFFSET 0110CF44    ASCII ">>>>>>>- AddOp: '%s'"
00A460C6  PUSH OFFSET 0110CF5C    ASCII ">>>>>>>- OnValid: '%s'"
00A462C6  PUSH OFFSET 0110CFBC    ASCII ">>>>>>>- Begin AsyncCopy: '%s'"
00A46423  PUSH OFFSET 0110CF98    ASCII ">>>>>>>- Begin StandardCopy: '%s'"
00A464B8  PUSH OFFSET 0110CF98    ASCII ">>>>>>>- Begin StandardCopy: '%s'"
00A465EC  PUSH OFFSET 0110CF78    ASCII ">>>>>>>- Copy Failed: '%s'"
00A46917  PUSH OFFSET 0110D070    ASCII ">>>>>>>- VALIDATE: InvalidSource: '%s'"
00A46A8F  PUSH OFFSET 0110D034    ASCII ">>>>>>>- VALIDATE: AlreadyCached on partition %d: '%s'"
00A46AFB  PUSH OFFSET 0110D000    ASCII ">>>>>>>- VALIDATE: Removed from partition %d:'%s'"
00A46CFD  PUSH OFFSET 0110D0C4    ASCII ">>>>>>>- VALIDATE: ReadyToCache: '%s'"
00A46D66  PUSH OFFSET 0110D09C    ASCII ">>>>>>>- VALIDATE: NoFreeSpace:  '%s'"
00A472D7  PUSH OFFSET 0110CE1C    ASCII ">>>>>>>- Copy error: '%s'"
00A47333  PUSH OFFSET 0110CE00    ASCII ">>>>>>>- OnComplete: '%s'"
00A4756B  PUSH OFFSET 0110CE00    ASCII ">>>>>>>- OnComplete: '%s'"
00A475B3  PUSH OFFSET 0110CE1C    ASCII ">>>>>>>- Copy error: '%s'"
00A47735  PUSH OFFSET 0110CDC8    ASCII "CachePause"
00A4775C  PUSH OFFSET 0110CDD4    ASCII "CacheBlock"
00A47A64  PUSH OFFSET 0110CDC8    ASCII "CachePause"
00A47A8C  PUSH OFFSET 0110CDD4    ASCII "CacheBlock"
00A48A7B  PUSH OFFSET 0110D114    ASCII "Memory Error"
00A48A80  PUSH OFFSET 0110D0EC    ASCII "Not enough memory to run application."
*/


namespace BSResource
{
}
