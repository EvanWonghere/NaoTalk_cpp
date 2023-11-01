/*
* 语音听写(iFly Auto Transform)技术能够实时地将语音转换成对应的文字。
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>
#include "qisr.h"
#include "msp_cmn.h"
#include "msp_errors.h"
#include "recognizer.h"
#include "demo.h"

char* ans=NULL;

char *g_result = NULL;
unsigned int g_buffersize = BUFFER_SIZE;

static void show_result(char *string, char is_over)
{
	ans = (char*)malloc((strlen(string) + 1) * sizeof(char));
	strcpy(ans, string);
	printf("\rResult: [ %s ]", string);
	if(is_over)
		putchar('\n');
}

void on_result(const char *result, char is_last)
{
	if (result) {
		size_t left = g_buffersize - 1 - strlen(g_result);
		size_t size = strlen(result);
		if (left < size) {
			g_result = (char*)realloc(g_result, g_buffersize + BUFFER_SIZE);
			if (g_result)
				g_buffersize += BUFFER_SIZE;
			else {
				printf("mem alloc failed\n");
				return;
			}
		}
		strncat(g_result, result, size);
		show_result(g_result, is_last);
	}
}
void on_speech_begin()
{
	if (g_result)
	{
		free(g_result);
	}
	g_result = (char*)malloc(BUFFER_SIZE);
	g_buffersize = BUFFER_SIZE;
	memset(g_result, 0, g_buffersize);

	printf("Start Listening...\n");
}
void on_speech_end(int reason)
{
	if (reason == END_REASON_VAD_DETECT)
		printf("\nSpeaking done \n");
	else
		printf("\nRecognizer error %d\n", reason);
}

/* demo recognize the audio from microphone */
static void demo_mic(const char* session_begin_params)
{
	printf("start recording...\n");
	int errcode;
	int i = 0;

	struct speech_rec iat;

	struct speech_rec_notifier recnotifier = {
		on_result,
		on_speech_begin,
		on_speech_end
	};

	printf("point 5\n");
	errcode = sr_init(&iat, session_begin_params, SR_MIC, &recnotifier);
	printf("point 6\n");
	if (errcode) {
		printf("speech recognizer init failed\n");
		return;
	}
	errcode = sr_start_listening(&iat);
	if (errcode) {
		printf("start listen failed %d\n", errcode);
	}
	/* demo 15 seconds recording */
	while(i++ < 15)
		sleep(1);
	errcode = sr_stop_listening(&iat);
	if (errcode) {
		printf("stop listening failed %d\n", errcode);
	}

	sr_uninit(&iat);
}

char* plisten(){

	printf("%d", 1);
	static char* test = "你好";
	return test;
}

/* main thread: start/stop record ; query the result of recgonization.
 * record thread: record callback(data write)
 * helper thread: ui(keystroke detection)
 * */
char* qlisten()
{
	int ret = MSP_SUCCESS;
	int aud_src =	1;
	/* login params, please do keep the appid correct */
	const char* login_params = "appid = 3bae7be3, work_dir = .";

	/*
	* See "iFlytek MSC Reference Manual"
	*/
	const char* session_begin_params =
		"sub = iat, domain = iat, language = zh_cn, "
		"accent = mandarin, sample_rate = 16000, "
		"result_type = plain, result_encoding = utf8";

	/* Login first. the 1st arg is username, the 2nd arg is password
	 * just set them as NULL. the 3rd arg is login paramertes 
	 * */
	printf("point 1\n");
	ret = MSPLogin(NULL, NULL, login_params);
	if (MSP_SUCCESS != ret)	{
		printf("MSPLogin failed , Error code %d.\n",ret);
		goto exit; // login fail, exit the program
	}

	printf("point 2\n");
	if(aud_src != 0) {
		printf("Demo recognizing the speech from microphone\n");
		printf("Speak in 15 seconds\n");

		printf("point 3\n");
		demo_mic(session_begin_params);
		printf("point 4\n");
		printf("ans: %s\n", ans);
//
		printf("15 sec passed\n");
	}
exit:
	MSPLogout(); // Logout...

	return ans;
}
