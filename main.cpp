#include "sdk.h"
typedef void(__cdecl *MsgFn)(char const* pMsg, va_list);
void __cdecl Msg(char const* msg, ...)
{
	static MsgFn oMsg = (MsgFn)GetProcAddress(GetModuleHandle("tier0.dll"), "Msg");
	char buffer[989];
	va_list list;
	va_start(list, msg);
	vsprintf(buffer, msg, list);
	va_end(list);
	oMsg(buffer, list);
}
void SetupIndexes()
{
	using namespace indexes;
	//Engine
	GetScreenSize = 5;
	GetPlayerInfo = 8;
	GetLocalPlayer = 12;
	ClientCmd = 102;
	SetViewAngles = 20;
	GetViewAngles = 19;
	WorldToScreenMatrix = 36;

	//ClientEntList
	GetClientEntity = 3;
	GetHighestEntityIndex = 8;
	GetClientEntityFromHandle = 7;

	//Surface
	SetDrawColor = 10;
	DrawFilledRect = 12;
	DrawOutlinedRect = 14;
	DrawLine = 15;
	SCreateFont = 66;
	SetFontGlyphSet = 67;
	DrawSetTextFont = 17;
	DrawSetTextColor = 18;
	DrawSetTextPos = 20;
	DrawPrintText = 22;

	//ModelInfo
	GetStudioModel = 29;
}

void StartCheat()
{
	SetupIndexes();
	Interfaces.Engine->ClientCmd("clear");
	Msg("Plugin system loaded!\n");

	Hooks.Hook();
}