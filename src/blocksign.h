// Copyright (c) 2014 The MidasCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef MIDASCOIN_BLOCKSIGN_H
#define MIDASCOIN_BLOCKSIGN_H

#define BLOCKSIGN_PRIVATE ""
#define BLOCKSIGN_PUBLIC "-----BEGIN PUBLIC KEY-----\nMIICIjANBgkqhkiG9w0BAQEFAAOCAg8AMIICCgKCAgEAr/sPCSQjsbIVyB5BS1Y2\npeQQ5NLNu6TCbjeeiep32mXhCfwIrqJpKhudlkxOE431DFJz00LFgSZzHzcWkgby\nEZhHKRQearLPQ54W7mVo6XHGqJwgA4yq6bt7N8LzILij3y4iMxTFG9smVuC7NgR3\nDdOoCDDNriV4k42YtFhbvgOPepktGho/zpIWWHW96j6DKbFO7CTZDOZfU01t6X9V\nuYO1tR3O83NUtfX1skyNXud07FGocdqXsSzT9/dC7Os1IfRj1dsTfM4UkGos2Qok\nQEai3SsMZcb82hR5ywOOceb4dKP8q0WyxCD1qTydWvft61kT3tGnKQ4zvSgQxOTF\nRP6cF6WNfBr7gFrBokG60g5shjAdKFPvDDr5xJAlKObWEx6Zh/X/RcHXBqWz6g4T\nyyTQDvrycxkdAG5R+aJyr4xQOg6zC5AdOL9KpQgF6p/z9ujiNXWKkymXCuAlYN+a\nwO2iAZU407VQCF5eXzEOvkDuuesuJ5ntRKt6j+lTOwiBOMDj2gZDtQgjVcahFj59\nxrVG4dQtxeHvt36wu/W0NGJDsiHtYXmYYWfnpng9QDckqu9lXzpmqci2iBW1upcp\nM+P/PLyu6FOAaYyTyLS4J+bnfxY7H3hpGvEJSvY+mmegmzkVO6WnT2iPvxbUtCMD\nb+k0ZwUaPyTOTbYj/PITW+kCAwEAAQ==\n-----END PUBLIC KEY-----"
#define BLOCKSIGN_SLEN 512

#include "main.h"

struct block_signature{
	std::string sig;
	unsigned int slen;
};

void SignBlock(CBlock& block);
block_signature MakeBlockSignature(const unsigned char* message);
bool VerifyBlock(const unsigned char* message, const unsigned char* signature, unsigned int slen);

#endif
