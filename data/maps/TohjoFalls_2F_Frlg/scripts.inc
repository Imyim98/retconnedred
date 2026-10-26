TohjoFalls_2F_Frlg_MapScripts::
	.byte 0

TohjoFalls_2F_Frlg_EventScript_Wanderer::
	lock
	faceplayer
	message TohjoFalls_2F_Frlg_Text_WandererIntro
	waitmessage
	playbgm MUS_RG_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_WANDERER, TohjoFalls_2F_Frlg_Text_WandererDefeat
	msgbox TohjoFalls_2F_Frlg_Text_WandererPostBattle
	fadescreen FADE_TO_BLACK
	closemessage
	removeobject LOCALID_TOHJO_WANDERER
	setflag FLAG_HIDE_TOHJO_WANDERER
	fadescreen FADE_FROM_BLACK
	release
	end

TohjoFalls_2F_Frlg_Text_WandererIntro::
	.string "…!$"

TohjoFalls_2F_Frlg_Text_WandererDefeat::
	.string "…!\n"
	.string "Amazing…$"

TohjoFalls_2F_Frlg_Text_WandererPostBattle::
	.string "You have come far on your journey…$"
