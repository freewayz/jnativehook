/* JNativeHook: Global keyboard and mouse hooking for Java.
 * Copyright (C) 2006-2013 Alexander Barker.  All Rights Received.
 * http://code.google.com/p/jnativehook/
 *
 * JNativeHook is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * JNativeHook is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <jni.h>
#include <nativehook.h>

#include "jni_Globals.h"

void jni_SetProperties(JNIEnv *env) {
	// Create a buffer for converting numbers to strings.
	char buffer[16];

	// Set the native keyboard auto repeat rate.
	long rate = hook_get_auto_repeat_rate();
	if (rate >= 0) {
		if (snprintf(buffer, sizeof(buffer), "%li", rate) >= 0) {
			jstring name = (*env)->NewStringUTF(env, "jnativehook.autoRepeatRate");
			jstring value = (*env)->NewStringUTF(env, buffer);

			(*env)->CallStaticObjectMethod(
					env, 
					java_lang_System->cls, 
					java_lang_System->setProperty, 
					name, 
					value);

			(*env)->DeleteLocalRef(env, name);
			(*env)->DeleteLocalRef(env, value);
		}
		#ifdef DEBUG
		else {
			fprintf(stderr, "%s [%u]: Failed to convert auto repeat rate to string!\n", 
					__FUNCTION__, __LINE__);
		}
		#endif
	}
	#ifdef DEBUG
	else {
		fprintf(stderr, "%s [%u]: Invalid result returned from hook_get_auto_repeat_rate()!\n", 
				__FUNCTION__, __LINE__);
	}
	#endif


	long delay = hook_get_auto_repeat_delay();
	if (delay >= 0) {
		if (snprintf(buffer, sizeof(buffer), "%li", delay) >= 0) {
			jstring name = (*env)->NewStringUTF(env, "jnativehook.autoRepeatDelay");
			jstring value = (*env)->NewStringUTF(env, buffer);

			(*env)->CallStaticObjectMethod(
					env, 
					java_lang_System->cls, 
					java_lang_System->setProperty, 
					name, 
					value);

			(*env)->DeleteLocalRef(env, name);
			(*env)->DeleteLocalRef(env, value);
		}
		#ifdef DEBUG
		else {
			fprintf(stderr, "%s [%u]: Failed to convert auto repeat delay to string!\n", 
					__FUNCTION__, __LINE__);
		}
		#endif
	}
	#ifdef DEBUG
	else {
		fprintf(stderr, "%s [%u]: Invalid result returned from hook_get_auto_repeat_delay()!\n", 
				__FUNCTION__, __LINE__);
	}
	#endif


	// 0-Threshold X, 1-Threshold Y and 2-Speed.
	long multiplier = hook_get_pointer_acceleration_multiplier();
	if (multiplier >= 0) {
		if (snprintf(buffer, sizeof(buffer), "%li", multiplier) >= 0) {
			jstring name = (*env)->NewStringUTF(env, "jnativehook.pointerAccelerationMultiplier");
			jstring value = (*env)->NewStringUTF(env, buffer);

			(*env)->CallStaticObjectMethod(
					env, 
					java_lang_System->cls, 
					java_lang_System->setProperty, 
					name, 
					value);

			(*env)->DeleteLocalRef(env, name);
			(*env)->DeleteLocalRef(env, value);
		}
		#ifdef DEBUG
		else {
			fprintf(stderr, "%s [%u]: Failed to convert pointer acceleration multiplier to string!\n", 
					__FUNCTION__, __LINE__);
		}
		#endif
	}
	#ifdef DEBUG
	else {
		fprintf(stderr, "%s [%u]: Invalid result returned from hook_get_pointer_acceleration_multiplier()!\n", 
				__FUNCTION__, __LINE__);
	}
	#endif


	// 0-Threshold X, 1-Threshold Y and 2-Speed.
	long threshold = hook_get_pointer_acceleration_threshold();
	if (threshold >= 0) {
		if (snprintf(buffer, sizeof(buffer), "%li", threshold) >= 0) {
			jstring name = (*env)->NewStringUTF(env, "jnativehook.pointerAccelerationThreshold");
			jstring value = (*env)->NewStringUTF(env, buffer);

			(*env)->CallStaticObjectMethod(
					env, 
					java_lang_System->cls, 
					java_lang_System->setProperty, 
					name, 
					value);

			(*env)->DeleteLocalRef(env, name);
			(*env)->DeleteLocalRef(env, value);
		}
		#ifdef DEBUG
		else {
			fprintf(stderr, "%s [%u]: Failed to convert pointer acceleration threshold to string!\n", 
					__FUNCTION__, __LINE__);
		}
		#endif
	}
	#ifdef DEBUG
	else {
		fprintf(stderr, "%s [%u]: Invalid result returned from hook_get_pointer_acceleration_threshold()!\n", 
				__FUNCTION__, __LINE__);
	}
	#endif


	long sensitivity = hook_get_pointer_sensitivity();
	if (sensitivity >= 0) {
		if (snprintf(buffer, sizeof(buffer), "%li", sensitivity) >= 0) {
			jstring name = (*env)->NewStringUTF(env, "jnativehook.pointerSensitivity");
			jstring value = (*env)->NewStringUTF(env, buffer);

			(*env)->CallStaticObjectMethod(
					env, 
					java_lang_System->cls, 
					java_lang_System->setProperty, 
					name, 
					value);

			(*env)->DeleteLocalRef(env, name);
			(*env)->DeleteLocalRef(env, value);
		}
		#ifdef DEBUG
		else {
			fprintf(stderr, "%s [%u]: Failed to convert pointer sensitivity to string!\n", 
					__FUNCTION__, __LINE__);
		}
		#endif
	}
	#ifdef DEBUG
	else {
		fprintf(stderr, "%s [%u]: Invalid result returned from hook_get_pointer_sensitivity()!\n", 
				__FUNCTION__, __LINE__);
	}
	#endif


	long clicktime = hook_get_multi_click_time();
	if (clicktime >= 0) {
		#ifdef DEBUG
		fprintf(stdout, "GetMultiClickTime(): successful. (time: %li)\n", clicktime);
		#endif

		if (snprintf(buffer, sizeof(buffer), "%li", clicktime) >= 0) {
			jstring name = (*env)->NewStringUTF(env, "jnativehook.multiClickInterval");
			jstring value = (*env)->NewStringUTF(env, buffer);

			(*env)->CallStaticObjectMethod(
					env, 
					java_lang_System->cls, 
					java_lang_System->setProperty, 
					name, 
					value);

			(*env)->DeleteLocalRef(env, name);
			(*env)->DeleteLocalRef(env, value);
		}
		#ifdef DEBUG
		else {
			fprintf(stderr, "%s [%u]: Failed to convert multi click time to string!\n", 
					__FUNCTION__, __LINE__);
		}
		#endif
	}
	#ifdef DEBUG
	else {
		fprintf(stderr, "%s [%u]: Invalid result returned from hook_get_multi_click_time()!\n", 
				__FUNCTION__, __LINE__);
	}
	#endif
}


void jni_ClearProperties(JNIEnv *env) {
	jstring name = NULL;
	
	name = (*env)->NewStringUTF(env, "jnativehook.autoRepeatRate");
	(*env)->CallStaticObjectMethod(
			env, 
			java_lang_System->cls, 
			java_lang_System->clearProperty, 
			name);
	(*env)->DeleteLocalRef(env, name);


	name = (*env)->NewStringUTF(env, "jnativehook.autoRepeatDelay");
	(*env)->CallStaticObjectMethod(
			env, 
			java_lang_System->cls, 
			java_lang_System->clearProperty, 
			name);
	(*env)->DeleteLocalRef(env, name);


	name = (*env)->NewStringUTF(env, "jnativehook.pointerAccelerationMultiplier");
	(*env)->CallStaticObjectMethod(
			env, 
			java_lang_System->cls, 
			java_lang_System->clearProperty, 
			name);
	(*env)->DeleteLocalRef(env, name);


	name = (*env)->NewStringUTF(env, "jnativehook.pointerAccelerationThreshold");
	(*env)->CallStaticObjectMethod(
			env, 
			java_lang_System->cls, 
			java_lang_System->clearProperty, 
			name);
	(*env)->DeleteLocalRef(env, name);


	name = (*env)->NewStringUTF(env, "jnativehook.pointerSensitivity");
	(*env)->CallStaticObjectMethod(
			env, 
			java_lang_System->cls, 
			java_lang_System->clearProperty, 
			name);
	(*env)->DeleteLocalRef(env, name);


	name = (*env)->NewStringUTF(env, "jnativehook.multiClickInterval");
	(*env)->CallStaticObjectMethod(
			env, 
			java_lang_System->cls, 
			java_lang_System->clearProperty, 
			name);
	(*env)->DeleteLocalRef(env, name);
}