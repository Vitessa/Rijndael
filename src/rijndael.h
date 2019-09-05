/* rijndael.h */

/* This file is derived from ccrypt, which is free software
   and covered by the GNU general public license. */

#ifndef __RIJNDAEL_H
#define __RIJNDAEL_H

#include <cstdint>

enum ERijndaelBits
{
	ERijndaelBits128 = 128,
	ERijndaelBits192 = 192,
	ERijndaelBits256 = 256,
};

struct roundkey
{
public:
	roundkey(){};
	~roundkey(){};
public:
	bool isInit()
	{
		return (BC!=0 && KC!=0 && ROUNDS!=0);
	}
public:
    int BC = 0;
    int KC = 0;
    int ROUNDS = 0;
    int shift[2][4];
    uint32_t rk[120];
};


/*
 * @brief ��ʼ��Rijndael��Կ
 * 
 * @param handle ��Կ���
 * @param key ��Կ���飬���ȱ����keyBits��ͬ
 * @param keyBits ��Կ����128/192/256
 * @param blockBits ���ܿ��С128/192/256
 *
 * @return 0�ɹ�����0ʧ�� 
 */
roundkey xrijndaelKeySched(const void* key, int keyBits = ERijndaelBits256, int blockBits = ERijndaelBits128);

/*
 * @brief ��������
 *
 * @param handle ��Կ���
 * @param block ���������飬���������е�blockBitsһ�£�ֱ�Ӹ�������
 */
void xrijndaelEncrypt(const roundkey& handle, const void* block);

/*
 * @brief ��������
 *
 * @param handle ��Կ���
 * @param block ���������飬���������е�blockBitsһ�£�ֱ�Ӹ�������
 */
void xrijndaelDecrypt(const roundkey& handle, const void* block);


#endif              /* __RIJNDAEL_H */
