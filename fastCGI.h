/*************************************************************************
	> File Name: fastCGI.h
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年09月29日 星期二 15时46分48秒
 ************************************************************************/

#ifndef _FASTCGI_H
#define _FASTCGI_H

#define FCGI_HOST "127.0.0.1"
#define FCGI_PORT 9000      // php-fpm监听的端口地址
#define FCGI_REQUEST_ID 1
#define FCGI_VERSION_1 1
#define FCGI_BEGIN_REQUEST 1
#define FCGI_RESPONDER 1
#define FCGI_END_REQUEST 3
#define FCGI_PARAMS 4
#define FCGI_STDIN 5
#define FCGI_STDOUT 6
#define FCGI_STDERR 7

/*
 * 包头
 */
typedef struct{
    unsigned char version;
    unsigned char type;
    unsigned char requestIdB1;
    unsigned char requestIdB0;
    unsigned char contentLengthB1;
    unsigned char contentLengthB0;
    unsigned char paddingLength;
    unsigned char reserved;
}FCGI_Header;

/*
 * FCGI_BEGIN_REQUEST请求包体
 */
typedef struct{
    unsigned char roleB1;
    unsigned char roleB0;
    unsigned char flags;
    unsigned char reserved[5];
}FCGI_BeginRequestBody;

/*
 * FCGI_BEGIN_REQUEST请求记录
 */
typedef struct{
    FCGI_Header header;
    FCGI_BeginRequestBody body;
}FCGI_BeginRequestRecord;

/*
 * FCGI_PARAMS传递参数记录
 */
typedef struct{
    FCGI_Header header;
    unsigned char nameLength;
    unsigned char valueLength;
    unsigned char data[0];
}FCGI_ParamsRecord;

/*
 * 构造请求头部，返回FCGI_Header结构体
 */
FCGI_Header makeHeader(
		int type,
		int requestId,
		int contentLength,
		int paddingLength);

/*
 * 构造请求体，返回FCGI_BeginRequestBody结构体
 */
FCGI_BeginRequestBody makeBeginRequestBody(
		int role);

#endif
