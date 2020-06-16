//
//  _sodium.h
//  _sodium
//
//  Created by Adrian Labbé on 13-05-20.
//  Copyright © 2020 Adrian Labbé. All rights reserved.
//

#include "../../sodium/crypto_pwhash_scryptsalsa208sha256.h"
#include "../../sodium/crypto_shorthash_siphash24.h"

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_bytes_min(void) {
    return crypto_pwhash_scryptsalsa208sha256_BYTES_MIN;
}

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_bytes_max(void) {
    return crypto_pwhash_scryptsalsa208sha256_BYTES_MAX;
}

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_passwd_min(void) {
    return crypto_pwhash_scryptsalsa208sha256_PASSWD_MIN;
}

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_passwd_max(void) {
    return crypto_pwhash_scryptsalsa208sha256_PASSWD_MAX;
}

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_saltbytes(void) {
    return crypto_pwhash_scryptsalsa208sha256_SALTBYTES;
}

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_strbytes(void) {
    return crypto_pwhash_scryptsalsa208sha256_STRBYTES;
}

SODIUM_EXPORT const char *crypto_pwhash_scryptsalsa208sha256_strprefix(void) {
    return crypto_pwhash_scryptsalsa208sha256_STRPREFIX;
}

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_opslimit_min(void) {
    return crypto_pwhash_scryptsalsa208sha256_OPSLIMIT_MIN;
}

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_opslimit_max(void) {
    return crypto_pwhash_scryptsalsa208sha256_OPSLIMIT_MAX;
}

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_memlimit_min(void) {
    return crypto_pwhash_scryptsalsa208sha256_MEMLIMIT_MIN;
}

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_memlimit_max(void) {
    return crypto_pwhash_scryptsalsa208sha256_MEMLIMIT_MAX;
}

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_opslimit_interactive(void) {
    return crypto_pwhash_scryptsalsa208sha256_OPSLIMIT_INTERACTIVE;
}

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_memlimit_interactive(void) {
    return crypto_pwhash_scryptsalsa208sha256_MEMLIMIT_INTERACTIVE;
}

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_opslimit_sensitive(void) {
    return crypto_pwhash_scryptsalsa208sha256_OPSLIMIT_SENSITIVE;
}

SODIUM_EXPORT size_t crypto_pwhash_scryptsalsa208sha256_memlimit_sensitive(void) {
    return crypto_pwhash_scryptsalsa208sha256_MEMLIMIT_SENSITIVE;
}


SODIUM_EXPORT size_t crypto_shorthash_siphashx24_bytes(void) {
    return crypto_shorthash_siphashx24_BYTES;
}

SODIUM_EXPORT size_t crypto_shorthash_siphashx24_keybytes(void) {
    return crypto_shorthash_siphashx24_KEYBYTES;
}
