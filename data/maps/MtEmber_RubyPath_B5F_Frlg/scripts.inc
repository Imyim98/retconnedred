MtEmber_RubyPath_B5F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtEmber_RubyPath_B5F_Frlg_OnResume
	.byte 0

MtEmber_RubyPath_B5F_Frlg_Text_StrangeSymbol::
	.string "There's a strange symbol carved into the ground.\p"
	.string "Do you want to examine it closer?$"

MtEmber_RubyPath_B5F_Frlg_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtEmber_RubyPath_B5F_Frlg_EventScript_TryRemoveCamerupt
	end

MtEmber_RubyPath_B5F_Frlg_EventScript_TryRemoveCamerupt::
	removeobject VAR_LAST_TALKED
	return

MtEmber_RubyPath_B5F_Frlg_EventScript_Camerupt::
	lock
	faceplayer
	msgbox MtEmber_RubyPath_B5F_Frlg_Text_StrangeSymbol, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtEmber_RubyPath_B5F_Frlg_EventScript_CameruptNo
	msgbox Text_EnterCamerupt
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartCameruptBattle
	waitstate
	goto_if_eq VAR_RESULT, FALSE, MtEmber_RubyPath_B5F_Frlg_EventScript_DefeatedCamerupt  @ VAR_RESULT set by CB2_EndCameruptBattle
	call MtEmber_RubyPath_B5F_Frlg_EventScript_FoughtCamerupt
	applymovement LOCALID_PLAYER, MtEmber_RubyPath_B5F_Frlg_Movement_ForcePlayerDown
	waitmovement 0
	releaseall
	end

MtEmber_RubyPath_B5F_Frlg_EventScript_DefeatedCamerupt::
	message Text_Camerupt
	waitmessage
	waitse
	playmoncry SPECIES_CAMERUPT, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	msgbox Text_CameruptWasCalmed
	waitmessage
	setvar VAR_MAP_SCENE_MTEMBER_RUBY, 1
	goto_if_unset FLAG_GOT_CAMERUPTITE, MtEmber_RubyPath_B5F_Frlg_EventScript_GiveMegaStone
	end

MtEmber_RubyPath_B5F_Frlg_EventScript_GiveMegaStone::
	msgbox MtEmber_RubyPath_B5F_Frlg_Text_CollectStone
	waitmessage
	checkitemspace ITEM_CAMERUPTITE
	goto_if_eq VAR_RESULT, FALSE, MtEmber_RubyPath_B5F_Frlg_EventScript_NoRoomForStone
	giveitem_msg MtEmber_RubyPath_B5F_Frlg_Text_ReceivedStone, ITEM_CAMERUPTITE
	setflag FLAG_GOT_CAMERUPTITE
	release
	end

MtEmber_RubyPath_B5F_Frlg_EventScript_NoRoomForStone::
	msgbox MtEmber_RubyPath_B5F_Frlg_Text_DontHaveRoomForThis
	release
	end

MtEmber_RubyPath_B5F_Frlg_Text_CollectStone::
	.string "Something's glowing on the ground:$"

MtEmber_RubyPath_B5F_Frlg_Text_ReceivedStone::
	.string "{PLAYER} received the CAMERUPTITE!$"

MtEmber_RubyPath_B5F_Frlg_Text_DontHaveRoomForThis::
	.string "You don't have room for this.$"

MtEmber_RubyPath_B5F_Frlg_Movement_ForcePlayerDown::
	walk_down
	step_end

MtEmber_RubyPath_B5F_Frlg_EventScript_FoughtCamerupt::
	msgbox Text_CameruptReturnedToDepths
	release
	end

MtEmber_RubyPath_B5F_Frlg_EventScript_CameruptNo::
	msgbox Text_NoCamerupt
	release
	end

Text_NoCamerupt::
	.string "You decided to leave it alone for now.$"

Text_EnterCamerupt::
	.string "Something is emerging from below!$"

Text_CameruptReturnedToDepths::
	.string "The rogue MEGA Camerupt disappeared\n" 
	.string "into the depths…$"

Text_Camerupt::
	.string "It was a rogue MEGA Camerupt!$"

Text_CameruptWasCalmed::
	.string "The rogue Camerupt was calmed.\p"
	.string "It's spirit is now free once more…$"
