/*
 * flash_config.h
 *
 *  Created on: 2018��5��24��
 *      Author: Administrator
 */

#ifndef APP_INCLUDE_FLASH_CONFIG_H_
#define APP_INCLUDE_FLASH_CONFIG_H_

#ifdef __cplusplus
extern "C"{
#endif //__cplusplus

//#define USE_OS			//�Ƿ�ʹ��ϵͳ
#define FLASH_SIZE 1024	//flash�Ĵ�С(��λ:KB)

#ifdef USE_OS
	#define FOTA
#else
	#define NON_FOTA
#endif

#ifdef NON_FOTA
	#if (FLASH_SIZE==512)
		#define PRIV_PARAM_START_SEC 	0x3C
		#define ESP_PARAM_START_SEC 	0x3D
	#else	//Ĭ��Ϊ512KB
		#define PRIV_PARAM_START_SEC 	0x7C
		#define ESP_PARAM_START_SEC 	0x7D
	#endif
#endif //NON_FOTA

#ifdef FOTA
	#if (FLASH_SIZE==512)
		#define PRIV_PARAM_START_SEC 	0x3C
		#define ESP_PARAM_START_SEC 	0x3D
	#elif (FLASH_SIZE == 1024)
		#define PRIV_PARAM_START_SEC 	0x7C
		#define ESP_PARAM_START_SEC 	0x7D
	#else
		#define PRIV_PARAM_START_SEC 	0xFC
		#define ESP_PARAM_START_SEC 	0xFD
	#endif
#endif //FOTA

#ifdef __cplusplus
}
#endif //__cplusplus

#endif /* APP_INCLUDE_FLASH_CONFIG_H_ */