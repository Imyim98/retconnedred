ViridianDeepForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ViridianDeepForest_OnResume
	.byte 0

ViridianDeepForest_Text_RestlessPikachu::
	.string "This PIKACHU seems restless...\n" 
	.string "like something dangerous is nearby.\p"
	.string "Perhaps there's something you\n"
	.string "can try to calm it with?$"

ViridianDeepForest_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ViridianDeepForest_EventScript_TryRemoveRaichuX
	end

ViridianDeepForest_EventScript_TryRemoveRaichuX::
	removeobject VAR_LAST_TALKED
	return

ViridianDeepForest_EventScript_RaichuX::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_POKE_FLUTE, ViridianDeepForest_EventScript_RaichuXNoPokeFlute
	msgbox ViridianDeepForest_Text_RestlessPikachu
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, ViridianDeepForest_EventScript_DontUsePokeFlute
	call EventScript_AwakenRaichuX
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRaichuXBattle
	waitstate
	goto_if_eq VAR_RESULT, FALSE, ViridianDeepForest_EventScript_DefeatedRaichuX  @ VAR_RESULT set by CB2_EndRaichuXBattle
	call ViridianDeepForest_EventScript_FoughtRaichuX
	applymovement LOCALID_PLAYER, ViridianDeepForest_Movement_ForcePlayerDown
	waitmovement 0
	releaseall
	end

ViridianDeepForest_EventScript_DefeatedRaichuX::
	message Text_RaichuX
	waitmessage
	waitse
	playmoncry SPECIES_RAICHU, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	msgbox Text_RaichuXWasCalmed
	waitmessage
	setvar VAR_MAP_SCENE_DEEPFOREST, 1
	goto_if_unset FLAG_GOT_RAICHUNITEX, ViridianDeepForest_EventScript_GiveMegaStone
	end

ViridianDeepForest_EventScript_GiveMegaStone::
	msgbox ViridianDeepForest_Text_CollectStone
	waitmessage
	checkitemspace ITEM_RAICHUNITE_X
	goto_if_eq VAR_RESULT, FALSE, ViridianDeepForest_EventScript_NoRoomForStone
	giveitem_msg ViridianDeepForest_Text_ReceivedStone, ITEM_RAICHUNITE_X
	setflag FLAG_GOT_RAICHUNITEX
	release
	end

ViridianDeepForest_EventScript_NoRoomForStone::
	msgbox ViridianDeepForest_Text_DontHaveRoomForThis
	release
	end

ViridianDeepForest_Text_CollectStone::
	.string "Something's glowing on the ground:$"

ViridianDeepForest_Text_ReceivedStone::
	.string "{PLAYER} received the RAICHUNITE X!$"

ViridianDeepForest_Text_DontHaveRoomForThis::
	.string "You don't have room for this.$"

ViridianDeepForest_Movement_ForcePlayerDown::
	walk_down
	step_end

ViridianDeepForest_EventScript_DontUsePokeFlute::
	release
	end

ViridianDeepForest_EventScript_FoughtRaichuX::
	msgbox Text_RaichuXReturnedToForest
	release
	end

ViridianDeepForest_EventScript_RaichuXNoPokeFlute::
	msgbox ViridianDeepForest_Text_RestlessPikachu
	release
	end

Text_EnterRaichuX::
	.string "Something is emerging from the trees!$"

Text_RaichuXReturnedToForest::
	.string "The rogue MEGA RAICHU disappeared\n" 
	.string "into the forest...$"

Text_RaichuX::
	.string "It was a rogue MEGA RAICHU!$"

Text_RaichuXWasCalmed::
	.string "The rogue RAICHU was calmed.\p"
	.string "It's spirit is now free once more...$"
