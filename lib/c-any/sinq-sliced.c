//HEADER
/*
  sinq-sliced.c - fixed point sine tables. 
  Copyright 2013 Marc Prager
 
  This file is part of the c-any library.
  c-any is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
 
  c-any is published in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
  of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License along with c-any.
  If not see <http://www.gnu.org/licenses/>
 */

#include <sinq.h>

//SLICE
// Created by program 'exxTable sin 8 8 short'
// Manually modified.
#include <integers.h>
static const Uint8 sinq8To7Short[65] = {
	0x00,0x03,0x06,0x09,0x0D,0x10,0x13,0x16,0x19,0x1C,0x1F,0x22,0x25,0x28,0x2B,0x2E,
	0x31,0x34,0x37,0x3A,0x3C,0x3F,0x42,0x44,0x47,0x4A,0x4C,0x4F,0x51,0x54,0x56,0x58,
	0x5B,0x5D,0x5F,0x61,0x63,0x65,0x67,0x69,0x6A,0x6C,0x6E,0x6F,0x71,0x72,0x74,0x75,
	0x76,0x77,0x79,0x7A,0x7A,0x7B,0x7C,0x7D,0x7E,0x7E,0x7F,0x7F,0x7F,0x80,0x80,0x80,
	0x80,
};

Int32 sinq8To7(Int32 phi) {
	return (phi & 128 ? -1 : 1) * sinq8To7Short[ (phi & 64 ? 64 - (phi & 63) : phi & 63) ];
}

//SLICE
// Created by program 'exxTable sin 10 16 short'
// Manually modified.
#include <integers.h>
static const Uint16 sinq10To15Short[257] = {
	0x0000,0x00C9,0x0192,0x025B,0x0324,0x03ED,0x04B6,0x057F,0x0648,0x0711,0x07D9,0x08A2,0x096B,0x0A33,0x0AFB,0x0BC4,
	0x0C8C,0x0D54,0x0E1C,0x0EE4,0x0FAB,0x1073,0x113A,0x1201,0x12C8,0x138F,0x1455,0x151C,0x15E2,0x16A8,0x176E,0x1833,
	0x18F9,0x19BE,0x1A83,0x1B47,0x1C0C,0x1CD0,0x1D93,0x1E57,0x1F1A,0x1FDD,0x209F,0x2162,0x2224,0x22E5,0x23A7,0x2467,
	0x2528,0x25E8,0x26A8,0x2768,0x2827,0x28E5,0x29A4,0x2A62,0x2B1F,0x2BDC,0x2C99,0x2D55,0x2E11,0x2ECC,0x2F87,0x3042,
	0x30FC,0x31B5,0x326E,0x3327,0x33DF,0x3497,0x354E,0x3604,0x36BA,0x3770,0x3825,0x38D9,0x398D,0x3A40,0x3AF3,0x3BA5,
	0x3C57,0x3D08,0x3DB8,0x3E68,0x3F17,0x3FC6,0x4074,0x4121,0x41CE,0x427A,0x4326,0x43D1,0x447B,0x4524,0x45CD,0x4675,
	0x471D,0x47C4,0x486A,0x490F,0x49B4,0x4A58,0x4AFB,0x4B9E,0x4C40,0x4CE1,0x4D81,0x4E21,0x4EC0,0x4F5E,0x4FFB,0x5098,
	0x5134,0x51CF,0x5269,0x5303,0x539B,0x5433,0x54CA,0x5560,0x55F6,0x568A,0x571E,0x57B1,0x5843,0x58D4,0x5964,0x59F4,
	0x5A82,0x5B10,0x5B9D,0x5C29,0x5CB4,0x5D3E,0x5DC8,0x5E50,0x5ED7,0x5F5E,0x5FE4,0x6068,0x60EC,0x616F,0x61F1,0x6272,
	0x62F2,0x6371,0x63EF,0x646C,0x64E9,0x6564,0x65DE,0x6657,0x66D0,0x6747,0x67BD,0x6832,0x68A7,0x691A,0x698C,0x69FD,
	0x6A6E,0x6ADD,0x6B4B,0x6BB8,0x6C24,0x6C8F,0x6CF9,0x6D62,0x6DCA,0x6E31,0x6E97,0x6EFB,0x6F5F,0x6FC2,0x7023,0x7083,
	0x70E3,0x7141,0x719E,0x71FA,0x7255,0x72AF,0x7308,0x735F,0x73B6,0x740B,0x7460,0x74B3,0x7505,0x7556,0x75A6,0x75F4,
	0x7642,0x768E,0x76D9,0x7723,0x776C,0x77B4,0x77FB,0x7840,0x7885,0x78C8,0x790A,0x794A,0x798A,0x79C9,0x7A06,0x7A42,
	0x7A7D,0x7AB7,0x7AEF,0x7B27,0x7B5D,0x7B92,0x7BC6,0x7BF9,0x7C2A,0x7C5A,0x7C89,0x7CB7,0x7CE4,0x7D0F,0x7D3A,0x7D63,
	0x7D8A,0x7DB1,0x7DD6,0x7DFB,0x7E1E,0x7E3F,0x7E60,0x7E7F,0x7E9D,0x7EBA,0x7ED6,0x7EF0,0x7F0A,0x7F22,0x7F38,0x7F4E,
	0x7F62,0x7F75,0x7F87,0x7F98,0x7FA7,0x7FB5,0x7FC2,0x7FCE,0x7FD9,0x7FE2,0x7FEA,0x7FF1,0x7FF6,0x7FFA,0x7FFE,0x7FFF,
	0x8000,
};

Int32 sinq10To15(Int32 phi) {
	return (phi & 512 ? -1 : 1) * sinq10To15Short[ (phi & 256 ? 256 - (phi & 255) : phi & 255) ];
}

//SLICE
// Created by program 'exxTable sin 12 16 short'
// Manually modified.
#include <integers.h>
static const Uint16 sinq12To15Short[1025] = {
	0x0000,0x0032,0x0065,0x0097,0x00C9,0x00FB,0x012E,0x0160,0x0192,0x01C4,0x01F7,0x0229,0x025B,0x028D,0x02C0,0x02F2,
	0x0324,0x0356,0x0389,0x03BB,0x03ED,0x041F,0x0452,0x0484,0x04B6,0x04E8,0x051B,0x054D,0x057F,0x05B1,0x05E3,0x0616,
	0x0648,0x067A,0x06AC,0x06DE,0x0711,0x0743,0x0775,0x07A7,0x07D9,0x080C,0x083E,0x0870,0x08A2,0x08D4,0x0906,0x0938,
	0x096B,0x099D,0x09CF,0x0A01,0x0A33,0x0A65,0x0A97,0x0AC9,0x0AFB,0x0B2D,0x0B60,0x0B92,0x0BC4,0x0BF6,0x0C28,0x0C5A,
	0x0C8C,0x0CBE,0x0CF0,0x0D22,0x0D54,0x0D86,0x0DB8,0x0DEA,0x0E1C,0x0E4E,0x0E80,0x0EB2,0x0EE4,0x0F15,0x0F47,0x0F79,
	0x0FAB,0x0FDD,0x100F,0x1041,0x1073,0x10A4,0x10D6,0x1108,0x113A,0x116C,0x119E,0x11CF,0x1201,0x1233,0x1265,0x1296,
	0x12C8,0x12FA,0x132B,0x135D,0x138F,0x13C1,0x13F2,0x1424,0x1455,0x1487,0x14B9,0x14EA,0x151C,0x154D,0x157F,0x15B1,
	0x15E2,0x1614,0x1645,0x1677,0x16A8,0x16DA,0x170B,0x173C,0x176E,0x179F,0x17D1,0x1802,0x1833,0x1865,0x1896,0x18C7,
	0x18F9,0x192A,0x195B,0x198D,0x19BE,0x19EF,0x1A20,0x1A51,0x1A83,0x1AB4,0x1AE5,0x1B16,0x1B47,0x1B78,0x1BA9,0x1BDA,
	0x1C0C,0x1C3D,0x1C6E,0x1C9F,0x1CD0,0x1D01,0x1D31,0x1D62,0x1D93,0x1DC4,0x1DF5,0x1E26,0x1E57,0x1E88,0x1EB8,0x1EE9,
	0x1F1A,0x1F4B,0x1F7B,0x1FAC,0x1FDD,0x200E,0x203E,0x206F,0x209F,0x20D0,0x2101,0x2131,0x2162,0x2192,0x21C3,0x21F3,
	0x2224,0x2254,0x2284,0x22B5,0x22E5,0x2316,0x2346,0x2376,0x23A7,0x23D7,0x2407,0x2437,0x2467,0x2498,0x24C8,0x24F8,
	0x2528,0x2558,0x2588,0x25B8,0x25E8,0x2618,0x2648,0x2678,0x26A8,0x26D8,0x2708,0x2738,0x2768,0x2797,0x27C7,0x27F7,
	0x2827,0x2856,0x2886,0x28B6,0x28E5,0x2915,0x2945,0x2974,0x29A4,0x29D3,0x2A03,0x2A32,0x2A62,0x2A91,0x2AC1,0x2AF0,
	0x2B1F,0x2B4F,0x2B7E,0x2BAD,0x2BDC,0x2C0C,0x2C3B,0x2C6A,0x2C99,0x2CC8,0x2CF7,0x2D26,0x2D55,0x2D84,0x2DB3,0x2DE2,
	0x2E11,0x2E40,0x2E6F,0x2E9E,0x2ECC,0x2EFB,0x2F2A,0x2F59,0x2F87,0x2FB6,0x2FE5,0x3013,0x3042,0x3070,0x309F,0x30CD,
	0x30FC,0x312A,0x3159,0x3187,0x31B5,0x31E4,0x3212,0x3240,0x326E,0x329D,0x32CB,0x32F9,0x3327,0x3355,0x3383,0x33B1,
	0x33DF,0x340D,0x343B,0x3469,0x3497,0x34C4,0x34F2,0x3520,0x354E,0x357B,0x35A9,0x35D7,0x3604,0x3632,0x365F,0x368D,
	0x36BA,0x36E8,0x3715,0x3742,0x3770,0x379D,0x37CA,0x37F7,0x3825,0x3852,0x387F,0x38AC,0x38D9,0x3906,0x3933,0x3960,
	0x398D,0x39BA,0x39E7,0x3A13,0x3A40,0x3A6D,0x3A9A,0x3AC6,0x3AF3,0x3B20,0x3B4C,0x3B79,0x3BA5,0x3BD2,0x3BFE,0x3C2A,
	0x3C57,0x3C83,0x3CAF,0x3CDC,0x3D08,0x3D34,0x3D60,0x3D8C,0x3DB8,0x3DE4,0x3E10,0x3E3C,0x3E68,0x3E94,0x3EC0,0x3EEC,
	0x3F17,0x3F43,0x3F6F,0x3F9A,0x3FC6,0x3FF1,0x401D,0x4048,0x4074,0x409F,0x40CB,0x40F6,0x4121,0x414D,0x4178,0x41A3,
	0x41CE,0x41F9,0x4224,0x424F,0x427A,0x42A5,0x42D0,0x42FB,0x4326,0x4351,0x437B,0x43A6,0x43D1,0x43FB,0x4426,0x4450,
	0x447B,0x44A5,0x44D0,0x44FA,0x4524,0x454F,0x4579,0x45A3,0x45CD,0x45F7,0x4621,0x464B,0x4675,0x469F,0x46C9,0x46F3,
	0x471D,0x4747,0x4770,0x479A,0x47C4,0x47ED,0x4817,0x4840,0x486A,0x4893,0x48BD,0x48E6,0x490F,0x4939,0x4962,0x498B,
	0x49B4,0x49DD,0x4A06,0x4A2F,0x4A58,0x4A81,0x4AAA,0x4AD3,0x4AFB,0x4B24,0x4B4D,0x4B75,0x4B9E,0x4BC7,0x4BEF,0x4C17,
	0x4C40,0x4C68,0x4C91,0x4CB9,0x4CE1,0x4D09,0x4D31,0x4D59,0x4D81,0x4DA9,0x4DD1,0x4DF9,0x4E21,0x4E49,0x4E71,0x4E98,
	0x4EC0,0x4EE8,0x4F0F,0x4F37,0x4F5E,0x4F85,0x4FAD,0x4FD4,0x4FFB,0x5023,0x504A,0x5071,0x5098,0x50BF,0x50E6,0x510D,
	0x5134,0x515B,0x5181,0x51A8,0x51CF,0x51F5,0x521C,0x5243,0x5269,0x5290,0x52B6,0x52DC,0x5303,0x5329,0x534F,0x5375,
	0x539B,0x53C1,0x53E7,0x540D,0x5433,0x5459,0x547F,0x54A4,0x54CA,0x54F0,0x5515,0x553B,0x5560,0x5586,0x55AB,0x55D0,
	0x55F6,0x561B,0x5640,0x5665,0x568A,0x56AF,0x56D4,0x56F9,0x571E,0x5743,0x5767,0x578C,0x57B1,0x57D5,0x57FA,0x581E,
	0x5843,0x5867,0x588C,0x58B0,0x58D4,0x58F8,0x591C,0x5940,0x5964,0x5988,0x59AC,0x59D0,0x59F4,0x5A18,0x5A3B,0x5A5F,
	0x5A82,0x5AA6,0x5AC9,0x5AED,0x5B10,0x5B34,0x5B57,0x5B7A,0x5B9D,0x5BC0,0x5BE3,0x5C06,0x5C29,0x5C4C,0x5C6F,0x5C91,
	0x5CB4,0x5CD7,0x5CF9,0x5D1C,0x5D3E,0x5D61,0x5D83,0x5DA5,0x5DC8,0x5DEA,0x5E0C,0x5E2E,0x5E50,0x5E72,0x5E94,0x5EB6,
	0x5ED7,0x5EF9,0x5F1B,0x5F3C,0x5F5E,0x5F80,0x5FA1,0x5FC2,0x5FE4,0x6005,0x6026,0x6047,0x6068,0x6089,0x60AA,0x60CB,
	0x60EC,0x610D,0x612E,0x614E,0x616F,0x6190,0x61B0,0x61D1,0x61F1,0x6211,0x6232,0x6252,0x6272,0x6292,0x62B2,0x62D2,
	0x62F2,0x6312,0x6332,0x6351,0x6371,0x6391,0x63B0,0x63D0,0x63EF,0x640F,0x642E,0x644D,0x646C,0x648B,0x64AB,0x64CA,
	0x64E9,0x6507,0x6526,0x6545,0x6564,0x6582,0x65A1,0x65C0,0x65DE,0x65FC,0x661B,0x6639,0x6657,0x6675,0x6693,0x66B2,
	0x66D0,0x66ED,0x670B,0x6729,0x6747,0x6764,0x6782,0x67A0,0x67BD,0x67DA,0x67F8,0x6815,0x6832,0x6850,0x686D,0x688A,
	0x68A7,0x68C4,0x68E0,0x68FD,0x691A,0x6937,0x6953,0x6970,0x698C,0x69A9,0x69C5,0x69E1,0x69FD,0x6A1A,0x6A36,0x6A52,
	0x6A6E,0x6A89,0x6AA5,0x6AC1,0x6ADD,0x6AF8,0x6B14,0x6B30,0x6B4B,0x6B66,0x6B82,0x6B9D,0x6BB8,0x6BD3,0x6BEE,0x6C09,
	0x6C24,0x6C3F,0x6C5A,0x6C75,0x6C8F,0x6CAA,0x6CC4,0x6CDF,0x6CF9,0x6D14,0x6D2E,0x6D48,0x6D62,0x6D7C,0x6D96,0x6DB0,
	0x6DCA,0x6DE4,0x6DFE,0x6E17,0x6E31,0x6E4A,0x6E64,0x6E7D,0x6E97,0x6EB0,0x6EC9,0x6EE2,0x6EFB,0x6F14,0x6F2D,0x6F46,
	0x6F5F,0x6F78,0x6F90,0x6FA9,0x6FC2,0x6FDA,0x6FF2,0x700B,0x7023,0x703B,0x7053,0x706B,0x7083,0x709B,0x70B3,0x70CB,
	0x70E3,0x70FA,0x7112,0x712A,0x7141,0x7158,0x7170,0x7187,0x719E,0x71B5,0x71CC,0x71E3,0x71FA,0x7211,0x7228,0x723F,
	0x7255,0x726C,0x7282,0x7299,0x72AF,0x72C5,0x72DC,0x72F2,0x7308,0x731E,0x7334,0x734A,0x735F,0x7375,0x738B,0x73A0,
	0x73B6,0x73CB,0x73E1,0x73F6,0x740B,0x7421,0x7436,0x744B,0x7460,0x7475,0x7489,0x749E,0x74B3,0x74C7,0x74DC,0x74F0,
	0x7505,0x7519,0x752D,0x7542,0x7556,0x756A,0x757E,0x7592,0x75A6,0x75B9,0x75CD,0x75E1,0x75F4,0x7608,0x761B,0x762E,
	0x7642,0x7655,0x7668,0x767B,0x768E,0x76A1,0x76B4,0x76C7,0x76D9,0x76EC,0x76FE,0x7711,0x7723,0x7736,0x7748,0x775A,
	0x776C,0x777E,0x7790,0x77A2,0x77B4,0x77C6,0x77D8,0x77E9,0x77FB,0x780C,0x781E,0x782F,0x7840,0x7851,0x7863,0x7874,
	0x7885,0x7895,0x78A6,0x78B7,0x78C8,0x78D8,0x78E9,0x78F9,0x790A,0x791A,0x792A,0x793A,0x794A,0x795B,0x796A,0x797A,
	0x798A,0x799A,0x79AA,0x79B9,0x79C9,0x79D8,0x79E7,0x79F7,0x7A06,0x7A15,0x7A24,0x7A33,0x7A42,0x7A51,0x7A60,0x7A6E,
	0x7A7D,0x7A8C,0x7A9A,0x7AA8,0x7AB7,0x7AC5,0x7AD3,0x7AE1,0x7AEF,0x7AFD,0x7B0B,0x7B19,0x7B27,0x7B34,0x7B42,0x7B50,
	0x7B5D,0x7B6A,0x7B78,0x7B85,0x7B92,0x7B9F,0x7BAC,0x7BB9,0x7BC6,0x7BD3,0x7BDF,0x7BEC,0x7BF9,0x7C05,0x7C11,0x7C1E,
	0x7C2A,0x7C36,0x7C42,0x7C4E,0x7C5A,0x7C66,0x7C72,0x7C7E,0x7C89,0x7C95,0x7CA0,0x7CAC,0x7CB7,0x7CC2,0x7CCE,0x7CD9,
	0x7CE4,0x7CEF,0x7CFA,0x7D05,0x7D0F,0x7D1A,0x7D25,0x7D2F,0x7D3A,0x7D44,0x7D4E,0x7D58,0x7D63,0x7D6D,0x7D77,0x7D81,
	0x7D8A,0x7D94,0x7D9E,0x7DA7,0x7DB1,0x7DBA,0x7DC4,0x7DCD,0x7DD6,0x7DE0,0x7DE9,0x7DF2,0x7DFB,0x7E03,0x7E0C,0x7E15,
	0x7E1E,0x7E26,0x7E2F,0x7E37,0x7E3F,0x7E48,0x7E50,0x7E58,0x7E60,0x7E68,0x7E70,0x7E78,0x7E7F,0x7E87,0x7E8E,0x7E96,
	0x7E9D,0x7EA5,0x7EAC,0x7EB3,0x7EBA,0x7EC1,0x7EC8,0x7ECF,0x7ED6,0x7EDD,0x7EE3,0x7EEA,0x7EF0,0x7EF7,0x7EFD,0x7F03,
	0x7F0A,0x7F10,0x7F16,0x7F1C,0x7F22,0x7F27,0x7F2D,0x7F33,0x7F38,0x7F3E,0x7F43,0x7F49,0x7F4E,0x7F53,0x7F58,0x7F5D,
	0x7F62,0x7F67,0x7F6C,0x7F71,0x7F75,0x7F7A,0x7F7E,0x7F83,0x7F87,0x7F8B,0x7F90,0x7F94,0x7F98,0x7F9C,0x7FA0,0x7FA3,
	0x7FA7,0x7FAB,0x7FAE,0x7FB2,0x7FB5,0x7FB9,0x7FBC,0x7FBF,0x7FC2,0x7FC5,0x7FC8,0x7FCB,0x7FCE,0x7FD1,0x7FD3,0x7FD6,
	0x7FD9,0x7FDB,0x7FDD,0x7FE0,0x7FE2,0x7FE4,0x7FE6,0x7FE8,0x7FEA,0x7FEC,0x7FED,0x7FEF,0x7FF1,0x7FF2,0x7FF4,0x7FF5,
	0x7FF6,0x7FF7,0x7FF8,0x7FF9,0x7FFA,0x7FFB,0x7FFC,0x7FFD,0x7FFE,0x7FFE,0x7FFF,0x7FFF,0x7FFF,0x8000,0x8000,0x8000,
	0x8000,
};

Int32 sinq12To15(Int32 phi) {
	return (phi & 2048 ? -1 : 1) * sinq12To15Short[ (phi & 1024 ? 1024 - (phi & 1023) : phi & 1023) ];
}
