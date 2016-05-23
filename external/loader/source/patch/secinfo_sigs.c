#include <3ds.h>
#include "../patcher.h"
#include "../ifile.h"

#ifndef PATH_MAX
#define PATH_MAX 255
#define _MAX_LFN 255
#endif
#include "../config.h"
#include "../../../../source/patch_format.h"

void secureinfo_sigpatch(u64 progId, u8 *code, u32 size) {
	static const u8 secureinfoSigCheckPattern[] = {0x06, 0x46, 0x10, 0x48, 0xFC};
	static const u8 secureinfoSigCheckPatch[]   = {0x00, 0x26};

	//Disable SecureInfo signature check
	patchMemory(code, size,
		secureinfoSigCheckPattern,
		sizeof(secureinfoSigCheckPattern), 0,
		secureinfoSigCheckPatch,
		sizeof(secureinfoSigCheckPatch), 1
	);
}
