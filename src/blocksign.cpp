// Copyright (c) 2014 The MidasCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <openssl/sha.h>
#include <openssl/bio.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#include "blocksign.h"

void SignBlock(CBlock& block){
	block_signature sig = MakeBlockSignature((const unsigned char*) block.GetHash().GetHex().c_str());
	block.sig = sig.sig;
	block.slen = sig.slen;
}

block_signature MakeBlockSignature(const unsigned char* message){
	block_signature ret;

	const char *privkey = BLOCKSIGN_PRIVATE;
	RSA *private_key; 
	BIO *priv_bio;

	unsigned int slen;
	unsigned char* signature;

	priv_bio = BIO_new_mem_buf((char*)privkey, -1);
	if(priv_bio == NULL) {
		printf("SignBlock() : Bio is null\n");
		return ret;
	}

	private_key = PEM_read_bio_RSAPrivateKey(priv_bio, NULL, NULL, NULL);
	if(private_key == NULL) {
		printf("SignBlock() : Key is null\n");
		return ret;
	}

	printf("SignBlock() : Signing block %s\n", message);
	printf("Message length: %d, message: %s\n", strlen((char*)message), message);

	unsigned char hash[20];
	if (!SHA1(message, strlen((char*)message), hash)){
		printf("SignBlock() : Hashing message failed");
		return ret;
	}
	printf("SignBlock() : Hash message: ");
	for (int i = 0; i < 20; i++) {
        printf("%02x", hash[i]);
    }
	printf("\n");

	signature = (unsigned char*) malloc(RSA_size(private_key));
	if(RSA_sign(NID_sha1, hash, 20,	signature, &slen, private_key) != 1) {
		printf("SignBlock() : Sign is null\n");
		return ret;
	}

	printf("SignBlock() : Signature: ");
	for(unsigned int i=0; i < slen; i++){
		printf("%02x", signature[i]);
	}
	printf("\n%d\n", slen);

	ret.sig = std::string(reinterpret_cast<const char *>(signature), slen);
	ret.slen = slen;

	RSA_free(private_key);
	
	return ret;
}

bool VerifyBlock(const unsigned char* message, const unsigned char* signature, unsigned int slen){
	slen = BLOCKSIGN_SLEN;
	const char *pubkey = BLOCKSIGN_PUBLIC;
	RSA *public_key;
	BIO *pub_bio;
	
	unsigned int verified;

	pub_bio = BIO_new_mem_buf((char*)pubkey, -1);
	if(pub_bio == NULL) {
		printf("VerifyBlock() : Bio is null\n");
		return false;
	}

	public_key = PEM_read_bio_RSA_PUBKEY(pub_bio, NULL, NULL, NULL);
	if(public_key == NULL) {
		printf("VerifyBlock() : Key is null\n");
		return false;
	}
	
	printf("VerifyBlock() : Message: %s ---\n", message);
	printf("Message length: %d, message: %s\n", strlen((char*)message), message);

	unsigned char hash[20];
	if (!SHA1(message, strlen((char*)message), hash)){
		printf("VerifyBlock() : Hashing message failed");
		return false;
	}
	printf("VerifyBlock() : Hash message: ");
	for (int i = 0; i < 20; i++) {
        printf("%02x", hash[i]);
    }
	printf("\n");

	printf("VerifyBlock() : Signature: ");
	for(unsigned int i=0; i < slen; i++){
		printf("%02x", signature[i]);
	}
	printf("\n");


	verified = RSA_verify(NID_sha1, hash, 20, signature, slen, public_key);
	
	printf("VerifyBlock() : verified=%d\n", verified);

	RSA_free(public_key);

	return verified;
}
