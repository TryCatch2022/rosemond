// _WinMain at 0x00465040, decompiled by Ghidra.
//
// This file belongs to the project now: edit it freely. Re-exporting the
// function overwrites it only while it is unchanged since the export. Its
// signature still belongs to Ghidra (functions.h, and the stub that
// translated code calls it through), so change that in Ghidra.

#include <decomp.h>

namespace game
{

WPARAM _WinMain(HINSTANCE hInstance, undefined4 param_2, char *launchParam, int showWindowMode)
{
	ATOM windowClassAtom;
	WPARAM WVar1;
	int result;

	g_moduleHandle = hInstance;
	FUN_004656b0();
	g_errorLogFileHandle = _freopen("debug.log", "w", _iob + 1);
	if (g_errorLogFileHandle == (FILE *)0x0)
	{
		printf("Could not create error.log\n");
	}

	CreateBlackExe();

	nullsub_2();

	if (CreateWindowClass(hInstance) == 0)
	{
		return CloseOnError();
	}

	result = CreateGameWindow(hInstance, showWindowMode);
	if (result == 0)
	{
		OutputDebugString("oops\n");
		return CloseOnError();
	}

	OutputDebugStringA("caca");

	unk_lockDatFileExists();

	result = MeasureCpuPerfStats();
	if (result == 0)
	{
		return CloseOnError();
	}

	result = DirectInput_Init();
	if (result == 0)
	{
		logError("InitInput() failed");
	}

	Run(launchParam);
	_fflush((FILE *)(_iob + 1));
	return CloseOnError(); // ?
}

}
