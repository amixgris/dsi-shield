#include "fb.h"

static const uint8_t _gw[] = { 4,4,5,8,8,12,10,3,5,5,7,9,3,9,3,4,8,8,8,8,8,8,8,8,8,8,3,4,8,9,8,8,13,11,9,10,10,9,9,11,10,5,8,10,8,13,10,11,9,11,9,9,9,10,11,15,10,9,9,4,4,4,7,8,3,8,8,8,8,8,4,8,8,3,4,7,3,11,8,8,8,8,5,8,4,8,8,9,7,7,7,5,3,5,8};
static const uint16_t _go[] = { 0,17,34,51,68,85,119,153,170,187,204,221,255,272,306,323,340,357,374,391,408,425,442,459,476,493,510,527,544,561,595,612,629,663,697,731,765,799,833,867,901,935,952,969,1003,1020,1054,1088,1122,1156,1190,1224,1258,1292,1326,1360,1394,1428,1462,1496,1513,1530,1547,1564,1581,1598,1615,1632,1649,1666,1683,1700,1717,1734,1751,1768,1785,1802,1836,1853,1870,1887,1904,1921,1938,1955,1972,1989,2023,2040,2057,2074,2091,2108,2125};
static const uint8_t _gd[] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x20,0x20,0x00,0x00,0x00,
0x00,0x00,0x00,0x50,0x50,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x14,0x14,0x14,0x7e,0x28,0x28,0xfc,0x50,0x50,0x50,0x00,0x00,0x00,
0x00,0x00,0x10,0x10,0x7c,0x92,0x92,0x50,0x38,0x14,0x12,0x92,0x92,0x7c,0x10,0x10,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x80,0x89,0x00,0x89,0x00,0x72,0x00,0x02,0x00,0x04,0x00,0x09,0xc0,0x12,0x20,0x12,0x20,0x21,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x24,0x00,0x24,0x00,0x18,0x00,0x10,0x00,0x29,0x00,0x45,0x00,0x42,0x00,0x45,0x00,0x38,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x60,0x20,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x10,0x20,0x20,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x20,0x20,0x10,
0x00,0x00,0x00,0x40,0x20,0x20,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x20,0x20,0x40,
0x00,0x00,0x00,0x10,0x54,0x38,0x54,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x7f,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x80,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x00,0x00,0x00,
0x00,0x00,0x00,0x10,0x10,0x20,0x20,0x20,0x40,0x40,0x40,0x80,0x80,0x80,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x3c,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0x3c,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x08,0x38,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x3c,0x42,0x42,0x04,0x08,0x10,0x20,0x40,0x40,0x7e,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x3c,0x42,0x42,0x02,0x1c,0x02,0x02,0x42,0x42,0x3c,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x06,0x0a,0x12,0x12,0x22,0x42,0x7f,0x02,0x02,0x02,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x7e,0x40,0x40,0x40,0x7c,0x02,0x02,0x42,0x42,0x3c,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x3c,0x42,0x40,0x40,0x5c,0x62,0x42,0x42,0x42,0x3c,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x7e,0x02,0x04,0x04,0x08,0x08,0x10,0x10,0x20,0x20,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x3c,0x42,0x42,0x42,0x3c,0x42,0x42,0x42,0x42,0x3c,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x3c,0x42,0x42,0x42,0x42,0x3e,0x02,0x42,0x42,0x3c,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x80,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x18,0x60,0x18,0x06,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7e,0x00,0x00,0x00,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x18,0x06,0x18,0x60,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0x66,0x42,0x42,0x02,0x04,0x08,0x10,0x00,0x10,0x10,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x80,0x18,0x60,0x20,0x10,0x23,0x50,0x44,0x90,0x48,0x90,0x48,0x90,0x49,0xa0,0x46,0xc0,0x20,0x00,0x30,0x40,0x0f,0x80,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x04,0x00,0x0a,0x00,0x0a,0x00,0x11,0x00,0x11,0x00,0x20,0x80,0x3f,0x80,0x20,0x80,0x40,0x40,0x40,0x40,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x7e,0x00,0x43,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0x7e,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0x7e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,0x31,0x80,0x20,0x80,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x20,0x80,0x31,0x80,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0x00,0x43,0x00,0x41,0x00,0x40,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x41,0x00,0x43,0x00,0x7c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x7e,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x7e,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0x00,0x30,0xc0,0x20,0x40,0x40,0x00,0x40,0x00,0x43,0xc0,0x40,0x40,0x40,0x40,0x20,0x40,0x31,0xc0,0x0e,0x40,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x7f,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00,0x00,0x00,
0x00,0x00,0x00,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x42,0x42,0x3c,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x00,0x42,0x00,0x44,0x00,0x48,0x00,0x50,0x00,0x70,0x00,0x48,0x00,0x44,0x00,0x42,0x00,0x41,0x00,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x7e,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x10,0x40,0x10,0x60,0x30,0x50,0x50,0x50,0x50,0x48,0x90,0x48,0x90,0x45,0x10,0x45,0x10,0x42,0x10,0x42,0x10,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x80,0x60,0x80,0x50,0x80,0x48,0x80,0x48,0x80,0x44,0x80,0x44,0x80,0x42,0x80,0x42,0x80,0x41,0x80,0x41,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,0x31,0x80,0x20,0x80,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x20,0x80,0x31,0x80,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x7e,0x00,0x43,0x00,0x41,0x00,0x41,0x00,0x43,0x00,0x7e,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,0x31,0x80,0x20,0x80,0x40,0x40,0x40,0x40,0x40,0x40,0x44,0x40,0x42,0x40,0x21,0x80,0x31,0x80,0x0e,0x40,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x7e,0x00,0x43,0x00,0x41,0x00,0x41,0x00,0x42,0x00,0x7c,0x00,0x42,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0x41,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x1c,0x00,0x63,0x00,0x41,0x00,0x40,0x00,0x30,0x00,0x0c,0x00,0x03,0x00,0x01,0x00,0x41,0x00,0x63,0x00,0x1c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x80,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x40,0x80,0x21,0x00,0x1e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x20,0x80,0x20,0x80,0x11,0x00,0x11,0x00,0x11,0x00,0x0a,0x00,0x0a,0x00,0x04,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x04,0x41,0x04,0x42,0x84,0x22,0x88,0x22,0x88,0x22,0x88,0x14,0x50,0x14,0x50,0x14,0x50,0x08,0x20,0x08,0x20,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x40,0x80,0x21,0x00,0x12,0x00,0x0c,0x00,0x0c,0x00,0x12,0x00,0x21,0x00,0x21,0x00,0x40,0x80,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x41,0x00,0x41,0x00,0x22,0x00,0x22,0x00,0x14,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x00,0x01,0x00,0x02,0x00,0x04,0x00,0x0c,0x00,0x08,0x00,0x10,0x00,0x30,0x00,0x20,0x00,0x40,0x00,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x70,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x70,
0x00,0x00,0x00,0x80,0x80,0x40,0x40,0x40,0x20,0x20,0x20,0x10,0x10,0x10,0x00,0x00,0x00,
0x00,0x00,0x00,0xe0,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xe0,
0x00,0x00,0x00,0x00,0x10,0x28,0x44,0x82,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,
0x00,0x00,0x00,0x40,0x80,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x66,0x02,0x3e,0x62,0x42,0x66,0x3b,0x00,0x00,0x00,
0x00,0x00,0x00,0x40,0x40,0x40,0x5c,0x66,0x42,0x42,0x42,0x42,0x66,0x5c,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x66,0x40,0x40,0x40,0x42,0x66,0x3c,0x00,0x00,0x00,
0x00,0x00,0x00,0x02,0x02,0x02,0x3a,0x66,0x42,0x42,0x42,0x42,0x66,0x3a,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x66,0x42,0x7e,0x40,0x40,0x66,0x3c,0x00,0x00,0x00,
0x00,0x00,0x00,0x30,0x40,0x40,0xe0,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x3a,0x66,0x42,0x42,0x42,0x42,0x66,0x3a,0x02,0x66,0x3c,
0x00,0x00,0x00,0x40,0x40,0x40,0x5c,0x66,0x42,0x42,0x42,0x42,0x42,0x42,0x00,0x00,0x00,
0x00,0x00,0x00,0x40,0x40,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,
0x00,0x00,0x00,0x20,0x20,0x00,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0xc0,
0x00,0x00,0x00,0x40,0x40,0x40,0x44,0x48,0x50,0x60,0x50,0x48,0x44,0x42,0x00,0x00,0x00,
0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x59,0x80,0x66,0x40,0x44,0x40,0x44,0x40,0x44,0x40,0x44,0x40,0x44,0x40,0x44,0x40,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x5c,0x66,0x42,0x42,0x42,0x42,0x42,0x42,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x66,0x42,0x42,0x42,0x42,0x66,0x3c,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x5c,0x66,0x42,0x42,0x42,0x42,0x66,0x5c,0x40,0x40,0x40,
0x00,0x00,0x00,0x00,0x00,0x00,0x3a,0x66,0x42,0x42,0x42,0x42,0x66,0x3a,0x02,0x02,0x02,
0x00,0x00,0x00,0x00,0x00,0x00,0x58,0x60,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x3c,0x42,0x40,0x3c,0x06,0x02,0x42,0x3c,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x40,0x40,0xf0,0x40,0x40,0x40,0x40,0x40,0x40,0x30,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x42,0x42,0x42,0x42,0x42,0x42,0x66,0x3a,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x42,0x42,0x42,0x24,0x24,0x24,0x18,0x18,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0x80,0x88,0x80,0x88,0x80,0x49,0x00,0x49,0x00,0x55,0x00,0x22,0x00,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0xc6,0x44,0x28,0x10,0x10,0x28,0x44,0xc6,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x82,0x82,0x44,0x44,0x24,0x28,0x18,0x10,0x10,0x30,0x60,
0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x04,0x08,0x10,0x20,0x40,0x80,0xfc,0x00,0x00,0x00,
0x00,0x00,0x00,0x18,0x20,0x20,0x20,0x20,0x40,0x80,0x40,0x20,0x20,0x20,0x20,0x20,0x18,
0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x40,
0x00,0x00,0x00,0xc0,0x20,0x20,0x20,0x20,0x10,0x08,0x10,0x20,0x20,0x20,0x20,0x20,0xc0,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x32,0x5a,0x4c,0x00,0x00,0x00,0x00,0x00,0x00
};
const struct fb_font font_helv17 = {
32, 126, 17, _gw, _go, _gd };