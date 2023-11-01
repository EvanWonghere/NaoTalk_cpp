#pragma once

#ifndef DEMO_H
#define DEMO_H


#define FRAME_LEN	640 
#define	BUFFER_SIZE	4096

    #ifdef __cplusplus
extern "C" {
    #endif

static void show_result(char *string, char is_over);

void on_result(const char *result, char is_last);

void on_speech_begin();

void on_speech_end(int reason);

static void demo_mic(const char* session_begin_params);

char* qlisten();

char* plisten();

    #ifdef __cplusplus
}
    #endif

#endif
