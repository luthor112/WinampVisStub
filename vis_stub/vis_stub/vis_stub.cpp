#include <Windows.h>

#include "vis.h"

//////////////////////////
// FORWARD DECLARATIONS //
//////////////////////////

void showConfigDialog(struct winampVisModule* this_mod);
int init(struct winampVisModule* this_mod);
int render(struct winampVisModule* this_mod);
void quit(struct winampVisModule* this_mod);

////////////////////////
// PLUGIN DESCRIPTORS //
////////////////////////

winampVisModule visDescriptor = {
	const_cast<char*>("TEST DESCRIPTION"),	// description: description of module
	NULL,	// hwndParent: parent window (filled in by calling app)
	NULL,	// hDllInstance: instance handle to this DLL (filled in by calling app)
	0,		// sRate: sample rate (filled in by calling app)
	0,		// nCh: number of channels (filled in...)
	10,		// latencyMS: latency from call of RenderFrame to actual drawing (calling app looks at this value when getting data)
	15,		// delayMS: delay between calls in ms
	0,		// spectrumNch
	2,		// waveformNch
	{ 0 },	// spectrumData[2][576]
	{ 0 },	// waveformData[2][576]
	showConfigDialog,	// configuration dialog
	init,				// 0 on success, creates window, etc
	render,				// returns 0 if successful, 1 if vis should end
	quit,				// call when done
	NULL	// userData: user data, optional
};

winampVisModule* getModule(int which)
{
	switch (which)
	{
	case 0:	return &visDescriptor;
	default: return NULL;
	}
}

winampVisHeader visHeader = {
	VIS_HDRVER,
	const_cast<char*>("TEST DESCRIPTION"),	// description
	getModule
};

extern "C" __declspec(dllexport) winampVisHeader * winampVisGetHeader()
{
	return &visHeader;
}

///////////////////////////
// PLUGIN IMPLEMENTATION //
///////////////////////////

// configuration dialog
void showConfigDialog(struct winampVisModule* this_mod)
{
	// Show config window
	// TODO
}

// 0 on success, creates window, etc
int init(struct winampVisModule* this_mod)
{
	// Move to correct position
	// TODO

	// Create window + save HWND for later
	// TODO

	return 0;
}

// returns 0 if successful, 1 if vis should end
int render(struct winampVisModule* this_mod)
{
	// Render stuff
	// TODO

	return 0;
}

// call when done
void quit(struct winampVisModule* this_mod)
{
	// Save window position
	// TODO
}
