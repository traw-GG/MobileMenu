#include "MobileMenu.h"

void (*InitForPause)(uintptr* thiz);
void InitForPause_hook(uintptr* thiz)
{
    InitForPause(thiz);
}

void CMobileMenu::InjectHooks() {
	// hook tap to card and init pause screen
    CHook::InlineHook("_ZN10MobileMenu12InitForPauseEv", &InitForPause_hook, &InitForPause);
}