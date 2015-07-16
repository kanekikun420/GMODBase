#pragma once
#include "crc32.h"
class CUserCmd
{
public:
	//This is really fucking large for some reason. -Snorflake
	char _0x0000[4];
	float command_number; //0x0004
	float tick_count; //0x0008
	Vector viewangles; //0x000C
	float forwardmove; //0x0018
	float sidemove; //0x001C
	float upmove; //0x0020
	int buttons; //0x0024
	char _0x0028[12];
	float random_seed; //0x0034
	__int16 mousedx; //0x0038
	__int16 mousey; //0x003A
	char _0x003C[288];

};//Size=0x015C
/*
class CVerifiedUserCmd
{
public:
void* m_cmd; //0x0000
__int32 m_crc; //0x0004

};//Size=0x0008*/
class CVerifiedUserCmd
{
public:
	CUserCmd	m_cmd;
	unsigned long	m_crc;
};
