/** 
 @file  types.h
 @brief type definitions for ENet
*/
#ifndef __ENET_TYPES_H__
#define __ENET_TYPES_H__

#ifndef S_IREAD
#define S_IREAD S_IRUSR
#endif

#ifndef S_IWRITE
#define S_IWRITE S_IWUSR
#endif

#ifndef S_IEXEC
#define S_IEXEC S_IXUSR
#endif

typedef unsigned char enet_uint8;       /**< unsigned 8-bit type  */
typedef unsigned short enet_uint16;     /**< unsigned 16-bit type */
typedef unsigned int enet_uint32;      /**< unsigned 32-bit type */

#endif /* __ENET_TYPES_H__ */

