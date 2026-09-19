MtMoon_Square_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtMoon_Square_OnResume
	.byte 0

MtMoon_Square_EventScript_MtMoonSign::
	msgbox MtMoon_Square_Text_MtMoonSign, MSGBOX_SIGN
	end

MtMoon_Square_Text_MtMoonSign::
	.string "This is Mt. Moon Square.\p"
	.string "Please don't litter. Put trash\n"
	.string "where it belongs!$"

MtMoon_Square_Text_RestlessClefairy::
	.string "This CLEFAIRY seems restless…\n" 
	.string "like something dangerous is nearby.\p"
	.string "Perhaps there's something you\n"
	.string "can try to calm it with?$"

MtMoon_Square_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtMoon_Square_EventScript_TryRemoveClefable
	end

MtMoon_Square_EventScript_TryRemoveClefable::
	removeobject VAR_LAST_TALKED
	return

MtMoon_Square_EventScript_Clefable::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, MtMoon_Square_EventScript_ClefableNoPokeFlute
	msgbox MtMoon_Square_Text_RestlessClefairy
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtMoon_Square_EventScript_DontUsePokeFlute
	call EventScript_AwakenClefable
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartClefableBattle
	waitstate
	goto_if_eq VAR_RESULT, FALSE, MtMoon_Square_EventScript_DefeatedClefable  @ VAR_RESULT set by CB2_EndClefableBattle
	call MtMoon_Square_EventScript_FoughtClefable
	applymovement LOCALID_PLAYER, MtMoon_Square_Movement_ForcePlayerDown
	waitmovement 0
	releaseall
	end

MtMoon_Square_EventScript_DefeatedClefable::
	message Text_Clefable
	waitmessage
	waitse
	playmoncry SPECIES_CLEFABLE, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	msgbox Text_ClefableWasCalmed
	waitmessage
	setvar VAR_MAP_SCENE_MTMOONSQUARE, 1
	goto_if_unset FLAG_GOT_CLEFABLITE, MtMoon_Square_EventScript_GiveMegaStone
	end

MtMoon_Square_EventScript_GiveMegaStone::
	msgbox MtMoon_Square_Text_CollectStone
	waitmessage
	checkitemspace ITEM_CLEFABLITE
	goto_if_eq VAR_RESULT, FALSE, MtMoon_Square_EventScript_NoRoomForStone
	giveitem_msg MtMoon_Square_Text_ReceivedStone, ITEM_CLEFABLITE
	setflag FLAG_GOT_CLEFABLITE
	release
	end

MtMoon_Square_EventScript_NoRoomForStone::
	msgbox MtMoon_Square_Text_DontHaveRoomForThis
	release
	end

MtMoon_Square_Text_CollectStone::
	.string "Something's glowing on the ground:$"

MtMoon_Square_Text_ReceivedStone::
	.string "{PLAYER} received the CLEFABLITE!$"

MtMoon_Square_Text_DontHaveRoomForThis::
	.string "You don't have room for this.$"

MtMoon_Square_Movement_ForcePlayerDown::
	walk_down
	step_end

MtMoon_Square_EventScript_DontUsePokeFlute::
	release
	end

MtMoon_Square_EventScript_FoughtClefable::
	msgbox Text_ClefableReturnedToMountains
	release
	end

MtMoon_Square_EventScript_ClefableNoPokeFlute::
	msgbox MtMoon_Square_Text_RestlessClefairy
	release
	end

Text_EnterClefable::
	.string "Something is descending from the peaks!$"

Text_ClefableReturnedToMountains::
	.string "The rogue MEGA CLEFABLE disappeared\n" 
	.string "into the mountains…$"

Text_Clefable::
	.string "It was a rogue MEGA CLEFABLE!$"

Text_ClefableWasCalmed::
	.string "The rogue CLEFABLE was calmed.\p"
	.string "It's spirit is now free once more…$"
