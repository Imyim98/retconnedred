JavaMountMerapi_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JavaMountMerapi_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JavaMountMerapi_OnTransition
	.byte 0

JavaMountMerapi_OnResume:
	setstepcallback STEP_CB_ASH
	end

JavaMountMerapi_OnTransition:
	call Route113_EventScript_CheckSetAshWeather
	end

