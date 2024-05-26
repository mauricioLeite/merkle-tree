#include "sha256.h"

/**
 * Returns the SHA256 value of the reference string
 * @param reference input string for which the hash to be calculated
 * @returns string (32 bytes) - SHA256 hash
 */
std::string sha256(const std::string reference) {
    EVP_MD_CTX *mdCtx = EVP_MD_CTX_new();
    unsigned char mdVal[EVP_MAX_MD_SIZE], *md;
    unsigned int mdLen, i;

    if (!EVP_DigestInit_ex(mdCtx, EVP_sha256(), OPENSSL_ENGINE)) {
        printf("Message digest initialization failed.\n");
        EVP_MD_CTX_free(mdCtx);
        exit(EXIT_FAILURE);
    }

    if (!EVP_DigestUpdate(mdCtx, reference.c_str(), reference.length())) {
        printf("Message digest update failed.\n");
        EVP_MD_CTX_free(mdCtx);
        exit(EXIT_FAILURE);
    }

    if (!EVP_DigestFinal_ex(mdCtx, mdVal, &mdLen)) {
        printf("Message digest finalization failed.\n");
        EVP_MD_CTX_free(mdCtx);
        exit(EXIT_FAILURE);
    }

    EVP_MD_CTX_free(mdCtx);

    std::stringstream ss;
    for(int i = 0; i < mdLen; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)mdVal[i];
    }

    return ss.str();
}