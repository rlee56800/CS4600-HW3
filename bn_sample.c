/* bn_sample.c */
#include <stdio.h>
#include <openssl/bn.h>
#define NBITS 256

void printBN(char *msg, BIGNUM * a)
{
	/* Use BN_bn2hex(a) for hex string
	* Use BN_bn2dec(a) for decimal string */
	char * number_str = BN_bn2hex(a);
	printf("%s %s\n", msg, number_str);
	OPENSSL_free(number_str);
}

int main ()
{
	BN_CTX *ctx = BN_CTX_new(); // structure

	/*// TASK 1
	BIGNUM *p = BN_new();
	BIGNUM *q = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *n = BN_new();
	BIGNUM *d = BN_new();
	BIGNUM *one = BN_new(); // for subtraction in torient
	BIGNUM *torient = BN_new();

	BIGNUM *p1 = BN_new(); // temp to store p-1
	BIGNUM *q1 = BN_new(); // temp to store q-1

	// Initialize p, q, e
	BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
	BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
	BN_hex2bn(&e, "0D88C3");
	BN_hex2bn(&one, "1");
	
	// Calculate d
	BN_mul(n, p, q, ctx); //n = p*q
	BN_sub(p1, p, one); //p-1
	BN_sub(q1, q, one); //q-1
	BN_mul(torient, p1, q1, ctx); // PHI(n) = (p-1)(q-1)
	BN_mod_inverse(d, e, torient, ctx); // e * d mod PHI(n)
	
	// Print results
	printBN("p is", p);
	printBN("q is", q);
	printBN("e is", e);
	printBN("n is", n);
	printBN("PHI(n) is", torient);
	printBN("d is", d);*/

/*
	// TASK 2
	BIGNUM *C = BN_new();
	BIGNUM *n = BN_new();
	BIGNUM *m = BN_new();
	BIGNUM *m_decrypt = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *d = BN_new();
	// "A top secret!"
	char msg_text[] = "A top secret!";
	
	BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&m, "4120746f702073656372657421");
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

	printBN("n = ", n);
	printBN("e = ", e);
	printf("M = %s\n", msg_text);
	printBN("d = ", d);
	
	BN_mod_exp(C, m, e, n, ctx); // C = (M^e) mod n (encrypt)
	printBN("C = ", C);

	BN_mod_exp(m_decrypt, C, d, n, ctx); // D = (C^d) mod n (decrypt)
	printBN("M decrypted = ", m_decrypt);*/



/*
	// TASK 3
	BIGNUM *C = BN_new();
	BIGNUM *n = BN_new();
	BIGNUM *m = BN_new();
	BIGNUM *m_decrypt = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *d = BN_new();
	
	BN_hex2bn(&C, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");
	BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&m, "4120746f702073656372657421");
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

	printBN("n = ", n);
	printBN("e = ", e);
	printBN("d = ", d);

	BN_mod_exp(m_decrypt, C, d, n, ctx); // D = (C^d) mod n (decrypt)
	printBN("M decrypted = ", m_decrypt);*/


/*
	// TASK 4
	BIGNUM *C = BN_new();
	BIGNUM *n = BN_new();
	BIGNUM *m2000 = BN_new();
	BIGNUM *m3000 = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *d = BN_new();
	BIGNUM *sig2000 = BN_new();
	BIGNUM *sig3000 = BN_new();
	char msg_text2000[] = "I owe you $2000.";
	char msg_text3000[] = "I owe you $3000.";
	
	BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
	BN_hex2bn(&m2000, "49206f776520796f752024323030302e");
	BN_hex2bn(&m3000, "49206f776520796f752024333030302e");
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

	BN_mod_exp(sig2000, m2000, d, n, ctx); // sig2000 = (m2000^d) mod n
	BN_mod_exp(sig3000, m3000, d, n, ctx); // sig3000 = (m3000^d) mod n

	printBN("n = ", n);
	printBN("e = ", e);
	printBN("d = ", d);

	printBN("m2000 = ", m2000);
	printBN("m3000 = ", m3000);

	printBN("signature 2000 = ", sig2000);
	printBN("signature 3000 = ", sig3000);*/


	// TASK 5
	BIGNUM *C = BN_new();
	BIGNUM *n = BN_new();
	BIGNUM *m = BN_new();
	BIGNUM *e = BN_new();
	BIGNUM *s = BN_new();
	
	BN_hex2bn(&s, "643D6F34902D9C7EC90CB0B2BCA36C47FA37165C0005CAB026C0542CBDB6802F");
	BN_hex2bn(&e, "010001");
	BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");

	BN_mod_exp(m, s, e, n, ctx); // m = (sig^e) mod n

	printBN("s = ", s);
	printBN("e = ", e);
	printBN("n = ", n);

	printBN("m = ", m);

	return 0;
}