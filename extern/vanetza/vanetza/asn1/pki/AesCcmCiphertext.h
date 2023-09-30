/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IEEE1609dot2"
 * 	found in "asn1/IEEE1609dot2.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -no-gen-example -R`
 */

#ifndef	_AesCcmCiphertext_H_
#define	_AesCcmCiphertext_H_


#include "asn_application.h"

/* Including external dependencies */
#include "OCTET_STRING.h"
#include "Opaque.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* AesCcmCiphertext */
typedef struct AesCcmCiphertext {
	OCTET_STRING_t	 nonce;
	Opaque_t	 ccmCiphertext;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} AesCcmCiphertext_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_AesCcmCiphertext;
extern asn_SEQUENCE_specifics_t asn_SPC_AesCcmCiphertext_specs_1;
extern asn_TYPE_member_t asn_MBR_AesCcmCiphertext_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _AesCcmCiphertext_H_ */
#include "asn_internal.h"
